/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW04_141044021_Emre_Behadir                                              */
/*                                                                          */
/* main.c                                                                   */
/* ---------                              									*/
/* Created on 19/03/2016 by Emre_Behadir									*/
/*                                                      					*/
/* Description                                          					*/
/* -----------                                          					*/
/*    The main.c contains the implementations of homework IV.               */
/*	  This code develop for ASCII art.               					    */
/*                                                                          */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* void getInputs(int* num,int* borderWidth,char* borderChar)               */
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes num , border width and border char.               */
/*    Then,it return variables.           					                */
/*                                                                          */
/*--------------------------------------------------------------------------*/
void getInputs(int* num,int* borderWidth,char* borderChar);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* int printNumber(int num,int borderWidth,char borderChar)                 */
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes num , border width and border char.               */
/*    Then,it print number.                            					    */
/*                                                                          */
/*--------------------------------------------------------------------------*/
int printNumber(int num,int borderWidth,char borderChar);


void getInputs(int* num,int* borderWidth,char* borderChar)
{
	scanf("%d %d %c",num ,borderWidth, borderChar);
	return ;
}

int printNumber(int num,int borderWidth,char borderChar)
{
    int totalWidth,totalHeight;
	int rowNumber,testwidh,number,stopNumber;
	int digitSpace;/* for 7x7 digit*/
	int totalDigit,digit;
	int tempNum; 
	int i,bol;
	
	if(num<0 || num>99999)
	{
		return 0;
	}
	
	else
	{
	    tempNum=num;
	    for (totalDigit=1; tempNum>9 ; totalDigit++)
	    {    
	        tempNum/=10;  
	    }

		totalHeight =7 + 2*borderWidth;
		totalWidth  =7*totalDigit + 2*borderWidth;

		rowNumber=1;
		while(rowNumber<=totalHeight)
		{

			testwidh=1;/* writing border*/
			while(testwidh<=totalWidth)
			{
				if(borderWidth != 0)/* for 0 border width test */
				{
					printf("%c",borderChar);
				}
				

				if( testwidh>=borderWidth && testwidh<=totalWidth-borderWidth && 
					rowNumber>borderWidth && rowNumber<=totalHeight-borderWidth)
				{
				
				stopNumber=1;
				while( stopNumber<=totalDigit )
				{
					number=borderWidth;
					while( number<totalWidth-borderWidth && 
						   number<=totalHeight-borderWidth &&
						   testwidh<totalWidth-borderWidth ) 
					{
					
					    if(rowNumber==borderWidth+1 || 
					       rowNumber==totalHeight-borderWidth )/*1,7 row space*/
						{
							printf(" ");
							number++;
							testwidh++;
						}
						
						else
						{

						for (i = 0; i < totalDigit; ++i)
						{
							/*first two space*/
							for (digitSpace=0; 
							     rowNumber>borderWidth && digitSpace < 2; 
							     digitSpace++ , number++ , testwidh++ )
							{
								printf(" ");
							}

							for ( digitSpace=0; 
								  rowNumber>borderWidth && digitSpace < 3; 
								  digitSpace++ , number++ , testwidh++)
							{	
								tempNum=num;
								

								for(bol=0;bol<totalDigit-1-i;bol++)
								{
									tempNum=tempNum/10;
								}
								digit=tempNum%10;

								if(rowNumber==borderWidth+2)
								{
									if ( !(digit==1 || digit==4))
									{
										printf("%c%c",borderChar,borderChar);
										printf("%c",borderChar);
									}

									if ( digit==1 )
									{
										printf(" %c ",borderChar);
									}

									if ( digit==4 )
									{
										printf("%c %c",borderChar,borderChar);
									}

								digitSpace+=3;
								number+=2;
								testwidh+=2 ;
								}

								if(rowNumber==borderWidth+3)
								{

									if ( digit==4 || digit==8 || 
										 digit==9 || digit==0     )
									{
										printf("%c %c",borderChar,borderChar);
									}

									if ( digit==2 || digit==3 || digit==7)
									{
										printf("  %c",borderChar);	
									}

									if ( digit==5 || digit==6 )
									{
										printf("%c  ",borderChar);	
									}

									if ( digit==1 )
									{
										printf("%c%c ",borderChar,borderChar);	
									}
								
								digitSpace+=3;
								number+=2;
								testwidh+=2 ;
								}
								
								if(rowNumber==borderWidth+4)
								{
									
									if ( !(digit==1 || digit==3 || 
										   digit==7 || digit==0)    ) 
									{
										printf("%c%c",borderChar,borderChar);
										printf("%c",borderChar);	
									}

									if ( digit==1)
									{
										printf(" %c ",borderChar);
									}

									if ( digit==3)
									{
										printf(" %c%c",borderChar,borderChar);
									}

									if ( digit==7)
									{
										printf("  %c",borderChar);
									}

									if ( digit==0)
									{
										printf("%c %c",borderChar,borderChar);
									}
								
								digitSpace+=3;
								number+=2;
								testwidh+=2 ;
								}
								
								if(rowNumber==borderWidth+5)
								{

									if ( digit==3 || digit==4 || digit==5 || 
										 digit==7 || digit==9)
									{
										printf("  %c",borderChar);
									}

									if ( digit==6 || digit==8 || digit==0 )
									{
										printf("%c %c",borderChar,borderChar);
									}

									if ( digit==1)
									{
										printf(" %c ",borderChar);
									}

									if ( digit==2)
									{
										printf("%c  ",borderChar);
									}

								digitSpace+=3;
								number+=2;
								testwidh+=2 ;
								}
								
								if(rowNumber==borderWidth+6)
								{
									
									if ( !(digit==4 || digit==7))
									{
										printf("%c%c",borderChar,borderChar);
										printf("%c",borderChar);
									}

									if ( digit==4 || digit==7 )
									{
										printf("  %c",borderChar);
										digitSpace+=3;
									}

								digitSpace+=3;
								number+=2;
								testwidh+=2 ;
								}
							}

							/*last two space for digit*/
							for( digitSpace=0; 
								 rowNumber>borderWidth && digitSpace < 2; 
								 digitSpace++ , number++ , testwidh++ )
							{
								printf(" "); 
							}

						}/*end of for (i = 0; i < totalDigit; ++i)*/

						}/*end of else*/
			
					}/*end of while( number<totalWidth-borderWidth ..) */

				stopNumber++;
				}/*end of while( stopNumber<=totalDigit )*/
				
				}/*end of if( testwidh>=borderWidth && ..)*/
				
			testwidh++;
			}/*end of while(testwidh<=totalWidth)*/

		printf("\n");
		rowNumber++;
		}

	return 1 ; 
	}

}

