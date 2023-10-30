#include <stdio.h>   //<-- Para função printf
#include <string.h>  //<-- Para uso com string e função strlen()
#include <ctype.h>   //<-- Para função toupper()
#include <Windows.h> //<-- Para função system()
// #include <conio.h> // pensando aqui se devo realmente usá-lo **

// function prototype
char GetCharInput(char *chr, int size);

int main()
{

    system("chcp 65001");

    char input[2];

    int attempts = 0;

    while (1)
    {

        printf("Você concorda em doar 5%% do seu tempo para estudo? (y:sim) ou (n:não):");

        GetCharInput(input, 2);

        if (attempts == 2)
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
                    attempts = 0;
                    break;
                }
                else
                    printf("Informe (y:sim) ou (n:não)?:");
            }
        }
        else if (toupper(input[0]) == 'Y')
            break;
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