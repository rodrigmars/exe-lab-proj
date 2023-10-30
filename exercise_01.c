#include <stdio.h>
#include <Windows.h>

char GetCharInput(char *chr, int size)
{
    int i = 0;

    while ((chr[i] = getchar()) != '\n' && i < size)
        i++;

    chr[++i] = '\0';
}

int main()
{

    system("chcp 65001");

    char input[2];

    printf("Você concorda?: ");

    GetCharInput(input, 2);

    if (input[0] == 'y' || input[0] == 'Y')
    {
        printf("Acordado.\n");
    }
    else if (input[0] == 'n' || input[0] == 'N')
    {
        printf("Não acordado.\n");
    }
    else
    {
        printf("Opção não compatível.\n");
    }

    return 0;
}