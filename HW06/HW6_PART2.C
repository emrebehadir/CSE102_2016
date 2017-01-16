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
/*    The code contains the implementations seceond part of homework VI.    */
/*	  This code develop on for finding substring(s) in a given string.      */
/*                                                                          */
/*--------------------------------------------------------------------------*/

char* matcher(char*haystack,char*needle);

char* matcher(char*haystack,char*needle)
{
	int i,j,lengthNeedle,initializeIndex=0,matchedLetter=0,haystackLength;

	for (lengthNeedle = 0 ; needle[lengthNeedle] != '\0' ; lengthNeedle++);
	for ( i = 0; haystack[i] != '\0' ; i++);
	haystackLength=i;

	if (lengthNeedle>haystackLength)
	{
		return NULL;
	}

	for ( i = 0; haystack[i] != '\0' ; i++)
	{
		if (  ( (65<=haystack[i] && haystack[i]<=90) ||
		        (97<=haystack[i] && haystack[i]<=122) )   
		        &&  (haystack[i]==needle[0]) ) 
		{
			
			initializeIndex=i;
			for ( j=0; j < lengthNeedle; j+=2 )
			{
					if(haystack[i]==needle[j])
					{
						matchedLetter++;
					}

			i+=2;
			}

			if (lengthNeedle%2==0 && (lengthNeedle/2==matchedLetter ) )
			{
				
				return  &haystack[initializeIndex];
			}
			
			if (lengthNeedle%2==1 && ( (lengthNeedle+1)/2==matchedLetter ) )
			{
				
				return &haystack[initializeIndex];
			}
			
			matchedLetter=0;
			i=initializeIndex+lengthNeedle-1;

			if(i==lengthNeedle)
				{i=lengthNeedle-1;}
		}
			
	}
	
return NULL;
}