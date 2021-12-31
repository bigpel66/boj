#include <iostream>

int note[8];
int asc = 0;
int desc = 0;

int main() {
    for(int i = 0; i < 8; i++) {
        std::cin >> note[i];
    }
    
    for(int i = 0; i < 4; i++) {
        if(note[i] == i + 1 && note[7 - i] ==  8 - i){
            asc++;
        } else if(note[i] == 8 - i && note[7 - i] == i + 1) {
            desc++;
        }
    }
    
    if(asc == 4) {
        std::cout << "ascending";
    } else if(desc == 4) {
        std::cout << "descending";
    } else {
        std::cout << "mixed";
    }
    
    return 0;
}
