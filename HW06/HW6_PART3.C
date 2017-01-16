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
/*    The code contains the implementations third part of homework VI.      */
/*	  This code develop on for counts the occurrences of a substring in     */
/*    the a given string                                                    */
/*                                                                          */
/*--------------------------------------------------------------------------*/
int count(char*str,char*substr);
int count(char*str,char*substr)
{

	int i,j,temp,substrLength,strLength,timesSubs=0,count=0;

	for (substrLength = 0 ; substr[substrLength] != '\0' ; substrLength++);
	for ( i = 0; str[i] != '\0' ; i++);
	strLength=i;
	
	if (strLength<substrLength)
	{
		return 0;
	}
	
	for ( i = 0; str[i] != '\0' ; i++)
	{
		
		if (  ( (65<=str[i] && str[i]<=90) || (97<=str[i] && str[i]<=122) )   
		        &&  (str[i]==substr[0]) )
		{
			temp=i;
			for (j= 0; j <substrLength ; j+=2)
			{	
				if(str[i]==substr[j])
				{
					timesSubs++;
				}
				
				i+=2;
			}

			if (substrLength%2==0 && (substrLength/2==timesSubs ) )
			{
				count++;
			}
				
			if (substrLength%2==1 && ( (substrLength+1)/2==timesSubs ) )
			{
				count++;
			}

			timesSubs=0;
			i=temp+1;

			if(i==strLength)
			{i=strLength-1;}	
		}

	}
	
return count;
}