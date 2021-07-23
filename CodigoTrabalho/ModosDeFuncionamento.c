#include "ModosDeFuncionamento.h"
void ModoIterativo(){
    int numClausulas,qntVariaveis,i,j,numVariavel,Negacao,relogio = 0;
    printf("Insira o numero de clausulas(c):\n");
    scanf("%d",&numClausulas);
    printf("Insira o numero de variaveis (N):\n");
    scanf("%d",&qntVariaveis);
    int **ValoresBool; 
    ValoresBool = malloc (numClausulas * sizeof (int*));
    for (i=0; i < numClausulas; i++)
        ValoresBool[i] = malloc (3 * sizeof (int));
    for(i=0;i<numClausulas;i++){
        for(j=0;j<3;j++){
            ValoresBool[i][j] = 0;
        }
    }
    for(i=0;i<numClausulas;i++){
        for(j=0;j<3;j++){
            printf("Insira o numero da variavel\n");
            scanf("%d",&numVariavel);
            printf("Insira se ela esta negada(1) ou nao(2)\n");
            scanf("%d",&Negacao);
            if(Negacao==1)
                ValoresBool[i][j] = numVariavel * -1; 
            else if(Negacao==2)
                ValoresBool[i][j] = numVariavel;
        }
    }
    relogio = clock();
    GerarTabela(qntVariaveis,numClausulas,ValoresBool,2);
    relogio = clock() - relogio;
    printf("\nTempo para gerar a tabela verdade:%dms\n",relogio);
}
void ModoAutomatico(){
    int i,j;
    int numClausulas, qntVariaveis, pos, v,flag=0,valoresPos[3],k,relogio=0;
    srand(time(NULL));
    printf("numero de variaveis:");
    scanf("%d", &qntVariaveis);
    numClausulas = (qntVariaveis/3)*2;
    //MATRIZ COM ZERO EM TODAS AS POSIÇOES
    int **ValoresBool; 
    ValoresBool = malloc (numClausulas * sizeof (int*));
    for (i=0; i < numClausulas; i++)
        ValoresBool[i] = malloc (qntVariaveis * sizeof (int));
    for (i=0; i<numClausulas;i++){
        for (j=0; j<qntVariaveis;j++){
            ValoresBool[i][j] = 0;
        }
    }
    //Gerando expressoes booleanas aleatoria
    for (i=0; i< numClausulas;i++){
        for(k=0;k<3;k++){
            valoresPos[k] = qntVariaveis+1;      
        }
        for(j=0;j<3;j++){
            flag = 0;
            v = 1+(rand()%2) ;
            pos = rand()%qntVariaveis;
            for(k=0;k<3;k++){
                if(valoresPos[k]==pos){
                    flag=1;
                    j--;
                }       
            }
            if(flag!=1){
                ValoresBool[i][pos] = v; //matriz que receberá as expressoes booleanas
                valoresPos[j] = pos;
            }
        }
    }
    printf("Matriz Gerada:\n");
    for (i=0; i < numClausulas; i++){
        for(j=0;j<qntVariaveis;j++)
            printf("%d\t",ValoresBool[i][j]);
        printf("\n");
    }
    printf("\n\n\n");
    relogio = clock();
    GerarTabela(qntVariaveis,numClausulas,ValoresBool,1);
    relogio = clock() - relogio;
    printf("\n");
    printf("Tempo para gerar a tabela verdade:%dms\n",relogio);
    printf("\n");
    for (i=0; i < numClausulas; i++){
        for(j=0;j<qntVariaveis;j++)
            free(ValoresBool[i][j]);
    }
        
}