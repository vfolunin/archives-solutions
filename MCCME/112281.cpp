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

    int l, r, size, sum;
    cin >> l >> r >> size >> sum;

    vector<int> a(size);
    int res = -1;

    minstd_rand generator;
    uniform_int_distribution<int> distr(l, r);
    for (int &value : a) {
        value = distr(generator);
        if (value > 0 && value % 2 == 0 && res < value)
            res = value;
    }

    for (int value : a)
        cout << value << " ";
    cout << "\n";

    cout << res << "\n";
}