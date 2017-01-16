/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW09_141044021_Emre_Behadir                                              */
/*                                                                          */
/* main.c                                                                   */
/* ---------                              									*/
/* Created on 27/04/2016 by Emre_Behadir									*/
/*                                                      					*/
/* Description                                          					*/
/* -----------                                          					*/
/*    The code contains the implementations of homework IX.                 */
/*	  This code develop for keeps information about world countries.		*/
/*                                                                          */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*                             Includes                                     */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

/*--------------------------------------------------------------------------*/
/*                             typedef                                      */
/*--------------------------------------------------------------------------*/
typedef struct 
{
	char neigCountry[25];
}neighbor;

typedef struct 
{
	char 	 countryName[25];
	int 	 countryPopulation,
			 countryArea,
		     countryTolalsoldier;
	neighbor numNeighbor[10];	

}countryInformation;


/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* void fillInformation(countryInformation* countries)						*/
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes countries array of types countryInformatin.       */
/*    Then,it fill information in array.	                         		*/
/*                                                                          */
/*--------------------------------------------------------------------------*/
void fillInformation(countryInformation* countries);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* int  																	*/
/* searchIndex(countryInformation*countries,char*lookIncountry,int*countryI)*/
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes countries,lookIncountry and countryIndex variable.*/
/*    Then,it search lookincountry.If it find,return 1.If it does not find  */
/*	  return 0.								                         		*/
/*                                                                          */
/*--------------------------------------------------------------------------*/
int 
searchIndex(countryInformation* countries,char*lookIncountry,int*countryIndex);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* void biggestArmy(countryInformation* countries)						    */
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes countries array of types countryInformatin.       */
/*    Then,it find the biggest army in victincy of neigborhs and print.     */
/*                                                                          */
/*--------------------------------------------------------------------------*/
void biggestArmy(countryInformation* countries);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* void largestCountry(countryInformation* countries)					    */
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes countries array of types countryInformatin.       */
/*    Then,it find the largest county in victincy of neigborhs and print.   */
/*                                                                          */
/*--------------------------------------------------------------------------*/
void largestCountry(countryInformation* countries);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* void minPeople(countryInformation* countries)                            */
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes countries array of types countryInformatin.       */
/*    Then,it calculate minimum people that you can see on travel.          */
/*                                                                          */
/*--------------------------------------------------------------------------*/
void minPeople(countryInformation* countries);


int main()
{
	countryInformation countries[100];
	int numCont=0;/*number country*/
	char choise;

	scanf("%c",&choise);
	while(choise!='e')
	{
		switch(choise)
		{
			case 'a':
				fillInformation(&countries[numCont]);
				numCont++;
				break;

			case 'b':
				biggestArmy( countries);
				break;
			
			case 'c':
				largestCountry( countries);
				break;

			case 'd':
				minPeople( countries);
				break;
		}
	scanf(" %c",&choise);	
	}

	printf("%c\n",choise );
	return 0;
}

void minPeople(countryInformation* countries)
{
	char sourceCountry[25],targetCountry[25];
	int sc,tc;
	scanf("%s",sourceCountry);
	scanf("%s",targetCountry);

	if (searchIndex(countries,sourceCountry,&sc) &&
		searchIndex(countries,targetCountry,&tc)
		)
	{
	}
	else
	{
		printf("INACCESABLE\n");
	}
}

