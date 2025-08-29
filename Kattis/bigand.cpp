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

    int size, delay1, delay2;
    cin >> size >> delay1 >> delay2;

    multiset<long long> values;
    for (int i = 0; i < size; i++) {
        long long value;
        cin >> value;

        values.insert(value);
    }

    while (values.size() > 1) {
        values.erase(values.begin());
        values.insert(*values.begin() + delay1);
        values.erase(values.begin());
    }

    cout << *values.begin() + delay2;
}