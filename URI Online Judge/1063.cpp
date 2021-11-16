#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<char> a(n);
    for (char &c : a)
        cin >> c;

    vector<char> b(n);
    for (char &c : b)
        cin >> c;

    string stack, res;
    for (int ai = 0, bi = 0; ai < n; ai++) {
        res.push_back('I');
        stack.push_back(a[ai]);

        while (!stack.empty() && stack.back() == b[bi]) {
            res.push_back('R');
            stack.pop_back();
            bi++;
        }
    }
    
    cout << res;
    if (!stack.empty())
        cout << " Impossible";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}