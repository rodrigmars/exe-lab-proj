#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"

#include <stdio.h>   //<-- Para função printf
#include <string.h>  //<-- Para uso com string e função strlen()
#include <ctype.h>   //<-- Para função toupper()
#include <Windows.h> //<-- Para função system()

// #include <conio.h> // pensando aqui se devo realmente usá-lo **

typedef struct
{
    float credit;
    int status;
} Credits;

// function prototype
char GetCharInput(char *chr, int size);

void RunningCreditCheck(char *input, float *coin);

void ExitProgram(char *input, int *attempts);

void message();

void DisplayCreditsMenu(float *coin, Credits credits[][2]);

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
    Credits credits[3][2] = {{15.5, 1}, {25.5, 1}, {50.5, 1}};

    int run = 1;
    // 1:true
    // 0:false

    while (run)
    {

        system("cls");
        DisplayCreditsMenu(coin, credits);
        GetCharInput(input, 2);
        system("pause");

        switch (input[0])
        {
        case '1':
            if (*coin < credits[0]->credit)
            {
                message();
                credits[0]->status = 0;
                continue;
            }

            *coin -= credits[0]->credit;

            break;

        case '2':

            if (*coin < credits[1]->credit)
            {
                message();
                credits[1]->status = 0;
                continue;
            }

            *coin -= credits[1]->credit;

            break;

        case '3':

            if (*coin < credits[2]->credit)
            {
                message();
                credits[2]->status = 0;
                continue;
            }

            *coin -= credits[2]->credit;

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

void DisplayCreditsMenu(float *coin, Credits credits[][2])
{
    printf(KYEL "\n\nTotal em créditos: " KGRN "%.2f\n\n", *coin);
    printf(KYEL "Selecione uma operação [x]\n\n");

    for (size_t i = 0; i < 3; i++)
    {
        if (credits[i]->status == 1)
            printf(KGRN "[%i] > Crédito: ", i + 1);
        else
            printf(KRED "[%i] > Crédito: ", i + 1);

        printf("%.2f\n", credits[i]->credit);
    }

    printf(KYEL "[4] > Sair\n\n_" KWHT);
}