void largestCountry(countryInformation* countries)
{
	int index=0,
		tempIndex=0,countryIndex,
		largeAreindex,
		i,j;

	char tempCountry[25],largeArea[25];

	scanf("%s",largeArea);

	if (searchIndex(countries,largeArea,&countryIndex))
	{
		strcpy(largeArea,countries[countryIndex].countryName);
		largeAreindex=countryIndex;

		for ( i = 0; 
			  countries[countryIndex].numNeighbor[i].neigCountry[0] != '\0'; 
			  ++i)
		{
			strcpy(tempCountry,
				   countries[countryIndex].numNeighbor[i].neigCountry);
			printf("%d\n",index );
			if (searchIndex(countries,tempCountry,&index))
			{			
				tempIndex=index;/*i mi index mi*/
			
				if (countries[countryIndex].countryArea > 
					countries[largeAreindex].countryArea  )
				{
					largeAreindex=index;
				}  

		  		for (j = 0; 
		  			 countries[tempIndex].numNeighbor[j].neigCountry[0] != '\0'; 
		  			 ++j)
		  		{
		  			strcpy(tempCountry ,
		  				   countries[tempIndex].numNeighbor[j].neigCountry);
		  			if (searchIndex(countries,tempCountry,&index))
		  			{
		  				if (countries[index].countryArea > 
		  					countries[largeAreindex].countryArea  )
						{
							largeAreindex=index;
						} 
		  			}
		  		}  
			}
		}
	printf("<output>%s\n",countries[index].countryName );
	}
	else
	{
		printf("THERE IS NO INFORMATION!!\n");
	}

}

void biggestArmy(countryInformation* countries)
{
	int index=0,
		tempIndex=0,countryIndex,
		biggestArmyindex,
		i,j;

	char tempCountry[25],biggestArmy[25];

	scanf("%s",biggestArmy);

	if (searchIndex(countries,biggestArmy,&countryIndex))
	{
		strcpy(biggestArmy,countries[countryIndex].countryName);
		biggestArmyindex=countryIndex;

		for ( i = 0; 
			  countries[countryIndex].numNeighbor[i].neigCountry[0] != '\0'; 
			  ++i)
		{
			strcpy(tempCountry,
				   countries[countryIndex].numNeighbor[i].neigCountry);
			printf("%d\n",index );
			if (searchIndex(countries,tempCountry,&index))
			{			
				tempIndex=index;/*i mi index mi*/
			
				if (countries[countryIndex].countryTolalsoldier > 
					countries[biggestArmyindex].countryTolalsoldier  )
				{
					biggestArmyindex=index;
				}  

		  		for (j = 0; 
		  			 countries[tempIndex].numNeighbor[j].neigCountry[0] != '\0'; 
		  			 ++j)
		  		{
		  			strcpy(tempCountry,
		  				   countries[tempIndex].numNeighbor[j].neigCountry);
		  			if (searchIndex(countries,tempCountry,&index))
		  			{
		  				if (countries[index].countryTolalsoldier > 
		  					countries[biggestArmyindex].countryTolalsoldier  )
						{
							biggestArmyindex=index;
						} 
		  			}
		  		}  
			}
		}
	printf("<output>%s\n",countries[index].countryName );
	}
	else
	{
		printf("THERE IS NO INFORMATION!!\n");
	}

}

int 
searchIndex(countryInformation* countries,char* lookIncountry,int*countryIndex)
{
	int i=0,found=0;

	while(i<100 && !found)
	{
		if (strcmp(countries[i].countryName,lookIncountry) == 0)
		{
			found=1;
		}
		else
		{
			i++;
		}
	}

	if (found)
	{
		*countryIndex=i;
		return 1;
	}
	else
	{
		return 0;
	}

}

void fillInformation(countryInformation* countries)
{
	int i=0;
	countryInformation newCountry;
	neighbor 		   newNeighbor;

	scanf("%s",newCountry.countryName);
	scanf("%d",&newCountry.countryPopulation);
	scanf("%d",&newCountry.countryArea);
	scanf("%d",&newCountry.countryTolalsoldier);

	while(i<10 &&  
		  strcmp(newNeighbor.neigCountry , "-1") != 0)
	{
		scanf("%s",newNeighbor.neigCountry);
		newCountry.numNeighbor[i]=newNeighbor;
		if (strcmp(newNeighbor.neigCountry , "-1") == 0)
		{
			*(newCountry.numNeighbor[i].neigCountry)='\0';
		}
		i++;	
	}

	*countries=newCountry;
	*(newNeighbor.neigCountry)='\0';
}
