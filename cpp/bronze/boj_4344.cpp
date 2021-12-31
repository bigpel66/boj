#include <iostream>

int main()
{
    int case_num;
    int std_num;
    int sum;
    int count;
    double avg;
    double *score;

    std::cin >> case_num;

    for(int i = 0; i < case_num; i++)
    {
        sum = 0;
        avg = 0;
        count = 0;

        std::cin >> std_num;
        score = new double[std_num];

        for(int j = 0; j < std_num; j++)
        {
            std::cin >> score[j];
            sum += score[j];
        }

        avg = (double) sum / std_num;

        for(int j = 0; j < std_num; j++)
        {
            if(score[j] > avg)
                count++;
        }

        std::cout << std::fixed;
        std::cout.precision(3);
        std::cout << ((double) count / std_num) * 100 << "%" << "\n";

        delete []score;
    }

    return 0;
}
