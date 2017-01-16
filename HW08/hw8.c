/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW08_141044021_Emre_Behadir                                              */
/*                                                                          */
/* main.c                                                                   */
/* ---------                              									*/
/* Created on 20/04/2016 by Emre_Behadir									*/
/*                                                      					*/
/* Description                                          					*/
/* -----------                                          					*/
/*    The code contains the implementations of homework IIX.                */
/*	  This code develop for chess game.               					    */
/*                                                                          */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#define BOARD_SIZE 8

int isInCheck(char* board);
int makeMove(char *board, char sc, int sr, char tc, int tr);
int isBlack(char currPlayer);
int isWhite(char currPlayer);
char getPlayer(char* board,char sc,char sr);
void initBoard(char* board);
void getPosition(char *col, int *row);
void printBoard(char *board);
int isValidCell(char col, int row); 

int isPieceMovable(char *board, char sc, int sr, char tc, int tr);
int isRookMovable(char *board, char sc, int sr, char tc, int tr);
int isBishopMovable(char *board, char sc, int sr, char tc, int tr);
int isKnightMovable(char *board, char sc, int sr, char tc, int tr);
int isKingMovable(char *board, char sc, int sr, char tc, int tr);
int isQueenMovable(char *board, char sc, int sr, char tc, int tr);
int isPawnMovable(char *board, char sc, int sr, char tc, int tr);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/*int moveVertical(char *board,int sourceRow, int targetRow, char sourceCol)*/
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes num , border width and border char.               */
/*    Then,it cheks place where is correct.                         		*/
/*                                                                          */
/*--------------------------------------------------------------------------*/
int moveVertical(char *board,int sr, int tr, char sc);
/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/*int moveHorizontal(char *board,int sourceCol,int targetCol,char sourceRow)*/
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes board,sourceCol,targetCol and sourceRow.          */
/*    Then,it cheks place where is correct.                         		*/
/*                                                                          */
/*--------------------------------------------------------------------------*/
int moveHorizontal(char *board,int sc, int tc, char sr);
/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* int movePositiveSlope(char *board, int sourceRow, int targetRow, ....)   */
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes board,sourceRow,targetRow,sourceCol and targetCol.*/
/*    Then,it cheks place where is correct.                         		*/
/*                                                                          */
/*--------------------------------------------------------------------------*/
int movePositiveSlope(char *board, int sr, int tr, char sc,char tc);
/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* int moveNegativelope(char *board, int sourceRow, int targetRow, ....)    */
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes board,sourceRow,targetRow,sourceCol and targetCol.*/
/*    Then,it cheks place where is correct.                         		*/
/*                                                                          */
/*--------------------------------------------------------------------------*/
int moveNegativeSlope(char *board, int sc, int tc, char sr,char tr);


/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* void findKing(int* i,int* j,char*board,int*checkKing)    				*/
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function finds white and black king on board.Then,it change      */
/*    cordinate (i,j) call by refrance.                                     */
/*--------------------------------------------------------------------------*/
void findKing(int* i,int* j,char*board,int*checkKing);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* int absulute(int number);               									*/
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes number.Then,it return absulute number.            */
/*                                                                          */
/*--------------------------------------------------------------------------*/
int absulute(int number);


int absulute(int number)
{
    if(number<0)
    {
        number *=-1;
    }
    return number;
}

char getPlayer(char* board,char sc,char sr)
{
    return board[(absulute(sr-8)*8 +(sc%96))-1];
}

int isBlack(char currPlayer)
{
    if (currPlayer=='p' || currPlayer=='r' || currPlayer=='n' ||
        currPlayer=='q' || currPlayer=='k' || currPlayer=='b'   )
    {
        return 1;
    }
    
    return 0;
}

int isWhite(char currPlayer)
{
    if (currPlayer=='P' || currPlayer=='R' || currPlayer=='N' ||
        currPlayer=='Q' || currPlayer=='K' || currPlayer=='B'   )
    {
        return 1;
    }

    return 0;
}

 void initBoard(char* board)
{
    int i;
    char testarray[]={'r','n','b','q','k','b','n','r',
                      'p','p','p','p','p','p','p','p',
                      ' ',' ',' ',' ',' ',' ',' ',' ',
                      ' ',' ',' ',' ',' ',' ',' ',' ',
                      ' ',' ',' ',' ',' ',' ',' ',' ',
                      ' ',' ',' ',' ',' ',' ',' ',' ',
                      'P','P','P','P','P','P','P','P',
                      'R','N','B','Q','K','B','N','R'};

    for(i=0;i<64;i++)
    {
        board[i]=testarray[i];
    }
} 

