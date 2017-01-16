/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW07_141044021_Emre_Behadir                                              */
/*                                                                          */
/* main.c                                                                   */
/* ---------                              									*/
/* Created on 10/04/2016 by Emre_Behadir									*/
/*                                                      					*/
/* Description                                          					*/
/* -----------                                          					*/
/*    The main.c contains the implementations first part of homework VI.	*/
/*	  This code develop for simulate goal situation in air hockey table.	*/
/*                                                                          */
/*--------------------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535897932384626

int kickDisc(double wallWidth, double wallHeight, double ballCenterX, 
			 double kickAngle, double ballRadius, double goalWidth);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* void kickSurface(double wallWidth, double wallHeight, .....) 		    */
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes variables.It find update variables.    		    */
/*    Then,it return variables call by referance.							*/
/*                                                                          */
/*--------------------------------------------------------------------------*/
void kickSurface(double wallWidth, double wallHeight, double ballCenterX, 
				double kickAngle, double ballRadius, double goalWidth,
				double* updateballCenterX, double* updatekickAngle,
				double* updateHeigh);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* int isGoaltest(double wallWidth, double ballCenterX, double goalWidth)   */
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes variables.Then,it checks goal situation.          */
/*                                                                          */
/* Returns                                               					*/
/* -----------                                          					*/
/*    Return zero means kick is not goal. 								    */
/*    Return one means kick is goal.        		                    	*/
/*                                                                          */
/*--------------------------------------------------------------------------*/
int isGoaltest(double wallWidth, double ballCenterX, double goalWidth)
{
	if( ( wallWidth- goalWidth)/2 <= ballCenterX &&  
		  ballCenterX <= wallWidth - (wallWidth- goalWidth)/2 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int randNumber(int angle)
{
	srand(angle);

	return rand();
}

int reflection(int angle)
{
	return angle+randNumber(angle)%11-5;
}

int main()
{
	printf("Condition of goal>>%d\n",kickDisc(10, 26 , 2 , 41 , 1 , 2) );	
	return 0;
}


void kickSurface(double wallWidth, double wallHeight, double ballCenterX, 
				 double kickAngle, double ballRadius, double goalWidth,
				 double* updateballCenterX, double* updatekickAngle,
				 double* updateHeigh)
{
	if(kickAngle<90 )
		{
			*updateHeigh= tan(kickAngle*(PI/180))*(wallWidth
													-ballCenterX- ballRadius);
			*updatekickAngle=180-reflection(kickAngle);

			if (*updatekickAngle>175)
			{
				*updatekickAngle=175;
			}
			
			if(*updateHeigh<wallHeight)/*son durumda bi önceki durumu korumak icin*/
			{
				*updateballCenterX= wallWidth - ballRadius;
			}
			
		}

		if(kickAngle>90 )
		{
			kickAngle= 180 - kickAngle;
			
			*updateHeigh= tan(kickAngle*(PI/180))*( ballCenterX- ballRadius);
				*updatekickAngle=reflection(kickAngle);

			if (*updatekickAngle<5)
			{
				*updatekickAngle=5;
			}
			
			if(*updateHeigh<wallHeight)/*son durumda bi önceki durumu korumak icin*/
			{		
				*updateballCenterX= ballRadius;
			}
		
			
		}

}

int kickDisc(double wallWidth, double wallHeight, double ballCenterX, 
			 double kickAngle, double ballRadius, double goalWidth)
{
	

	double updateballCenterX,
		   updatekickAngle,
		   updateHeigh=0;/*wallheigte esitlemelimi esitlememelimi*/

	if ( 0>=goalWidth || 0>=wallWidth || 0>=wallHeight || 0>=ballRadius ||
		 0>=ballCenterX  ||ballRadius>wallWidth || ballRadius>wallHeight ||
		 wallWidth<=2*ballRadius || wallHeight<=2*ballRadius 
	   )
	{
		return 0;
	}


	kickSurface(wallWidth,wallHeight,ballCenterX,kickAngle,ballRadius,
				goalWidth, &updateballCenterX, &updatekickAngle, &updateHeigh);

	if(kickAngle==90 )
	{
		return isGoaltest( wallWidth,  ballCenterX,  goalWidth);
	}

	if(updateHeigh<wallHeight)
	{
		wallHeight= wallHeight - updateHeigh;
		kickAngle=updatekickAngle;
		ballCenterX=updateballCenterX;
	}

	if(updateHeigh>=wallHeight)
	{
		if (kickAngle<90)
		{
			ballCenterX=(wallHeight- ballRadius)/tan(kickAngle*(PI/180)) 
						 									+ ballCenterX;
			
			return isGoaltest( wallWidth,  ballCenterX,  goalWidth);
		}
		if (kickAngle>90)
		{
			kickAngle= 180 - kickAngle;
			
			ballCenterX= ballCenterX -
						 ((wallHeight- ballRadius)/tan(kickAngle*(PI/180)) );
			
			return isGoaltest( wallWidth,  ballCenterX,  goalWidth);
		}

	}
	
	return kickDisc(wallWidth,wallHeight,ballCenterX,
					kickAngle,ballRadius,goalWidth);

}