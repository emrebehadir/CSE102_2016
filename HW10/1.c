/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW10_141044021_Emre_Behadir                                              */
/*                                                                          */
/* main.c                                                                   */
/* ---------                              									*/
/* Created on 01/05/2016 by Emre_Behadir									*/
/*                                                      					*/
/* Description                                          					*/
/* -----------                                          					*/
/*    The code contains the implementations of homework X.                  */
/*	  This code develop for a simple database management system which reads */
/*	  information about a department in a university such as students, 		*/
/*	  lectures, and professors and outputs a file which includes some 		*/
/*	  summary information.													*/
/*                                                                          */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*                             Includes                                     */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

/*--------------------------------------------------------------------------*/
/*                             typedef                                      */
/*--------------------------------------------------------------------------*/
typedef struct 
{
	int  stId;
	char stName[30];
	char stSurname[30];
}studentType;

typedef struct 
{
	char lecDegree[30];
	int  lecId;
	char lecName[30];
	char lecSurname[30];
}lecturerType;

typedef struct 
{
	int  lectCode;
	char lectName[30];
	int lecId;
}lectureType;

typedef struct 
{
	char shClassName[30];
	char shDay[30];
	int  shTime;
	int  shDuration;
	int  shLectcode;
}sheduleType;

typedef struct 
{
	int  csStId;
	int  cslectCode;
}courseStudentType;

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* void readVariable(studentType* student,lecturerType* lecturer,...)		*/
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes student,lecturer,lecture,shedule and courseStudent*/ 
/*	  call by referance.Then,it fill variable in array of own strcuktypes.  */
/*                                                                          */
/*--------------------------------------------------------------------------*/
void 
readVariable(studentType* student,lecturerType* lecturer,
			lectureType* lecture,sheduleType* shedule,
			courseStudentType* courseStudent);

/*--------------------------------------------------------------------------*/
/*                             Function Prototypes                          */
/*--------------------------------------------------------------------------*/
/*                                                                          */
/* void writeVariable(studentType* student,lecturerType* lecturer,...)		*/
/* -----------                                                              */
/*                                                                          */
/* Description                                          					*/
/* -----------                                          					*/
/*	  This function takes student,lecturer,lecture,shedule and courseStudent*/ 
/*	  call by referance.Then,it write variable in output text file.         */
/*                                                                          */
/*--------------------------------------------------------------------------*/
void 
writeVariable(studentType* student,lecturerType* lecturer,
			  lectureType* lecture,sheduleType* shedule,
			  courseStudentType* courseStudent);

int main()
{
	studentType         student[20];
	lecturerType		lecturer[20];
	lectureType 		lecture[20];
	sheduleType			shedule[20];
	courseStudentType	courseStudent[20];

	readVariable(student,lecturer,lecture,
		         shedule,courseStudent);
	writeVariable(student,lecturer,lecture,
		         shedule,courseStudent);

	return 0;
}

