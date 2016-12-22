#include <iostream>
#include <cstring>

using namespace std;

int fib[1000000] = {-1};

int fibonacci_fast(int n) {
    if(fib[n] != -1)
        return fib[n];
    else
        return fib[n] = (fibonacci_fast(n-1) + fibonacci_fast(n-2))%10;
}

int get_fibonacci_last_digit_naive(int n) {
    fibonacci_fast(60);
    return fib[n%60];
}

int main() {
    int n = 0;
    memset(fib, -1, sizeof(fib));
    fib[0] = 0;
    fib[1] = 1;

    std::cin >> n;

    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';

    return 0;
}