#include "TabelaVerdade.h"
void GerarTabela(int numVariaveis,int numClausulas,int **matrizPTR,int opcao){
    int numPossibilidades = pow(2,numVariaveis),i,contador,j,k,flagMensagem=0;
    bool contadorBinario[numVariaveis];
    for(i=0;i<pow(2,numVariaveis);i++){
        contador = i;
        //conta em binario
        for (j = numVariaveis-1; j >= 0; j--){
            if (contador % 2 == 0)
                contadorBinario[j] = 0;
            else
                contadorBinario[j] = 1;
            contador = contador / 2;
        }
        //pega o vetor que ta com a linha x da tabela verdade e compara a saida
        switch (opcao)
        {
        case 1:        //Caso o usuario tenha usado o modo automatico
            if(ExpressaoLogica(contadorBinario,numVariaveis,numClausulas,matrizPTR)==1){
                if(flagMensagem==0){
                    printf("Variaveis\n");
                    for(k=1;k<=numVariaveis;k++){
                        printf("%d ",k);
                    }
                    printf("\n");
                    printf("\n");
                    flagMensagem =1;
                }
                for(k=0;k<numVariaveis;k++){
                    if(contadorBinario[k]==1)
                        printf("V ");
                    else
                        printf("F ");
                }
                printf("\n");
                }
                break;
        
        case 2:     //Caso o usuário tenha usado o modo iterativo
            if(ExpressaoLogicaIterativa(contadorBinario,numVariaveis,numClausulas,matrizPTR)==1){
                if(flagMensagem==0){
                    printf("Variaveis\n");
                    for(k=1;k<=numVariaveis;k++){
                        printf("%d ",k);
                    }
                    printf("\n");
                    printf("\n");
                    flagMensagem =1;
                }
                for(k=0;k<numVariaveis;k++){
                    if(contadorBinario[k]==1)
                        printf("V ");
                    else
                        printf("F ");
                }
                printf("\n");
                }
                break;
            break;
        }
        
    }
}
int ExpressaoLogica(bool tabelaVerdade[],int numVariaveis,int numClausulas,int **matrizLogicaPTR){
    int i,j,k,posicaoVetor=0;
    bool LinhaLogica[3],LogicaBool[numClausulas];
    for(i=0;i<numClausulas;i++){
        for(j=0;j<numVariaveis;j++){
            if(matrizLogicaPTR[i][j]==1){
                LinhaLogica[posicaoVetor] = !(tabelaVerdade[j]);
                posicaoVetor++;
            }
            else if(matrizLogicaPTR[i][j]==2){
                LinhaLogica[posicaoVetor] = tabelaVerdade[j];
                posicaoVetor++;
            }     
        }
        posicaoVetor=0;
        LogicaBool[i] = LinhaLogica[0] || LinhaLogica[1] || LinhaLogica[2];
    }
    for(i=0;i<numClausulas;i++){
        if(LogicaBool[i]==0)
            return 0;
    }
    return 1;
}
int ExpressaoLogicaIterativa(bool tabelaVerdade[],int numVariaveis,int numClausulas,int **matrizLogicaPTR){
    int i,j,k;
    bool LinhaLogica[3],LogicaBool[numClausulas];
    for(i=0;i<numClausulas;i++){
        for(j=0;j<3;j++){
            if(matrizLogicaPTR[i][j]<0){
                LinhaLogica[j] = !(tabelaVerdade[abs(matrizLogicaPTR[i][j])-1]);
            }
            else if(matrizLogicaPTR[i][j]>0){
                LinhaLogica[j] = tabelaVerdade[abs(matrizLogicaPTR[i][j])-1];
            }
        }
        LogicaBool[i] = LinhaLogica[0] || LinhaLogica[1] || LinhaLogica[2];
    }
    for(i=0;i<numClausulas;i++){
        if(LogicaBool[i]==0)
            return 0;
    }
    return 1;
}