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
/*	  This code develop for calculating cosine and sine values.             */
/*                                                                          */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* double cosine(int degree, int n)                                         */
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes degree  and n variables.                          */
/*    Then,it calculate cosine.                                             */
/*                                                                          */
/*--------------------------------------------------------------------------*/
double cosine(int degree, int n);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* double sine(int degree, int n)                                           */
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes degree  and n variables.                          */
/*    Then,it calculate cosine.                                             */
/*                                                                          */
/*--------------------------------------------------------------------------*/
double sine(int degree, int n);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* double power(double degree, int n)                                       */
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This is a basic power function.it calculate x power y.                */
/*                                                                          */
/*--------------------------------------------------------------------------*/
double power(double degree, int n);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* double factorial(int n)                                                  */
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/* This is a basic factorial function.it calculate n factorial.             */
/*                                                                          */
/*--------------------------------------------------------------------------*/
double factorial(int n);

double power(double degree, int n)
{
	double result=1;
	int i;
	
	for(i=1;i<=n;i++)
	{
		result*=degree;

	}

	return (result);
}

double factorial(int n)
{
	int result,i;
	
	result=1;
	for(i=n;i>0;i--)
	{
		result*=i;
	}

	return (result);

}

void getInputs(int* degree,int* n, int* exit)
{
    char ex;
    int control;
    
    *exit=0;
    control=scanf("%d", degree);
    
    if( control == 1 )
    {
        scanf("%d",n);
        *exit=0;
    }
    
    else
    {
        scanf("%c",&ex);
        if( ex == 'e' || ex == 'E')
        {
        *exit=1;
        }
    }

	printf("cos(%d) where n is %d = %.4f\n",*degree,*n,cosine(*degree,*n));
	printf("sin(%d) where n is %d = %.4f\n",*degree,*n,sine(*degree, *n));

}

double cosine(int degree, int n)
{
	double PI=3.14,radian,cosine;
	int i;
    
    degree=degree%180;
	radian=(degree*2*PI)/360;
	
	cosine=0;
	for (i=0 ;  i < n ; i++)
	{	
		cosine +=  (power(-1,i)*power(radian,2*i)) / factorial(2*i);
	}
	
	return cosine;
}

double sine(int degree, int n)
{
	double PI=3.14,radian,sine;
	int i;
    
    degree=degree%180;
	radian=(degree*PI)/180;
	
	sine=0;
	for (i=0 ;  i < n ; i++)
	{	
		sine += (power(-1,i)*power(radian,2*i+1)) / (factorial(2*i+1));
	}

	return sine;
}