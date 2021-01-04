/*
Ismat - Engenheria Informática 1º Ano
Fundamentos de Programação - Prof. Francisco Pereira
Leandro Fonseca
04/01/2021 - 20:39
Resumo: Programa com menus com 2 jogos
Inputs:
Outputs:
 */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef LINUX
#define CLEAR "clear"
#else
#define CLEAR "cls"
#endif

#define TEXT_MENU_TITLE "Game Menu\n"
#define TEXT_MENU_DIVISION "-------------------------------------\n"
#define TEXT_MENU_PRINT_OPT1 "1. - Jogo do HI-LOW\n"
#define TEXT_MENU_PRINT_OPT2 "2. - Jogo ainda não decidido\n"
#define TEXT_MENU_PRINT_OPT0 "0. - Sair do Programa\n"

#define TEXT_HILOW_INSERT "\nIntroduza a sua resposta: "
#define TEXT_HILOW_CONDITION "\n%d é %s que o número a adivinhar!"
#define TEXT_HILOW_WIN "\nVocẽ Ganhou! O número era %d! Número de tentativas: %d"


void printMenu()
{
//    system("CLEAR");
    printf(TEXT_MENU_TITLE);
    printf(TEXT_MENU_DIVISION);
    printf(TEXT_MENU_PRINT_OPT1);
    printf(TEXT_MENU_PRINT_OPT2);
    printf(TEXT_MENU_PRINT_OPT0);
}

void gameHiLow()
{
    int intToGuess, intFailedCounter, intUserResult;
    srand(time(NULL));

    intToGuess = rand() % 100 + 1;
    printf("%d",intToGuess);

    for(intFailedCounter = 0; (intToGuess != intUserResult); intFailedCounter++)
    {
        printf(TEXT_HILOW_INSERT);
        scanf("%d", &intUserResult);

        if(intUserResult < intToGuess)
        {
            printf(TEXT_HILOW_CONDITION,intUserResult, "menor");
        }else
        {
            printf(TEXT_HILOW_CONDITION,intUserResult, "maior");
        }
    }
    printf(TEXT_HILOW_WIN, intToGuess, intFailedCounter);
}

void main()
{

    gameHiLow();
    printMenu();
}