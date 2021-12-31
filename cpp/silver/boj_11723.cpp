#include <iostream>
#include <string>

int M;
int cmp =0;
int x;
std::string s;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::cin >> M;
    
    for(int i =0; i < M; i++)
    {
        std::cin >> s;
        
        if(s[0] == 'a' && s[1] == 'd') {std::cin >> x; cmp |= (1<<x);}
        if(s[0] == 'a' && s[1] == 'l') {cmp = (1<<21) - 1;}
        if(s[0] == 'r') {std::cin >> x; cmp &= ~(1<<x);}
        if(s[0] == 't') {std::cin >> x; cmp ^= (1<<x);}
        if(s[0] == 'c') {std::cin >> x; (cmp&(1<<x)) == 0? std::cout << 0 : std::cout << 1; std::cout << '\n';}
        if(s[0] == 'e') {cmp =0;}
    }
    
    return 0;
}
