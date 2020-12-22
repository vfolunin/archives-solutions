#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void solve(int test) {
    int amplitude, frequency;
    cin >> amplitude >> frequency;

    if (test)
        cout << "\n";

    for (int i = 0; i < frequency; i++) {
        if (i)
            cout << "\n";
        for (int j = 1; j < amplitude; j++)
            cout << string(j, '0' + j) << "\n";
        for (int j = amplitude; j > 0; j--)
            cout << string(j, '0' + j) << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}