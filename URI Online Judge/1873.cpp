#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string sa, sb;
    cin >> sa >> sb;

    vector<string> signs = { "tesoura", "papel", "pedra", "lagarto", "spock" };
    int a = find(signs.begin(), signs.end(), sa) - signs.begin();
    int b = find(signs.begin(), signs.end(), sb) - signs.begin();

    if (a == b)
        cout << "empate\n";
    else if ((a + 1) % 5 == b || (a + 3) % 5 == b)
        cout << "rajesh\n";
    else
        cout << "sheldon\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}