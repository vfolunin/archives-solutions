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

    vector<int> a;
    int value;

    while (cin >> value)
        a.push_back(value);

    auto [minIt, maxIt] = minmax_element(a.begin(), a.end());
    swap(*minIt, *maxIt);

    for (int value : a)
        cout << value << " ";
}