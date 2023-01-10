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
    int count = 0;

    minstd_rand generator;
    uniform_int_distribution<int> distr(l, r);
    for (int &value : a) {
        value = distr(generator);
        count += 100 <= value && value <= 999 && value % 5 != 0;
    }

    for (int value : a)
        cout << value << " ";
    cout << "\n";

    cout << count << "\n";
}