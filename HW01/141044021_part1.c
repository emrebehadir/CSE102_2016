/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW01_141044021_Emre_Behadir                                              */                                                                          
/*                                                                          */
/* main.c                                                                   */
/* ---------                              									*/
/* Created on 18/02/2016													*/
/*                                                      					*/
/* Description                                          					*/
/* -----------                                          					*/
/*    The main.c contains the implementations of first part of homework I.  */
/*	  This code develop for computing grade of lesson.					    */
/*                                                                          */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*                                 Includes                                 */
/*--------------------------------------------------------------------------*/
#include <stdio.h>

int main()
{
	/*Defined varibles */ 
 	int midWeight1, midWeight2, midWeight3, /*Midterm weight          */
					  hwWeight1, hwWeight2, /*Homework weight         */
							   finalWeight; /*Final weight            */
 
	double midgrade1, midgrade2, midgrade3, /*Midterm grade           */
				        hwGrade1, hwGrade2, /*Homework grade          */
			       finalExgrade,finalGrade; /*Final and final grade   */

	/*Get the weight variables*/		       
	printf("Please enter the 1. midterm weight:  ");
	scanf("%d", &midWeight1);
	printf("Please enter the 2. midterm weight:  ");
	scanf("%d", &midWeight2);
	printf("Please enter the 3. midterm weight:  ");
	scanf("%d", &midWeight3);
	printf("Please enter the 1. homework weight: ");
	scanf("%d", &hwWeight1);
	printf("Please enter the 2. homework weight: ");
	scanf("%d", &hwWeight2);
	printf("Please enter the final exam weight:  ");
	scanf("%d", &finalWeight);
	
	/*Get the grade variables*/ 
	printf("Please enter the 1. midterm grade:   ");
	scanf("%lf", &midgrade1);
	printf("Please enter the 2. midterm grade:   ");
	scanf("%lf", &midgrade2);
	printf("Please enter the 3. midterm grade:   ");
	scanf("%lf", &midgrade3);
	printf("Please enter the 1. homework grade:  ");
	scanf("%lf", &hwGrade1);
	printf("Please enter the 2. homework grade:  ");
	scanf("%lf", &hwGrade2);
	printf("Please enter the final exam grade:   ");
	scanf("%lf", &finalExgrade);
	 
	 finalGrade = ((midgrade1*midWeight1)+(midgrade2*midWeight2)
	                +(midgrade3*midWeight3)+(hwGrade1*hwWeight1)
	 	  +(hwGrade2*hwWeight2)+(finalExgrade*finalWeight))/100;
	 
	 printf("Your final grade is: %.2f \n" , finalGrade);

	 return (0);

}
/*--------------------------------------------------------------------------*/
/*                               End of main.c                              */
/*--------------------------------------------------------------------------*/