void getPosition(char *col, int *row) 
{
    scanf(" %c%d", col,row );
}

void printBoard(char *board)
{
    int i,a;
    a = 0;
    printf("\n");
    printf("  a b c d e f g h \n");
    printf("  - - - - - - - - \n");

    for(i=0;i<=7;i++)
    {
        printf("%d|",8-i );
        for ( ; a < 8*(i+1); a++)
        {
            printf("%c",board[a] );
            if ( a <8*(i+1)-1)
            {
                printf(" ");
            }
        }
        printf("|");
        printf("\n");
    }
    printf("  - - - - - - - - \n");
}

int isValidCell(char col, int row) 
{
    if( ((int)(col) >= (int)('a') && (int)(col) <= (int)('h')) 
                                  && (row>=1 && row<=8 )     )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isInCheck(char* board)
{
    int i=0,j=0,checkKing;
    findKing(&i,&j,board,&checkKing);
    
    if (checkKing)
    {
        for (j = 0; j < 64; ++j)
        {
            if (isPieceMovable(board,((j%8)+97), 8-j/8, ((i%8)+97-1), 8- (i/8)))
            {
                return 1;
            }
        }
    }
    else
    {
        for (j = 0; j < 64; ++j)
        {
            if (isPieceMovable(board,((j%8)+97), 8-j/8, ((i%8)+97-1), 8- (i/8)))
            {
                return 2;
            }
        }
    }

    findKing(&i,&j,board,&checkKing);

    if (checkKing)
    {
        for (j = 0; j < 64; ++j)
        {
            if (isPieceMovable(board,((j%8)+97), 8-j/8, ((i%8)+97-1), 8- (i/8)))
            {
                return 1;
            }
        }
    }
    else
    {
        for (j = 0; j < 64; ++j)
        {
            if (isPieceMovable(board,((j%8)+97), 8-j/8, ((i%8)+97-1), 8- (i/8)))
            {
                return 2;

            }
        }
    }

    return 0;
}

int makeMove(char *board, char sc, int sr, char tc, int tr)
{
   int checkValue;
   char tempTarget,tempSource;

   tempSource=board[(absulute(sr-8)*8 +(sc%96))-1];
   tempTarget=board[(absulute(tr-8)*8 +(tc%96))-1];
    
   if (isPieceMovable(board, sc, sr, tc, tr))
   {
        board[(absulute(tr-8)*8 +(tc%96))-1]=tempSource;
        board[(absulute(sr-8)*8 +(sc%96))-1]=' ';
   }
   else
   {
    return 0;
   }

   checkValue=isInCheck(board);

   if (checkValue==0)
   {
        return 2;
   }

   if ((checkValue==1 && 
           (tempSource=='p'||tempSource=='r'||tempSource=='n'||
           tempSource=='b'||tempSource=='q'||tempSource=='k'  ) ) ||
        (checkValue==2 && 
           (tempSource=='P'||tempSource=='R'||tempSource=='N'||
            tempSource=='B'||tempSource=='Q'||tempSource=='K')   ) ) 
   {
        return 3;
   }

    if ((checkValue==2 && 
           (tempSource=='p'||tempSource=='r'||tempSource=='n'||
           tempSource=='b'||tempSource=='q'||tempSource=='k'  ) ) ||
        (checkValue==1 && 
           (tempSource=='P'||tempSource=='R'||tempSource=='N'||
            tempSource=='B'||tempSource=='Q'||tempSource=='K')   ) ) 
    {
        
        board[(absulute(sr-8)*8 +(sc%96))-1]=tempSource;
        board[(absulute(tr-8)*8 +(tc%96))-1]=tempTarget;

        return 1;
    }

    return 0;
}

void findKing(int* i,int* j,char*board,int*checkKing)
{
    int found=0;    
    for ( ; *i < 64 && !found; *i+=1)
    {
         if(board[*i]=='K')
            {
                *checkKing=1;
                found=1;
            }
            if(board[*i]=='k')
            {
                *checkKing=0;
                found=1;
            }
    }

}

int isPieceMovable(char *board,char sc, int sr, char tc, int tr)
{
    char chessPiece;

    chessPiece=board[(absulute(sr-8)*8 +(sc%96))-1];

    if(chessPiece=='r' || chessPiece=='R')
    {
       return isRookMovable(board,  sc, sr, tc,tr); 
    }
    else if(chessPiece=='n' || chessPiece=='N')
    {
         return isKnightMovable(board, sc, sr, tc,tr);
    }
    else if(chessPiece=='b' || chessPiece=='B')
    {
        return isBishopMovable(board,  sc, sr, tc,tr);
    }
    else if(chessPiece=='q' || chessPiece=='Q')
    {
        return isQueenMovable(board,  sc, sr, tc,tr);
    }
    else if(chessPiece=='k' || chessPiece=='K')
    {
        return isKingMovable(board, sc, sr, tc,tr);
    }
    else if (chessPiece=='p' || chessPiece=='P') 
    { 
        return isPawnMovable(board,  sc, sr, tc,tr);
    }

    return 0;
}

int isKnightMovable(char *board, char sc, int sr, char tc, int tr)
{
    int i,j,n;
    int upperPiece[]={'P','R','N','B','Q','K'};
    int lowerPiece[]={'p','r','n','b','q','k'};
    char testKnightpiece,targetTestpiece;
    
    i=sr;
    j=sc%96;
    testKnightpiece=board[(absulute((i)-8)*8 +(j))-1];
    targetTestpiece=board[(absulute((tr)-8)*8 +(tc%96))-1];
    
    if(tr-sr ==2 || tr-sr == -2)
    {
        if(tr>sr)/*yukarı*/
        {   
            for ( ; i < tr ; ++i);
            
            if(tc%96>sc%96)
                {j++;}
            if(tc%96<sc%96)
                {j--;}
        }

        if(tr<sr)/*assagi*/
        {   
            for ( ; i > tr ; --i);
            
            if(tc%96>sc%96)
                {j++;}
            if(tc%96<sc%96)
                {j--;}
        }
    }

    if(tr-sr ==1 || tr-sr == -1)
    {
        if(tr>sr)/*yukarı*/
        {   
            i++;

            if(tc%96>sc%96)
                {for ( ; j < tc%96 ; ++j);}

            if(tc%96<sc%96)
                {for ( ; j > tc%96 ; --j);}
        }

        if(tr<sr)/*assagi*/
        {   
            i--;

            if(tc%96>sc%96)
                {for ( ; j < tc%96 ; ++j);}

            if(tc%96<sc%96)
                {for ( ; j > tc%96 ; --j);}
        }
    }
    
    if ( j+96==tc && i==tr)
    {    

    if( ((int)(testKnightpiece)) < 90 )/* tas büyük */
    {
        for (n = 0; n < 6; ++n)
        {
            if(upperPiece[n]==targetTestpiece)
                {return 0 ;}
        }
        
        return 1;
    }
    
    if((int)testKnightpiece > 90 )/* tas kücük */
    {
        for (n = 0; n < 6; ++n)
        {
            if(lowerPiece[n]==targetTestpiece)
                {return 0 ;}
        }

        return 1;
    }

    }

    return 0;   
}

int isBishopMovable(char *board, char sc, int sr, char tc, int tr)
{
    if(sc==tc)
    {
        return 0;
    }

    if( (tr- sr )/(tc- sc) == 1 )
    {
        return movePositiveSlope(board,sr,tr,sc,tc);
    }

    if( (tr- sr )/(tc- sc) == -1 )
    {   
        return moveNegativeSlope(board,sc,tc,sr,tr);
    }

    return 0;
}

int isRookMovable(char *board, char sc, int sr, char tc, int tr)
{
    if(sc==tc)
    {
        return moveVertical(board,sr,tr,sc);
    }

    if(sr==tr)
    {
        return  moveHorizontal(board,sc,tc,sr);
    }

    return 0;
}

int isPawnMovable(char *board, char sc, int sr, char tc, int tr)
{
    char pawnPiece,targetPiece;
    pawnPiece=board[(absulute(sr-8)*8 +(sc%96))-1];
    targetPiece=board[(absulute(tr-8)*8 +(tc%96))-1];

    if((sr-tr==-1) && (pawnPiece=='P') && sc==tc && targetPiece==' ' )
    {
        return  moveVertical(board,sr,tr,sc);
    }

    if((sr-tr==1) && (pawnPiece=='p') && sc==tc && targetPiece==' ')
    {   
        return  moveVertical(board,sr,tr,sc);
    }

    if((sc%96-tc%96==1) && (pawnPiece=='p') && 
       (targetPiece=='P'||targetPiece=='R'||targetPiece=='N'||
        targetPiece=='B'||targetPiece=='Q'||targetPiece=='K'   ) )
    {   
        if(  (tr- sr )/(tc- sc) == 1 )
        {
            return movePositiveSlope(board,sr,tr,sc,tc);
        }
        
        if(  (tr- sr )/(tc- sc) == -1 )
        {
            return moveNegativeSlope(board,sc,tc,sr,tr);
        }
    }

    if((sc%96-tc%96==-1) && (pawnPiece=='P') && 
       (targetPiece=='p'||targetPiece=='r'||targetPiece=='n'||
        targetPiece=='b'||targetPiece=='q'||targetPiece=='k'  ) )
    {   
        if(  (tr- sr )/(tc- sc) == 1 )
        {
            return movePositiveSlope(board,sr,tr,sc,tc);
        }
        
        if(  (tr- sr )/(tc- sc) == -1 )
        {
            return moveNegativeSlope(board,sc,tc,sr,tr);
        }
    }

    return 0;
}

int isKingMovable(char *board, char sc, int sr, char tc, int tr)
{
    if (sr==tr && sc==tc )
    {
        return 0;
    }

    if((sr-tr==-1 || sr-tr==1 ) && sc==tc )
    {
        return  moveVertical(board,sr,  tr, sc);
    }

    if(((sc-tc)%96 ==-1 || (sc-tc)%96==1 ) && sr==tr )
    {
        return  moveHorizontal(board,sc,tc,sr);
    }

    if( !(sc==tc) && ( (tr- sr )/(tc- sc) == 1 ) && 
        (sr-tr==-1 || sr-tr==1 ) && 
        ( (sc-tc)%96 ==-1 || (sc-tc)%96==1 ) )
    {
        return movePositiveSlope(board,sr,tr,sc,tc);
    }

    if(  !(sc==tc) && ( (tr- sr )/(tc- sc) == -1 ) && 
          (sr-tr==-1 || sr-tr==1 ) && 
         ((sc-tc)%96 ==-1 || (sc-tc)%96==1 )  )
    {   
        return moveNegativeSlope(board,sc,tc,sr,tr);
    }

    return 0;
}

int isQueenMovable(char *board, char sc, int sr, char tc, int tr)
{
    if(sc==tc)
    {
        return moveVertical(board,sr,tr,sc);
    }

    if(sr==tr)
    {
        return  moveHorizontal(board,sc,tc,sr);
    }

    if(sc==tc)
    {
        return 0;
    }

    if( (tr- sr )/(tc- sc) == 1 )
    {
        return movePositiveSlope(board,sr,tr,sc,tc);
    }

    if( (tr- sr )/(tc- sc) == -1 )
    {   
        return moveNegativeSlope(board,sc,tc,sr,tr);
    }

    return 0;
}

int movePositiveSlope(char *board, int sr, int tr, char sc,char tc)
{
    int i,j,n;
    char chessPiece,sourcePiece;
    int upperPiece[]={'P','R','N','B','Q','K'};
    int lowerPiece[]={'p','r','n','b','q','k'};

    sourcePiece=board[(absulute(sr-8)*8 +(sc%96))-1];

    if(sr<tr)/* sag yukari*/
    {       
        i = sr +1;
        j = (sc%96)+1 ;

        chessPiece=board[(absulute((i)-8)*8 +(j))-1]; 

        while( (chessPiece==' ') && (i < tr ) && (j < tc%96)  )
        {
            chessPiece=board[(absulute(i-8)*8 +(j))-1];
            
            if(chessPiece=='q' || chessPiece=='k'|| chessPiece=='b'|| 
               chessPiece=='n'|| chessPiece=='r' || chessPiece=='P' || 
               chessPiece=='Q' || chessPiece=='K'|| chessPiece=='B'|| 
               chessPiece=='N'|| chessPiece=='R' || chessPiece=='p'    )
            {  return 0;}

            i++;
            j++;
        }
        
        if( (j==tc%96) && (i==tr) )
        {
            chessPiece=board[(absulute(i-8)*8 +(j))-1];
            
            if( ((int)(sourcePiece)) < 90 )/* tas büyük */
            {
            
                for (n = 0; n < 6; ++n)
                {
                    if(upperPiece[n]==chessPiece)
                        { return 0 ;}
                }

                return 1;
            }

            if((int)sourcePiece > 90 )/* tas kücük */
            {
                for (n = 0; n < 6; ++n)
                {
                    if(lowerPiece[n]==chessPiece)
                        {return 0 ;}
                }

                return 1;
            }

        }
        else
        {
            return 0;
        }
    
    }

    else if(sr>tr)/* sol assagi*/
    {       
        i = sr -1;
        j = (sc%96)-1 ;

        chessPiece=board[(absulute((i)-8)*8 +(j))-1]; 

        while( (chessPiece==' ') && (i > tr ) && (j > tc%96)  )
        {
            chessPiece=board[(absulute(i-8)*8 +(j))-1];
            
            if(chessPiece=='q' || chessPiece=='k'|| chessPiece=='b'|| 
               chessPiece=='n'|| chessPiece=='r' || chessPiece=='P' || 
               chessPiece=='Q' || chessPiece=='K'|| chessPiece=='B'|| 
               chessPiece=='N'|| chessPiece=='R' || chessPiece=='p'    )
            { return 0;}

            i--;
            j--;
        }
        
        if( (j==tc%96) && (i==tr) )
        {
            chessPiece=board[(absulute(i-8)*8 +(j))-1];
            
            if( ((int)(sourcePiece)) < 90 )/* tas büyük */
            {
                for (n = 0; n < 6; ++n)
                {
                    if(upperPiece[n]==chessPiece)
                        {return 0 ;}
                }

                return 1;
            }
            
            if((int)sourcePiece > 90 )/* tas kücük */
            {
                for (n = 0; n < 6; ++n)
                {
                    if(lowerPiece[n]==chessPiece)
                        {return 0 ;}
                }

                return 1;
            }
            
        }
        else
        {
            return 0;
        }

    }
    else
    {
        return 0;
    }

    return 0;
}

int moveNegativeSlope(char *board, int sc, int tc, char sr ,char tr)
{
    int i,j,n;
    char chessPiece,sourcePiece;
    int upperPiece[]={'P','R','N','B','Q','K'};
    int lowerPiece[]={'p','r','n','b','q','k'};

    sourcePiece=board[(absulute(sr-8)*8 +(sc%96))-1];

    if(sr<tr)/* sol yukari*/
    {       
        i = sr +1;
        j = (sc%96)-1 ;

        chessPiece=board[(absulute((i)-8)*8 +(j))-1]; 
        
        while( (chessPiece==' ') && (i < tr ) && (j > tc%96)  )
        {
            chessPiece=board[(absulute(i-8)*8 +(j))-1];
            
            if(chessPiece=='q' || chessPiece=='k'|| chessPiece=='b'|| 
               chessPiece=='n'|| chessPiece=='r' || chessPiece=='P' || 
               chessPiece=='Q' || chessPiece=='K'|| chessPiece=='B'|| 
               chessPiece=='N'|| chessPiece=='R' || chessPiece=='p'    )
            { return 0;}
            
            i++;
            j--;    
        }
        
        if( (j==tc%96) && (i==tr) )
        {
            chessPiece=board[(absulute(i-8)*8 +(j))-1];
            
            if( ((int)(sourcePiece)) < 90 )/* tas büyük */
            {
                for (n = 0; n < 6; ++n)
                {
                    if(upperPiece[n]==chessPiece)
                        {return 0 ;}
                }

                return 1;
            }
            
            if((int)sourcePiece > 90 )/* tas kücük */
            {
                for (n = 0; n < 6; ++n)
                {
                    if(lowerPiece[n]==chessPiece)
                        {return 0 ;}
                }

                return 1;
            }
            
        }
        else
        {
            return 0;
        }
    
    }
    else if(sr>tr)/* sag assagi*/
    {       
        i = sr -1;
        j = (sc%96)+1 ;

        chessPiece=board[(absulute((i)-8)*8 +(j))-1]; 

        while( (chessPiece==' ') && (i > tr ) && (j < tc%96)  )
        {
            chessPiece=board[(absulute(i-8)*8 +(j))-1];
            
            if(chessPiece=='q' || chessPiece=='k'|| chessPiece=='b'|| 
               chessPiece=='n'|| chessPiece=='r' || chessPiece=='P' || 
               chessPiece=='Q' || chessPiece=='K'|| chessPiece=='B'|| 
               chessPiece=='N'|| chessPiece=='R' || chessPiece=='p' )
            {  return 0;}
        
            i--;
            j++;
        }
        
        if( (j==tc%96) && (i==tr) )
        {
            
            chessPiece=board[(absulute(i-8)*8 +(j))-1];
            
            if( ((int)(sourcePiece)) < 90 )/* tas büyük */
            {
                for (n = 0; n < 6; ++n)
                {
                    if(upperPiece[n]==chessPiece)
                        {return 0 ;}
                }

                return 1;
            }
            
            if((int)sourcePiece > 90 )/* tas kücük */
            {
                for (n = 0; n < 6; ++n)
                {
                    if(lowerPiece[n]==chessPiece)
                        {return 0 ;}
                }

                return 1;
            }

        }
        else
        {
            return 0;
        }
    
    }
    else
    {
        return 0;
    }

    return 0;
}

int moveHorizontal(char *board,int sc, int tc, char sr)
{
    int i,n;
    char chessPiece,sourcePiece;
    int upperPiece[]={'P','R','N','B','Q','K'};
    int lowerPiece[]={'p','r','n','b','q','k'};

    sourcePiece=board[(absulute(sr-8)*8 +(sc%96))-1];

    if(sc<tc)/* sag*/
    {
        i = (sc%96)+1 ; 

        chessPiece=board[(absulute((sr)-8)*8 +(i))-1]; 

        while( (chessPiece==' ') && (i < tc%96) )
        {
            chessPiece=board[(absulute(sr-8)*8 +(i))-1];
            
            if(chessPiece=='q' || chessPiece=='k'|| chessPiece=='b'|| 
               chessPiece=='n'|| chessPiece=='r' || chessPiece=='P' || 
               chessPiece=='Q' || chessPiece=='K'|| chessPiece=='B'|| 
               chessPiece=='N'|| chessPiece=='R' || chessPiece=='p' )
            { return 0;}

            i++;    
        }

        if( (i==tc%96) )
        {
            chessPiece=board[(absulute(sr-8)*8 +(i))-1];
                
            if( ((int)(sourcePiece)) < 90 )/* tas büyük */
            {
                for (n = 0; n < 6; ++n)
                {
                    if(upperPiece[n]==chessPiece)
                        {return 0 ;}
                }

                return 1;
            }
            
            if((int)sourcePiece > 90 )/* tas kücük */
            {
                for (n = 0; n < 6; ++n)
                {
                    if(lowerPiece[n]==chessPiece)
                        {return 0 ;}
                }

                return 1;
            }

        }
        else
        {
            return 0;
        }
    
    }

    else if(sc>tc)/* sol*/
    {       
        i = (sc%96)-1 ; 

        chessPiece=board[(absulute((sr)-8)*8 +(i))-1]; 
            
        while( (chessPiece==' ') && (i > tc%96) )
        {
            chessPiece=board[(absulute(sr-8)*8 +(i))-1];
            
            if(chessPiece=='q' || chessPiece=='k'|| chessPiece=='b'|| 
               chessPiece=='n'|| chessPiece=='r' || chessPiece=='P' || 
               chessPiece=='Q' || chessPiece=='K'|| chessPiece=='B'|| 
               chessPiece=='N'|| chessPiece=='R' || chessPiece=='p'   )
            { return 0;}
        
            i--;    
        }

        if( (i==tc%96) )
        {
            chessPiece=board[(absulute(sr-8)*8 +(i))-1];
            
            if( ((int)(sourcePiece)) < 90 )/* tas büyük */
            {
                for (n = 0; n < 6; ++n)
                {
                    if(upperPiece[n]==chessPiece)
                        {return 0 ;}
                }

                return 1;
            }
            
            if((int)sourcePiece > 90 )/* tas kücük */
            {
                for (n = 0; n < 6; ++n)
                {
                    if(lowerPiece[n]==chessPiece)
                        {return 0 ;}
                }

                return 1;
            }

        }
        else
        {
            return 0;
        }
    
    }
    else
    {
        return 0;
    }
    
    return 0;
}

int moveVertical(char *board,int sr, int tr, char sc)
{
    int j,n;
    char chessPiece,sourcePiece;
    int upperPiece[]={'P','R','N','B','Q','K'};
    int lowerPiece[]={'p','r','n','b','q','k'};

    sourcePiece=board[(absulute(sr-8)*8 +(sc%96))-1];
    
    if(sr<tr)/* yukarı*/
    {
        j = sr+1 ; 
        chessPiece=board[(absulute((j)-8)*8 +(sc%96))-1]; 

        while( (chessPiece==' ') && (j < tr) )
        {
            chessPiece=board[(absulute(j-8)*8 +(sc%96))-1];
            
            if(chessPiece=='q' || chessPiece=='k'|| chessPiece=='b'|| 
               chessPiece=='n'|| chessPiece=='r' || chessPiece=='P' || 
               chessPiece=='Q' || chessPiece=='K'|| chessPiece=='B'|| 
               chessPiece=='N'|| chessPiece=='R' || chessPiece=='p'   )
            { return 0;}

            j++;
        }

        if( (j==tr) )
        {
            chessPiece=board[(absulute(j-8)*8 +(sc%96))-1];
            
            if( ((int)(sourcePiece)) < 90 )/* tas büyük */
            {
                for (n = 0; n < 6; ++n)
                {
                    if(upperPiece[n]==chessPiece)
                        {return 0 ;}
                }


                return 1;
            }

            if((int)sourcePiece > 90 )/* tas kücük */
            {
                for (n = 0; n < 6; ++n)
                {
                    if(lowerPiece[n]==chessPiece)
                        {return 0 ;}
                }
                

                return 1;
            }

        }
        else
        {
            return 0;
        }
    
    }
    
    else if(sr>tr) /* assagi*/
    {
        j = sr-1 ; 
        chessPiece=board[(absulute((sr-1)-8)*8 +(sc%96))-1]; 

        while( (chessPiece==' ') && (j > tr) )
        {
            chessPiece=board[(absulute(j-8)*8 +(sc%96))-1];
            
            if(chessPiece=='q' || chessPiece=='k'|| chessPiece=='b'|| 
               chessPiece=='n'|| chessPiece=='r' || chessPiece=='P' || 
               chessPiece=='Q' || chessPiece=='K'|| chessPiece=='B'|| 
               chessPiece=='N'|| chessPiece=='R' || chessPiece=='p'  )
            {return 0;}

            j--;
        }

        if( (j==tr) )
        {
            chessPiece=board[(absulute(j-8)*8 +(sc%96))-1];

            if( ((int)(sourcePiece)) < 90 )/* tas büyük */
            {
                for (n = 0; n < 6; ++n)
                {
                    if(upperPiece[n]==chessPiece)
                        {return 0 ;}
                }
                
                return 1;
            }

            if((int)sourcePiece > 90 )/* tas kücük */
            {
                for (n = 0; n < 6; ++n)
                {
                    if(lowerPiece[n]==chessPiece)
                        {return 0 ;}
                }

                return 1;
            }

        }
        else
        {
            return 0;
        }

    }
    else
    {
        return 0;
    }
    return 0;
}