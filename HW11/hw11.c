/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW11_141044021_Emre_Behadir                                              */
/*                                                                          */
/* main.c                                                                   */
/* ---------                                                         */
/* Created on 10/05/2016 by Emre_Behadir                          */
/*                                                                   */
/* Description                                                       */
/* -----------                                                       */
/*    Ödev 11 uygulamasını içerir.Verilen bilinmeyen struck tipiyle         */
/*    kriptolanmış binary dosyasını çözümler.                               */
/*                                                                          */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

int hwDecode(const char filename[],int arr_out[]);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* int factorialNumber( int positiveInteger)                            */
/* -----------                                                              */
/*                                                                          */
/* Description                                                       */
/* -----------                                                       */
/*  Fonksiyon positif int sayı alarak sayının faktöriyelini bulur.         */ 
/*                                                                          */
/*--------------------------------------------------------------------------*/
int factorialNumber( int positiveInteger);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* void controlPermutation(int*equationArray,int arrSize, ....)            */
/* -----------                                                              */
/*                                                                          */
/* Description                                                       */
/* -----------                                                       */
/*   Fonksiyon denklem eşitliğinden elde ettiğimiz integer arrayin         */
/*    createPermutation tarafından oluşturulan permütasyonlarını okuyarak   */
/*    doğru sifreyi bulur.                                                  */ 
/*                                                                          */
/*--------------------------------------------------------------------------*/
void controlPermutation(int*equationArray,int arrSize,const char filename[],int arr_out[]);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* void swap(int *x, int *y)                                            */
/* -----------                                                              */
/*                                                                          */
/* Description                                                       */
/* -----------                                                       */
/*   Fonksiyon integer array permutasyonları oluşuturuken yer değişimini   */
/*    yapar.                                                                */ 
/*                                                                          */
/*--------------------------------------------------------------------------*/
void swap(int *x, int *y);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* void createPermuation(int *equationArray ,int index,int arrSize ..)     */
/* -----------                                                              */
/*                                                                          */
/* Description                                                       */
/* -----------                                                       */
/*   Fonksiyon verilen denklem eşitliğinin tüm permutasyonlarını oluşturur.*/ 
/*                                                                          */
/*--------------------------------------------------------------------------*/
void createPermuation(int *equationArray ,int index,int arrSize,const char filename[],int arr_out[]);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* void createEquationArray(int aArr ,int bArr,int cArr,int* equationArray) */
/* -----------                                                              */
/*                                                                          */
/* Description                                                       */
/* -----------                                                       */
/*   Fonksiyon elde edilen katsayılardan int array oluşturur.              */ 
/*    ax + by + cz + dm + en                                              */                       
/*    x >> 1 byte(char) y >> 4 byte(float veya int) z >> 8 byte (double veya*/ 
/*    long long int) Örnegin 29 byte olan bir alan  a*1 + b*4 + c*8 = 29    */
/*    seklinde bi denklemle ifade edilir.Burdan olası bir sonucu            */
/*    değerlendirirsek a=1 b=1 c=3 değerlerinin oluşturduğu integer array   */
/*    >>>[1,4,8,8,8] bu şekildedir.                                         */
/*                                                                          */
/*--------------------------------------------------------------------------*/
void createEquationArray(int aArr ,int bArr,int cArr,int dArr,int eArr,int* equationArray);


int factorialNumber( int positiveInteger)
{
    int n,factorialNum=1;

    for(n=1; n <= positiveInteger ;n+=1)
    {
        factorialNum = factorialNum*n;
    }
  
    return factorialNum;
}

void controlPermutation(int*equationArray,int arrSize,const char filename[],int arr_out[]) 
{
   int i,totaldigit=0,found=0;
   double average=0;
   char c;
   int in;
   float f;
   double d;
   long int l;

   FILE *file;
   /* oluşturlan permutasyon arrayini degerlerini toplar  */
   /* average eşit olup olmadığını kontrol eder.*/
   for (i = 0; equationArray[i] != '\0' && !found; ++i)
   {
      file=fopen(filename,"rb");
      if (equationArray[i] == 1)/* char */
      {
         fread(&c ,sizeof(char),1,file);
         printf("%c ",c );
         average+=c;
         totaldigit++;
      }

      if (equationArray[i] == 40)/* int */
      {
         fread(&in ,sizeof(int),1,file);
         printf("%d ",in );
         average+=in;
         totaldigit++;
      }

      if (equationArray[i] == 41)
      {
         fread(&f ,sizeof(float),1,file);/* float */
         printf("%f ",f );
         average+=f;
         totaldigit++;
      }

      if (equationArray[i] == 80)
      {
         fread(&d ,sizeof(double),1,file);/* double */
         printf("%f ",d );
         average+=d;
         totaldigit++;
      }

      if (equationArray[i] == 81)
      {
         fread(&l ,sizeof( long long int),1,file);/* long long int */
         printf("%ld",l );
         average+=l;
         totaldigit++;
      }

      fread(&d ,sizeof(double),1,file);
      printf("%f ",d );
      if ( (average/totaldigit) == d)
      {
         found=1;
      }


      fclose(file);
   }
   

   if (found)/* bulgunda arr_out denklemini oluşturur.*/
   {
      for ( i = 0; i < totaldigit; ++i)
      {
         if (equationArray[i] == 1)
         {
            arr_out[i]=1;
         }

         if (equationArray[i] == 40)
         {
            arr_out[i]=2;
         }

         if (equationArray[i] == 41)
         {
            arr_out[i]=3;
         }

         if (equationArray[i] == 80)
         {
            arr_out[i]=4;
         }

         if (equationArray[i] == 81)
         {
            arr_out[i]=5;
         }
      }

      for ( i = totaldigit; i < 11; ++i)
      {
         arr_out[i]=-1;
      }     
   }

   /*printf(">>[");
   for (i = 0; arr_out[i] != '\0'; ++i)
   {
      printf("%d ", arr_out[i] );
   }
   printf("]\n");*/

} 

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 

