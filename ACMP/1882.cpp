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

    int size, sum;
    cin >> size >> sum;

    set<int> values;
    int need = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (values.count(value))
            continue;

        values.insert(value);
        need += sum / value + 1;
        if (need > sum) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}