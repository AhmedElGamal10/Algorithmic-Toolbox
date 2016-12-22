#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int n;
int capacity;
vector< pair<double,int> > unit_price_number;
bool pairCompare(const std::pair<double, int>& firstElem, const std::pair<double, int>& secondElem) {
    return firstElem.first > secondElem.first;

}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    for(int i=0 ; i<n ; i++){
        unit_price_number.push_back(make_pair((double)values[i]/(double)weights[i], weights[i]));
    }
    std::sort(unit_price_number.begin(), unit_price_number.end(), pairCompare);

    for(int i= 0 ; i < n ; i++){
//        cout<< unit_price_number[i].first << " " << unit_price_number[i].second << endl;
    }

    int i = 0;
    while(i < n){
        while(unit_price_number[i].second > 0 && capacity > 0){
            int taken_amount = min(capacity, unit_price_number[i].second);
            value += taken_amount*unit_price_number[i].first;
            capacity -= taken_amount;
            unit_price_number[i].second -= taken_amount;
        }
        i++;
    }
    //sort the vector descending upon unit price
    return value;
}

int main() {

    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
