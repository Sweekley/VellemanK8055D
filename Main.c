/*
============================================================================
 Name        : Main.c
 Project	 : Groupcheck
 Author      : Scott Weekley
 Version     : 0.0A
 Description : Contains the code for ~groupcheck~
============================================================================
* Enceladus Confidential
* 2013 Enceladus Technologies
* All Rights Reserved.
* ___________________________________________________________________
* NOTICE:
* The intellectual and technical concepts contained
* herein are proprietary to Enceladus Technologies.
* Dissemination of this information or reproduction of this material
* is strictly forbidden unless prior written permission is obtained
* from Enceladus Technologies.
*/

//*special thanks from http://tehcakeswineblog.wordpress.com
//TODO: Need a larger game list.
#if !defined(WIN32) || !defined(_WIN32) || !defined(__WIN32)
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#endif

#include "ctype.h"
#include "string.h"
#include "Match.h"
#include "Readfile.h"
#include "Main.h"
#define game_offset 	13		//ofset for gamecount
#define appid_offset 	8
#define MAX_GAMES 		3000	//Games Steam has per wikipedia
//#define debug
#define part2
#define appidfile		"appidlist.txt"
#define MAXCHAR 		256 	//MAX chars to be taken in for now

int main(void){

	/************ File structure **************
	 * File1 && File2 are input files from the user (user xml files)
	 * File3 is an csv output file
	 */
	//TODO: Find a quicker way to read in the APPID's
	char path1con[] = "";
	char path2con[] = "";
	char buff[MAXCHAR -1] = "";
	int status = -1;
	int i =0, max_count = 0,j = 0,search_count,x=0, increment = 0;
    int yours[MAX_GAMES];
    int theres[MAX_GAMES];
    int gameMatch[MAX_GAMES];
    char *tok1 = "";
    char *tok2 = "";
    Gametype gm[3000];

#ifdef part2
#ifdef debug
	printf("------------Groupcheck-----------\n");
	printf("Created by Enceladus Technologies\n");
	printf("This was created to allow you to\n");
	printf("It is suggested that you put this\n");
	printf("in the same folder as the files. To\n");
	printf("be compared.\n");
	printf("\n\n");
#endif
	printf("Enter the path of file 1:\n");
	fflush(stdin);
	scanf("%s",path1con);
	int game_count1 = fileReadUser(path1con, yours);
	if(game_count1 > 0) printf("\nFound: %i\n",game_count1);
	if(game_count1 < 0 ) printf("Error: %i\n",game_count1);
#ifdef debug
	if(game_count1 >0){
		printf("Here's a listing of your games\n");
		for(i = 0;i<=game_count1;i++){
			printf("Your Games: %i\n",yours[i]);
		}
	}
#endif
/**************************Theirs**************************************/
	printf("Enter the path of file 2:\n");
	fflush(stdin);
	scanf("%s",path2con);
	int game_count2 = fileReadUser(path2con, theres);
	if(game_count2 > 0) printf("\nFound: %i\n",game_count2);
	if(game_count2 < 0 ) printf("\nError: %i\n",game_count2);
#ifdef debug
	if(game_count2 >0){
		printf("Here's a listing of their games.\n");
		for(i = 0;i<=game_count1;i++){
			printf("Their Games: %i\n",theres[i]);
		}
	}
#endif
/****************************Matching**********************************/
	if(game_count1 >=game_count2){
		max_count = game_count1;
		search_count = game_count2;
	}
	else if(game_count1 < game_count2){
		max_count = game_count2;
		search_count = game_count1;
	}
	else max_count = game_count1;
	for(i = 0; i<=max_count;i++){
		for(j=0;j<=search_count;j++){
			if(yours[i] == theres[j]){
				gameMatch[x] = yours[i];
				x++;
#ifdef debug
				printf("Matching game found: %i\n",yours[i]);
#endif
			}
		}
	}
	printf("%i Matches found.",(x-1));
	int matchNum = x-1;
	//The best way I know to do this is declare the variable externally
	//for now lets keep it internally
#ifdef debug
	printf("Matching games are as follows:\n");
	for(i = 0;i<x;i++) {
		printf("Game: %i\n",gameMatch[i]);
	}
#endif
#endif
	FILE* appids = NULL;
	appids = fopen(appidfile,"r"); //read only
	if(appids != NULL){
		printf("File found Found.\n");
	}
	else{
		printf("File was not found.\n");
		return -3;
	}
	while(fgets(buff,sizeof(buff),appids) != NULL){
		//start reading the file
#ifdef debug
		printf("File Contains: %s",buff);
#endif
		tok1 = strtok(buff,",");
		tok2 = strtok(NULL, ",");
		gm[increment].id = atoi(tok1);
		gm[increment].gamename = tok2;
//#ifdef debug
		//printf("tok:%s gm[i]:%i\n",tok1,gm[increment].id);
		//printf("tok:%s gm[i]:%s\n",tok2,gm[increment].gamename);
		printf("%i:%s",gm[increment].id,gm[increment].gamename);
//#endif
		increment++;
	}
#ifdef debug
	printf("Games found: %i",increment);
#endif
	printf("Games you have in common: \n");
	for(i = 0; i <=matchNum; i++){
		for(j=0; j<=increment;j++){
			if(gameMatch[i]==gm[j].id){
				printf("Common game found!\n");

#ifdef debug
				//proven that this is in fact correct
				printf("i:%i j:%i\n",i,j);
				printf("Match:%i\n",gameMatch[i]);

#endif
				printf("IDs: %i\n",gm[j].id);
				//printf("game: %i\n",gameMatch[i]);
				//printf("%s \n",gm[j].gamename);
				break;
				if((j==increment) && (gameMatch[i]!=gm[j].id)){
					printf("Match not found");
					break;
				}
			}
		}
	}
	fclose(appids);
	return status;
}
