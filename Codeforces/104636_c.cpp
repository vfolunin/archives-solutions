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

    vector<int> a(size);
    for (int &value : a) {
        for (int i = 0; i < 4; i++) {
            int score;
            cin >> score;

            value += score;
        }
    }

    vector<int> order(a.size());
    iota(order.begin(), order.end(), 0);
    stable_sort(order.begin(), order.end(), [&](int lhs, int rhs) {
        return a[lhs] > a[rhs];
    });

    cout << find(order.begin(), order.end(), 0) - order.begin() + 1 << "\n";
}