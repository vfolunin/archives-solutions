#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int diff(const string &a, const string &b) {
    int res = 0;
    for (int i = 0; i < a.size(); i++)
        res += a[i] != b[i];
    return res;
}

bool solve() {
    int studentCount;
    cin >> studentCount;

    if (!studentCount)
        return 0;

    map<string, string> signatures;
    for (int i = 0; i < studentCount; i++) {
        string name, signature;
        cin >> name >> signature;
        signatures[name] = signature;
    }

    cin >> studentCount;

    int falseSignatureCount = 0;
    for (int i = 0; i < studentCount; i++) {
        string name, signature;
        cin >> name >> signature;
        falseSignatureCount += diff(signatures[name], signature) > 1;
    }

    cout << falseSignatureCount << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}