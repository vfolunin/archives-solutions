#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int bitCount, varCount;
    if (!(cin >> bitCount >> varCount))
        return 0;

    vector<string> var(varCount);
    vector<int> size(varCount);
    for (int i = 0; i < varCount; i++)
        cin >> var[i] >> size[i];

    map<string, unsigned long long> value;
    for (int i = 0; i < varCount; i++) {
        unsigned long long val = 0;
        for (int j = 0; j < size[i]; j++) {
            string memPart;
            cin >> memPart;
            for (char c : memPart)
                val = val * 2 + c - '0';
        }
        value[var[i]] = val;
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        string name;
        cin >> name;

        cout << name << "=";
        if (value.count(name))
            cout << value[name];
        cout << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}