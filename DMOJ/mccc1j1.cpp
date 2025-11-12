#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a(4);
    for (int &value : a)
        cin >> value;

    auto [minIt, maxIt] = minmax_element(a.begin(), a.end());

    cout << *minIt << "\n" << *maxIt << "\n";
}