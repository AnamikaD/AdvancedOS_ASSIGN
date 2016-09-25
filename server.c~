#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include "dict.h"

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

#define ALPHABET_SIZE (26)

#define CHAR_TO_INDEX(c) ((int)c-(int)'a')

#define FREE(p) \
    free(p);    \
    p = NULL;

typedef struct TrieNode TrieNode;

struct TrieNode
{
	TrieNode *children[ALPHABET_SIZE];
	dict_out *head;
	int isleaf;
}; 

typedef struct Trie Trie;

struct Trie
{
	TrieNode *root;
	int count;
};

Trie *pTrie;

TrieNode *getNode()
{
	TrieNode *pNode= NULL;
	pNode = (TrieNode *)malloc(sizeof(TrieNode));
	if(pNode)
	{
		int i;
		pNode->isleaf=false;
		for(i=0; i<ALPHABET_SIZE; i++)
			pNode->children[i]=NULL;
	}
	return pNode;
}


void *init_1_svc(dict_in *inp, struct svc_req *rqstp)
{
	pTrie=(Trie *)malloc(sizeof(Trie));
	pTrie->root=getNode();
	pTrie->count=0;
}

void *insert_1_svc(dict_in *inp, struct svc_req *rqstp)
{
	char key[100], mean[100];
	strcpy(key, inp->word);
	strcpy(mean, inp->mean);
	int i;
	int length= strlen(key);
	int index;
	pTrie->count++;
	TrieNode *pCrawl= pTrie->root;
	
	for(i=0; i<length; i++)
	{
		index= CHAR_TO_INDEX(key[i]);
		if( pCrawl->children[index] )
        	{
            		pCrawl = pCrawl->children[index];
        	}
        	else
        	{
            		pCrawl->children[index] = getNode();
            		pCrawl = pCrawl->children[index];
        	}
	} 
	pCrawl->isleaf=pTrie->count;
	if(pCrawl->head==NULL)
	{
		pCrawl->head=(dict_out *)malloc(sizeof(dict_out));
		strcpy(pCrawl->head->word, mean);
		pCrawl->head->next=NULL;
	}
	else 
	{
		dict_out *t=pCrawl->head;
		while(t->next!=NULL)
			t=t->next;
		dict_out *curr;
		curr=(dict_out *)malloc(sizeof(dict_out));
		strcpy(curr->word, mean);
		curr->next=NULL;
		t->next= curr;
	}
}

dict_out * search_1_svc(dict_in *inp, struct svc_req *rqstp)
{
	char key[100];
	dict_out *temp;
	strcpy(key, inp->word);
	int i, index;
	int length= strlen(key);
	TrieNode *pCrawl= pTrie->root;
	for(i=0; i<length; i++)
	{
		index = CHAR_TO_INDEX(key[i]);
		if(!pCrawl->children[index])
		{
			temp=NULL;
			return temp;
		}
		
		pCrawl= pCrawl->children[index];
	}
	if(pCrawl!=NULL && pCrawl->isleaf)
		temp=pCrawl->head;
	else 
		temp=NULL;

	return temp;
}

int leafNode(TrieNode *pNode)
{
    return (pNode->isleaf != 0);
}
 
int isFree(TrieNode *pNode)
{
    int i;
    for(i = 0; i < ALPHABET_SIZE; i++)
    {
        if( pNode->children[i] )
            return 0;
    }
 
    return 1;
}

int delete1(TrieNode *pNode, const char *key, int level, int len)
{
   if(pNode)
   {
	if(level==len)
	{
		if(pNode->isleaf)
		{
			pNode->isleaf=0;
			FREE(pNode->head);
			if(isFree(pNode))
				return 1;
			
			return 0;
		}
	}
	else
	{
		int index= CHAR_TO_INDEX(key[level]);
		if(delete1(pNode->children[index], key, level+1, len))
		{
			FREE(pNode->children[index]);
			return (!leafNode(pNode) && isFree(pNode));
		}
	}
  }
return 0;
} 
int ans;
int *delete_1_svc(dict_in *inp, struct svc_req *rqstp)
{
	char key[100];
	strcpy(key, inp->word);
	int len= strlen(key);
	if(delete1(pTrie->root, key, 0, len))
		ans=1;
	else 
		ans=0;
	return (&ans);
}









