#include"stdio.h"
#include"matrix.h"
#include<string.h>
#include<stdlib.h>

Matrix* fillmatrix(Matrix* m){
    int r,c;
    scanf("%d %d",&r,&c);
    m = create_matrix(r,c);
    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            scanf("%lld",&m->data[i][j]);
        }
    }
    return m;
}

Matrix* read_matrix_from_file(Matrix* m){
    FILE * fptr;
    char filename[10000];
    scanf("%s",filename);
    fptr = fopen(filename,"r");
    if(fptr==NULL){
        printf("ERROR: INVALID ARGUMENT\n");
        return NULL;
    }
    int r,c;
    fscanf(fptr,"%d %d",&r,&c);
    m = create_matrix(r,c);
    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            fscanf(fptr,"%lld",&m->data[i][j]);
        }
    }
    fclose(fptr);
    return m;
}

int main(){
    int q,code;
    scanf("%d",&q);
    char query[25];
    Matrix* A,*B,*C;
    while(q--){
        scanf("%s",query);
        if(strcmp(query,"history")==0){
            FILE * mx_history;
            mx_history = fopen("mx_history","a");
            fprintf(mx_history,"%s\n",query);
            char read;
            fclose(mx_history);
            mx_history = fopen("mx_history","r");
            while(read!=EOF){
                printf("%c",read);
                read = fgetc(mx_history);
            }
            continue;
        }
        scanf("%d",&code);
        if(strcmp(query,"add_matrix")==0||strcmp(query,"mult_matrix")==0||strcmp(query,"scalar_mult_matrix")==0||strcmp(query,"transpose_matrix")==0||strcmp(query,"determinant")==0){
            if(code==0||code==1){
                FILE * mx_history;
                mx_history = fopen("mx_history","a");
                fprintf(mx_history,"%s %d\n",query,code);
                fclose(mx_history);
            }
        }
        if(code==0){
            if(strcmp(query,"add_matrix")==0){
                A = fillmatrix(A);
                B = fillmatrix(B);
                C = add_matrix(A,B);
                print_matrix(C);
                destroy_matrix(A);
                destroy_matrix(B);
                // destroy_matrix(C);
            }
            if(strcmp(query,"mult_matrix")==0){
                A = fillmatrix(A);
                B = fillmatrix(B);
                C = mult_matrix(A,B);
                print_matrix(C);
                destroy_matrix(A);
                destroy_matrix(B);
                // destroy_matrix(C);
            }
            if(strcmp(query,"scalar_mult_matrix")==0){
                long long int s;
                scanf("%lld",&s);
                A = fillmatrix(A);
                B = scalar_mult_matrix(s,A);
                print_matrix(B);
                destroy_matrix(A);
                // destroy_matrix(B);
            }
            if(strcmp(query,"transpose_matrix")==0){
                A = fillmatrix(A);
                B = transpose_matrix(A);
                print_matrix(B);
                destroy_matrix(A);
                // destroy_matrix(B);
            }
            if(strcmp(query,"determinant")==0){
                A = fillmatrix(A);
                if(A->num_cols!=A->num_rows){
                    printf("ERROR: INVALID ARGUMENT\n");
                    continue;
                }
                printf("%lld",determinant(A));
                destroy_matrix(A);
            }
        }
        if(code==1){
            if(strcmp(query,"add_matrix")==0){
                A = read_matrix_from_file(A);
                if(A==NULL){
                    continue;
                }
                B = read_matrix_from_file(B);
                if(B==NULL){
                    continue;
                }
                C = add_matrix(A,B);
                write_matrix_to_file(C);
                destroy_matrix(A);
                destroy_matrix(B);
                // destroy_matrix(C);
            }
            if(strcmp(query,"mult_matrix")==0){
                A = read_matrix_from_file(A);
                if(A==NULL){
                    continue;
                }
                B = read_matrix_from_file(B);
                if(B==NULL){
                    continue;
                }
                C = mult_matrix(A,B);
                write_matrix_to_file(C);
                destroy_matrix(A);
                destroy_matrix(B);
                // destroy_matrix(C);
            }
            if(strcmp(query,"scalar_mult_matrix")==0){
                long long int s;
                scanf("%lld",&s);
                A = read_matrix_from_file(A);
                if(A==NULL){
                    continue;
                }
                B = scalar_mult_matrix(s,A);
                write_matrix_to_file(B);
                destroy_matrix(A);
                // destroy_matrix(B);
            }
            if(strcmp(query,"transpose_matrix")==0){
                A = read_matrix_from_file(A);
                if(A==NULL){
                    continue;
                }
                B = transpose_matrix(A);
                write_matrix_to_file(B);
                destroy_matrix(A);
                // destroy_matrix(B);
            }
            if(strcmp(query,"determinant")==0){
                A = read_matrix_from_file(A);
                if(A==NULL){
                    continue;
                }
                if(A->num_cols!=A->num_rows){
                    printf("ERROR: INVALID ARGUMENT\n");  
                    continue;      
                }
                printf("%lld",determinant(A));
                destroy_matrix(A);
            }
        }
    }
    // Matrix* m,* n,* ans;
    // int r,c;
    // scanf("%d %d",&r,&c);
    // m = create_matrix(r,c);
    // fillmatrix(m);
    // scanf("%d %d",&r,&c);
    // n = create_matrix(r,c);
    // fillmatrix(n);
    // ans = mult_matrix(m,n);
    // if(ans!=NULL){
    //     print_matrix(ans);
    // }
    // else{
    //     printf("ERROR!!!");
    // }
    // // printf("%lld",determinant(m));
    // // print_matrix(m);
    // // print_matrix(transpose_matrix(m));
    // destroy_matrix(m);
    // destroy_matrix(n);
    return 0;
}