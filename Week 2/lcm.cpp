#include <iostream>

long long gcd_fast(long long a, long long b) {
    if (b == 0)
        return a;

    return gcd_fast(b, a % b);
}

long long lcm_fast(long long a, long long b) {
    long long gcd = gcd_fast(a, b);
    long long temp = (a * b);
    return temp / gcd;
}

int main() {
    long long a, b;
    std::cin >> a >> b;
    std::cout << lcm_fast(a, b) << std::endl;
    return 0;
}
