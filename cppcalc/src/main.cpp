#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        cerr << "Wrong arg count" << endl;
        for(int i = 0; i < argc; i++)
        {
            cerr << "argv[" << i << "] = " << argv[i] << endl;
        }
        return EXIT_SUCCESS;
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
                cerr << "Division by zero" << endl;
                return EXIT_FAILURE;
            }
            result = a / b;
            break;

        default:
            cerr << "Wrong operator" << endl;
            return EXIT_FAILURE;
    }

    cout << result << endl;
    return EXIT_SUCCESS;
}