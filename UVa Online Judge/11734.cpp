#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    cout << "Case " << test << ": ";
    if (a == b) {
        cout << "Yes\n";
    } else {
        a.erase(remove(a.begin(), a.end(), ' '), a.end());
        if (a == b)
            cout << "Output Format Error\n";
        else
            cout << "Wrong Answer\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int test = 1; test <= n; test++)
        solve(test);
}