#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using std::vector;
int count[1000000000 + 5];
int get_majority_element(vector<int> &a, int left, int right) {
  int n = a.size();
  for(int i=0 ; i<n; ++i){
    count[a[i]]++;
  }

  for(int i=0 ; i<n; ++i){
    if(count[a[i]] > (n/2))
      return a[i];
  }

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
