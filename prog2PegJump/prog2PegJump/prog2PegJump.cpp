//	Author: Victor Fong
//	Assignment : 2, PegJump
//	TA : Nianzu Ma, Tues 4PM
//	Feb 4, 2017



/*SAMPLE OUTPUT:
Author: Victor Fong
Program: #1, Guess Number
TA: Lamar, Tues @ 4PM
2/4/2017


This program represents the peg jumping puzzle.

The board starts out with a single blank position, represented by the 'O'.
To make a move, select the letter of the peg to be moved, then the letter of the destination position
(e.g.the first move might be : d a, meaning we move peg 'd' into blank position 'a').
A peg must be able to jump over an adjacent peg into a blank for a move to be valid.
The jumped peg is then removed from the board.
The game is over when there are no valid moves left to be made, or when there is a single peg left.

At any point enter 'x' to exit the program.

-----------------------
  Board    Positions
    o          A
   + +        B C
  + + +      D E F
 + + + +    G H I J
+ + + + +  K L M N O
-----------------------

Enter your move: d a

-----------------------
  Board    Positions
    +          A
   o +        B C
  o + +      D E F
 + + + +    G H I J
+ + + + +  K L M N O
-----------------------

Enter your move: k d

-----------------------
  Board    Positions
    +          A
   o +        B C
  + + +      D E F
 o + + +    G H I J
o + + + +  K L M N O
-----------------------

Enter your move: i g

-----------------------
  Board    Positions
    +          A
   o +        B C
  + + +      D E F
 + o o +    G H I J
o + + + +  K L M N O
-----------------------

Enter your move: n p


*** Invalid destination.  Please retry ****


-----------------------
  Board    Positions
    +          A
   o +        B C
  + + +      D E F
 + o o +    G H I J
o + + + +  K L M N O
-----------------------

Enter your move: q n


*** Invalid source.  Please retry ****


-----------------------
  Board    Positions
    +          A
   o +        B C
  + + +      D E F
 + o o +    G H I J
o + + + +  K L M N O
-----------------------

Enter your move: j h


*** Must jump a piece.  Please retry. ***


-----------------------
  Board    Positions
    +          A
   o +        B C
  + + +      D E F
 + o o +    G H I J
o + + + +  K L M N O
-----------------------

Enter your move: b i


*** Source must have a piece.  Please retry. ***


-----------------------
  Board    Positions
    +          A
   o +        B C
  + + +      D E F
 + o o +    G H I J
o + + + +  K L M N O
-----------------------

Enter your move: l n


*** Destination must be empty.  Please retry. ***


-----------------------
  Board    Positions
    +          A
   o +        B C
  + + +      D E F
 + o o +    G H I J
o + + + +  K L M N O
-----------------------

Enter your move: g b

-----------------------
  Board    Positions
    +          A
   + +        B C
  o + +      D E F
 o o o +    G H I J
o + + + +  K L M N O
-----------------------

Enter your move: a d

-----------------------
  Board    Positions
    o          A
   o +        B C
  + + +      D E F
 o o o +    G H I J
o + + + +  K L M N O
-----------------------

Enter your move: c h

-----------------------
  Board    Positions
    o          A
   o o        B C
  + o +      D E F
 o + o +    G H I J
o + + + +  K L M N O
-----------------------

Enter your move: l e

-----------------------
  Board    Positions
    o          A
   o o        B C
  + + +      D E F
 o o o +    G H I J
o o + + +  K L M N O
-----------------------

Enter your move: j c

-----------------------
  Board    Positions
    o          A
   o +        B C
  + + o      D E F
 o o o o    G H I J
o o + + +  K L M N O
-----------------------

Enter your move: c h

-----------------------
  Board    Positions
    o          A
   o o        B C
  + o o      D E F
 o + o o    G H I J
o o + + +  K L M N O
-----------------------

Enter your move: n l

-----------------------
  Board    Positions
    o          A
   o o        B C
  + o o      D E F
 o + o o    G H I J
o + o o +  K L M N O
-----------------------

Enter your move: d m

-----------------------
  Board    Positions
    o          A
   o o        B C
  o o o      D E F
 o o o o    G H I J
o + + o +  K L M N O
-----------------------

Enter your move: l n

-----------------------
  Board    Positions
    o          A
   o o        B C
  o o o      D E F
 o o o o    G H I J
o o o + +  K L M N O
-----------------------

Enter your move: o m

# left   Rating
------  ---------------
  >4     Dufus
  4      Poor
  3      Mediocre
  2      Good Job
  1      Awesome Genius!

You had 1 left. Awesome Genius!

Thanks for Playing... Exiting . . .

Press any key to continue . . .
*/


