#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string name;
    int level;
    cin >> name >> level;

    cout << "Caso #" << test << ": " << name << " nivel " << level << "\n";

    int b, iv, ev;
    cin >> b >> iv >> ev;
    cout << "HP: " << (int)((iv + b + sqrt(ev) / 8 + 50) * level / 50 + 10) << "\n";

    for (string s : { "AT", "DF", "SP" }) {
        cin >> b >> iv >> ev;
        cout << s << ": " << (int)((iv + b + sqrt(ev) / 8) * level / 50 + 5) << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}