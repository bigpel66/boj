#include <iostream>
using namespace std;

int gcd(int a, int b);

int main(){
    int a, b;
    cin >> a >> b;
    
    cout << gcd(a, b) << "\n" << a * b / gcd(a, b);
}

int gcd(int a, int b)
{
    return (a%b == 0 ? b : gcd(b, a%b));
}
