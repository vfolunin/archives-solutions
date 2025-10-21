#include <iostream>
#include <algorithm>
#include <cmath>
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

    vector<double> a(size);
    for (double &value : a)
        cin >> value;

    for (int type, i; cin >> type >> i; ) {
        i--;
        if (type == 99) {
            double percentage;
            cin >> percentage;
            percentage /= 100;

            a.insert(a.begin() + i + 1, a[i] * (1 - percentage));
            a[i] *= percentage;
        } else {
            a[i] += a[i + 1];
            a.erase(a.begin() + i + 1);
        }
    }

    for (double value : a)
        cout << (int)round(value) << " ";
}