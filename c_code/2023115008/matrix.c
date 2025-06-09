#include"stdio.h"
#include"stdlib.h"
#include"matrix.h"

Matrix* create_matrix(int r, int c){
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    m->num_rows = r;
    m->num_cols = c;
    m->data = (long long int**) calloc(r, sizeof(long long int*));
    for (int i =0; i < r; i++) {
        m->data[i] = (long long int*) calloc(c, sizeof(long long int));
    }
    return m;
}
void destroy_matrix(Matrix* m){
    int r = m->num_rows;
    for (int i =0; i < r; i++) {
        free(m->data[i]);
    }
    free(m->data);
    return;
// 1: Write code here to free all memory used by the matrix stored in m
}
Matrix* add_matrix(Matrix* A, Matrix* B){
    if(A->num_cols!=B->num_cols||A->num_rows!=B->num_rows){
        return NULL;
    }
    Matrix* m = create_matrix(A->num_rows,A->num_cols);
    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
           m->data[i][j]=A->data[i][j]+B->data[i][j];
        }
    }
    return m;
// 2: write code here to add the matrices A and B and return a new matrix with the results.
// A, B should remain unmodified. If dimensions don't match, it should return NULL.

    // Matrix* A = create_matrix();
    // Matrix* B = create_matrix();
}
Matrix* mult_matrix(Matrix* A, Matrix* B){
    if(A->num_cols!=B->num_rows){
        return NULL;
    }
    Matrix* C = create_matrix(A->num_rows,B->num_cols);
    for (int i = 0; i < C->num_rows; i++) {
        for (int j = 0; j < C->num_cols; j++) {
            for(int k=0;k<A->num_cols;k++){
                C->data[i][j]+=A->data[i][k]*B->data[k][j];
            }
        }
    }
    return C;    
// 3: write code here to multiply the matrices A and B and return a new matrix with the results.
// A, B should remain unmodified. If the dimensions don't match, it should return NULL.
}

Matrix* scalar_mult_matrix(long long int s, Matrix* M){
    Matrix* m = create_matrix(M->num_rows,M->num_cols);
    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
           m->data[i][j]=s*M->data[i][j];
        }
    }
    return m;
// 4: write code here to multiply the matrix A with a scalar s and return a new matrix with the results.
// M should remain unmodified.
}
Matrix* transpose_matrix(Matrix* A){
    Matrix* m= create_matrix(A->num_cols,A->num_rows);
    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            m->data[i][j]=A->data[j][i];
        }
    }
    return m;
// 5: write code here to find the transpose of given matrix A and return a new matrix with the results.
// A should remain unmodified.
}
long long int determinant(Matrix* M){
    // if(M->num_cols==2){
    //     return M->data[0][0]*M->data[1][1]- M->data[1][0]*M->data[0][1];
    // }
    if(M->num_cols==1){
        return M->data[0][0];
    }
    else{
        long long int Determinant=0;
        long long int cofactor;
        for(int t=0;t<M->num_cols;t++){
            Matrix* A = create_matrix(M->num_rows-1,M->num_cols-1);
            for (int i = 0,a=1; i < A->num_rows; i++,a++) {
                for (int j = 0,b=0; j < A->num_cols; j++,b++) {
                    if(b==t)b++;
                    A->data[i][j] = M->data[a][b];
                }
            }
            cofactor=determinant(A);
            if(t%2==0){
                Determinant +=M->data[0][t]*cofactor;
            }
            else{
                Determinant -=M->data[0][t]*cofactor;
            }
        }
        return Determinant;
    }
    // return Determinant;
// 6: Write code here to calculate the determinant of the given matrix M (if not a square matrix, return -1).
// Return the determinant value.
}
// DO NOT MODIFY THE OUTPUT FORMAT of this function. Will be used for grading
void print_matrix(Matrix* m) {
    if(m==NULL){
        printf("ERROR: INVALID ARGUMENT\n");
        return ;
    }
    printf("%d %d\n", m->num_rows, m->num_cols);
    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            printf("%lld ", m->data[i][j]);
        }
        printf("\n");
    }
    destroy_matrix(m);
    return;
}

void  write_matrix_to_file(Matrix* m) {
    FILE * fptr;
    char filename[10000];
    scanf("%s",filename);
    fptr = fopen(filename,"w");
    if(m==NULL){
        printf("ERROR: INVALID ARGUMENT\n");
        fclose(fptr);
        return ;
    }
    fprintf(fptr,"%d %d\n", m->num_rows, m->num_cols);
    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            fprintf(fptr,"%lld ", m->data[i][j]);
        }
        fprintf(fptr,"\n");
    }
    fclose(fptr);
    destroy_matrix(m);
    return ;
}