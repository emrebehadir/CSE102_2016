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
/*    The main.c contains the implementations of second part of homework I. */
/*	  This code developed for computing ages of person.  					*/
/*                                                                          */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*                                 Includes                                 */
/*--------------------------------------------------------------------------*/
#include <stdio.h>

int main()
{
	/* Defined varibles */ 
	int yearEarth,monthEarth,dayEarth,         /*Current date               */
		pyearEarth,pmonthEarth,pdayEarth,      /*Person's birthdate         */
	    anPlanetyear,anPlanetmonth,anPlanetday,/*The time of another planet */
	    anPersonage,anPersonmonth,anPersonday, /*Another planet person's age*/
		totalDay;							   /*Person's lived total day   */

	/*Get the current date variables*/
	printf("Please enter the current date.\n");
	printf("Year:");
	scanf("%d", &yearEarth);
	printf("Month:");
	scanf("%d", &monthEarth);
	printf("Day:");
	scanf("%d", &dayEarth);
	
	/*Get the person's birthdate variables*/
	printf("Please enter your birthdate.\n");
	printf("Year:");
	scanf("%d", &pyearEarth);
	printf("Month:");
	scanf("%d", &pmonthEarth);
	printf("Day:");
	scanf("%d", &pdayEarth);

	/*A year assume 360 days ,then added 5 days for each year.*/
	totalDay = ((yearEarth-pyearEarth)*12*30 - (pmonthEarth-1)*30 - pdayEarth) 
	            + ((monthEarth-1)*30 + dayEarth) + (5*(yearEarth-pyearEarth));
	printf("You have lived %d days. \n", totalDay);
	
	/*Get the time of another planet variables*/
	printf("Please enter about the time of another planet:\n");
	printf("How many hours is a day?");
	scanf("%d", &anPlanetday );
	printf("How many day is a month?");
	scanf("%d", &anPlanetmonth );
	printf("How many month is a year?");
	scanf("%d", &anPlanetyear );

	
	anPersonage = (totalDay*24) / (anPlanetyear*anPlanetmonth*anPlanetday);
	
	anPersonmonth = ((totalDay*24) % (anPlanetyear*anPlanetmonth*anPlanetday))
	                                        /(anPlanetmonth*anPlanetday);
	
	anPersonday= (((totalDay*24) % (anPlanetyear*anPlanetmonth*anPlanetday))
		                       %(anPlanetmonth*anPlanetday))/anPlanetday;


	

	printf("If you lived in a planet where a day is %d hours,", anPlanetday);
	printf("a month is %d days", anPlanetmonth);
	printf(" and a year is %d months : ", anPlanetyear);
	printf("you were %d years , ",anPersonage);
	printf("%d months and %d days old.", anPersonmonth,anPersonday);


	return 0;
}
/*--------------------------------------------------------------------------*/
/*                               End of main.c                              */
/*--------------------------------------------------------------------------*/