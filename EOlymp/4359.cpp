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

    multiset<long long> values;
    for (int i = 0; i < size; i++) {
        long long value;
        cin >> value;

        values.insert(value);
    }

    while (values.size() > 1) {
        long long a = *values.begin();
        values.erase(values.begin());
        long long b = *values.begin();
        values.erase(values.begin());

        values.insert(max(2 * a, b));
    }

    cout << *values.begin();
}