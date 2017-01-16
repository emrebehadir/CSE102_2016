/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW04_141044021_Emre_Behadir                                              */
/*                                                                          */
/* main.c                                                                   */
/* ---------                              									*/
/* Created on 02/04/2016 by Emre_Behadir									*/
/*                                                      					*/
/* Description                                          					*/
/* -----------                                          					*/
/*    The code contains the implementations of homework V.                  */
/*	  This code develop for chess game.               					    */
/*                                                                          */
/*--------------------------------------------------------------------------*/

void emptyBuffer();
void initBoard(char* board);

void getPosition(char *col, int *row);  
int isValidCell(char col, int row); 
void printBoard(char *board);
int isPieceMovable(char *board);

int isRookMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);
int isBishopMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);
int isKnightMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);
int isKingMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);
int isQueenMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);
int isPawnMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);

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
int moveVertical(char *board,int sourceRow, int targetRow, char sourceCol);

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
int moveHorizontal(char *board,int sourceCol, int targetCol, char sourceRow);

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
int movePositiveSlope(char *board, int sourceRow, int targetRow, char sourceCol,char targetCol);

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
int moveNegativeSlope(char *board, int sourceCol, int targetCol, char sourceRow,char targetRow);

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

void emptyBuffer()
{
	while ( getchar() != '\n' );
} 

int absulute(int number)
{
	if(number<0)
	{
		number *=-1;
	}
	return number;
}

int isPieceMovable(char *board)
{
	char sourceCol,targetCol; 
	int sourceRow, targetRow;
	char chessPiece;
	
	getPosition(&sourceCol, &sourceRow); 
	getPosition( &targetCol, &targetRow);

 	if(!(isValidCell(sourceCol,sourceRow) && isValidCell(targetCol,targetRow)))
 	{
 		return 0;
 	}

 	chessPiece=board[(absulute(sourceRow-8)*8 +(sourceCol%96))-1];

    if(chessPiece=='r' || chessPiece=='R')
    {
       return isRookMovable(board,  sourceCol, sourceRow, targetCol,targetRow); 
  	}
    else if(chessPiece=='n' || chessPiece=='N')
    {
    	 return isKnightMovable(board, sourceCol, sourceRow, targetCol,  targetRow);
 	}
    else if(chessPiece=='b' || chessPiece=='B')
    {
      	return isBishopMovable(board,  sourceCol, sourceRow, targetCol,targetRow);
    }
    else if(chessPiece=='q' || chessPiece=='Q')
    {
    	return isQueenMovable(board,  sourceCol, sourceRow, targetCol,targetRow);
 	}
    else if(chessPiece=='k' || chessPiece=='K')
    {
    	return isKnightMovable(board,  sourceCol, sourceRow, targetCol,targetRow);
 	}
    else if (chessPiece=='p' || chessPiece=='P') 
    { 
    	return isPawnMovable(board,  sourceCol, sourceRow, targetCol,targetRow);
    }
    else
    {
      return 0;
   	}

	return 1; 
}

int isKnightMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)/* bi kare gitmiyor*/
{
	int i,j,n;
	int upperPiece[]={'P','R','N','B','Q','K'};
	int lowerPiece[]={'p','r','n','b','q','k'};
	char testKnightpiece,targetTestpiece;
	
	i=sourceRow;
	j=sourceCol%96;
	testKnightpiece=board[(absulute((i)-8)*8 +(j))-1];
	targetTestpiece=board[(absulute((targetRow)-8)*8 +(targetCol%96))-1];
	
	if(targetRow-sourceRow ==2 || targetRow-sourceRow == -2)
	{
		if(targetRow>sourceRow)/*yukarı*/
		{	
			for ( ; i < targetRow ; ++i);
			
			if(targetCol%96>sourceCol%96)
				{j++;}
			if(targetCol%96<sourceCol%96)
				{j--;}
		}

		if(targetRow<sourceRow)/*assagi*/
		{	
			for ( ; i > targetRow ; --i);
			
			if(targetCol%96>sourceCol%96)
				{j++;}
			if(targetCol%96<sourceCol%96)
				{j--;}
		}
	}

	if(targetRow-sourceRow ==1 || targetRow-sourceRow == -1)
	{
		if(targetRow>sourceRow)/*yukarı*/
		{	
			i++;

			if(targetCol%96>sourceCol%96)
				{for ( ; j < targetCol%96 ; ++j);}

			if(targetCol%96<sourceCol%96)
				{for ( ; j > targetCol%96 ; --j);}
		}

		if(targetRow<sourceRow)/*assagi*/
		{	
			i--;

			if(targetCol%96>sourceCol%96)
				{for ( ; j < targetCol%96 ; ++j);}

			if(targetCol%96<sourceCol%96)
				{for ( ; j > targetCol%96 ; --j);}
		}
	}
	
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

	return 0;	
}

int isBishopMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)/* bi kare gitmiyor*/
{
	if(sourceCol==targetCol)
	{
		return 0;
	}

	if( (targetRow- sourceRow )/(targetCol- sourceCol) == 1 )
	{
		return movePositiveSlope(board,sourceRow,targetRow,sourceCol,targetCol);
	}

	if( (targetRow- sourceRow )/(targetCol- sourceCol) == -1 )
	{	
		return moveNegativeSlope(board,sourceCol,targetCol,sourceRow,targetRow);
	}

	return 0;
}

int isRookMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)/* bi kare gitmiyor*/
{
	if(sourceCol==targetCol)
	{
		return moveVertical(board,sourceRow,targetRow,sourceCol);
	}

	if(sourceRow==targetRow)
	{
		return  moveHorizontal(board,sourceCol,targetCol,sourceRow);
	}

	return 0;
}

int isPawnMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
	char pawnPiece,targetPiece;
	pawnPiece=board[(absulute(sourceRow-8)*8 +(sourceCol%96))-1];
	targetPiece=board[(absulute(targetRow-8)*8 +(targetCol%96))-1];

	if((sourceRow-targetRow==-1) && (pawnPiece=='P') && sourceCol==targetCol )
	{
		return  moveVertical(board,sourceRow,targetRow,sourceCol);
	}

	if((sourceRow-targetRow==1) && (pawnPiece=='p') && sourceCol==targetCol )
	{	
		return  moveVertical(board,sourceRow,targetRow,sourceCol);
	}

	if((sourceRow-targetRow==1) && (pawnPiece=='p') && 
	   (targetPiece=='P'||targetPiece=='R'||targetPiece=='N'||
	   	targetPiece=='B'||targetPiece=='Q'||targetPiece=='K'   ) )
	{	
		if(  (targetRow- sourceRow )/(targetCol- sourceCol) == 1 )
		{
			return movePositiveSlope(board,sourceRow,targetRow,sourceCol,targetCol);
		}
		
		if(  (targetRow- sourceRow )/(targetCol- sourceCol) == -1 )
		{
			return moveNegativeSlope(board,sourceCol,targetCol,sourceRow,targetRow);
		}
	}

	if((sourceRow-targetRow==-1) && (pawnPiece=='P') && 
	   (targetPiece=='p'||targetPiece=='r'||targetPiece=='n'||
	   	targetPiece=='b'||targetPiece=='q'||targetPiece=='k'  ) )
	{	
		if(  (targetRow- sourceRow )/(targetCol- sourceCol) == 1 )
		{
			return movePositiveSlope(board,sourceRow,targetRow,sourceCol,targetCol);
		}
		
		if(  (targetRow- sourceRow )/(targetCol- sourceCol) == -1 )
		{
			return moveNegativeSlope(board,sourceCol,targetCol,sourceRow,targetRow);
		}
	}

	return 0;
}

int isKingMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
	if((sourceRow-targetRow==-1 || sourceRow-targetRow==1 ) && sourceCol==targetCol )
	{
		return  moveVertical(board,sourceRow,  targetRow, sourceCol);
	}

	if(((sourceCol-targetCol)%96 ==-1 || (sourceCol-targetCol)%96==1 ) && sourceRow==targetRow )
	{
		return  moveHorizontal(board,sourceCol,targetCol,sourceRow);
	}

	if( ( (targetRow- sourceRow )/(targetCol- sourceCol) == 1 ) && 
		  (sourceRow-targetRow==-1 || sourceRow-targetRow==1 ) && 
		  ((sourceCol-targetCol)%96 ==-1 || (sourceCol-targetCol)%96==1 ) )
	{
		return movePositiveSlope(board,sourceRow,targetRow,sourceCol,targetCol);
	}

	if( ( (targetRow- sourceRow )/(targetCol- sourceCol) == -1 ) && 
		  (sourceRow-targetRow==-1 || sourceRow-targetRow==1 ) && 
		 ((sourceCol-targetCol)%96 ==-1 || (sourceCol-targetCol)%96==1 )  )
	{	
		return moveNegativeSlope(board,sourceCol,targetCol,sourceRow,targetRow);
	}

	return 0;
}

int isQueenMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
	if(sourceCol==targetCol)
	{
		return moveVertical(board,sourceRow,targetRow,sourceCol);
	}

	if(sourceRow==targetRow)
	{
		return  moveHorizontal(board,sourceCol,targetCol,sourceRow);
	}

	if(sourceCol==targetCol)
	{
		return 0;
	}

	if( (targetRow- sourceRow )/(targetCol- sourceCol) == 1 )
	{
		return movePositiveSlope(board,sourceRow,targetRow,sourceCol,targetCol);
	}

	if( (targetRow- sourceRow )/(targetCol- sourceCol) == -1 )
	{	
		return moveNegativeSlope(board,sourceCol,targetCol,sourceRow,targetRow);
	}

	return 0;
}

int movePositiveSlope(char *board, int sourceRow, int targetRow, char sourceCol,char targetCol)
{
	int i,j,n;
	char chessPiece,sourcePiece;
	int upperPiece[]={'P','R','N','B','Q','K'};
	int lowerPiece[]={'p','r','n','b','q','k'};

	sourcePiece=board[(absulute(sourceRow-8)*8 +(sourceCol%96))-1];

	if(sourceRow<targetRow)/* sag yukari*/
	{		
		i = sourceRow +1;
		j = (sourceCol%96)+1 ;

		chessPiece=board[(absulute((i)-8)*8 +(j))-1]; 

		while( (chessPiece==' ') && (i < targetRow ) && (j < targetCol%96)  )
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
		
		if( (j==targetCol%96) && (i==targetRow) )
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

	else if(sourceRow>targetRow)/* sol assagi*/
	{		
		i = sourceRow -1;
		j = (sourceCol%96)-1 ;

		chessPiece=board[(absulute((i)-8)*8 +(j))-1]; 

		while( (chessPiece==' ') && (i > targetRow ) && (j > targetCol%96)  )
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
		
		if( (j==targetCol%96) && (i==targetRow) )
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

int moveNegativeSlope(char *board, int sourceCol, int targetCol, char sourceRow ,char targetRow)
{
	int i,j,n;
	char chessPiece,sourcePiece;
	int upperPiece[]={'P','R','N','B','Q','K'};
	int lowerPiece[]={'p','r','n','b','q','k'};

	sourcePiece=board[(absulute(sourceRow-8)*8 +(sourceCol%96))-1];

	if(sourceRow<targetRow)/* sol yukari*/
	{		
		i = sourceRow +1;
		j = (sourceCol%96)-1 ;

		chessPiece=board[(absulute((i)-8)*8 +(j))-1]; 
		
		while( (chessPiece==' ') && (i < targetRow ) && (j > targetCol%96)  )
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
		
		if( (j==targetCol%96) && (i==targetRow) )
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
	else if(sourceRow>targetRow)/* sag assagi*/
	{		
		i = sourceRow -1;
		j = (sourceCol%96)+1 ;

		chessPiece=board[(absulute((i)-8)*8 +(j))-1]; 

		while( (chessPiece==' ') && (i > targetRow ) && (j < targetCol%96)  )
		{
			chessPiece=board[(absulute(i-8)*8 +(j))-1];
			
			if(chessPiece=='q' || chessPiece=='k'|| chessPiece=='b'|| chessPiece=='n'|| chessPiece=='r' || chessPiece=='P' || chessPiece=='Q' || chessPiece=='K'|| chessPiece=='B'|| chessPiece=='N'|| chessPiece=='R' || chessPiece=='p' )
	        {  return 0;}
		
			i--;
			j++;
		}
		
		if( (j==targetCol%96) && (i==targetRow) )
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

int moveHorizontal(char *board,int sourceCol, int targetCol, char sourceRow)
{
	int i,n;
	char chessPiece,sourcePiece;
	int upperPiece[]={'P','R','N','B','Q','K'};
	int lowerPiece[]={'p','r','n','b','q','k'};

	sourcePiece=board[(absulute(sourceRow-8)*8 +(sourceCol%96))-1];

	if(sourceCol<targetCol)/* sag*/
	{
		i = (sourceCol%96)+1 ; 

		chessPiece=board[(absulute((sourceRow)-8)*8 +(i))-1]; 

		while( (chessPiece==' ') && (i < targetCol%96) )
		{
			chessPiece=board[(absulute(sourceRow-8)*8 +(i))-1];
			
			if(chessPiece=='q' || chessPiece=='k'|| chessPiece=='b'|| 
			   chessPiece=='n'|| chessPiece=='r' || chessPiece=='P' || 
			   chessPiece=='Q' || chessPiece=='K'|| chessPiece=='B'|| 
			   chessPiece=='N'|| chessPiece=='R' || chessPiece=='p' )
	        { return 0;}

			i++;	
		}

		if( (i==targetCol%96) )
		{
			chessPiece=board[(absulute(sourceRow-8)*8 +(i))-1];
				
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

	else if(sourceCol>targetCol)/* sol*/
	{		
		i = (sourceCol%96)-1 ; 

		chessPiece=board[(absulute((sourceRow)-8)*8 +(i))-1]; 
			
		while( (chessPiece==' ') && (i > targetCol%96) )
		{
			chessPiece=board[(absulute(sourceRow-8)*8 +(i))-1];
			
			if(chessPiece=='q' || chessPiece=='k'|| chessPiece=='b'|| 
			   chessPiece=='n'|| chessPiece=='r' || chessPiece=='P' || 
			   chessPiece=='Q' || chessPiece=='K'|| chessPiece=='B'|| 
			   chessPiece=='N'|| chessPiece=='R' || chessPiece=='p'   )
	        { return 0;}
	    
			i--;	
		}

		if( (i==targetCol%96) )
		{
			chessPiece=board[(absulute(sourceRow-8)*8 +(i))-1];
			
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

int moveVertical(char *board,int sourceRow, int targetRow, char sourceCol)
{
	int j,n;
	char chessPiece,sourcePiece;
	int upperPiece[]={'P','R','N','B','Q','K'};
	int lowerPiece[]={'p','r','n','b','q','k'};

	sourcePiece=board[(absulute(sourceRow-8)*8 +(sourceCol%96))-1];
	
	if(sourceRow<targetRow)/* yukarı*/
	{
		j = sourceRow+1 ; 
		chessPiece=board[(absulute((j)-8)*8 +(sourceCol%96))-1]; 

		while( (chessPiece==' ') && (j < targetRow) )
		{
			chessPiece=board[(absulute(j-8)*8 +(sourceCol%96))-1];
			
			if(chessPiece=='q' || chessPiece=='k'|| chessPiece=='b'|| 
			   chessPiece=='n'|| chessPiece=='r' || chessPiece=='P' || 
			   chessPiece=='Q' || chessPiece=='K'|| chessPiece=='B'|| 
			   chessPiece=='N'|| chessPiece=='R' || chessPiece=='p'   )
	        { return 0;}

			j++;
		}

		if( (j==targetRow) )
		{
			chessPiece=board[(absulute(j-8)*8 +(sourceCol%96))-1];
			
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
	
	else if(sourceRow>targetRow) /* assagi*/
	{
		j = sourceRow-1 ; 
		chessPiece=board[(absulute((sourceRow-1)-8)*8 +(sourceCol%96))-1]; 

		while( (chessPiece==' ') && (j > targetRow) )
		{
			chessPiece=board[(absulute(j-8)*8 +(sourceCol%96))-1];
			
			if(chessPiece=='q' || chessPiece=='k'|| chessPiece=='b'|| 
			   chessPiece=='n'|| chessPiece=='r' || chessPiece=='P' || 
			   chessPiece=='Q' || chessPiece=='K'|| chessPiece=='B'|| 
			   chessPiece=='N'|| chessPiece=='R' || chessPiece=='p'  )
	        {return 0;}

			j--;
		}

		if( (j==targetRow) )
		{
			chessPiece=board[(absulute(j-8)*8 +(sourceCol%96))-1];

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

void getPosition(char *col, int *row) 
{
	scanf(" %c%d", col,row );
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