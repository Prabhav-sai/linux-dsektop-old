#ifndef _platform_h_
#define _platform_h_

#include<stdio.h>
#include<stdbool.h>
#include"post.h"

typedef struct Platform{
    Post* Posts;
    Post* lastViewedPost;
}Platform;

Platform* createPlatform();

bool addPost(char* username,char* caption);

bool deletePost(int n);

Post* viewPost(int n);

Post* currPost();

Post* nextPost();

Post* previousPost();

bool addComment(char* username,char* content);

void removeComment(Comment* c,Post* p);

bool deleteComment(int n);

Comment* viewComments();

bool addReply(char* username,char* content,int n);

bool deleteReply(int n,int m);

#endif