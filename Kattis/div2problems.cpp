#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, badCount;
    cin >> size >> badCount;

    unordered_set<string> bad;
    for (int i = 0; i < badCount; i++) {
        string s;
        cin >> s;

        bad.insert(s);
    }

    for (int i = 1; i <= size; i++) {
        int count;
        cin >> count;

        bool ok = 1;
        for (int j = 0; j < count; j++) {
            string s;
            cin >> s;

            ok &= !bad.contains(s);
        }

        if (ok)
            cout << i << " ";
    }
}