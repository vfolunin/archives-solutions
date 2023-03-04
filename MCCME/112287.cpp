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

    int resI = 0, resJ = 1;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (abs(a[resI] - a[resJ]) >= abs(a[i] - a[j])) {
                resI = i;
                resJ = j;
            }
        }
    }

    for (int value : a)
        cout << value << " ";
    cout << "\n";

    cout << resI + 1 << " " << resJ + 1;
}