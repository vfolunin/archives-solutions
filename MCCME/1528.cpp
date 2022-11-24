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

    vector<double> a(size);
    for (double &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    double num = 0, den = 0;
    for (int i = 1; i + 1 < a.size(); i++) {
        num += a[i];
        den++;
    }

    cout << fixed << num / den;
}