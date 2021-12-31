#include <iostream>
#include <vector>
#define lld long long
#define matrix std::vector<std::vector<lld>>
#define endl '\n'

int matrixNumber;
lld squareNumber;
matrix inputMatrix(5, std::vector<lld>(5));
matrix resultMatrix(5, std::vector<lld>(5));

matrix operator*(matrix formerMatrix, matrix latterMatrix)
{
    int size = formerMatrix.size();

    matrix operatedMatrix(matrixNumber, std::vector<lld>(matrixNumber));

    for (int i = 0; i < matrixNumber; i++)
    {
        for (int j = 0; j < matrixNumber; j++)
        {
            for (int k = 0; k < matrixNumber; k++)
            {
                operatedMatrix[i][j] += (formerMatrix[i][k] * latterMatrix[k][j]);
            }

            operatedMatrix[i][j] %= 1000;
        }
    }

    return operatedMatrix;
}

void input()
{
    std::cin >> matrixNumber >> squareNumber;

    for (int i = 0; i < matrixNumber; i++)
    {
        for (int j = 0; j < matrixNumber; j++)
        {
            std::cin >> inputMatrix[i][j];
        }
        resultMatrix[i][i] = 1;
    }
}

void getAnswerMatrix()
{
    while (squareNumber)
    {
        if (squareNumber % 2 == 1)
        {
            resultMatrix = resultMatrix * inputMatrix;
        }

        inputMatrix = inputMatrix * inputMatrix;
        squareNumber /= 2;
    }
}

void output()
{
    for (int i = 0; i < matrixNumber; i++)
    {
        for (int j = 0; j < matrixNumber; j++)
        {
            std::cout << resultMatrix[i][j] << ' ';
        }
        std::cout << endl;
    }
}

void solution()
{
    input();
    getAnswerMatrix();
    output();
}

int main()
{
    solution();
    return 0;
}
