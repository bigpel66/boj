#include <iostream>
using namespace std;

int gcd(int a, int b);

int main() {
    int a, b;
    int num;
    
    cin >> num;
    
    while(num-- > 0){
        cin >> a >> b;
        cout << a * b / gcd(a, b) << "\n";
    }
}

int gcd(int a, int b)
{
    return (a % b == 0? b : gcd(b, a%b));
}
