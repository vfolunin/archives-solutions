#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    deque<int> numbers(n);
    for (int i = 0; i < n; i++)
        numbers[i] = i + 1;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << numbers[x] << (i + 1 < n ? ' ' : '\n');
        numbers.erase(numbers.begin() + x);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}