#include<stdio.h>

void swap(long long int*a,long long int*b){
    long long int temp = *a;
    *a=*b;
    *b=temp;
    return;
}

void heapify(long long int * heap,long long int* y,long long int size,long long int i){
    long long int l,r;
    while(((2*i)+1)<=size){
        l=(2*i)+1;
        r=(2*i)+2;
            // printf("%d %d %d this\n",i,l,r);
            // printf("hi\n");
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
    return;
}

void delete(long long int* heap,long long int* y,long long int* size){
    heap[0]=heap[(*size)-1];
    y[0]=y[(*size)-1];
    *size -= 1;
    heapify(heap,y,*size,0);
    return;
}

void delete2(long long int * heap,long long int*size){
    heap[0]=heap[(*size)-1];
    *size -= 1;
    long long int l,r;
    long long int i =0;
    while(((2*i)+1)<=(*size)){
        l=(2*i)+1;
        r=(2*i)+2;
            // printf("%d %d %d this\n",i,l,r);
            // printf("hi\n");
        if(r<(*size)){
            if(heap[r]<heap[l]){
                if(heap[i]>heap[r]){
                    swap(&heap[i],&heap[r]);
                    i=r;
                }
                else return;
            }
            else{
                if(heap[i]>heap[l]){
                    swap(&heap[i],&heap[l]);
                    i=l;
                }
                else return;
            }
        }
        else{
            if(heap[i]>heap[l]){
                swap(&heap[i],&heap[l]);
                i=l;
            }
            else return;
        }
    }
    return;

}

void insert(long long int *heap,long long int*size,long long int num){
    heap[*size]=num;
    long long int i = *size;
    *size += 1;
    long long int p;
    while(i>=0){
        p = (i-1)/2;
        if(heap[i]<heap[p]){
            swap(&heap[i],&heap[p]);
            i = p;
        }
        else break;
    }
}

int main(){
    long long int n,k,d,p;
    scanf("%lld %lld %lld %lld",&n,&k,&d,&p);
    long long int x[n];
    long long int y[n];
    for(long long int i =0;i<n;i++){
        scanf("%lld",&x[i]);
    }
    for(long long int i =0;i<n;i++){
        scanf("%lld",&y[i]);
    }
    for(long long int i = (n-1)/2;i>=0;i--){
        heapify(x,y,n,i);
    }
    // for(int i =0;i<n;i++){
    //     printf("%d %d\n",x[i],y[i]);
    // }
    long long int size1=n;
    long long int time[n];
    long long int size2 = 0;
    long long int t =0;
    while(k<d){
        while((size1>0)&&x[0]<=k){
            insert(time,&size2,y[0]);
            delete(x,y,&size1);
        }
        // printf("a %lld a ",size2);
        if(size2==0) break;
        else{
            t +=time[0];
            k += p;
            delete2(time,&size2);
        }
        // for(int i =0;i<size2;i++){
        //     printf("%lld\n",time[i]);
        // }
        // for(int i =0;i<size2;i++){
        //     printf("%lld\n",time[i]);
        // }
    }
    if(k<d){
        printf("-1 %lld",k);
    }
    else{
        printf("%lld",t);
    }

    return 0;
}