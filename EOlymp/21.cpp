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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size, percent;
    cin >> size >> percent;

    multiset<double> values;
    for (int i = 0; i < size; i++) {
        double value;
        cin >> value;
        values.insert(value);
    }

    while (values.size() > 1) {
        double a = *values.begin();
        values.erase(values.begin());
        double b = *values.begin();
        values.erase(values.begin());
        values.insert((a + b) * (1 - percent / 100.0));
    }

    cout << fixed << *values.begin();
}