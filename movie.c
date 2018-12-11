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
	
	//동적 메모리 할당 
	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));
	
	//메모리가 할당되지 않으면 error	
	if(mvPtr == NULL)
	{
		printf("ERROR!\n");
		
		return NULL;
	}
	
	//파일의 정보를 구조체에 저장함. 
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
	
	//구조체에 저장된 정보를 출력  
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
	
	return;
}

int mv_printAll(void* obj, void* arg)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	printMv(mvPtr);
	printf("--------------------------------------------------\n");
	
	return 1;   //list_repeatFunc()을 지날 때마다 1씩 더해짐. 
}


int mv_printScore(void* obj, void* arg)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	//(*(float*)arg)는 사용자가 입력한 score 
	if((mvPtr->score) >= (*(float*)arg))
	{
		printMv(mvPtr);
		printf("--------------------------------------------------\n");
	}
	
	else
	{
		return 0;   //조건에 부합하지 않는 영화는 더하기 0  
	}
	
	return 1;   //list_repeatFunc()을 지날 때마다 1씩 더해짐. 
}

int mv_printRunTime(void* obj, void* arg)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	//(*(int*)arg)는 사용자가 입력한 runTime 
	if((mvPtr->runTime) >= (*(int*)arg))
	{
		printMv(mvPtr);
		printf("--------------------------------------------------\n");
	}
	
	else
	{
		return 0;   //조건에 부합하지 않는 영화는 더하기 0
	}
	return 1;   //list_repeatFunc()을 지날 때마다 1씩 더해짐. 
}

int mv_printCountry(void* obj, void* arg)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	//사용자가 입력한 country와 구조체에 저장된 국가들을 비교 
	if(!strcmp(arg, mvPtr->madeIn))
	{
		printMv(mvPtr);
		printf("--------------------------------------------------\n");
	}
	
	else
	{
		return 0;   //조건에 부합하지 않는 영화는 더하기 0
	}
	
	return 1;   //list_repeatFunc()을 지날 때마다 1씩 더해짐. 
}
