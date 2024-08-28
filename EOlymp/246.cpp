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

    vector<double> a(size);
    iota(a.begin(), a.end(), 1);

    while (a.size() > 1) {
        vector<double> b(a.size() - 1);
        for (int i = 0; i < b.size(); i++) {
            b[i] = a[i] * a[i + 1];
            while (b[i] > 1e15)
                b[i] /= 10;
        }
        a.swap(b);
    }

    cout << to_string(a[0])[0];
}