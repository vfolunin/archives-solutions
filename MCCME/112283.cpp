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
    vector<double> sum(2), count(2);

    minstd_rand generator;
    uniform_int_distribution<int> distr(l, r);
    for (int &value : a) {
        value = distr(generator);
        sum[value >= 50] += value;
        count[value >= 50]++;
    }

    for (int value : a)
        cout << value << " ";
    cout << "\n";

    cout.precision(3);
    for (int i = 0; i < 2; i++) {
        if (count[i])
            cout << fixed << sum[i] / count[i] << " ";
        else
            cout << "0 ";
    }
}