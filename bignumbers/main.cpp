//
//  main.cpp
//  bignumbers
//
//  Created by Euler Rithiele Alvarenga on 4/6/17.
//  Copyright © 2017 Euler Rithiele Alvarenga. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <ctype.h>       // isalpha()


/*************************************************************/
/* Aluno: Fulano de Tal */
/* Matrícula: 9999-17 */
/* Curso: Ci^encia da Computação */
/* 1o Trabalho Pr´atico -- Aritm´etica com "Inteiros Grandes" */
/* DCC254 -- 2017 -- IFSEMG, turma Especiais/K */
/* Prof. Fl´avio Augusto de Freitas */
/* Compilador: ... (gcc ou Code::Blocks) vers~ao ... */
/* Sistema Operacional: ... */
/*************************************************************/

#define MAX_NOME_ARQ 256

/*----- Declaracoes das variaveis para leitura e gravacao em arquivos -----*/
char buffer[MAX_NOME_ARQ]; /* para ler os nomes dos arquivos */
char nome_arq_entrada[MAX_NOME_ARQ] = ""; /* nome do arquivo de entrada */
char nome_arq_saida[MAX_NOME_ARQ]= ""; /* nome do arquivo de saida */
FILE *entrada; /* arquivo de entrada aberto */
FILE *saida; /* arquivo de saida aberto */

//função para inicializar o vetor com zeros.
void zera( int *vet ){
    int *p;
    for (p = vet; *p != '\0'; p++){
            *p = -1;
    }
    
}
//
void somaDoisNumeros(int *sum, int *v1, int *v2){
    
    int tempSum = 0;
    int carry1 = 0;
    
    
    for(int i = 7; i >= 0; i--)
    {
        tempSum = v1[i] + v2[i] + carry1; //sum of 10 digits
        
        if( i == 0)
            sum[i] = tempSum; //No carry in case of most significant digit
        else
            sum[i] = tempSum % 10; //Extra digits to be 'carried over'
        
        carry1 = tempSum/10; //pega parte inteira
    }
    //logs
    /*
     std::cout <<"soma: ";
     for (int i=0; i<8; i++) {
     
     std::cout << sum[i];
     }
     std::cout <<"\n";
     */
}

//função que acumula valores no vetor somados com um segundo vetor
void acc(int *acc, int *v1){
    
    int tempSum = 0;
    int carry1 = 0;
    
    
    for(int i = 7; i >= 0; i--)
    {
        tempSum = acc[i] + v1[i] + carry1; //sum of 10 digits
        
        if( i == 0)
            acc[i] = tempSum; //No carry in case of most significant digit
        else
            acc[i] = tempSum % 10; //Extra digits to be 'carried over'
        
        carry1 = tempSum/10; //pega parte inteira
    }
    
    std::cout <<"soma: ";
    for (int i=0; i<8; i++) {
        
        std::cout << acc[i];
    }
    std::cout <<"\n";
}


int main(int argc, const char * argv[]) {

    int state = 0;
    int ch, n , tam=0, i=1;
    char op;
    char sinal1, sinal2;
    char num1[50];
    char num2[50];
    int bigNum1[50];
    
    
    /*----- Primeiros comandos do seu programa -----*/
    
    ::zera(bigNum1);
    
    /* Leitura do nome do arquivo de entrada */
    printf("Digite o nome do arquivo de entrada: ");
    fgets(buffer, MAX_NOME_ARQ, stdin);
    sscanf(buffer, "%s", nome_arq_entrada);
    /* Leitura do nome do arquivo de saida */
    printf("Digite o nome do arquivo de saida: ");
    
    fgets(buffer, MAX_NOME_ARQ, stdin);
    sscanf(buffer, "%s", nome_arq_saida);
    /* Se o nome do arquivo de entrada for nao vazio,
     abre o arquivo de entrada para leitura ("r") */
    if (nome_arq_entrada[0] != '\0') {
        entrada = fopen(nome_arq_entrada, "r");
        if (entrada == NULL) {
            printf("Arquivo de entrada nao encontrado!\n");
            
            exit(1);
        }
//        printf("Testing...%s\n",(char *)entrada);
        
        
        while  ( ( ch = fgetc( entrada ) ) != EOF )
        {
            
            switch (state) {
                case 0:
                    if ( ch == '+' || ch == '-' || ch == ' '){
                        sinal1 = ch;
                        state = 1;
                    }
                    
                case 1:
                    if ( ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' ) {
                        printf("\noperador %c", ch);
                        op = ch;
                        i=1;
                        state = 2;
                        tam=0;
                        //num1[0] = "+710";
                    }else{
                        printf("\nnumero %d",  n = ch - '0');
                        tam++;
                        num1[i++] = ch;
                        bigNum1[i++] = (ch - '0');
                    }
                    break;
                case 2:
                    if ( ch == '+' || ch == '-' || ch == ' '){
                        sinal2 = ch;
                        break;
                    }
                    if( ch == '\n'){
                        state = 0;
                        printf("\n newline");
                    }
                    else{
                        printf("\nnumero %d",  n = ch - '0');
                        tam++;
                        num2[i++] = ch;
                    }
                    break;
            }
            
        }
        
        
    }
    else {
        entrada = stdin;
    }
    /* Se o nome do arquivo de saida for nao vazio,
     abre o arquivo de saida para escrita ("w") */
    if (nome_arq_saida[0] != '\0') {
        saida = fopen(nome_arq_saida, "w");
        if (saida == NULL) {
            printf("Erro na abertura do arquivo de saida!\n");
            exit(-1);
        }
        
    }
    else {
        saida = stdout;
    }

    return 0;
}



