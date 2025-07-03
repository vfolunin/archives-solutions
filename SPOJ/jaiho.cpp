#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isLeap(int year) {
    return year % 400 == 0 || year % 4 == 0 && year % 100;
}

void solve() {
    string s;
    cin >> s;

    int year = stoi(s.substr(6));

    if (year < 1947) {
        cout << "Invalid.\n";
        return;
    }

    int delta = 0;
    for (int i = 1948; i <= year; i++)
        delta += 365 + isLeap(i);

    cout << (delta % 7 ? "No.\n" : "Yes.\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}