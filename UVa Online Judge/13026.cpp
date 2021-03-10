#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int diff(string &a, string &b) {
    int res = 0;
    for (int i = 0; i < a.size(); i++)
        res += a[i] != b[i];
    return res;
}

void solve(int test) {
    int phoneCount;
    cin >> phoneCount;

    vector<string> phones(phoneCount);
    for (string &phone : phones)
        cin >> phone;

    string targetPhone;
    cin >> targetPhone;

    cout << "Case " << test << ":\n";
    for (string &phone : phones)
        if (diff(phone, targetPhone) <= 1)
            cout << phone << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}