void createPermuation(int *equationArray ,int index,int arrSize,const char filename[],int arr_out[]) 
{ 
  int j;
  if (arrSize == index)
  {
      /* Hocam  fread deki okuma dan dolayı segmentation veriyor.*/
      /* odan control permutation fonsiyonunu yorum satırına aldım.*/
     /*controlPermutation(equationArray,arrSize,filename, arr_out);*/

  }
  else
  {
     for (j = index; j <= arrSize; j++) 
     { 
        swap(equationArray +index,equationArray +j);
        createPermuation(equationArray ,index+1,arrSize,filename, arr_out);
        swap(equationArray +index, equationArray +j);
     }
  }
 
}



void createEquationArray(int aArr ,int bArr,int cArr,int dArr,int eArr,int* equationArray)
{
   int i,index=0;

   /*printf("\n>>>%d %d %d %d %d\n", aArr , bArr, cArr, dArr, eArr);*/
   
   for (i = 0; i < aArr; ++i)
   {
      equationArray[index]=1;
      index++;
   }

   for (i = 0; i < bArr; ++i)
   {
      equationArray[index]=40;
      index++;
   }

   for (i = 0; i < cArr; ++i)
   {
      equationArray[index]=41;
      index++;
   }

   for (i = 0; i < dArr; ++i)
   {
      equationArray[index]=80;
      index++;
   }

   for (i = 0; i < eArr; ++i)
   {
      equationArray[index]=81;
      index++;
   }
   equationArray[index]='\0';
   

}  


int hwDecode(const char filename[],int arr_out[])
{
   FILE *file;
   long length;

   int index=0;
   int aArr[1000];
   int bArr[1000];
   int cArr[1000];
   int dArr[1000];
   int eArr[1000];
   int a,b,c,d,e;/*kastayılar*/

   int *equationArray;
   int arrSize;

   /*Dosya yok ise*/
   if((fopen(filename,"rb"))==NULL)
   {
       return -1;
   }

   file=fopen(filename,"rb");
   fseek(file,0,SEEK_END);
   length=ftell(file);

   fclose(file);

   /* ax + by + cz + dm + en (a,b,c,d,e yi buluyorum)  */
   for ( a=0; a < 11; ++a)
   {
      for ( b=0; b < 11; ++b)
      {
         for ( c=0; c < 11; ++c)
         {
            for ( d=0; d < 11; ++d)
            {
               for ( e=0; e < 11; ++e)
               {
                  if ( a+b+c+d+e<11 && (a*1+(b+c)*4+(d+e)*8)==length/1000-8)
                  {
                     aArr[index]=a;
                     bArr[index]=b;
                     cArr[index]=c;
                     dArr[index]=d;
                     eArr[index]=e;
                     index++;
                  }
               }
            }              
         }  
      }  
   }

   
   /*printf("<<denlem olasıkları>>\n");
   for (a = 0; aArr[a] != '\0'; ++a)
   {
      printf("%d>>%d",a,aArr[a] );
      printf("%d",bArr[a] );
      printf("%d",cArr[a] );
      printf("%d",dArr[a] );
      printf("%d\n",eArr[a] );
   }
   printf("-------------------");*/
   
      

   for (a = 0; aArr[a] != '\0'; ++a)
   {
      
      equationArray= (int*)calloc(aArr[a] +bArr[a] + cArr[a] + dArr[a] + eArr[a] +1 , sizeof(int));
      createEquationArray(aArr[a] , bArr[a],cArr[a],dArr[a],eArr[a],equationArray);
      
      for (arrSize = 0; equationArray[arrSize] != '\0'; ++arrSize);

      createPermuation(equationArray,0,arrSize-1,filename,arr_out);

      free(equationArray); 

   }



   return 0;
}