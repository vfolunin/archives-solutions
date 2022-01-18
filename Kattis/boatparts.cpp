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

    int partCount, dayCount;
    cin >> partCount >> dayCount;

    set<string> parts;

    for (int i = 0; i < dayCount; i++) {
        string part;
        cin >> part;

        parts.insert(part);
        if (parts.size() == partCount) {
            cout << i + 1;
            return 0;
        }
    }

    cout << "paradox avoided\n";
}