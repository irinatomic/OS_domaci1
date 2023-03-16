## Homework 1 for Uni
The purpose of this homework was to practice understanding of the <br>
kernel/console.c and kernel/kbd.c files. The task was to show a custom <br>
table for choosing the color of the ourput text on the console.

Table appears and dissappears with the click ofvALT+C (for Mac users: Option+C). <br>
While the table is showing, the input to the console is disabled. <br>
Only moving through the table is allowed:
1. 'w' - go up
2. 's' - go down
The final choice is the one that is selected when the table dissappears.

The options in the table are:
1. WHT BLK (white on black)
2. PUR WHT (purple on white)
3. RED AQU (red on aqua)
4. WHT YEL (white on yellow)

## Important - Makefile is for M1 Macs
Makefile given in this repo is the one one configured so the xv6 works on Macs <br> 
with M1 chip. After cloning this repo to M1 Mac, run these commands in terminal:
`brew install qemu`
`brew install x86_64-elf-gcc`

Create a .bash_profile that contains additional variables for running xv6. <br>
`cd ~/` <br>
`touch .bash_profile` <br>
`open -e .bash_profile` 

Add these commands to your .bash_profile file: <br>
`export TOOLPREFIX=x86_64-elf- ` <br>
`export QEMU=qemu-system-x86_64`

Finally, run the file: <br>
`source .bash_profile`

After cmpleting this, you can go into the cloned repo and start the xv6 with <br>
`make qemu`