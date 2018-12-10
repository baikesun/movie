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
	
	name = strcpy(name, name);
	score = mvPtr->score;
	runTime = mvPtr->runTime;
	country = mvPtr->madeIn;
	
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
	
	arg = mvPtr;
	
	mvPtr->madeIn;
	mvPtr->name;
	mvPtr->runTime;
	mvPtr->score;
	
	printf("--------------------------------------------------\n");
	printMv(arg);
	printf("--------------------------------------------------\n");
	
	return;
}


int mv_printScore(void* obj, void* arg)
{
	movInfo_t* mvPtr;
	
	while(mvPtr != NULL)
	{
		if(obj >= arg)
		{
			printf("--------------------------------------------------\n");
			printMv(obj);
			printf("--------------------------------------------------\n");
		}
	}
	
	return;
}

int mv_printRunTime(void* obj, void* arg)
{
	movInfo_t* mvPtr;
	
	while(mvPtr != NULL)
	{
		if(obj >= arg)
		{
			printf("--------------------------------------------------\n");
			printMv(obj);
			printf("--------------------------------------------------\n");
		}
	}
	
	return;
}

int mv_printCountry(void* obj, void* arg)
{
	movInfo_t* mvPtr;
		
	while(mvPtr != NULL)
	{
		if(obj == arg)
		{
			printf("--------------------------------------------------\n");
			printMv(obj);
			printf("--------------------------------------------------\n");
		}
	}
	
	return;
}
