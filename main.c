/*
Ismat - Engenheria Informática 1º Ano
Fundamentos de Programação - Prof. Francisco Pereira
Leandro Fonseca
10/01/2021 - 23:27
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
#define TEXT_MENU_PRINT_OPT2 "2. - Jogo de Penaltis\n"
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
#define TEXT_PENALTI_PHASE2_LINE4 "\n\t |           / \\           |"
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
#define TEXT_PENALTI_PHASE6_LINE6 "\n\t |                    \\    |"

#define TEXT_PENALTI_REGRAS_LINE1 "\nRegras do Jogo Penálti:"
#define TEXT_PENALTI_REGRAS_LINE2 "\n-O jogo é simples, objetivo é marcar golo na baliza"
#define TEXT_PENALTI_REGRAS_LINE3 "\n-Para rematar basta introduzir o numero referente ao local onde deseja rematar"
#define TEXT_PENALTI_REGRAS_LINE4 "\n-A pontuacao é atualizada a seguir a cada remate"
#define TEXT_PENALTI_REGRAS_LINE5 "\n-Espero que se divirta!"

#define TEXT_PENALTI_GOAL1 "    ______          __ \n"
#define TEXT_PENALTI_GOAL2 "  .' ___  |        [  |   \n"
#define TEXT_PENALTI_GOAL3 " / .'   \\_|   .--.  | |  .--.    \n"
#define TEXT_PENALTI_GOAL4 " | |   ____ / .'`\\ \\| |/ .'`\\ \\  \n"
#define TEXT_PENALTI_GOAL5 " \\ `.___]  || \\__. || || \\__. | \n"
#define TEXT_PENALTI_GOAL6 "  `._____.'  '.__.'[___]'.__.'  \n\n"


#define TEXT_PENALTI_SCORE "\n%s | %d - %d | CPU"
#define TEXT_PENALTI_INPUT "\n\nEscolha o nome do seu clube(Ex:SLB;FCP;SCP): "
#define TEXT_PENALTI_CHOICE "\nEscolha uma posicao para rematar (1-Canto Superior Esquerdo 2-Central Superior 3-Canto Superior Direito 4-Canto Inferior Esquerdo 5-Remate a Figura 6-Canto Inferior Direito): "
#define TEXT_CONTINUE_OPTION "\nDeseja continuar a jogar(s-Sim, n-Não): "


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

void printRegrasPenalti(){
    printf(TEXT_PENALTI_REGRAS_LINE1);
    printf(TEXT_PENALTI_REGRAS_LINE2);
    printf(TEXT_PENALTI_REGRAS_LINE3);
    printf(TEXT_PENALTI_REGRAS_LINE4);
    printf(TEXT_PENALTI_REGRAS_LINE5);
}

void printGoal(){
    printf(TEXT_PENALTI_GOAL1);
    printf(TEXT_PENALTI_GOAL2);
    printf(TEXT_PENALTI_GOAL3);
    printf(TEXT_PENALTI_GOAL4);
    printf(TEXT_PENALTI_GOAL5);
    printf(TEXT_PENALTI_GOAL6);
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

int checkContinue()
{
    char chrCheckContinue = '\0';
    int intContinue = 0;
    printf(TEXT_CONTINUE_OPTION);
    scanf(" %c", &chrCheckContinue);

    if(chrCheckContinue == 115){
        intContinue = 1;
    }
    if (chrCheckContinue == 110){
        intContinue = 0;
    }
    return intContinue;
}

void gameHiLow()
{
    int intToGuess = 0, intFailedCounter = 0, intUserResult = 0;
    srand(time(NULL));

    intToGuess = rand() % 100 + 1;
    printf("\n%d",intToGuess);

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
    char chrClubName[10] = "\0";
    int intScoreUser = 0, intScoreCpu = 0, intUserChoice = 0, intCpuChoice = 0, intFlag = 1;
    srand(time(NULL));

    printRegrasPenalti();
    printf(TEXT_PENALTI_INPUT);
    scanf("%s", chrClubName);

    while(intFlag != 0)
    {
        intUserChoice = 0;
        intCpuChoice = rand() % 6 + 1;
        printf(TEXT_PENALTI_SCORE, chrClubName, intScoreUser, intScoreCpu);
        printBaliza(intUserChoice);

        printf(TEXT_PENALTI_CHOICE);
        scanf("%d", &intUserChoice);

        if(intUserChoice == intCpuChoice)
        {
            intScoreCpu += 1;
        }else
        {
            intScoreUser += 1;
            printGoal();
        }

        printBaliza(intCpuChoice);
        printf(TEXT_PENALTI_SCORE, chrClubName, intScoreUser, intScoreCpu);
        intFlag = checkContinue();
    }
}

int main()
{
    char chrMenuOption;
    int intExit = 1;

    while (intExit != 0){

        printMenu();
        scanf(" %c", &chrMenuOption);

        switch(chrMenuOption)
        {
            case '0':
                intExit = 0;
                break;

            case '1':
                gameHiLow();
                break;
            case '2':
                gamePenalti();
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    }


    return 0;

}