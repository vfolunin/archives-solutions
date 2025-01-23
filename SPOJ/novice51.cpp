#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int res = 0;
    while (n) {
        if (n % 2)
            n--;
        else
            n /= 2;
        res++;
    }

    cout << (res % 2 ? "Aayush\n" : "Akash\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}