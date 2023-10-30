#include <stdio.h>   //<-- Para função printf
#include <string.h>  //<-- Para uso com string e função strlen()
#include <ctype.h>   //<-- Para função toupper()
#include <Windows.h> //<-- Para função system()
// #include <conio.h> // pensando aqui se devo realmente usá-lo **

// function prototype
char GetCharInput(char *chr, int size);

void RunningCreditCheck(void);

void ExitProgram(char *input, int *attempts);

int main()
{
    system("chcp 65001");

    char input[2];

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
            RunningCreditCheck();
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

void RunningCreditCheck(void)
{
    printf("Selecione um valor:");

    // GetCharInput();

    return;
}
