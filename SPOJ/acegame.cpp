#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string ops;
    getline(cin, ops);

    string res = "010";
    for (char op : ops) {
        if (op == 'L')
            swap(res[0], res[1]);
        else if (op == 'R')
            swap(res[1], res[2]);
        else if (op == 'E')
            swap(res[0], res[2]);
    }

    if (res[0] == '1')
        cout << "L\n";
    else if (res[1] == '1')
        cout << "M\n";
    else
        cout << "R\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}