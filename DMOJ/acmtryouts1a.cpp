#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;

    if (s == "Rock")
        cout << "Paper\n";
    else if (s == "Scissors")
        cout << "Rock\n";
    else if (s == "Paper")
        cout << "Scissors\n";
    else if (s == "Fox")
        cout << "Foxen\n";
    else
        exit(0);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}