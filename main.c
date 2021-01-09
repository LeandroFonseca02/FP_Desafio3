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

#ifdef _WIN32
# define CLEAR system ("cls")
#else
# define CLEAR system("clear")
#endif

#define TEXT_MENU_TITLE "Game Menu\n"
#define TEXT_MENU_DIVISION "-------------------------------------\n"
#define TEXT_MENU_PRINT_OPT1 "1. - Jogo do HI-LOW\n"
#define TEXT_MENU_PRINT_OPT2 "2. - Jogo ainda não decidido\n"
#define TEXT_MENU_PRINT_OPT0 "0. - Sair do Programa\n"
#define TEXT_MENU_INSERT "\nEscolha uma opção: "


#define TEXT_HILOW_INSERT "\nIntroduza a sua resposta: "
#define TEXT_HILOW_CONDITION "\n%d é %s que o número a adivinhar!"
#define TEXT_HILOW_WIN "\nVocẽ Ganhou! O número era %d! Número de tentativas: %d"


#define TEXT_PENALTI_PHASE0_LINE1 "\n\t ___________________________"
#define TEXT_PENALTI_PHASE0_LINE2 "\n\t |                         |"
#define TEXT_PENALTI_PHASE0_LINE3 "\n\t |                         |"
#define TEXT_PENALTI_PHASE0_LINE4 "\n\t |            O            |"
#define TEXT_PENALTI_PHASE0_LINE5 "\n\t |           \\|/           |"
#define TEXT_PENALTI_PHASE0_LINE6 "\n\t |           / \\           |"

#define TEXT_PENALTI_PHASE1_LINE1 "\n\t ___________________________"
#define TEXT_PENALTI_PHASE1_LINE2 "\n\t |                         |"
#define TEXT_PENALTI_PHASE1_LINE3 "\n\t |   O |                   |"
#define TEXT_PENALTI_PHASE1_LINE4 "\n\t |   - \\                   |"
#define TEXT_PENALTI_PHASE1_LINE5 "\n\t |     / \\                 |"
#define TEXT_PENALTI_PHASE1_LINE6 "\n\t |                         |"

#define TEXT_PENALTI_PHASE2_LINE1 "\n\t ___________________________"
#define TEXT_PENALTI_PHASE2_LINE2 "\n\t |            O            |"
#define TEXT_PENALTI_PHASE2_LINE3 "\n\t |           \\|/           |"
#define TEXT_PENALTI_PHASE2_LINE4 "\n\t |           / \\          |"
#define TEXT_PENALTI_PHASE2_LINE5 "\n\t |                         |"
#define TEXT_PENALTI_PHASE2_LINE6 "\n\t |                         |"

#define TEXT_PENALTI_PHASE3_LINE1 "\n\t ___________________________"
#define TEXT_PENALTI_PHASE3_LINE2 "\n\t |                         |"
#define TEXT_PENALTI_PHASE3_LINE3 "\n\t |                   | O   |"
#define TEXT_PENALTI_PHASE3_LINE4 "\n\t |                   /  -  |"
#define TEXT_PENALTI_PHASE3_LINE5 "\n\t |                  / \\    |"
#define TEXT_PENALTI_PHASE3_LINE6 "\n\t |                         |"

#define TEXT_PENALTI_PHASE4_LINE1 "\n\t ___________________________"
#define TEXT_PENALTI_PHASE4_LINE2 "\n\t |                         |"
#define TEXT_PENALTI_PHASE4_LINE3 "\n\t |                         |"
#define TEXT_PENALTI_PHASE4_LINE4 "\n\t |    \\                    |"
#define TEXT_PENALTI_PHASE4_LINE5 "\n\t |   O-- <                 |"
#define TEXT_PENALTI_PHASE4_LINE6 "\n\t |    /                    |"

#define TEXT_PENALTI_PHASE6_LINE1 "\n\t ___________________________"
#define TEXT_PENALTI_PHASE6_LINE2 "\n\t |                         |"
#define TEXT_PENALTI_PHASE6_LINE3 "\n\t |                         |"
#define TEXT_PENALTI_PHASE6_LINE4 "\n\t |                    /    |"
#define TEXT_PENALTI_PHASE6_LINE5 "\n\t |                 >--O    |"
#define TEXT_PENALTI_PHASE6_LINE6 "\n\t |                    \\   |"


#define TEXT_PENALTI_SCORE "%s | %d - %d | CPU"
#define TEXT_PENALTI_INPUT "\nEscolha o nome do seu clube: "
#define TEXT_PENALTI_CHOICE "\nEscolha uma posicao para rematar (1-Canto Superior Esquerdo 2-Central Superior 3-Canto Superior Direito 4-Canto Inferior Esquerdo 5-Remate a Figura 6-Canto Inferior Direito): "


