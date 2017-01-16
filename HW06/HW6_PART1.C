/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW06_141044021_Emre_Behadir                                              */
/*                                                                          */
/* main.c                                                                   */
/* ---------                              									*/
/* Created on 02/04/2016 by Emre_Behadir									*/
/*                                                      					*/
/* Description                                          					*/
/* -----------                                          					*/
/*    The code contains the implementations of homework VI.                 */
/*	  This code develop for finding frequency of letters and numbers.       */
/*                                                                          */
/*--------------------------------------------------------------------------*/

void freq(char* str , int * fr );
void freq(char* str , int * fr )
{
	int i;

	for (i = 0; i < 37; ++i)
	{
		fr[i]=0;
	}

	for (i = 0; str[i] != '\0' ; ++i)
	{
		if( str[i]<=90 && str[i]>=65 )
		{
			fr[str[i]%65]++;
		}
		
		if( str[i]>=97 && str[i]<=122 )
		{
			fr[str[i]%97]++;
		}
		
		if( str[i]<=57 && str[i]>=48 )
		{
			fr[(str[i]%48)+26]++;
		}

		if( !( (str[i]>=97 && str[i]<=122) || 
			   (str[i]<=57 && str[i]>=48)  || 
			   (str[i]<=90 && str[i]>=65) )  )
		{
			fr[36]++;
		}
	}
}