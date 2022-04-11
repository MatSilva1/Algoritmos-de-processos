#include <stdlib.h> 
#include <stdio.h>  
#include <conio.h>
#define tam 50

int processos[tam];           //Fila de processos
int numProcessos;
int quantum;                //Numero de quantum

void Tipo(){
    
    int aux;
    int contadorFila=numProcessos;
    while(contadorFila !=0){
        printf("Selecione o tipo do processo");
        printf("1 para I/O");
        printf("2 para CPU");
        printf("3 para I/O CPU");
        scanf("%d", aux);
    }
    
}

void Espera(){
    int contadorFila = numProcessos;
    int frenteFila = 1;
    int tempoEspera;
    
    
    // Criar funcao espera
}

void tempoProcessador(){
    
    int processamento;
    
     printf("\nExecuta ate %d de tempo de processamento", processamento);
        processos[frenteFila] = processos[frenteFila] - processamento;        //Subtraido o valor de quantum
        if( processos[frenteFila]<=0){
            printf("\nFinalizado.\n");
            contadorFila--;
        }
        else{
            printf("\nE vai para fila aux com %d tempo de execucao restantes.\n", processos[frenteFila]);
        }
        frenteFila++;                               //Atualiza primeira posição
            if(frenteFila>numProcessos)    //Faz a rotação
                frenteFila=0;
        getchar();
    }
    
    Espera();
}

void calcQuantum(){       //Para que o usuario possa testar com diferentes quantidades de tempo de execução
    int numero;
    int i;
    for (i=1; i<=numProcessos; i++){
        printf("\nDigite a quantidade de tempo de execução por processo %d:", i);
        scanf("%d", &numero);               //Leitura de valor inserido pelo usuario
        processos[i]= numero;                 //cada processo recebe o valor informado
    }
}

/* void filaAux(){
    
    //antes criar função de espera
    
} */

void fila(){
    int contadorFila=numProcessos;            //contagem de processos que estão na fila
    int frenteFila = 1;                 //Primeira posição da fila
    while(contadorFila !=0){
        while(processos[frenteFila] <= 0){ //Tira processos que não tem tempo da primeira posição
            frenteFila++;
            if(frenteFila>= numProcessos) //Faz a rotação
                frenteFila=0;
        }
        printf("\n\nO processo %d vai para o execução com %d tempo", frenteFila , processos[frenteFila]);
        printf("\nExecuta ate %d quantum", quantum);
        processos[frenteFila] = processos[frenteFila] - quantum;        //Subtraido de quantum contas
        if( processos[frenteFila]<=0){
            printf("\nE sai da fila.\n");
            contadorFila--;
        }
        else{
            printf("\nE vai pro final da fila com %d tempo de execucao restantes.\n", processos[frenteFila]);
        }
        frenteFila++;                               //Atualiza primeira posição
            if(frenteFila>numProcessos)    //Faz a rotação
                frenteFila=0;
        getchar();
    }  //Não esquecer de chamar as funções para rodar no loop atraves da função fila
}
 
main(){
    printf("::::::: Programa exemplo sobre round-robin :::::::");
    printf("\nDigite o valor de quantum: ");
    scanf("%d", &quantum);
    printf("\nDigite o numero de processos na fila: ");
    scanf("%d", &numProcessos);
    Tipo();
    Espera();
    calcQuantum();
    fila();
        printf("\n\n::::::::: Fim ::::::::::\n");
    getch();
} 
