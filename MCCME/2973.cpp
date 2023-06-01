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

    int size;
    cin >> size;

    vector<int> a(2 * size);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());

    if (count(a.begin(), a.end(), a[size - 1]) >= size) {
        cout << a[size - 1] << " 0";
        return 0;
    }

    if (count(a.begin(), a.end(), a[size]) >= size) {
        cout << a[size] << " 0";
        return 0;
    }

    minstd_rand generator;
    while (1) {
        int i = generator() % a.size();
        int j = generator() % a.size();
        if (i == j)
            continue;

        long long x = a[i], d = abs(a[i] - a[j]);
        while (binary_search(a.begin(), a.end(), x - d))
            x -= d;

        long long count = 1, y = x;
        while (binary_search(a.begin(), a.end(), y + d)) {
            count++;
            y += d;
        }

        if (count >= size) {
            cout << x << " " << d;
            break;
        }
    }
}