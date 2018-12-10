#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp; //FILE pointer for reading movie data 
	char name[200]; //movie name
	char country[10]; //movie country
	int runTime; //movie runtime
	float score; //movie score
	
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	void *list, *mvInfo; //pointers for linked list and a specific structure instance for a movie data
	int (*repFunc)(void* obj, void* arg); //function pointer for using list_repeatFunc() function
	void *arg; //a void pointer for passing argument to repFunc
	int cnt; //integer variable
	
	//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	fp = fopen("movie.dat", "r");
	
	//1.2 list generation (use function list_genList() )
	list = list_genList();
	
	//1.3 read each movie data from the file and add it to the linked list
	while ( /* read name, country, runtime and score*/ 1)
	{	
		//generate a movie info instance(mvInfo) with function mv_genMvInfo()
		fscanf(fp, "%s %s %i %f", movInfo_t->name, movInfo_t->madeIn, movInfo_t->runTime, movInfo_t->score);
		
		
		list_addTail(mvInfo, list);
	}

	//1.4 FILE close
	fclose(fp);
	
	//2. program start
	while(exit_flag == 0)
	{
		//2.1 print menu message and get input option
		printf("-------------------- MENU --------------------\n");
		printf(" 1. Print all the movies.\n");
		printf(" 2. Search for specific country movies.\n");
		printf(" 3. Search for specific runtime movies.\n");
		printf(" 4. Search for specific score movies.\n");
		printf(" 5. Exit.\n");
		printf("----------------------------------------------\n\n");
		
		printf("    Select an option : ");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1: //print all the movies
				printf("\nprinting all the movies in the list.....\n\n\n");
				printf("----------------------------------------\n");
				
				repFunc = mv_printAll;
				arg = NULL;
				
				break;
				
			case 2: //print movies of specific country
				printf("Select a COUNTRY : ");
				scanf("%s", country);
				
				repFunc = mv_printCountry;
				arg = country;
				
				break;
				
			case 3: //print movies with long runtime
				printf("Select a RUNTIME : ");
				scanf("%d", &runTime);
				
				repFunc = mv_printRunTime;
				arg = &runTime;
				
				break;
				
			case 4: //print movies with high score
				printf("Select a SCORE : ");
				scanf("%f", &score);
				
				repFunc = mv_printScore;
				arg = &score;
				
				break;
				
			case 5:
				printf("\n\nBye!\n\n");
				exit_flag = 1;
				
				break;
				
			default:
				printf("wrong command! input again\n");
				
				break;
		}
		
		//2.2 printing operation by function pointer (list_repeatFunc() is called here)
		//2.3 print number of movies
		printf("    Totally %d movies are listed!\n\n", cnt);
	}
	
	return 0;
}
