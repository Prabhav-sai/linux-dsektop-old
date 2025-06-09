#ifndef _comment_h_
#define _comment_h_

#include<stdio.h>
#include"reply.h"

typedef struct Comment{
    char Username[100];
    char Content[100];
    Reply* replies;
    Reply* replies_end;    
    struct Comment* next;
    struct Comment* prev;
}Comment;

Comment* createComment(char* username,char* content);

#endif