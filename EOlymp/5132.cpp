#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int test;
    cin >> test;
    cin.ignore();
    cout << test << " ";

    string s;
    getline(cin, s);

    int size;
    cin >> size;

    int index = 0;
    for (int i = 0; i < size; i++) {
        int delta;
        cin >> delta;

        index = (index + delta + s.size()) % s.size();

        cout << s[index];
    }
    cout << "\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}