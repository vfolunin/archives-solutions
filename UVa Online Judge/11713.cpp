#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isVowel(char c) {
    static string vowels = "aeiou";
    return vowels.find(c) != -1;
}

void solve() {
    string a, b;
    cin >> a >> b;

    if (a.size() != b.size()) {
        cout << "No\n";
        return;
    }
    
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i] || isVowel(a[i]) && isVowel(b[i]))
            continue;
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}