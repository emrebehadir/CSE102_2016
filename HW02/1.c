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
/*    The main.c contains the implementations of first part of homework II. */
/*	  This code develop for computing grade of lesson.					    */
/*                                                                          */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*                                 Includes                                 */
/*--------------------------------------------------------------------------*/
#include <stdio.h>

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* void calculateLastGrade()                                                */
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes lessons weight and grade for computing grade of   */
/*    lesson.Then,it display final grade.           					    */
/*                                                                          */
/*--------------------------------------------------------------------------*/
void calculateLastGrade();

int main()
{

	calculateLastGrade();
	calculateLastGrade();
	calculateLastGrade();
	
	return (0);
}
/*--------------------------------------------------------------------------*/
/*                               End of main.c                              */
/*--------------------------------------------------------------------------*/

void calculateLastGrade()
{

	/*Defined varibles */ 
 	int 	midWeight1,              /*Midterm weight        */
			hwWeight1,               /*Homework weight       */
			finalWeight;             /*Final weight          */
 
	double  midgrade1,               /*Midterm grade         */
			hwGrade1,                /*Homework grade        */
			finalExgrade,finalGrade; /*Final and final grade */

	/*Get the weight variables*/		       
	printf("Please enter the 1. midterm weight:");
	scanf("%d", &midWeight1);
	printf("Please enter the 1. homework weight:");
	scanf("%d", &hwWeight1);
	printf("Please enter the final exam weight:");
	scanf("%d", &finalWeight);
	
	/*Get the grade variables*/ 
	printf("Please enter the 1. midterm grade:");
	scanf("%lf", &midgrade1);
	printf("Please enter the 1. homework grade:");
	scanf("%lf", &hwGrade1);
	printf("Please enter the final exam grade:");
	scanf("%lf", &finalExgrade);
	 
	 finalGrade = ((midgrade1*midWeight1)+(hwGrade1*hwWeight1)
	 	 +(finalExgrade*finalWeight))/100;
	 
	 printf("Your final grade is: %f \n" , finalGrade);
}