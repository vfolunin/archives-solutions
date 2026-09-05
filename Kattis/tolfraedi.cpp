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

    int queryCount;
    cin >> queryCount;

    multiset<int> values;
    double sum = 0;

    for (int i = 0; i < queryCount; i++) {
        char type;
        int value;
        cin >> type >> value;

        if (type == 'A') {
            values.insert(value);
            sum += value;
        } else {
            values.erase(values.find(value));
            sum -= value;
        }

        if (values.empty())
            cout << "-1 -1 -1\n";
        else
            cout << *values.begin() << " " << *prev(values.end()) << " " << fixed << sum / values.size() << "\n";
    }
}