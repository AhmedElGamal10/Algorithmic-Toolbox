#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    int i = 0;
    int sum = 0;
    while(n > 0){
        i++;
        if((n-i) <= i) {
            summands.push_back(n);
            break;
        }
        n = n-(i);
        summands.push_back(i);
        sum += i;
    }
    return summands;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
}
