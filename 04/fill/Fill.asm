// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.
(START)
    @24576
    D=M     // set D to the keyboard map
    @START
    D;JEQ   // goto start of program if d is 0
    @16384
    D=A
    @screenIndex
    M=D
(BLACK)
    @24575
    D=D-A   // check if all the screen memory map has been written to
    @START
    D;JEQ
    @screenIndex
    D=M + 1
    A=D-1
    M=-1    // turn it all black
    @screenIndex
    M=D
    @BLACK
    0;JMP
