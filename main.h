/* 
 * File:   main.h
 * Author: JoséLuís
 *
 * Created on 4 de Janeiro de 2014, 11:02
 */



#ifndef MAIN_H
#define	MAIN_H

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define TAMSTRING 50 
#define TAM_ETAPA 5 
#define TAM_ITINERARIOS 15
#define DEBUG 1 

int listarEtapas();
int editarEtapas();
int verificarNome(char *nome);

typedef struct {
    float disParcial;
    char instrucao[TAMSTRING];
    char infAdicional[TAMSTRING];
} itinerario;

typedef struct {
    char nomeEtapa[TAMSTRING];
    float distanciaTotal;
    float duracao;
    itinerario ite[15];
    int nrItinerarios;
} etapas;

#endif	/* MAIN_H */

