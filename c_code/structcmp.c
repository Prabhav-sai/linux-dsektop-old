#include<stdio.h>
#include<string.h>
typedef struct Person {
    char name[100];
    int age;
    int rel_status;
}Person;
int find(Person* a,int size,char b[]){
    for(int i=0;i<size;i++){
        int y=strcmp(b,a[i].name);
        if(y==0) return i;
    }
}
int main(){
    Person directory[5] = {
        {"Ivan", 24,  5.4},
        {"Kiri", 22,  4.8},
        {"Jake", 28, 6.2},
        {"Alice", 26, 5.8},
        {"Bob", 30, 5.5}
    };
    int size=5;
    char name[size];
    scanf("%s",name);
    int ans =find(directory,size,name);
    printf("%d",ans);
    return 0;
}