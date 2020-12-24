#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << "Case " << test << ": ";
    cout << (a <= 20 && b <= 20 && c <= 20 ? "good\n" : "bad\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        solve(i);
}