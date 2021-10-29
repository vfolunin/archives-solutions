#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    static vector<string> songs = {
        "PROXYCITY", "P.Y.N.G.", "DNSUEY!", "SERVERS", "HOST!",
        "CRIPTONIZE", "OFFLINE DAY", "SALT", "ANSWER!", "RAR?", "WIFI ANTENNAS"
    };

    cout << songs[a + b] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}