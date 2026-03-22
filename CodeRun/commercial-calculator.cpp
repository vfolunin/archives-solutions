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

    multiset<int> values;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        values.insert(value);
    }

    double res = 0;
    while (values.size() > 1) {
        int a = *values.begin();
        values.erase(values.begin());
        int b = *values.begin();
        values.erase(values.begin());
        res += (a + b) * 0.05;
        values.insert(a + b);
    }

    cout.precision(2);
    cout << fixed << res;
}