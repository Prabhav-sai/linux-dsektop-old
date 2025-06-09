#include<stdio.h>
#include<stdlib.h>
#include"post.h"

Post* createPost(char* username,char* caption){
    Post* post = (Post*)malloc(sizeof(struct Post));
    post->Username=username;
    post->Caption=caption;
    post->comments=NULL;
    post->next=NULL;
    post->prev=NULL;
    // post->viewnext=NULL;
    // post->viewprev=NULL;
    return post;
}