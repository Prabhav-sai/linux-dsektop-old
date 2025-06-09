#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"reply.h"

Reply* createReply(char* username,char* content){
    Reply* reply = (Reply*)malloc(sizeof(struct Reply));
    strcpy(reply->Username,username);
    strcpy(reply->Content,content);
    reply->next=NULL;
    reply->prev=NULL;
    return reply;
}