//include libraries
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


char getChar(char input) {	//function acquires input of a character as prompted by other functions.

	scanf(" %c", &input);

	return input;
}




char correctUpper(char input) {		//function changes any of the possible lower-case iterations inputted by user into a capital letter for ease of use.

	switch (input) {
		case 'a': input = 'A'; break;
		case 'b': input = 'B'; break;
		case 'c': input = 'C'; break;
		case 'd': input = 'D'; break;
		case 'e': input = 'E'; break;
		case 'f': input = 'F'; break;
		case 'g': input = 'G'; break;
		case 'h': input = 'H'; break;
		case 'i': input = 'I'; break;
		case 'j': input = 'J'; break;
		case 'k': input = 'K'; break;
		case 'l': input = 'L'; break;
		case 'm': input = 'M'; break;
		case 'n': input = 'N'; break;
		case 'o': input = 'O'; break;
		default: break;
	}

	return input;
}


int checkForX(char input) {	//function that takes character variable and checks for for 'x' or 'X'. if true than the function will return an integer of 1 to main(), which will then break away from the loop.
	int errCheck = 0;

	if (input == 'X' || input == 'x') {
		errCheck = 1;
	}
	return errCheck;
}


void displayInfo(void) {    //function Displays general information of program

	printf("Author: Victor Fong\n");
	printf("Program: #1, Guess Number\n");
	printf("TA: Nianzu Ma, Tues @ 4PM\n");
	printf("2/4/2017\n");
	printf("\n\n\n");
	return;
}



void displayInstructions(void) {    //function displays instructions of program

	printf("This program represents the peg jumping puzzle.\n");
	printf("\n");
	printf("The board starts out with a single blank position, represented by the 'O'.\nTo make a move, select the letter of the peg to be moved, then the letter of the destination position\n(e.g.the first move might be : d a, meaning we move peg 'd' into blank position 'a').\nA peg must be able to jump over an adjacent peg into a blank for a move to be valid.\nThe jumped peg is then removed from the board.\nThe game is over when there are no valid moves left to be made, or when there is a single peg left.\n");
	printf("\n");
	printf("At any point enter 'x' to exit the program.\n");

	return;
}


void showBoard(char p1, char  p2, char  p3, char  p4, char  p5, char  p6, char  p7, char  p8, char  p9, char  p10, char  p11, char  p12, char  p13, char  p14, char  p15) {		//function displays the pegboard and it's subsequent positions.

	printf("\n-----------------------\n"); //total board is 23 chars wide
	printf("  Board    Positions   \n");
	printf("    %c          A       \n", p1);
	printf("   %c %c        B C      \n", p2, p3);
	printf("  %c %c %c      D E F     \n", p4, p5, p6);
	printf(" %c %c %c %c    G H I J    \n", p7, p8, p9, p10);
	printf("%c %c %c %c %c  K L M N O   \n", p11, p12, p13, p14, p15);
	printf("-----------------------\n");
	printf("\n");
	return;
}


void promptforMove(void) {		//function displays a single print statement to prompt the user for a move.

	printf("Enter your move: ");

	return;
}


void showScoreBoard(int pegsLeft) {		//function displays a finishing scoreboard that ranks the user based on how many pegs they successfully removed from the pegboard.

	printf("\n# left  Rating         \n");
	printf("------  ---------------\n");
	printf("  >4    Dufus          \n");
	printf("   4    Poor           \n");
	printf("   3    Mediocre       \n");
	printf("   2    Good Job       \n");
	printf("   1    Awesome Genius!\n");
	printf("                       \n");
	printf("You had %d left. ", pegsLeft);

	switch (pegsLeft) {
	case 1: printf("Awesome Genius!\n\n"); break;
	case 2: printf("Good Job.\n\n"); break;
	case 3: printf("Mediocre.\n\n"); break;
	case 4: printf("Poor.\n\n"); break;
	default: printf("Dufus.\n\n"); break;
	}
	printf("Thanks for Playing... Exiting . . .\n\n");


return;
}

