/*
    Name: Chen, Isaac, 2002582920, CS 135 1001, Assignment 7
    Description: Creating a C++ program that takes in a some
	input and draws
    Input: coordinates
    Output: art
*/
#include <iostream>
#include <string>
//You may NOT include additional libraries.

using namespace std;

const int CANVAS_DIM = 100; //Max dimensions of the canvas

//Function prototypes/declarations
//In C++, we must tell the compiler about any functions, variables, classes, etc. before using them.
//We'll declare functions above main, use them in main, and then write actual definition (code) below main
//Prototypes can either include parameter names or just the types

int readInteger(int min, int max);
char readCharacter();
void readCanvasDimensions(int& width, int& height);
void readPosition(int& x, int& y, int width, int height);
void drawPoint(char canvas[CANVAS_DIM][CANVAS_DIM], int x, int y, char draw_char = ' ');
void drawHorizontalLine(char[CANVAS_DIM][CANVAS_DIM], int left, int y, int length, char draw_char);
void drawVerticalLine(char[CANVAS_DIM][CANVAS_DIM], int top, int x, int height, char draw_char);
void drawRectangle(char canvas[CANVAS_DIM][CANVAS_DIM], int left, int width, int top, int height, char draw_char);
void clearCanvas(char canvas[CANVAS_DIM][CANVAS_DIM], int height, int width);
void displayCanvas(char canvas[CANVAS_DIM][CANVAS_DIM], int height, int width);
//TODO: Finish prototypes/declarations for clearCanvas and printCanvas as described in pdf

int main() {
	char canvas[CANVAS_DIM][CANVAS_DIM]; //Canvas to draw our beautiful art on. (In)finite possibilities
	clearCanvas(canvas, CANVAS_DIM, CANVAS_DIM); //Clear the canvas to begin

	int canvasWidth, canvasHeight;
	readCanvasDimensions(canvasWidth, canvasHeight); //Get initial canvas width and height

	//Print a welcome message
	cout << "################## Welcome to CS Paint! ##################" << endl;
	cout << "p = Draw Point" << endl;
	cout << "h = Draw Horizontal Line" << endl;
	cout << "v = Draw Vertical Line" << endl;
	cout << "r = Draw Rectangle" << endl;
	cout << "e = Erase" << endl;
	cout << "d = Display Picture" << endl;
	cout << "s = Resize Canvas" << endl;
	cout << "x = Exit and Display Picture" << endl;
	cout << "##########################################################" << endl;

	char option = ' '; //Used for getting what to do and the char to draw with
	int x, y, length, width; //For finding position to draw and length if applicable
	while (option != 'x')
	{
		cout << "Enter next command" << endl;
		cin >> option;
		switch (option)
		{
			case 'p': //Draw point
				readPosition(x, y, canvasWidth, canvasHeight); //Read the position to draw the point at
				drawPoint(canvas, x, y, readCharacter()); //Read the character to draw and draw it 
				break;
			case 'h': //Draw horizontal line
				readPosition(x, y, canvasWidth, canvasHeight); //Read the position to draw the line at
				cout << "Please enter length of line" << endl;
				length = readInteger(0, canvasWidth);
				drawHorizontalLine(canvas, x, y, length, readCharacter()); //Read the character to draw and draw it 
				break;
			case 'v': //Draw vertical line
				readPosition(x, y, canvasWidth, canvasHeight); //Read the position to draw the line at
				cout << "Please enter length of line" << endl;
				length = readInteger(0, canvasHeight);
				drawVerticalLine(canvas, y, x, length, readCharacter()); //Read the character to draw and draw it
				break;
			case 'r': //Draw rectangle
				readPosition(x, y, canvasWidth, canvasHeight); //Read the position to draw the rectangle at
				cout << "Please enter length of the rectangle" << endl; //Prompt for length and width and read within args
				length = readInteger(0, canvasWidth);
				cout << "Please enter width of the rectangle" << endl; //Prompt for length and width and read within args
				width = readInteger(0, canvasHeight);
				drawRectangle(canvas, x, length, y, width, readCharacter()); 
				break;
			case 'e': //Erase Canvas
				clearCanvas(canvas, canvasWidth, canvasHeight);
				break;
			case 'd': //Display Canvas
				displayCanvas(canvas, canvasWidth, canvasHeight);
				break;
			case 's': //Get new Canvas Dimensions
				readCanvasDimensions(canvasWidth, canvasHeight);
				break;
			case 'x': //Exit
				break;
			default:
				cout << "Option " << option << " is not supported" << endl;
				break;
		}
	}
	displayCanvas(canvas, canvasHeight, canvasWidth);
}

