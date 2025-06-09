#ifndef _reply_h_
#define _reply_h_

#include<stdio.h>

typedef struct Reply{
    char Username[100];
    char Content[100];
    struct Reply* next;
    struct Reply* prev;    
}Reply;

Reply* createReply(char* username,char* content);

#endif