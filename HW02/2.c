/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW02_141044021_Emre_Behadir                                              */                                                                          
/*                                                                          */
/* main.c                                                                   */
/* ---------                              									*/
/* Created on 27/02/2016 by Emre_Behadir									*/ 
/*                                                      					*/
/* Description                                          					*/
/* -----------                                          					*/
/*    The main.c contains the implementations of second part of homework II.*/
/*	  This code develop for computing grade of lesson.					    */
/*                                                                          */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*                                 Includes                                 */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#define PI 3.14

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* int perimeterofRectangle(int width, int height)                          */
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/* 		This function takes rectangle width and height for computing        */
/*      perimeter of rectangle.   											*/
/*                                                                          */
/*--------------------------------------------------------------------------*/
int perimeterofRectangle(int width, int height);
/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* int areaofRectangle(int width, int height)                               */
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/* 		This function takes rectangle width and height for computing area   */
/* 		of rectangle.   											        */
/*                                                                          */
/*--------------------------------------------------------------------------*/
int areaofRectangle(int width, int height);
/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* int perimeterOfCircle(int radius)                                        */
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes circle radius for computing perimeter of circle   */
/*                                                                          */
/*--------------------------------------------------------------------------*/
int perimeterOfCircle(int radius);
/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* int areaOfCircle(int radius)                                             */
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes circle radius for computing perimeter of area     */
/*                                                                          */
/*--------------------------------------------------------------------------*/
int areaOfCircle(int radius);

int main()
{
	int rectangleWidth,rectangleHeight,
		squareWidth,
		radCircle;

	int	areaRegtangle,perimeterRegtangle,
		areaSquare,perimeterSquare,
		arCircle,perCircle;

	printf("Please enter the width of the rectangle:");
	scanf("%d",&rectangleWidth);
	printf("Please enter the height of the rectangle:");
	scanf("%d",&rectangleHeight);
	
	areaRegtangle =areaofRectangle(rectangleWidth,rectangleHeight);
	
	printf("The area of the rectangle is: %d\n", areaRegtangle);
	
	perimeterRegtangle = perimeterofRectangle(rectangleWidth,rectangleHeight);
	
	printf("The perimeter of the rectangle is: %d\n",perimeterRegtangle );
	
	printf("Please enter the width of the square:");
	scanf("%d",&squareWidth);

	areaSquare = areaofRectangle(squareWidth,squareWidth);

	printf("The area of the square is: %d\n", areaSquare);

	perimeterSquare = perimeterofRectangle(squareWidth,squareWidth);

	printf("The perimeter of the square is: %d\n", perimeterSquare);

	printf("Please enter the radius of circle:");			
	scanf("%d",&radCircle);
 	
 	arCircle = areaOfCircle(radCircle);

	printf("The area of the circle is: %d\n", arCircle);

	perCircle= perimeterOfCircle(radCircle);
	printf("The perimeter of the circle is: %d\t  ", perCircle );

	return 0;
}
/*--------------------------------------------------------------------------*/
/*                               End of main.c                              */
/*--------------------------------------------------------------------------*/

int areaofRectangle(int width, int height)
{
	
	return(width*height);
}

int perimeterofRectangle(int width, int height)
{
	
	return(2*width + 2*height);
}

int areaOfCircle(int radius)
{
	
	return(PI*radius*radius);
}

int perimeterOfCircle(int radius)
{
	
	return(2*PI*radius);
}

