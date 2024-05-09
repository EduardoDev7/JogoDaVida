#ifndef ALOCAMATRIZ_H
#define ALOCAMATRIZ_H


int **aloca(int n){
    int **matriz = malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        matriz[i]=malloc(n*sizeof(int));
    }
    
    return matriz;
}

void libera(int **A,int m){
    for (int i = 0; i < m; i++)
    {
        free(A[i]);
    }
    free(A);
}

#endif