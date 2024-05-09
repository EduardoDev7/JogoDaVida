#ifndef JOGO_H
#define JOGO_H

int **alocarReticulado(int n);
void desalocarReticulado(int **A,int n);
int **LeituraReticulado(int **A, int n);
int **evoluirReticulado(int **A,int **B, int n, int gen);
void imprimeReticulado(int **A, int n);

#endif