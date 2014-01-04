#include "main.h"


etapas etapa[TAM_ETAPA];
itinerario itinerarios[TAM_ITINERARIOS];
int cont_etapas = 0, cont_itinerarios = 0;

int verificarNome(char *nome) {
    int i = 0;

    // se o cont_etapas estiver a zeros, nao necessitamos de verificar
    if (cont_etapas == 0) {

        return 5;
    }

    // neste ciclo verificamos se existe algum nome igual
    //enquanto o i for menor, vai incrementado +1 ate chegar ao final, caso nao encontre o nome inserido
    while (i < cont_etapas) {
        if (strcmp(etapa[i].nomeEtapa, nome) == 0)
            return i;

        i++;
    }
    return 5; //retorna 5, porque se passou por todas as opcoes acima e sinal de que podemos inserir a etapa 
}

int adicionarEtapas() {
    char tmp[TAMSTRING];
    int retorno;

    // se cont_etapas for menor e sinal que existe espaço e por isso perguntamos 
    // pelo nome que o utilizador deseja chamar a etapa
    if (cont_etapas < TAM_ETAPA) {

        printf("Insira o nome da etapa :  ");
        scanf("%s", tmp); // guardamos o nome numa variavel temporaria
        retorno = verificarNome(tmp); //chama a funcçãi verificarNome 

        switch (retorno) {
                //caso o retorno seja de sucesso (5) podemos entao inserir os restantes dados)

            case 5:
                //copia os caracteres da nossa variavel temporaria para a nossa string
                strcpy(etapa[cont_etapas].nomeEtapa, tmp);
                printf("\ninsira a duracao da etapa : ");
                scanf("%f", &etapa[cont_etapas].duracao); //guardamos o valor directamente
                etapa[cont_etapas].nrItinerarios = 0;
                ++cont_etapas;
                return 0;
                break;

            default:
                printf("O nome que Inseriu ja existe \n");
                return -1;
                break;

        }

    } else {
        return -2;
    }
}

int editarEtapas() {

    int i = 0;
    int temp, retorno;
    char tmpNome[TAMSTRING];
    if (cont_etapas == 0) { // se o cont_etapas estiver a zeros, nao temos nada para editar
        printf("Não existem etapas\n");
        return -1;
    }

    printf("Qual a etapa que quer editar: ");

    while (i < cont_etapas) {
        printf("\n%d - Nome da Etapa: %s\nDuracao da Etapa: %d\n", i, etapa[i].nomeEtapa, etapa[i].duracao);
        ++i; // listamos as etapas e o utilizador escolhe o numero associado a etapa a editar
    }
    printf("5 - Sair \n");
    scanf("%d", &temp);


    //se a opcao escolhida for menor que 0, 
    // maior ou igual que o nosso contador e diferente de 5 a opcao nao e valida  
    while (temp < 0 || temp >= cont_etapas && temp != 5) {
        printf("Nao existe essa opcao\n Insira uma opcao valida.\n");
        scanf("%d", &temp); // guaradamos a opcao na variavel temp
    }
    if (temp == 5) { // opcao 5 ´´e para sair
        return 0;
    }
    printf("insira o nome pretendido: ");
    scanf("%s", tmpNome); //guaradmos o nome temporariamente ate verificar
    retorno = verificarNome(tmpNome); // verifica se o nome existe 
    if (retorno != 5) { // se o retorno for diferente do valor de sucesso sinal de que ja existe
        printf("\nO nome da Etapa ja existe\n");
        return -1; // volta ao menu de gestao de etapas
    }
    strcpy(etapa[temp].nomeEtapa, tmpNome); // se  o retorno for 5 entao podemos editar o restante e copiamos logo o valor temporario para a nossa string
    printf("Insira a duracao: ");
    scanf("%d", &etapa[temp].duracao);
    if (DEBUG)
        printf("%s %d", etapa[temp].nomeEtapa, etapa[temp].duracao);
}

