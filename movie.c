#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

//structure definition
typedef struct movInfo {
	char name[100];
	float score;
	int runTime;
	char madeIn[10];
} movInfo_t;

void* mv_genMvInfo(char* name, float score, int runTime, char* country)
{
	movInfo_t* mvPtr;
	
	//allocate memory and set the member variables
	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));
		
	if(mvPtr == NULL)
	{
		printf("ERROR!\n");
		
		return NULL;
	}
	
	strcpy(mvPtr->name, name);
	strcpy(mvPtr->madeIn, country);
	mvPtr->score = score;
	mvPtr->runTime = runTime;
	
	return (void*)mvPtr;
}

void printMv(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);
	printf("running time : %i, score : %f\n\n", mvPtr->runTime, mvPtr->score);
	
	return;
}

int mv_printAll(void* obj, void* arg)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	printMv(mvPtr);
	printf("----------------------------------------------\n");
	
	return;
}


int mv_printScore(void* obj, void* arg)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	if((mvPtr->score) >= (*(float*)arg))
	{
		printf("----------------------------------------------\n");
		printMv(mvPtr);
		printf("----------------------------------------------\n");
	}
	
	return;
}

int mv_printRunTime(void* obj, void* arg)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	if((mvPtr->runTime) >= (*(int*)arg))
	{
		printf("--------------------------------------------------\n");
		printMv(mvPtr);
		printf("--------------------------------------------------\n");
	}
	
	return;
}

int mv_printCountry(void* obj, void* arg)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	if(!strcmp(arg, mvPtr->madeIn))
	{
		printf("--------------------------------------------------\n");
		printMv(mvPtr);
		printf("--------------------------------------------------\n");
	}
	
	return;
}
