#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int peopleCount;
    cin >> peopleCount;

    set<string> languages;
    for (int i = 0; i < peopleCount; i++) {
        string language;
        cin >> language;
        languages.insert(language);
    }

    if (languages.size() == 1)
        cout << *languages.begin() << "\n";
    else
        cout << "ingles\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}