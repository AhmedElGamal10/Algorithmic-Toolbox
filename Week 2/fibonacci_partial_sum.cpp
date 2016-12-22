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

long long get_fibonacci_partial_sum_fast(long long a, long long b){
    fibonacci_fast(60);
    long long sum = 0;
    long long full_cycles_no = (b-a+1)/60;

    if(full_cycles_no > 0)
        for(int i=0 ; i<60 ; i++){
            sum += (full_cycles_no%10)*fib[i];
            sum = sum%10;
        }

    int remainder = (b-a+1)%60;
    for(long long i=a ; i<a+remainder ; i++){
        sum += fib[i%60];
        sum = sum%10;
    }


    return sum;
}

int main() {
    long long a,b;
    memset(fib, -1, sizeof(fib));
    fib[0] = 0;
    fib[1] = 1;

    std::cin >> a >> b;

    long long c = get_fibonacci_partial_sum_fast(a,b);
    std::cout << c << '\n';

    return 0;
}