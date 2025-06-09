#include<stdio.h>
#include"comment.h"

#ifndef _post_h_
#define _post_h_

typedef struct Post{
    char* Username;
    char* Caption;
    Comment* comments;
    Comment* comments_end;
    struct Post* next;
    struct Post* prev;
    // struct Post* viewnext;
    // struct Post* viewprev;
}Post;

Post* createPost(char* username,char* caption);

#endif