#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int myCompare(string X, string Y) {
    string XY = X.append(Y);
    string YX = Y.append(X);
    return XY.compare(YX) > 0 ? 1 : 0;
}

vector<string> largest_number(vector<string> &input) {
    sort(input.begin(), input.end(), myCompare);

    for (int i = 0; i < input.size(); i++)
        cout << input[i];

    return input;
}

int main() {
    int n;
    std::cin >> n;
    vector<string> input(n);
    for (size_t i = 0; i < input.size(); i++) {
        std::cin >> input[i];
    }
    largest_number(input);

    return 0;
}