void 
writeVariable(studentType* student,lecturerType* lecturer,
			  lectureType* lecture,sheduleType* shedule,
			  courseStudentType* courseStudent)
{
	FILE* outputFile;		 /*test->noktalı virgül yazdırma kontrolü icin */
	int i,j,k,count=0,test=0;/*count->ders alan ogenci sayısı*/
	outputFile=fopen("output.txt","w");

	fprintf(outputFile, "%s\n","Lecture-Lecturer" );
	/*Tüm ders isimlerini tarar.*/
	for ( i = 0; lecture[i].lectName[0] != '\0'; ++i)
	{
		fprintf(outputFile, "%s ",lecture[i].lectName );
		/*Ders veren hocaın indisni bulur.*/
		for(j = 0; lecture[i].lecId != lecturer[j].lecId; ++j);
		fprintf(outputFile,"%s %s",lecturer[j].lecName,lecturer[j].lecSurname);
		/*Ders alan ogrencilerin sayısını bulur.*/
		for ( k = 0;  courseStudent[k].cslectCode != '\0'; k++)
		{
			if (lecture[i].lectCode==courseStudent[k].cslectCode)
			{
				count++;
			}
		}

		fprintf(outputFile, " %d\n",count);
		count=0;
	}

	fprintf(outputFile, "%s\n","" );
	fprintf(outputFile, "%s\n","Student-Lecture" );
	/*Tüm ogrencileri tarar.*/
	for ( i = 0; student[i].stId != '\0'; ++i)
	{
		fprintf(outputFile,"%d" ,student[i].stId );
		fprintf(outputFile," %s",student[i].stName );
		fprintf(outputFile," %s",student[i].stSurname );
		/*Ders alan ogrencileri tarar.*/
		for ( k = 0;  courseStudent[k].csStId != '\0'; k++)
		{
			/*Ogrencinin kac ders aldıgını sayar.*/
			if (student[i].stId==courseStudent[k].csStId)
			{
				count++;
			}
		}
		/*Count ogrencinin kac ders aldıgını basar. */
		fprintf(outputFile, " %d\n",count);
		count=0;
	}

	fprintf(outputFile,"%s\n","" );
	fprintf(outputFile,"%s\n","Student-Day" );
	/*Tüm ogrencileri tarar.*/
	for ( i = 0; student[i].stId != '\0'; ++i)
	{
		fprintf(outputFile, "%d",student[i].stId );
		fprintf(outputFile," %s",student[i].stName );
		fprintf(outputFile," %s ",student[i].stSurname );
		/*Ogrencinin kac gunu dersi oldugunu bulur.Test degiskeine atar.*/
		for ( k = 0;  courseStudent[k].csStId != '\0'; k++)
		{
			if (student[i].stId==courseStudent[k].csStId)
			{
				for (j = 0; 
					 courseStudent[k].cslectCode != shedule[j].shLectcode;
				     ++j);
				test++;/*Noktalı virgulü basmak icin kullandım.*/
			}
		}
		/*Ogrencinin dersi oldugu günleri yazar.*/
		for ( k = 0;  courseStudent[k].csStId != '\0'; k++)
		{
			if (student[i].stId==courseStudent[k].csStId)
			{
				for (j = 0; 
					 courseStudent[k].cslectCode != shedule[j].shLectcode;
				     ++j);
				fprintf(outputFile,"%s",shedule[j].shDay);

				if (test>1)
				{	
					fprintf(outputFile,"%s","," );
					test--;
				}
			}	
		}
		test=0;
		fprintf(outputFile,"%c",'\n' );
	}

	fclose(outputFile);
	return;
}

void
readVariable(studentType* student,lecturerType* lecturer,
			lectureType* lecture,sheduleType* shedule,
			courseStudentType*	courseStudent)
{
	FILE* inputFile;
	int i,line;
	inputFile=fopen("input.dat","rb");
	
	fread(&line,sizeof(int),1,inputFile);
	
	for (i=0 ; i < line; i++)
	{
		fread((&student[i]),sizeof(studentType),1,inputFile);
	}

	fread(&line,sizeof(int),1,inputFile);
	
	for (i=0 ; i < line; i++)
	{
		fread(&lecturer[i],sizeof(lecturerType),1,inputFile);
	}

	fread(&line,sizeof(int),1,inputFile);
	
	for (i=0 ; i < line; i++)
	{
		fread(&lecture[i],sizeof(lectureType),1,inputFile);
	}

	fread(&line,sizeof(int),1,inputFile);
	
	for (i=0 ; i < line; i++)
	{
		fread(&shedule[i],sizeof(sheduleType),1,inputFile);
	}

	fread(&line,sizeof(int),1,inputFile);
	
	for (i=0 ; i < line; i++)
	{
		fread(&courseStudent[i],sizeof(courseStudentType),1,inputFile);
	}
	
	fclose(inputFile);
	return;
}
