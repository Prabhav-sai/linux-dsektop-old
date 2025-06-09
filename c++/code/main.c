#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"platform.h"

int main(){
    char fn[100],user[100],caption[100],content[100],reply[100];
    int no,no2/*q*/;
    Post* p;
    Comment* c;
    Reply* r;
    bool check;
    // scanf("%d",&q);
    while(1){
        // printf("%d-----------------------------------------------------------\n",q);
        scanf("%s",fn);
        // printf("%s\n",fn);
        if(strcmp(fn,"create_platform")==0){
            // printf("1");
            createPlatform();
        }
        else if(strcmp(fn,"add_post")==0){
            scanf("\n%[^\n]s\n",user);
            // printf("%s user\n",user);
            scanf("\n%[^\n]s\n",caption);
            // printf("%s caption\n",caption);
            addPost(user,caption);
        }
        else if(strcmp(fn,"delete_post")==0){
            scanf("%d",&no);
            check=deletePost(no);
            if(check==false)printf("Post not founded!!\n");
        }
        else if(strcmp(fn,"view_post")==0){
            scanf("%d",&no);
            p=viewPost(no);
            if(p==NULL){
                printf("Post does not exist!!\n");
                continue;
            }
            printf("%s %s\n",p->Username,p->Caption);
        }
        else if(strcmp(fn,"current_post")==0){
            p=currPost();
            if(p==NULL){
                printf("Post does not exist!!\n");
                continue;
            }
            printf("%s %s\n",p->Username,p->Caption);
        }
        else if(strcmp(fn,"previous_post")==0){
            p=previousPost();
            if(p==NULL){
                printf("Post does not exist!!\n");
                continue;
            }
            printf("%s %s\n",p->Username,p->Caption);
        }
        else if(strcmp(fn,"next_post")==0){
            p=nextPost();
            if(p==NULL){
                printf("Post does not exist!!\n");
                continue;
            }
            printf("%s %s\n",p->Username,p->Caption);
        }
        else if(strcmp(fn,"add_comment")==0){
            scanf("\n%[^\n]s",user);
            scanf("\n%[^\n]s",content);
            addComment(user,content);
        }
        else if(strcmp(fn,"view_comments")==0){
            c=viewComments();
            if(c==NULL){
                printf("No comments\n");
                continue;
            }
            while(c!=NULL){
                printf("%s %s\n",c->Username,c->Content);
                r=c->replies;
                while(r!=NULL){
                    printf("%s %s\n",r->Username,r->Content);
                    r=r->next;
                }
                c=c->next;
            }
        }
        else if(strcmp(fn,"delete_comment")==0){
            scanf("%d",&no);
            check = deleteComment(no);
            if(check==false) printf("Comment not found!!\n");
        }
        else if(strcmp(fn,"add_reply")==0){
            scanf("\n%[^\n]s\n",user);
            scanf("\n%[^\n]s\n",reply);
            scanf("%d",&no);
            addReply(user,reply,no);
        }
        else if(strcmp(fn,"delete_reply")==0){
            scanf("%d %d",&no,&no2);
            check = deleteReply(no,no2);
            if(check==false) printf("Reply not found!!\n");
        }
    }
}