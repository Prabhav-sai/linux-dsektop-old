#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"post.h"

Post* createPost(char* username,char* caption){
    Post* post = (Post*)malloc(sizeof(struct Post));
    strcpy(post->Username,username);
    strcpy(post->Caption,caption);
    post->comments=NULL;
    post->comments_end=NULL;
    post->next=NULL;
    post->prev=NULL;
    return post;
}