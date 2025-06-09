#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void insertion(int* a,int l,int r){
    for(int i =l;i<r-1;i++){
        for(int j = i+1;j<r;j++){
            if(a[i]>a[j]){
                swap(&a[i],&a[j]);
            }
        }
    }
}

void median3(int*a,int*b,int*c){
    if(*a>*b)swap(a,b);
    if(*a>*c)swap(a,c);
    if(*b>*c)swap(b,c);
    return;
}

void quicksort(int * a,int left,int right){
    if(left==right)return;
    // printf(" l%dl ",left);
    // for(int i =left;i<=right;i++){
    //     printf("%d",a[i]);
    // }
    // printf(" ");
    int cutoff = 3;
    int center = (left+right)/2;
    median3(&a[left],&a[center],&a[right]);
    swap(&a[center],&a[right-1]);   
    int pivot = a[right-1];
    int i = left , j = right - 1;
    // printf(" r%dr ",right);
    if(right-left>cutoff){
        // printf("hu");
        while(1){
            while(a[++i]<pivot){};
            while(a[--j]>pivot){};
            // printf("i %d %d j",i,j);
            if(i<j){
                swap(&a[i],&a[j]);
            }
            else{
                break;
            }
        }
        swap(&a[i],&a[right-1]);
        quicksort(a,left,i-1);
        quicksort(a,i+1,right);
    }
    else{
        insertion(a,left,right);
    }
}

int main(){
    // int a[3]={-1,12,1};
    // median3(&a[0],&a[1],&a[2]);
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    // printf("%d %d %d",a[0],a[1],a[2]);
    for(int i =0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}