#include <stdio.h>
#include <stdlib.h>
#include "automato.h"

int **alocarReticulado(int n){
    int **matriz = malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        matriz[i]=malloc(n*sizeof(int));
    }
    return matriz;
}

void desalocarReticulado(int **A,int n){
    for (int i = 0; i < n; i++)
    {
        free(A[i]);
    }
    free(A);
}

int **LeituraReticulado(int **matriz, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&matriz[i][j]);
        }
    }
    
    return matriz;
}

int **evoluirReticulado(int **matriz,int **matrizAux, int n, int gen){
    int verifica;
    gen--;
    for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                //00
                if(j==0 && k==0){
                    verifica = matriz[j][k+1] + matriz[j+1][k+1] + matriz[j+1][k];
                }
                //04
                else if(j==0 && k==n-1){
                    verifica = matriz[j][k-1] + matriz[j+1][k-1] + matriz[j+1][k];
                }
                //44
                else if(j==n-1 && k==n-1){
                    verifica = matriz[j-1][k] + matriz[j-1][k-1] + matriz[j][k-1];
                }
                //40
                else if(j==n-1 && k==0){
                    verifica = matriz[j-1][k] + matriz[j-1][k+1] + matriz[j][k+1];
                }
                //cima
                else if(j==0 && k>0 && k<n-1){
                    verifica = matriz[j][k-1] + matriz[j+1][k-1] + matriz[j+1][k] + matriz[j+1][k+1] + matriz[j][k+1];
                }
                //direita
                else if(k==n-1 && j>0 && j<n-1){
                    verifica = matriz[j-1][k-1] + matriz[j-1][k] +  matriz[j+1][k] + matriz[j+1][k-1] + matriz[j][k-1];
                }
                //baixo
                else if(j==n-1 && k>0 && k<n-1){
                    verifica = matriz[j-1][k-1] + matriz[j-1][k] + matriz[j-1][k+1] + matriz[j][k+1] +  matriz[j][k-1];
                }
                //esquerda
                else if(k==0 && j>0 && j<n-1){
                    verifica = matriz[j-1][k] + matriz[j-1][k+1] + matriz[j][k+1] + matriz[j+1][k+1] + matriz[j+1][k];
                }
                
                else{
                    verifica = matriz[j-1][k-1] + matriz[j-1][k] + matriz[j-1][k+1] + matriz[j][k+1] + matriz[j+1][k+1] + matriz[j+1][k] + matriz[j+1][k-1] + matriz[j][k-1];
                }
                
                if(verifica>1 && verifica<4 && matriz[j][k]==1)
                    matrizAux[j][k]=1;

                else if(verifica>3 && matriz[j][k]==1)
                    matrizAux[j][k]=0;

                else if(verifica<2 && matriz[j][k]==1)
                    matrizAux[j][k]=0;
                
                else if(verifica==3 && matriz[j][k]==0)
                    matrizAux[j][k]=1;
                else
                    matrizAux[j][k]=0;
                }
                
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matriz[i][j] = matrizAux[i][j];
                }
                
            }

            gen--;
            if(gen>0){
                matriz = evoluirReticulado(matriz,matrizAux, n, gen);
            }
            
            return matriz;
}

void imprimeReticulado(int **matriz, int n){
    for (int l = 0; l < n; l++)
    {
        for (int m = 0; m < n; m++)
        {
            printf("%d ",matriz[l][m]);
        }
        printf("\n");
    }
}