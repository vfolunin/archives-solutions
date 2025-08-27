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

    map<long long, int> count;
    for (int i = 0; i < size; i++) {
        long long value;
        cin >> value;

        count[value]++;
    }

    long long a = 1, b = count.rbegin()->first;
    for (auto it = count.rbegin(); it->first > 1 && it != count.rend(); it++) {
        if (it->second > 1 || b % it->first) {
            a = it->first;
            break;
        }
    }

    cout << a << " " << b;
}