/* Reads an integer within the interval [min, max]
This function is written for you as an example of writing and using functions */
int readInteger(int min, int max)
{
	int value = min; //Initialize because CodeGrade gets mad if you only initialize through reads
	cin >> value; //Read the value
	//Re-read until the input does not fail and is in the given interval
	while (cin.fail() || value < min || value > max)
	{
		cin.clear();
		cin.ignore(4028);
		cout << "Invalid, please provide an int in the range [" << min << ", " << max << "]" << endl;
		cin >> value;
	}

	return value; //Return value after we're sure it's good
}

//TODO: Complete the definitions for the functions below

/* Reads a character and returns it */
char readCharacter()
{
	//Read a character from cin and return it
	cout << "Gimme a char" << endl;
	char potato = ' ';
	cin >> potato;
	return potato;
}

/* YOUR DESCRIPTION HERE */
void readPosition(int& x, int& y, int width, int height)
{
	/*Prompt and read the x and y positions. This is used for placing characters on the screen
	Prompt with the string "Please enter the _ position" where _ is replaced with x and you
	First prompt for x, read it, then prompt for y.
	Parameters with a & after the type are pass by reference, meaning any modifications that occur on those
	variables will persist on the arguments that were filled in for them .
	It's recommended to use the provided readInteger function. x 
	should be in the interval [0 , width] and y in [0, height]*/
	cout << "Please enter the x position" << endl;
	x = readInteger(0, width);
	cout << "Please enter the y position" << endl;
	y = readInteger(0, height);

}

void readCanvasDimensions(int& width, int& height)
{
	/* Prompts and reads the dimensions of the canvas to use. Should first prompt for width, then height.
	Similar to readPosition, the variables to be read are passed via 
	reference and it is suggested to use the readInteger function.
	Values should be in the range [0, CANVAS_DIM].
	Users should be prompted with "Please enter the _ of the canvas" where _ is replaced with the width or height
	*/
	string prompt1 = "Please enter the width of the canvas";
	string prompt2 = "Please enter the height of the canvas";

	cout << prompt1 << endl;
	width = readInteger(0, CANVAS_DIM);
	cout << prompt2 << endl;
	height = readInteger(0, CANVAS_DIM);
}

/* Makes the canvas blank. */
void clearCanvas(char canvas[CANVAS_DIM][CANVAS_DIM], int height, int width)
{
	/* Sets all elements in the given 2D canvas array to spaces chacters. The height and width of the canvas are given. */
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			canvas[i][j] = ' ';
		}
	}
}

/* YOUR DESCRIPTION HERE */
void displayCanvas(char canvas[CANVAS_DIM][CANVAS_DIM], int height, int width)
{
	/* Prints the given 2D canvas array to standard out. The height and width of the canvas are given. */
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			cout << canvas[i][j];
		}
		cout << endl;
	}
}

void drawPoint(char canvas[CANVAS_DIM][CANVAS_DIM], int x, int y, char draw_char)
{
	/* Set a single point in the canvas at the given x, y position to 
	the given character (Remember, y comes before x here) */
	canvas[y][x] = draw_char;
}

void drawHorizontalLine(char canvas[CANVAS_DIM][CANVAS_DIM], int left, int y, int length, char draw_char)
{
	/* Draws a horizontal line in the canvas. The left tells where the left side of the line is. 
	The y is the y position of the line in 
	the canvas. The length is the length of the line and the draw_char is the character to use when drawing the line. 
	Please see the pdf 
	for an illustrated example. Recommended that you use the drawPoint function to draw all points in the line */
	for (int i = 0; i < length; i++) {
		drawPoint(canvas, left + i, y, draw_char);
	}
}

//drawVerticalLine definition goes here!
void drawVerticalLine(char canvas[CANVAS_DIM][CANVAS_DIM], int top, int x, int height, char draw_char)
{
	/* Draws a vertical line in the canvas. The top tells where the top side of the line is. The x is the x position 
	of the line in 
	the canvas. The length is the length of the line and the draw_char is the character to use when drawing the line. 
	Please see the pdf 
	for an illustrated example. Recommended that you use the drawPoint function to draw all points in the line */
	for (int i = 0; i < height; i++) {
		drawPoint(canvas, x, top + i, draw_char);
	}

}

void drawRectangle(char canvas[CANVAS_DIM][CANVAS_DIM], int left, int width, int top, int height, char draw_char)
{
	/* Draws a rectangle to the canvas whose top left corner is given by the top and left variables. 
	This should use the drawHorizontalLine and drawVerticalLine functions to draw the top, bottom, 
	left, and right edges of
	the rectangle. This should be about 4 lines (I's encouraged to get practice with using other 
	function to simplify code) */

	drawHorizontalLine(canvas, left, top, width, draw_char);
    drawHorizontalLine(canvas, left, top + height - 1, width, draw_char);
    drawVerticalLine(canvas, top, left, height, draw_char);
    drawVerticalLine(canvas, top, left + width - 1, height, draw_char);


} 