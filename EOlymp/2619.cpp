#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> p(size);
    for (int &value : p)
        cin >> value;

    partial_sum(p.begin(), p.end(), p.begin());

    if (p.back() % 2) {
        cout << -1;
        return 0;
    }

    auto it = find(p.begin(), p.end(), p.back() / 2);

    cout << (it < p.end() ? it - p.begin() + 1 : -1);
}