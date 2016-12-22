#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n;

bool pairCompare(const std::pair<int, int>& firstElem, const std::pair<int, int>& secondElem) {
    return firstElem.first < secondElem.first;
}

vector<int> optimal_points(vector <pair <int,int> > &segments) {
    vector<int> points;
    std::sort(segments.begin(), segments.end(), pairCompare);
    for(int i= 0 ; i < n ; i++){
        //cout<< segments[i].first << " " << segments[i].second << endl;
    }

    while(segments.size() > 0) {
        int last_point = segments[segments.size() - 1].first;
        points.push_back(last_point);
        for (int i = segments.size() - 1; i >= 0; i--) {
            if (last_point >= segments[i].first && last_point <= segments[i].second){
                segments.erase(segments.begin() + i);
            }
        }
    }
    return points;
}

int main() {
    std::cin >> n;
    vector <pair <int,int> > segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].first >> segments[i].second;
    }
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}
