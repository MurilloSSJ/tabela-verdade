#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
void GerarTabela(int numVariaveis,int numClausulas,int **matrizPTR,int opcao);
int ExpressaoLogica(bool tabelaVerdade[],int numVariaveis,int numClausulas,int **matrizLogicaPTR);
int ExpressaoLogicaIterativa(bool tabelaVerdade[],int numVariaveis,int numClausulas,int **matrizLogicaPTR);