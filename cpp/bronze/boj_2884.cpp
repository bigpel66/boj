#include <iostream>

int main() {
    int hour, minute;
    
    std::cin >> hour >> minute;
    
    if(minute < 45) {
        minute = minute + 15;
        if(hour == 0){
            hour = 23;
        } else {
            hour = hour - 1;
        }
    } else {
        minute = minute - 45;
    }
    
    std::cout << hour << ' ' << minute;
    
    return 0;
}
