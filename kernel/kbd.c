#include "types.h"
#include "x86.h"
#include "defs.h"
#include "kbd.h"

// ALT = modifier key, does not affect ASCII values
int block_input = 0;

int
kbdgetc(void)
{
	static uint shift;
	static uchar *charcode[4] = {
		normalmap, shiftmap, ctlmap, ctlmap
	};
	uint st, data, c;

	st = inb(KBSTATP);						// status byte of the keyboard controller
	if((st & KBS_DIB) == 0)
		return -1;
	data = inb(KBDATAP);					// data byte from the keyboard input buffer

	// clicked ALT+c (scancode for 'c' is 0x2E)
	if ((data == (0x2E | (1 << 2))) && (shift & (1 << 2))) {
		clicked_alt_c();
	}

	if(data == 0xE0){
		shift |= E0ESC;
		return 0;
	} else if(data & 0x80){
		// Key released
		data = (shift & E0ESC ? data : data & 0x7F);
		shift &= ~(shiftcode[data] | E0ESC);
		return 0;
	} else if(shift & E0ESC){
		// Last character was an E0 escape; or with 0x80
		data |= 0x80;
		shift &= ~E0ESC;
	} 

	shift |= shiftcode[data];
	shift ^= togglecode[data];
	c = charcode[shift & (CTL | SHIFT)][data];

	if(shift & CAPSLOCK){
		if('a' <= c && c <= 'z')
			c += 'A' - 'a';
		else if('A' <= c && c <= 'Z')
			c += 'a' - 'A';
	}
	return c;
}

void
kbdintr(void)
{
	
	consoleintr(kbdgetc);
}