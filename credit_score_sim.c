#include <stdio.h>   //<-- Para função printf
#include <string.h>  //<-- Para uso com string e função strlen()
#include <ctype.h>   //<-- Para função toupper()
#include <Windows.h> //<-- Para função system()
// #include <conio.h> // pensando aqui se devo realmente usá-lo **

// function prototype
char GetCharInput(char *chr, int size);

void RunningCreditCheck(char *input, float *coin);

void ExitProgram(char *input, int *attempts);

void message();

int main()
{
    system("chcp 65001");

    char input[2];

    float coin = 120.0;

    int attempts = 0;

    printf("\n\n****************************\n");
    printf(" ** SIMULADOR DE CRÉDITO ** \n");
    printf("  ************************ \n\n");

    while (1)
    {

        printf("Deseja transferir alguns créditos? (y:sim) ou (n:não):");

        GetCharInput(input, 2);

        if (attempts == 2)
            ExitProgram(input, &attempts);
        else if (toupper(input[0]) == 'Y')
        {
            RunningCreditCheck(input, &coin);
            break;
        }
        else if (toupper(input[0]) == 'N')
            break;
        else
        {
            printf("Opção incorreta.\n");
            attempts++;
            system("pause");
        }
    }

    return 0;
}

// function definition

char GetCharInput(char *chr, int size)
{
    int i = 0;

    while ((chr[i] = getchar()) != '\n' && i < size)
        i++;

    chr[++i] = '\0';
}

void ExitProgram(char *input, int *attempts)
{
    printf("Você excedeu o número de tentativas para esta ação.\n");
    printf("Deseja encerrar o programa (y:sim) ou (n:não)?:");
    while (1)
    {
        GetCharInput(input, 2);
        system("pause");

        if (toupper(input[0]) == 'Y')
            exit(0);
        else if (toupper(input[0]) == 'N')
        {
            *attempts = 0;
            break;
        }
        else
            printf("Informe (y:sim) ou (n:não)?:");
    }
}

void RunningCreditCheck(char *input, float *coin)
{
    float credits = 0.0;

    int run = 1;

    while (run)
    {

        system("cls");
        printf("\n\nTotal em créditos: %.2f\n\n", *coin);
        printf("Selecione uma operação [x]\n\n");
        printf("[1] > Crédito: 15.5\n");
        printf("[2] > Crédito: 25.5\n");
        printf("[3] > Crédito: 50.5\n");
        printf("[4] > Sair\n\n_");
        GetCharInput(input, 2);
        system("pause");

        switch (input[0])
        {
        case '1':
            credits = 15.5;
            if (*coin < credits)
            {
                message();
                continue;
            }

            *coin -= credits;

            break;

        case '2':

            credits = 25.5;

            if (*coin < credits)
            {
                message();
                continue;
            }

            *coin -= credits;

            break;

        case '3':

            credits = 50.5;

            if (*coin < credits)
            {
                message();
                continue;
            }

            *coin -= credits;
            break;

        case '4':
            run = 0;
            break;

        default:
            printf("Opção incorreto!!!\n");
            system("pause");
        }
    }
}

void message()
{
    printf("Créditos insuficientes para esta operação.\n");
    printf("Escolha uma outra opção de crédito.\n\n");
    system("pause");
}