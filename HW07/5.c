#include <stdio.h>



int isPalindrome(char * str);


int main()
{
	
	char s[7]="ab2 a ";


	 printf(">>%d\n",	 isPalindrome(s) );
	return 0;
}

int isPalindrome(char * str)
{

	int i,bottomIndex,topIndex;
	for ( i = 0; str[i]!='\0'; ++i);
		printf("%d\n",i );
	bottomIndex=0;
	topIndex=i-1;

	if(str==NULL  )
	{
		return 0;
	}
	
	if (topIndex==-1 )
	{
		return 1;
	}
	
	if( (topIndex- bottomIndex ==1) && str[bottomIndex]==str[topIndex]  )
	{
		return 1;
	}
	else if( (topIndex- bottomIndex ==1) && str[bottomIndex]==((str[topIndex])%65+97)) 
	{
		return 1;
	}
	else if( (topIndex- bottomIndex ==1) && (str[bottomIndex])%65+97==str[topIndex]  )
	{
		return 1;
	}

	
	for (; !((65<=str[topIndex] && str[topIndex]<=90) || (97<=str[topIndex] && str[topIndex]<=122));topIndex--)
	{
		str[topIndex]='\0';
	}
	for (; !((65<=str[bottomIndex] && str[bottomIndex]<=90) || (97<=str[bottomIndex] && str[bottomIndex]<=122));bottomIndex++)
	{
		str[bottomIndex]='\0';
	}
		
	if(str[bottomIndex]==str[topIndex]  && bottomIndex<=topIndex)
	{
		
		str[topIndex]='\0';	
		return isPalindrome(&str[1]);
	}
	else if((str[bottomIndex]==((str[topIndex])%65+97))&&bottomIndex<=topIndex)
	{
		
		str[topIndex]='\0';	
		return isPalindrome(&str[1]);
	}
	else if(((str[bottomIndex])%65+97)==str[topIndex] && bottomIndex<=topIndex)
	{

		str[topIndex]='\0';
		return isPalindrome(&str[1]);
	}
	else
	{
		return 0;
	}

}

	