//function will determine the symbol of a specified position('+' or 'o')
char getPiece(char p1, char  p2, char  p3, char  p4, char  p5, char  p6, char  p7, char  p8, char  p9, char  p10, char  p11, char  p12, char  p13, char  p14, char  p15, char piece) {
	char pieceGot = ' ';
	

	
	switch (piece) {
		case 'A': pieceGot = p1; break;
		case 'B': pieceGot = p2; break;
		case 'C': pieceGot = p3; break;
		case 'D': pieceGot = p4; break;
		case 'E': pieceGot = p5; break;
		case 'F': pieceGot = p6; break;
		case 'G': pieceGot = p7; break;
		case 'H': pieceGot = p8; break;
		case 'I': pieceGot = p9; break;
		case 'J': pieceGot = p10; break;
		case 'K': pieceGot = p11; break;
		case 'L': pieceGot = p12; break;
		case 'M': pieceGot = p13; break;
		case 'N': pieceGot = p14; break;
		case 'O': pieceGot = p15; break;
	}


	return pieceGot;
}

//function will set a symbol ('+' or 'o') to a specified position on the board.
void setPiece(char *p1, char  *p2, char  *p3, char  *p4, char  *p5, char  *p6, char  *p7, char  *p8, char  *p9, char  *p10, char  *p11, char  *p12, char  *p13, char  *p14, char  *p15, char symbol, char position) {


	switch (position) {
	case 'A': *p1 = symbol; break;
	case 'B': *p2 = symbol; break;
	case 'C': *p3 = symbol; break;
	case 'D': *p4 = symbol; break;
	case 'E': *p5 = symbol; break;
	case 'F': *p6 = symbol; break;
	case 'G': *p7 = symbol; break;
	case 'H': *p8 = symbol; break;
	case 'I': *p9 = symbol; break;
	case 'J': *p10 = symbol; break;
	case 'K': *p11 = symbol; break;
	case 'L': *p12 = symbol; break;
	case 'M': *p13 = symbol; break;
	case 'N': *p14 = symbol; break;
	case 'O': *p15 = symbol; break;
	}

	return;
}

//function determines what position is between the chosen move "from" and the chosen move "to". Case-switch statement grouped specially for ease of readinga and functionality!
char findMid(char from, char to) {
	char mid = ' ';

	switch (from) {
	case 'A': switch (to) {case 'D': mid = 'B'; break;
						   case 'F': mid = 'C'; break;}
			  break;
	
	case 'B': switch (to) {case 'G': mid = 'D'; break;
						   case 'I': mid = 'E'; break;}
			  break;
	
	case 'C': switch (to) {case 'H': mid = 'E'; break;
						   case 'J': mid = 'F'; break;}
			  break;
	
	case 'D': switch (to) {case 'A': mid = 'B'; break;
						   case 'F': mid = 'E'; break;
						   case 'M': mid = 'H'; break;
						   case 'K': mid = 'G'; break;}
			  break;
	
	case 'E': switch (to) {case 'N': mid = 'I'; break;
						   case 'L': mid = 'H'; break;}
			  break;
	
	case 'F': switch (to) {case 'A': mid = 'C'; break;
						   case 'D': mid = 'E'; break;
						   case 'M': mid = 'I'; break;
						   case 'O': mid = 'J'; break;}
			  break;
	
	case 'G': switch (to) {case 'B': mid = 'D'; break;
						   case 'I': mid = 'H'; break;}
			  break;
	
	case 'H': switch (to) {case 'C': mid = 'E'; break;
						   case 'J': mid = 'I'; break;}
			  break;
	
	case 'I': switch (to) {case 'B': mid = 'E'; break;
						   case 'G': mid = 'H'; break;}
			  break;
	
	case 'J': switch (to) {case 'C': mid = 'F'; break;
						   case 'H': mid = 'I'; break;}
			  break;
	
	case 'K': switch (to) {case 'D': mid = 'G'; break;
						   case 'M': mid = 'L'; break;}
			  break;
	
	case 'L': switch (to) {case 'E': mid = 'H'; break;
						   case 'N': mid = 'M'; break;}
			  break;
	
	case 'M': switch (to) {case 'K': mid = 'L'; break;
						   case 'D': mid = 'H'; break;
						   case 'O': mid = 'N'; break;}
			  break;
	
	case 'N': switch (to) {case 'L': mid = 'M'; break;
						   case 'E': mid = 'I'; break;}
			  break;
	
	case 'O': switch (to) {case 'M': mid = 'N'; break;
						   case 'F': mid = 'J'; break;}
			  break;
	}
	
	return mid;
}

