#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Wrong arg count\n");
        for(int i = 0; i < argc; i++)
        {
            fprintf(stderr, "argv[%i] = %s\n", i, argv[i]);
        }
        return EXIT_FAILURE;
    }

    char op = 0;
    double a = 0;
    double b = 0;
    a = atof(argv[1]);
    op = argv[2][0];
    b = atof(argv[3]);
    double result = 0;
    switch (op)
    {
        case '+':
            result = a + b;
            break;

        case '-':
            result = a - b;
            break;

        case 'x':
            result = a * b;
            break;

        case '/':
            if(b == 0)
            {
                fprintf(stderr, "Division by zero\n");
                return EXIT_FAILURE;
            }
            result = a / b;
            break;

        default:
            fprintf(stderr, "Wrong operator\n");
            return EXIT_FAILURE;
    }

    printf("%g\n", result);
    return EXIT_SUCCESS;
}
