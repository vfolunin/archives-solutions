#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string a, b;
    cin >> a >> b;

    int questions0 = 0, questions1 = 0, wrong0 = 0, wrong1 = 0;
    for (int i = 0; i < a.size(); i++) {
        questions0 += a[i] == '?' && b[i] == '0';
        questions1 += a[i] == '?' && b[i] == '1';
        wrong0 += a[i] == '0' && b[i] == '1';
        wrong1 += a[i] == '1' && b[i] == '0';
    }

    int swaps = min(wrong0, wrong1);
    wrong0 -= swaps;
    wrong1 -= swaps;

    cout << "Case " << test << ": ";
    if (!wrong1)
        cout << questions0 + questions1 + swaps + wrong0 << "\n";
    else if (questions1 >= wrong1)
        cout << questions0 + questions1 + swaps + wrong1 << "\n";
    else
        cout << "-1\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}