void printMenu()
{
    system(CLEAR);
    printf(TEXT_MENU_TITLE);
    printf(TEXT_MENU_DIVISION);
    printf(TEXT_MENU_PRINT_OPT1);
    printf(TEXT_MENU_PRINT_OPT2);
    printf(TEXT_MENU_PRINT_OPT0);
    printf(TEXT_MENU_INSERT);
}

void printBaliza(int intPhase)
{
    if (intPhase == 0)
    {
        printf(TEXT_PENALTI_PHASE0_LINE1);
        printf(TEXT_PENALTI_PHASE0_LINE2);
        printf(TEXT_PENALTI_PHASE0_LINE3);
        printf(TEXT_PENALTI_PHASE0_LINE4);
        printf(TEXT_PENALTI_PHASE0_LINE5);
        printf(TEXT_PENALTI_PHASE0_LINE6);
    }else if (intPhase == 1)
    {
        printf(TEXT_PENALTI_PHASE1_LINE1);
        printf(TEXT_PENALTI_PHASE1_LINE2);
        printf(TEXT_PENALTI_PHASE1_LINE3);
        printf(TEXT_PENALTI_PHASE1_LINE4);
        printf(TEXT_PENALTI_PHASE1_LINE5);
        printf(TEXT_PENALTI_PHASE1_LINE6);
    }else if (intPhase == 2)
    {
        printf(TEXT_PENALTI_PHASE2_LINE1);
        printf(TEXT_PENALTI_PHASE2_LINE2);
        printf(TEXT_PENALTI_PHASE2_LINE3);
        printf(TEXT_PENALTI_PHASE2_LINE4);
        printf(TEXT_PENALTI_PHASE2_LINE5);
        printf(TEXT_PENALTI_PHASE2_LINE6);
    }else if (intPhase == 3)
    {
        printf(TEXT_PENALTI_PHASE3_LINE1);
        printf(TEXT_PENALTI_PHASE3_LINE2);
        printf(TEXT_PENALTI_PHASE3_LINE3);
        printf(TEXT_PENALTI_PHASE3_LINE4);
        printf(TEXT_PENALTI_PHASE3_LINE5);
        printf(TEXT_PENALTI_PHASE3_LINE6);
    }else if (intPhase == 4)
    {
        printf(TEXT_PENALTI_PHASE4_LINE1);
        printf(TEXT_PENALTI_PHASE4_LINE2);
        printf(TEXT_PENALTI_PHASE4_LINE3);
        printf(TEXT_PENALTI_PHASE4_LINE4);
        printf(TEXT_PENALTI_PHASE4_LINE5);
        printf(TEXT_PENALTI_PHASE4_LINE6);
    }else if (intPhase == 5)
    {
        printf(TEXT_PENALTI_PHASE1_LINE1);
        printf(TEXT_PENALTI_PHASE1_LINE2);
        printf(TEXT_PENALTI_PHASE1_LINE3);
        printf(TEXT_PENALTI_PHASE1_LINE4);
        printf(TEXT_PENALTI_PHASE1_LINE5);
        printf(TEXT_PENALTI_PHASE1_LINE6);
    }else if (intPhase == 6)
    {
        printf(TEXT_PENALTI_PHASE6_LINE1);
        printf(TEXT_PENALTI_PHASE6_LINE2);
        printf(TEXT_PENALTI_PHASE6_LINE3);
        printf(TEXT_PENALTI_PHASE6_LINE4);
        printf(TEXT_PENALTI_PHASE6_LINE5);
        printf(TEXT_PENALTI_PHASE6_LINE6);
    }
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

void gamePenalti()
{
    char chrClubName[3];
    int intScoreUser = 0, intScoreCpu = 0, intUserChoice, intCpuChoice;
    srand(time(NULL));

    printf(TEXT_PENALTI_INPUT);
    scanf(" %s", chrClubName);

    while((intScoreUser - intScoreCpu <= 3) || (intScoreCpu-intScoreUser <= 3))
    {
        intUserChoice = 0;
        intCpuChoice = rand() % 6 + 1;
        printf(TEXT_PENALTI_SCORE);
        printBaliza(intUserChoice);

        printf(TEXT_PENALTI_CHOICE);
        scanf("%d", &intUserChoice);

        if(intUserChoice != intCpuChoice)
        {
              intScoreUser += 1;
        }

        printBaliza(intUserChoice);
    }
}

void main()
{
    char chrMenuOption;

    printMenu();
    scanf(" %c", &chrMenuOption);

    switch(chrMenuOption)
    {
        case '1':
            gameHiLow();
            break;
        case '2':
            gamePenalti();
            break;
        default:
            printf("teste");
            break;
    }



}