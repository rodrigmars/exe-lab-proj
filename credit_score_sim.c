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
    int available_balance;
} Credits;

// function prototype

char GetCharInput(char *input, int size);

void DisplayTitle();

void MainMenu(char *input, float *current_balance);

void MenuCredit(char *input, float *current_balance);

void ExitProgram(char *input);

void message();

void DisplayCreditsMenu(float *current_balance, Credits credits[][2]);

int main()
{
    system("chcp 65001");

    system("cls");

    char input[2];

    float current_balance = 120.0;

    DisplayTitle();

    MainMenu(input, &current_balance);

    return 0;
}

// function definition

void DisplayTitle()
{
    printf("\n\n");
    printf("****************************");
    printf("\n");
    printf(" ** SIMULADOR DE CRÉDITO ** ");
    printf("\n");
    printf("  ************************ ");
    printf("\n\n");
}

void MainMenu(char *input, float *current_balance)
{

    int attempts = 0;

    while (1)
    {

        printf("Deseja adquirir alguns créditos? (y:sim) ou (n:não):");

        GetCharInput(input, 2);

        if (attempts == 2)
        {
            ExitProgram(input);
            attempts = 0;
        }
        else if (toupper(input[0]) == 'Y')
        {
            MenuCredit(input, current_balance);
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
}

char GetCharInput(char *input, int size)
{
    int i = 0;

    while ((input[i] = getchar()) != '\n' && i < size)
        i++;

    input[++i] = '\0';
}

void ExitProgram(char *input)
{
    printf("\nVocê excedeu o número de tentativas para esta ação.\n");

    printf("Deseja encerrar o programa (y:sim) ou (n:não)?:");

    while (1)
    {
        GetCharInput(input, 2);

        system("pause");

        if (toupper(input[0]) == 'Y')
        {
            system("cls");
            exit(0);
        }
        else if (toupper(input[0]) == 'N')
            break;

        printf("Informe (y:sim) ou (n:não)?:");
    }
}

void MenuCredit(char *input, float *current_balance)
{
    Credits credits[3][2] = {{15.5, 1}, {25.5, 1}, {50.5, 1}};

    int run = 1;
    // 1:true
    // 0:false

    while (run)
    {
        system("cls");
        DisplayCreditsMenu(current_balance, credits);
        GetCharInput(input, 2);
        system("pause");

        switch (input[0])
        {
        case '1':
            if (*current_balance < credits[0]->credit)
            {
                message();
                credits[0]->available_balance = 0;
                continue;
            }

            *current_balance -= credits[0]->credit;

            break;

        case '2':

            if (*current_balance < credits[1]->credit)
            {
                message();
                credits[1]->available_balance = 0;
                continue;
            }

            *current_balance -= credits[1]->credit;

            break;

        case '3':

            if (*current_balance < credits[2]->credit)
            {
                message();
                credits[2]->available_balance = 0;
                continue;
            }

            *current_balance -= credits[2]->credit;

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

void DisplayCreditsMenu(float *balance, Credits credits[][2])
{
    printf(KYEL "\n\nTotal em créditos: " KGRN "%.2f\n\n", *balance);
    printf(KYEL "Selecione uma operação [x]\n\n");

    for (size_t i = 0; i < 3; i++)
    {
        credits[i]->credit <= *balance ? printf(KGRN) : printf(KRED);

        printf("[%i] > Crédito: %.2f\n", i + 1, credits[i]->credit);
    }

    printf(KYEL "[4] > Sair\n\n_" KWHT);
}

void message()
{
    printf("Saldo insuficiente para esta operação.\n\n");
    system("pause");
}
