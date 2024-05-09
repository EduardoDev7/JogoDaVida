#include <stdio.h>
#include <stdlib.h>
#include "automato.h"

int main(){
    int **matriz;
    int **matrizAux;
    int n, gen;

    printf("Insira o tamanho da matriz: ");
    scanf("%d",&n);
    printf("Insira o numero de geracoes: ");
    scanf("%d",&gen);

    matriz = alocarReticulado(n);
    matrizAux = alocarReticulado(n);

    matriz = LeituraReticulado(matriz,n);

    matriz = evoluirReticulado(matriz,matrizAux,n,gen);

    imprimeReticulado(matriz,n);

    desalocarReticulado(matriz,n);
    desalocarReticulado(matrizAux,n);

    return 0;
}