int removerEtapas() {

    int i = 0, temp, nrItinerario = 0;

    while (i < cont_etapas) {
        printf("\n %d  Nome da Etapa: %s \n", i, etapa[i].nomeEtapa);
        ++i;
    }

    if (cont_etapas > 0) {
        printf("qual a etapa que quer remover \n");
        scanf("%d", &temp);

        i = 0;



        if (etapa[temp].nrItinerarios == 0) {

            if (cont_etapas == 1) {
                cont_etapas--;
            } else {

                while (temp < cont_etapas) {
                    etapa[temp] = etapa[temp + 1];
                    temp++;
                }
                cont_etapas--;
            }
        } else {
            printf("existem itinerarios na etapa pretendia");
        }

    } else {
        printf("nao existem etapas a remover");
    }

}

int trocar() {

    int i = 0;
    int etapa1, etapa2;
    char temp[TAMSTRING];

    if (cont_etapas == 0) { // se o cont_etapas estiver a zeros, nao temos nada para editar
        printf("Não existem etapas\n");
        return -1;
    }



    while (i < cont_etapas) {
        printf("\n%d - Nome da Etapa: %s", i, etapa[i].nomeEtapa);
        ++i; // listamos as etapas e o utilizador escolhe o numero associado a etapa a editar
    }

    printf("\nPor favor insira a primeira etapa: ");
    scanf(" %d", &etapa1);
    printf("\nPor favor insira a segunda etapa: ");
    scanf(" %d", &etapa2);
    strcpy(temp, etapa[etapa1].nomeEtapa);
    strcpy(etapa[etapa1].nomeEtapa, etapa[etapa2].nomeEtapa);
    strcpy(etapa[etapa2].nomeEtapa, temp);




}

int listarEtapas() {
    int i = 0;

    printf("\n\n ***** Lista de Etapas ***** \n");

    while (i < cont_etapas) {
        printf("\n - Nome da Etapa: %s     Nº: %d    Duracao da Etapa: %f\n", etapa[i].nomeEtapa, i + 1, etapa[i].duracao);
        ++i; // listamos as etapas e o utilizador escolhe o numero associado a etapa a editar
    }
}

int adicionarItinerarios() {
    int i = 0;
    int temp, retorno;
    char tmpNome[TAMSTRING];


    if (cont_etapas == 0) { // se o cont_etapas estiver a zeros, nao temos nada para adicionar
        printf("Não existem etapas\n");
        return -1;
    }

    printf("Qual a etapa que quer adicionar o itinerario? ");

    while (i < cont_etapas) {
        printf("\n%d - Nome da Etapa: %s\n\n", i, etapa[i].nomeEtapa);
        ++i; // listamos as etapas e o utilizador escolhe o numero associado a etapa 
    }
    printf("5 - Sair \n");
    scanf("%d", &temp);


    //se a opcao escolhida for menor que 0, 
    // maior ou igual que o nosso contador e diferente de 5 a opcao nao e valida  
    while (temp < 0 || temp >= cont_etapas && temp != 5) {
        printf("\n Nao existe essa opcao\n Por favor, insira uma opcao valida.\n");
        scanf("%d", &temp); // guardamos a opcao na variavel temp
    }
    if (temp == 5) { // opcao 5 e para sair
        return 0;
    }

    if (etapa[temp].nrItinerarios < TAM_ITINERARIOS) {

        // itinerario *este;
        //este = &etapa[temp].ite;

        int index = etapa[temp].nrItinerarios;
        printf("Insira a distancia parcial :  ");
        scanf(" %f", &etapa[temp].ite[index].disParcial);
        printf("Insira a Instruçao :  ");
        scanf(" %s", &etapa[temp].ite[index].instrucao);
        printf("Insira a informacao adicional :  ");
        scanf(" %s", &etapa[temp].ite[index].infAdicional);
        etapa[temp].nrItinerarios++;

        return 5;

    }
}

int editarItinerarios() {

    printf("editarItinerarios\n\n");
}

