#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<long long, long long> count;
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        long long value;
        cin >> value;

        count[value]++;
        sum += value;
    }

    int queryCount;
    cin >> queryCount;

    long long add = 0;
    for (int i = 0; i < queryCount; i++) {
        string type;
        long long value;
        cin >> type >> value;

        if (type == "SET") {
            long long newValue;
            cin >> newValue;

            if (value != newValue && count.count(value - add)) {
                sum += count[value - add] * (newValue - value);
                count[newValue - add] += count[value - add];
                count.erase(value - add);
            }
        } else {
            add += value;
            sum += size * value;
        }

        cout << sum << "\n";
    }
}