//errorChecker: checks if input is a character between 'A' and 'O'. if is is not then it will change errCode, which is returned to main() to check for errors
int rangeCheck(char input) {

	int errCode = 0;
	int decimal = 0;

	decimal = input;

	if (decimal >= 65 && decimal <= 79) {
		errCode = 0;
	}
	else {
		errCode = 1;
	}

	return errCode;
}

//errorChecker: checks for input of the character '+'. if is is not then it will change errCode, which is returned to main() to check for errors
int sourceisPeg(char symbolAtStart) {

	int errStatus = 0;


	if (symbolAtStart == '+') {
		errStatus = 0;
	}
	else {
		errStatus = 1;
	}
	return errStatus;
}

//errorChecker: checks for input of the character 'o'. if is is not then it will change errCode, which is returned to main() to check for errors
int destinationBlank(char symbolAtDest) {
	
	int errStatus = 0;
	

	if (symbolAtDest == 'o') {
		errStatus = 0;
	}
	else {
		errStatus = 1;
	}
	return errStatus;
}

//errorChecker: checks the middlePosition of a swap for input of the character '+'. if is is not then it will change errCode, which is returned to main() to check for errors
int middlePositionIsPeg(char middlePosition) {
		int errStatus = 0;

		if (middlePosition == '+') {
			errStatus = 0;
		}
		else {
			errStatus = 1;
		}

		return errStatus;
	}


int main(void) {	//main program

//initialize variables	
	char o = 'o';
	char plus = '+';
	char p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15;
	p1 = 'o';
	p2 = p3 = p4 = p5 = p6 = p7 = p8 = p9 = p10 = p11 = p12 = p13 = p14 = p15 = '+';

	char moveFrom = ' ';
	char middlePosition = ' ';
	char moveTo = ' ';
	char charInput1 = ' ';
	char charInput2 = ' ';
	char symbolFrom = ' ';
	char symbolMid = ' ';
	char symbolTo = ' ';
	int numPlus = 14;
	int exitLoopStatus = 0;
	int errStatus1, errStatus2, errStatus3, errStatus4, errStatus5;
	errStatus1 = errStatus2 = errStatus3 = errStatus4 = errStatus5 = 0;

//call functions and make calculations. see function definitions above for more information!
	displayInfo();
	displayInstructions();
	
	while (numPlus > 1){ //set counter
		showBoard(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
		promptforMove();
		charInput1 = getChar(charInput1);
		exitLoopStatus = checkForX(charInput1);

		if (exitLoopStatus == 1) {
			break;
		}
		else {
			charInput2 = getChar(charInput2);

			moveFrom = correctUpper(charInput1);
			symbolFrom = getPiece(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, moveFrom);
			
			moveTo = correctUpper(charInput2);
			symbolTo = getPiece(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, moveTo);
			
			middlePosition = findMid(moveFrom, moveTo);
			symbolMid = getPiece(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, middlePosition);
	//check for errors
			errStatus1 = rangeCheck(moveFrom);
			errStatus2 = rangeCheck(moveTo);
			errStatus3 = sourceisPeg(symbolFrom);
			errStatus4 = destinationBlank(symbolTo);
			errStatus5 = middlePositionIsPeg(symbolMid);



			if (errStatus1 !=0){
				printf(" \n\n *** Invalid source.  Please retry ****\n\n");
				continue;
			}
			else if (errStatus2 != 0) {
				printf(" \n\n  *** Invalid destination.  Please retry ****\n\n");
				continue;
			}
			else if (errStatus3 != 0) {
				printf("\n\n   *** Source must have a piece.  Please retry. ***\n\n");
				continue;
			}
			else if (errStatus4 != 0) {
				printf("\n\n   *** Destination must be empty.  Please retry. ***\n\n");
				continue;
			}
			else if (errStatus5 != 0) {
				printf("\n\n   *** Must jump a piece.  Please retry. ***\n\n");
				continue;
			}
			else {

				setPiece(&p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &p9, &p10, &p11, &p12, &p13, &p14, &p15, 'o', moveFrom);
				setPiece(&p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &p9, &p10, &p11, &p12, &p13, &p14, &p15, 'o', middlePosition);
				setPiece(&p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &p9, &p10, &p11, &p12, &p13, &p14, &p15, '+', moveTo);

				numPlus -= 1; //adjust counter
			}
		}
	} 
	
	showScoreBoard(numPlus);
	

	return 0;
}