#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r, size;
    cin >> l >> r >> size;

    vector<int> a(size);

    minstd_rand generator;
    uniform_int_distribution<int> distr(l, r);
    for (int &value : a)
        value = distr(generator);

    int minSum = a[0] + a[1], minIndex = 0;
    for (int i = 1; i + 1 < a.size(); i++) {
        if (minSum >= a[i] + a[i + 1]) {
            minSum = a[i] + a[i + 1];
            minIndex = i;
        }
    }

    for (int value : a)
        cout << value << " ";
    cout << "\n";

    cout << minIndex + 1 << " " << minIndex + 2;
}