#ifndef _post_h_
#define _post_h_

#include<stdio.h>
#include"comment.h"

typedef struct Post{
    char Username[100];
    char Caption[100];
    Comment* comments;
    Comment* comments_end;
    struct Post* next;
    struct Post* prev;
}Post;

Post* createPost(char* username,char* caption);

#endif