#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(char a, char b) {
    if (tolower(a) != tolower(b))
        return tolower(a) < tolower(b);
    return isupper(a) && islower(b);
}

void solve() {
    string s;
    cin >> s;

    sort(s.begin(), s.end(), compare);
    do {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end(), compare));
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}