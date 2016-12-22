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

int get_fibonacci_sum_last_digit(long long n){
    fibonacci_fast(60);
    long long sum = 0;
    long long full_cycles_no = n/60;

    if(full_cycles_no > 0)
        for(int i=0 ; i<60 ; i++){
            sum += full_cycles_no*fib[i];
            sum = sum%10;
        }

    int remainder = n%60;
    for(int i=0 ; i<=remainder ; i++){
        sum += fib[i];
        sum = sum%10;
    }


    return sum;
}

int main() {
    long long n = 0;
    memset(fib, -1, sizeof(fib));
    fib[0] = 0;
    fib[1] = 1;

    std::cin >> n;

    int c = get_fibonacci_sum_last_digit(n);
    std::cout << c << '\n';

    return 0;
}