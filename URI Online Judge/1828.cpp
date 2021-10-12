#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string sa, sb;
    cin >> sa >> sb;

    vector<string> signs = { "tesoura", "papel", "pedra", "lagarto", "Spock" };
    int a = find(signs.begin(), signs.end(), sa) - signs.begin();
    int b = find(signs.begin(), signs.end(), sb) - signs.begin();

    cout << "Caso #" << test << ": ";
    if (a == b)
        cout << "De novo!\n";
    else if ((a + 1) % 5 == b || (a + 3) % 5 == b)
        cout << "Bazinga!\n";
    else
        cout << "Raj trapaceou!\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}