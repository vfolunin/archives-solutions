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

    for (int i = 0; i < a.size(); i++) {
        double sum = 0;
        for (int j = max(i - 100, 0); j < i + 100 && j < a.size(); j++)
            sum += a[j] / pow(2, abs(i - j));

        cout << fixed << sum << " ";
    }
}