#include <stdio.h>

void ExecuteOperationGIP(char label, int *val, int *calc, int size);

void Display(char label, int *val, int *calc, int size);

int main()
{
    int calc[3];

    int size = 3;

    int x[] = {3, 6, 2, 30};

    int y[] = {90, 45, 135, 9};

    ExecuteOperationGIP('x', x, calc, size);

    ExecuteOperationGIP('y', y, calc, size);

    return 0;
}

void Display(char label, int *val, int *calc, int size)
{
    printf("\n%c: ", label);

    for (size_t i = 0; i < 4; i++)
    {
        if (i < 3)
        {
            printf("(%i %c %i = %i)", val[i], (val[i] < val[i + 1] ? '*' : '/'), val[i + 1], calc[i]);

            if (i < 2)
                printf(" |> ");
        }
    }

    printf("\n");
}

void ExecuteOperationGIP(char label, int *val, int *calc, int size)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (i < 3)
        {
            calc[i] = (val[i] < val[i + 1]) ? val[i] * val[i + 1] : val[i] / val[i + 1];
        }
    }

    Display(label, val, calc, size);
}
