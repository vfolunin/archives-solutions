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
    int sum = 0;
    for (int &value : a) {
        cin >> value;
        if (value > 0)
            sum += value;
    }

    auto [l, r] = minmax_element(a.begin(), a.end());
    if (l > r)
        swap(l, r);

    int product = 1;
    for (auto it = l + 1; it != r; it++)
        product *= *it;

    cout << sum << " " << product;
}