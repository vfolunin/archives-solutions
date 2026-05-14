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

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    auto [minIt, maxIt] = minmax_element(a.begin(), a.end());

    cout << max({ minIt - a.begin(), a.end() - minIt - 1, maxIt - a.begin(), a.end() - maxIt - 1 });
}