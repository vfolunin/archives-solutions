#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void processOne() {
    int n;
    cin >> n;

    static vector<string> type = { "Rolien", "Naej", "Elehcim", "Odranoel" };
    cout << type[n - 1] << "\n";
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        processOne();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}