#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    cout << "Case " << test << ": ";
    cin.ignore();
    while (cin.peek() != '\n' && cin.peek() != EOF) {
        char c;
        int k;
        cin >> c >> k;
        cout << string(k, c);
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}