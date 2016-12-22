#include <iostream>

int get_change(int m) {
    int a[] = {10, 5, 1};
    int i = 0;
    int coins = 0;
    while(m > 0){
        while(m >= a[i]){
            coins++;
            m -= a[i];
        }
        i++;
    }
    return coins;
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
