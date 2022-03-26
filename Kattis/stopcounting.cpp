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

    double maxRatio = 0, sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
        maxRatio = max(maxRatio, sum / (i + 1));
    }

    sum = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        sum += a[i];
        maxRatio = max(maxRatio, sum / (a.size() - i));
    }

    cout << fixed << maxRatio;
}