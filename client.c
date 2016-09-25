#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include "dict.h"
#define FREE(p) \
    free(p);    \
    p = NULL;

int main (int argc, char **argv)
 {
  CLIENT *cl;
  dict_in in;
  dict_out *out;
  if(argc!=2)
	{
		printf("Please enter LocalHost");
		exit(1);
	}
  cl = clnt_create (argv[1], DICT_PROG, DICT_VERS, "tcp");
  init_1(&in, cl);
  while(1)
  {
  printf("Enter your Choices:\n");
  printf("1. Insert\n");
  printf("2. Search\n");
  printf("3. Delete\n");
  int x;
  char word[100];
  char mean[100];
  scanf("%d", &x);
  if(x==1)
	{
		cl = clnt_create (argv[1], DICT_PROG, DICT_VERS, "tcp");
		printf("Enter Word\n");
		scanf("%s", word);
		printf("Enter meaning\n");
		scanf("%s", mean);
		strcpy(in.word, word);
		strcpy(in.mean, mean);
		insert_1(&in, cl);
		printf("Inserted Successfully\n");			
	}
   else if(x==2)
	{
		cl = clnt_create (argv[1], DICT_PROG, DICT_VERS, "tcp");
		dict_out *temp;
		temp=(dict_out *)malloc(sizeof(dict_out *));
		printf("Enter the word that you want to search\n");
		scanf("%s", word);
		strcpy(in.word, word);
		strcpy(in.mean, "\0");
		temp= search_1(&in, cl);
		if(temp==NULL)
			printf("Word not found\n");
		else
		{
			while(temp!=NULL)
			{
				printf("%s\n", temp->word);
				temp=temp->next;
			}	
		}	
	}
  else if(x==3)
	{
		cl = clnt_create (argv[1], DICT_PROG, DICT_VERS, "tcp");
		printf("Enter the word that you want to delete\n");
		scanf("%s", word);
		strcpy(in.word, word);
		strcpy(in.mean, "\0");
		int *ans=delete_1(&in, cl);
		if(*ans==0)
			printf("The word not found\n");
		else
			printf("The word is deleted successfully\n");
	}
	printf("Do you want to continue?y/n");
	char ch;
	scanf(" %c", &ch);
	if(ch=='n')
		exit(0);
  }
  
}
