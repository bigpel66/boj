#include <iostream>
#include <vector>
#include <stack>
#define endl "\n"

std::vector<std::string> parenthesisCollection;
size_t numberOfParenthesis;

void inputAction()
{
    std::cin >> numberOfParenthesis;

    for (size_t i = 0; i < numberOfParenthesis; i++)
    {
        std::string temp;
        std::cin >> temp;
        parenthesisCollection.push_back(temp);
    }
}

void outputAction()
{
    for (size_t i = 0; i < numberOfParenthesis; i++)
    {
        std::stack<char> parenthesisStack;

        parenthesisStack.push(parenthesisCollection[i][0]);

        for (size_t j = 1; j < parenthesisCollection[i].length(); j++)
        {

            if (!parenthesisStack.empty() && parenthesisStack.top() == '(' && parenthesisCollection[i][j] == ')')
            {
                parenthesisStack.pop();
            }
            else
            {
                parenthesisStack.push(parenthesisCollection[i][j]);
            }
        }

        if (parenthesisStack.empty())
        {
            std::cout << "YES" << endl;
        }
        else
        {
            std::cout << "NO" << endl;
        }
    }
}

void solution()
{
    inputAction();
    outputAction();
}

int main(void)
{
    solution();

    return 0;
}
