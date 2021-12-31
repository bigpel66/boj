#include <iostream>
#include <vector>
#define endl "\n"

int numberOfRows;
int numberOfCols;
int flipCount = 0;

std::vector<std::string> aMatrix;
std::vector<std::string> bMatrix;

void setMatrix(std::vector<std::string> &inputMatrix)
{
    for (int i = 0; i < numberOfRows; i++)
    {
        std::string temp;
        std::cin >> temp;

        inputMatrix.push_back(temp);
    }
}

void inputAction()
{
    std::cin >> numberOfRows >> numberOfCols;

    setMatrix(aMatrix);
    setMatrix(bMatrix);
}

void flip3on3Matrix(int rowOffset, int colOffset)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            aMatrix[rowOffset + i][colOffset + j] == '0' ? aMatrix[rowOffset + i][colOffset + j] = '1' : aMatrix[rowOffset + i][colOffset + j] = '0';
        }
    }
}

void flipByComp()
{

    for (int i = 0; i < numberOfRows - 2; i++)
    {
        for (int j = 0; j < numberOfCols - 2; j++)
        {
            if (aMatrix[i][j] != bMatrix[i][j])
            {
                flip3on3Matrix(i, j);
                ++flipCount;
            }
        }
    }
}

bool identityCheck()
{
    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfCols; j++)
        {
            if (aMatrix[i][j] != bMatrix[i][j])
            {
                std::cout << -1;
                return false;
            }
        }
    }

    return true;
}

// void outputAction(std::vector<std::string> &inputMatrix)
// {

//     for (int i = 0; i < numberOfRows; i++)
//     {
//         std::cout << inputMatrix[i] << endl;
//     }
// }

void solution()
{
    inputAction();
    flipByComp();

    if (identityCheck())
    {
        std::cout << flipCount;
    }
}

int main(void)
{
    solution();

    return 0;
}
