#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"platform.h"

Platform* a;

Platform* createPlatform(){
    Platform* platform = (Platform*)malloc(sizeof(struct Platform));
    platform->Posts=NULL;
    platform->lastViewedPost=NULL;
    a=platform;
    return platform;
}

bool addPost(char* username,char* caption){
    bool posted;
    Post* p = createPost(username,caption);
    if(a->Posts==NULL){
        a->Posts=p;
        posted = true;
    }
    else{
        p->next=a->Posts;
        a->Posts->prev=p;
        a->Posts=p;
        posted = true;
    }
    return posted;
}
// void addview(Post* post){
//     if(post==NULL) return;
//     if(a->lastViewedPost==NULL){
//         a->lastViewedPost=post;
//         return;
//     }
//     post->viewnext=a->lastViewedPost;
//     a->lastViewedPost->viewprev=post;
//     a->lastViewedPost = post;
//     return;
// }
// void deleteview(Post* post){
//     if(post==NULL) return;
//     if(a->lastViewedPost==post){
//         a->lastViewedPost=a->lastViewedPost->viewnext;
//     }
//     if(post->viewprev!=NULL) post->viewprev->viewnext=post->viewnext;
//     if(post->viewnext!=NULL) post->viewnext->viewprev=post->viewprev;
//     post->viewnext=NULL;
//     post->viewprev=NULL;
//     return;
// }
bool deletePost(int n){
    bool deleted;
    if(n<=0||a->lastViewedPost==NULL){
        deleted = false;
    }
    else{
        Post* p=a->Posts;
        if(n==1)n--;
        else{
            while(--n&&p->next!=NULL){
                p=p->next;
            }
        }
        if(n==0&&p!=NULL){
            Comment* c;
            while(p->comments_end!=NULL){
                c=p->comments_end;
                p->comments_end=p->comments_end->prev;
                removeComment(c,p);
            }
            free(p);
            deleted = true;
        }
        else deleted = false;
    }
    return deleted;
}

Post* viewPost(int n){
    Post* post=NULL;
    Post* view=a->Posts;
    if(view->next==NULL&&n==1){
        post = view;
    }
    while(view->next!=NULL&&--n){
        view=view->next;
    }
    if(n==0){
        post = view;
    }
    a->lastViewedPost=post;
    // deleteview(post);
    // addview(post);
    return post;
}
// each viewed post stays only once in the last viewed doubly linked list,there won't be multiple of the same post in the loop
Post* currPost(){
    // if(a->lastViewedPost==NULL) addview(a->Posts);
    return a->lastViewedPost;
}

Post* nextPost(){
    if(a->lastViewedPost->next==NULL){
        return a->lastViewedPost;
    }
    else{
        // addview(a->lastViewedPost->next);
        a->lastViewedPost=a->lastViewedPost->next;
        return a->lastViewedPost;
    }
}

Post* previousPost(){
    if(a->lastViewedPost->prev==NULL){
        return a->lastViewedPost;
    }
    else{
        // addview(a->lastViewedPost->prev);
        a->lastViewedPost=a->lastViewedPost->prev;
        return a->lastViewedPost;
    }
}

bool addComment(char* username,char* content){
    bool commented;
    if(a->lastViewedPost!=NULL){
        Post* post = a->lastViewedPost;
        Comment* c = createComment(username,content);
        if(post->comments_end==NULL){
            post->comments=c;
            post->comments_end=c;
        }
        else{
            post->comments_end->next=c;
            c->prev=post->comments_end;
            post->comments_end=c;
        }
        commented = true;
    }
    else commented = false;
    return commented;
}

void removeComment(Comment* c,Post* p){
    Reply* temp;
    while(c->replies_end!=NULL){
        temp = c->replies_end;
        c->replies_end=c->replies_end->prev;
        free(temp);
    }
    c->replies=NULL;
    if(c==p->comments){
        p->comments=p->comments->next;
    }
    if(c==p->comments_end){
        p->comments_end=p->comments_end->prev;
    }
    if(c->next!=NULL) c->next->prev=c->prev;
    if(c->prev!=NULL) c->prev->next=c->next;
    free(c);
    return;
}

bool deleteComment(int n){
    bool deleted;
    if(n<=0||a->lastViewedPost==NULL||a->lastViewedPost->comments_end==NULL){
        deleted = false;
    }
    else{
        Post* p = a->lastViewedPost;
        Comment* c = p->comments_end;
        if(n==1)n--;
        else{
            while(--n&&c->prev!=NULL){
                c=c->prev;
            }
        }
        if(n==0&&c!=NULL){
            removeComment(c,p);
            deleted = true;
        }
        else deleted = false;
    }
    return deleted; 
}

Comment* viewComments(){
    return a->lastViewedPost->comments;
}

bool addReply(char* username,char* content,int n){
    bool replied;
    Reply* r = createReply(username,content);
    if(n<=0||a->lastViewedPost==NULL||a->lastViewedPost->comments_end==NULL){
        replied = false;
    }
    else{
        Comment* c = a->lastViewedPost->comments_end;
        if(n==1)n--;
        else{
            while(--n&&c->prev!=NULL){
                c=c->prev;
            }
        }
        if(n==0&&c!=NULL){
            if(c->replies==NULL){
                c->replies=r;
                c->replies_end=r;
            }
            else{
                c->replies_end->next=r;
                r->prev=c->replies_end;
                c->replies_end=r;
            }
            replied = true;
        }
        else replied = false;
    }
    return replied;
}

bool deleteReply(int n,int m){
    bool deleted;
    if(n<=0||m<=0||a->lastViewedPost==NULL||a->lastViewedPost->comments_end==NULL){
        deleted = false;
    }
    else{
        Comment* c = a->lastViewedPost->comments_end;
        if(n==1)n--;
        else{
            while(--n&&c->prev!=NULL){
                c=c->prev;
            }
        }
        if(n==0&&c!=NULL){
            Reply* r = c->replies_end;
            if(m==1)m--;
            else{
                while(--n&&r->prev!=NULL){
                    r=r->prev;
                }
            }
            if(m==0&&r!=NULL){
                if(r==c->replies){
                    c->replies=c->replies->next;
                }
                if(r==c->replies_end){
                    c->replies_end=c->replies_end->prev;
                }
                if(r->prev!=NULL) r->prev->next=r->next;
                if(r->next!=NULL) r->next->prev=r->prev;
                free(r);
                deleted = true;
            }
            else deleted = false;
        }
        else deleted = false;
    }
    return deleted;  
}