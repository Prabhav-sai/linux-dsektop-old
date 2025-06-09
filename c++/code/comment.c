#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"comment.h"

Comment* createComment(char* username,char* content){
    Comment* comment = (Comment*)malloc(sizeof(struct Comment));
    strcpy(comment->Username,username);
    strcpy(comment->Content,content);
    comment->replies=NULL;
    comment->replies_end=NULL;
    comment->next=NULL;
    comment->prev=NULL;
    return comment;
}