#include <stdio.h>
#include <stdlib.h>
#include "ModosDeFuncionamento.h"
void main(){
    int opcao;
    printf("Ola! Bem-Vindo ao Programa de Problema da Satisfabilidade (SAT)\n");
    while(opcao!=3){
        printf("Digite a opcao desejada:\n1-Interativo\n2-Automatico\n3-Break\n");
        scanf("%d",&opcao);
        if(opcao==3){
            break;
        }
        switch (opcao)
        {
        case 1:
            ModoIterativo();
            break;
        case 2:
            ModoAutomatico();
            break;
        default:
            printf("Tecla não reconhecida, tente novamente!");
            break;
        }
    }
}
