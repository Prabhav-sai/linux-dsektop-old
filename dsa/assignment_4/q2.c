#include<stdio.h>

void swap(int*a,int*b){
    int temp = *a;
    *a=*b;
    *b=temp;
    return;
}

void heapify(int * heap,int* y,int size,int i,int order){
    int l,r;
    while(((2*i)+1)<=size){
        l=(2*i)+1;
        r=(2*i)+2;
        if(order==1){
            // printf("%d %d %d this\n",i,l,r);
            // printf("hi\n");
            if(r<size){
                if(heap[r]>heap[l]){
                    if(heap[i]<heap[r]){
                        swap(&heap[i],&heap[r]);
                        swap(&y[i],&y[r]);
                        i=r;
                    }
                    else return;
                }
                else{
                    if(heap[i]<heap[l]){
                        swap(&heap[i],&heap[l]);
                        swap(&y[i],&y[l]);
                        i=l;
                    }
                    else return;
                }
            }
            else{
                if(heap[i]<heap[l]){
                    swap(&heap[i],&heap[l]);
                    swap(&y[i],&y[l]);
                    i=l;
                }
                else return;
            }
        }
        else if(order==0){
            if(r<size){
                if(heap[r]<heap[l]){
                    if(heap[i]>heap[r]){
                        swap(&heap[i],&heap[r]);
                        swap(&y[i],&y[r]);
                        i=r;
                    }
                    else return;
                }
                else{
                    if(heap[i]>heap[l]){
                        swap(&heap[i],&heap[l]);
                        swap(&y[i],&y[l]);
                        i=l;
                    }
                    else return;
                }
            }
            else{
                if(heap[i]>heap[l]){
                    swap(&heap[i],&heap[l]);
                    swap(&y[i],&y[l]);
                    i=l;
                }
                else return;
            }
        }
    }
    return;
}

void delete(int* heap,int* y,int* size,int order){
    heap[0]=heap[(*size)-1];
    y[0]=y[(*size)-1];
    *size -= 1;
    heapify(heap,y,*size,0,order);
    return;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int x[n];
    int y[n];

    for(int i =0;i<n;i++){
        scanf("%d",&x[i]);
    }
    int positive=0;

    for(int i =0;i<n;i++){
        scanf("%d",&y[i]);
        if(y[i]>0)positive++;
    }
    int negative = n-positive;

    int x1[positive];
    int y1[positive];
    int x2[negative];
    int y2[negative];
    int a =0,b=0;

    for(int i =0;i<n;i++){
        if(y[i]>0){
            x1[a]=x[i];
            y1[a]=y[i];
            a++;
        }
        else{
            x2[b]=x[i];
            y2[b]=y[i];
            b++;
        }
    }

    for(int i =(positive/2)-1;i>=0;i--){
        heapify(x1,y1,positive,i,0);
    }
    for(int i =((negative)/2)-1;i>=0;i--){
        heapify(x2,y2,negative,i,1);
    }

    // // 1 is max, 0 min 
    // //x is oxygen requirement
    // //y is oxygen change
    
    // for(int i =0;i<positive;i++){
    //     printf("%d %d\n",x1[i],y1[i]);
    // }
    // for(int i =0;i<negative;i++){
    //     printf("%d %d\n",x2[i],y2[i]);
    // }
    int oxygen=k;
    // int size = n;
    int flag=0;
    // int max_requirement=0;
    a = positive;
    for(int i =0;i<a;i++){
        // printf("%d %d",x1[0],oxygen);
        if(x1[0]>oxygen){
            // printf("hi");
            flag =1;
            break;
        }
        else{
            oxygen +=y1[0];
            delete(x1,y1,&positive,0);
        }
    }
    // printf("%d\n",negative);
    b = negative;    
    for(int i =0;i<b;i++){
        // printf("%d hi",oxygen);
        if(x2[0]>oxygen){
            flag =1;
            break;
        }
        else{
            oxygen +=y2[0];
            delete(x2,y2,&negative,1);
            // printf("%d ",oxygen);
        }
    }
    // printf("%d",oxygen);
    if(oxygen<0)flag=1;
    if(flag==0){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    // for(int i =0;i<n;i++){
    //     printf("%d %d\n",x[i],y[i]);
    // }
    return 0;
}