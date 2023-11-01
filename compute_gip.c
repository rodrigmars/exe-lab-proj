#include <stdio.h>

void ExecuteCalc(char label, int *val, int *calc, int size);

void Display(char label, int *calc, int size);

int main()
{
    int x[] = {3, 6, 2, 30};

    int y[] = {90, 45, 135, 9};

    int calc[3];

    ExecuteCalc('x', x, calc, 3);

    ExecuteCalc('y', y, calc, 3);

    return 0;
}

void Display(char label, int *calc, int size)
{
    printf("%c: ", label);

    for (size_t i = 0; i < size; i++)
        if (i < 2)
            printf("%i%c ", calc[i], ',');
        else
            printf("%i", calc[i]);

    printf("\n");
}

void ExecuteCalc(char label, int *val, int *calc, int size)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (i < 3)
        {
            calc[i] = (val[i] < val[i + 1]) ? val[i] * val[i + 1] : val[i] / val[i + 1];
        }
    }

    Display(label, calc, size);
}
