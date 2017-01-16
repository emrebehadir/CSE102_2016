/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW03_141044021_Emre_Behadir                                              */                                                                          
/*                                                                          */
/* main.c                                                                   */
/* ---------                                                                */
/* Created on 5/03/2016 by Emre_Behadir                                     */
/*                                                                          */
/* Description                                                              */
/* -----------                                                              */
/*    The main.c contains the implementations of  homework III.             */
/*    This program checks whether the given number is an odd, a factorial   */
/*    or a narcissistic number.                                             */
/*                                                                          */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*                                 Includes                                 */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* long int oddNumber(long int positiveInteger)                             */
/* -----------                                                              */
/*                                                                          */
/* Description                                                              */
/* -----------                                                              */
/*    This function takes positiveInteger and checks number.                */
/*    If number is odd,it display odd number.If number is not odd,it display*/
/*    not odd number.                                                       */
/*                                                                          */
/*--------------------------------------------------------------------------*/
long int oddNumber(long int positiveInteger);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* long int factorialNumber(long int positiveInteger)                       */
/* -----------                                                              */
/*                                                                          */
/* Description                                                              */
/* -----------                                                              */
/*    This function takes positiveInteger and checks number.If number is    */
/*    factorial number,it display factorial number number .If number is not */
/*    factorial number,it display not factorial number number.              */
/*                                                                          */
/*--------------------------------------------------------------------------*/
long int factorialNumber(long int positiveInteger);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* long int narcissNumber(long int positiveInteger)                         */
/* -----------                                                              */
/*                                                                          */
/* Description                                                              */
/* -----------                                                              */
/*    This function takes positiveInteger and checks number.If number is    */
/*    narcisstic number,it display narcisstic number number .If number is   */
/*    not narcisstic number,it display not narcisstic number number.        */
/*                                                                          */
/*--------------------------------------------------------------------------*/
long int narcissNumber(long int positiveInteger);


int main(void) 
{
    char continueSelect;
    long int ilv,positiveInteger,checkNumber;/*ilv--infinite loop variable*/

    printf("****************************************************\n");
    printf("*                       WELCOME                    *\n");
    printf("*   This program checks whether the given number   *\n");
    printf("* is an odd, a factorial or a narcissistic number  *\n");
    printf("*                                                  *\n");
    printf("****************************************************\n");

    ilv=1;
    while (ilv)
    {
        printf("Please enter a positive integer : ");
        scanf("%ld",&positiveInteger);

        if(positiveInteger>0)
        {
            
            printf("Which property would you like to check?\n");
            printf("1)Odd number\n");
            printf("2)Factorial number\n");
            printf("3)Narcissistic number\n");
            printf("Please enter(1/2/3):  ");
            scanf("%ld",&checkNumber);

                switch (checkNumber)
                {
                    case 1:
                        oddNumber(positiveInteger);
                        break;
                    case 2:
                        factorialNumber(positiveInteger);
                        break;
                    case 3:
                        narcissNumber(positiveInteger);
                        break;
                }
             
        }
        
        else
        {
            printf("The entered number is not positive.\n");
        }
    
        printf("Do you want to continue(y/n)?");
        scanf(" %c", &continueSelect);
            
        switch (continueSelect)
        {
            case 'n':
                printf("Good bye !");
                ilv=0;
                break;
        }
        printf("\n");

    }

    return 0;
}

long int oddNumber(long int positiveInteger)
{
    if((positiveInteger%2) != 0 )
    {
        printf("%ld is a odd number !\n", positiveInteger );
    }
    else
    {
        printf("%ld is not an odd number !\n", positiveInteger );
    }
    return 1;
}

long int factorialNumber(long int positiveInteger)
{
    long int n,factorialNum=1;

    for(n=1; factorialNum < positiveInteger ;n+=1)
    {
        factorialNum = factorialNum*n;
    }

    if( positiveInteger == factorialNum)
    {
        printf("%ld is a factorial number !\n", positiveInteger );
    }
    else
    {
        printf("%ld is not a factorial number !\n", positiveInteger );
    }  
    return (2);
}

long int narcissNumber(long int positiveInteger)
{
    long int dig=0,tempPositiveinteger,sumDigit=0,totalDigit=0,flc;
             /* di--> digit && flc--> for loop counter */   
    
    /* To calculate total digit of positive number */
    tempPositiveinteger=positiveInteger;
    while (tempPositiveinteger)
    { 
        tempPositiveinteger = tempPositiveinteger / 10;
        totalDigit =totalDigit +1;  
    }

    /* To calculate narcissictic number */
    tempPositiveinteger=positiveInteger;
    for (flc = totalDigit; 0<flc ; flc-=1)
    {    
        dig = tempPositiveinteger / ( (long int)(pow(10,flc-1)) );
        tempPositiveinteger=tempPositiveinteger-dig*((long int)(pow(10,flc-1)));
        sumDigit= sumDigit + ((long int)(pow(dig,totalDigit)));
    }
        
    if(sumDigit == positiveInteger)
    {
        printf("%ld is narcissistic number ! \n",positiveInteger);
    }
    else
    {
        printf("%ld is not a narcissistic number ! \n",positiveInteger);   
    }

    return 3;
}