int removerItinerarios() {

    int i = 0, temp, nrItinerario = 0;

    while (i < cont_etapas) {
        printf("\n %d  Nome da Etapa: %s         Duracao da Etapa: %d\n", i, etapa[i].nomeEtapa, etapa[i].duracao);
        ++i;
    }

    printf("qual a etapa que quer remover o itinerario\n");
    scanf("%d", &temp);

    i = 0;
    if (etapa[temp].nrItinerarios > 0) {
        while (i < etapa[temp].nrItinerarios) {
            printf("\n nº %d  distancia parcial: %f  instrucao: %s", i, etapa[temp].ite[i].disParcial, etapa[temp].ite[i].instrucao);
            ++i;
        }

        printf("qual o itinerario a remover\n");
        scanf("%d", &nrItinerario);

        if (nrItinerario == (etapa[temp].nrItinerarios - 1)) {
            etapa[temp].nrItinerarios--;

        } else {
            while (nrItinerario < etapa[temp].nrItinerarios) {
                strcpy(etapa[temp].ite[nrItinerario].instrucao, etapa[temp].ite[nrItinerario + 1].instrucao);
                strcpy(etapa[temp].ite[nrItinerario].infAdicional, etapa[temp].ite[nrItinerario + 1].infAdicional);
                etapa[temp].ite[nrItinerario].disParcial = etapa[temp].ite[nrItinerario + 1].disParcial;
                ++nrItinerario;
            }
            etapa[temp].nrItinerarios--;
        }






    }
}

int listarItinerarios() {

    int i = 0, temp;

    while (i < cont_etapas) {
        printf("\n %d  Nome da Etapa: %s         Duracao da Etapa: %d\n", i, etapa[i].nomeEtapa, etapa[i].duracao);
        ++i;
    }

    printf("qual a etapa que quer listar os itinerarios\n");
    scanf("%d", &temp);

    i = 0;
    while (i < etapa[temp].nrItinerarios) {
        printf("\n nº %d  distancia parcial: %f  instrucao: %s", i, etapa[temp].ite[i].disParcial, etapa[temp].ite[i].instrucao);
        ++i;
    }

}

int menuEtapas() {

    int opcao, retorno;

    do {

        printf("\n\n ***** Menu Gestao de Etapas ***** \n");
        printf(" \n\n");
        printf(" 1 - Adicionar \n");
        printf(" 2 - Editar \n");
        printf(" 3 - Remover \n ");
        printf("4 - Trocar ordem \n ");
        printf("5 - listar \n ");
        printf("0 - Menu Principal \n ");
        scanf(" %d", &opcao);

        switch (opcao) {
            case 1:
                retorno = adicionarEtapas();
                if (retorno == 0) {
                    printf("\nInserido com sucesso\n");
                } else {
                    if (retorno == -1) {
                        printf("\nja existe\n");
                    } else {
                        printf("\nEsta cheio\n");
                    }
                }

                break;

            case 2:
                editarEtapas();
                break;

            case 3:
                removerEtapas();
                break;

            case 4:
                trocar();
                break;

            case 5:
                listarEtapas();
                break;

            default:
                printf("Por favor, escolha uma opcao valida\n\n");
                break;
        }
    } while (opcao != 0);

}

int menuItinerarios() {

    int opcao, retorno;

    do {

        printf("\n\n ***** Menu Gestao de Itinerarios ***** \n");
        printf(" \n\n");
        printf(" 1 - Adicionar \n");
        printf(" 2 - Editar \n");
        printf(" 3 - Remover \n ");
        printf("4 - listar \n ");
        printf("0 - Menu Principal \n ");
        scanf(" %d", &opcao);

        switch (opcao) {
            case 1:
                retorno = adicionarItinerarios();
                if (retorno == 5) {
                    printf("\nInserido com sucesso\n");
                } else {
                    if (retorno == -1) {
                        printf("\nja existe\n");
                    } else {
                        printf("\nEsta cheio\n");
                    }
                }

                break;

            case 2:
                editarItinerarios();
                break;

            case 3:
                removerItinerarios();
                break;

            case 4:
                listarItinerarios();
                break;

            default:
                printf("Por favor, escolha uma opcao valida\n\n");
                break;
        }
    } while (opcao != 0);

}

int menuConsultas() {

    printf(" Consultas \n");

}

/* 
 *  
 */
int main(int argc, char** argv) {

    int opcao;

    do {

        printf(" ***** Menu Principal ***** \n");
        printf(" \n\n");
        printf(" 1 - Gestao de Etapas \n");
        printf(" 2 - Gestao de Intinerarios \n");
        printf(" 3 - Consultas \n ");
        printf("0 - Sair \n ");
        scanf(" %d", &opcao);

        switch (opcao) {
            case 1:
                menuEtapas();
                break;

            case 2:
                menuItinerarios();
                break;

            case 3:
                menuConsultas();
                break;

            default:
                printf("Por favor, escolha uma opcao valida\n\n");
                break;
        }
    } while (opcao != 0);

    return 0;
} 