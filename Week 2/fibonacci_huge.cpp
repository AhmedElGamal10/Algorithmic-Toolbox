#include <iostream>
#include <cstring>

using namespace std;

int fib[1000000] = {-1};

long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

int fibonacci_fast(long long  n, long long  m) {
    if(fib[n] != -1)
        return fib[n];
    else
        return fib[n] = (fibonacci_fast(n-1, m) + fibonacci_fast(n-2, m))%m;
}

int get_fibonacci_huge(long long  n, long long  m){
    int length_of_period = get_pisano_period(m);
    fibonacci_fast(length_of_period, m);
    return fib[n%length_of_period];
}

int main() {
    long long n,m;
    memset(fib, -1, sizeof(fib));
    fib[0] = 0;
    fib[1] = 1;

    std::cin >> n >> m;

    int c = get_fibonacci_huge(n,m);
    std::cout << c << '\n';

    return 0;
}
