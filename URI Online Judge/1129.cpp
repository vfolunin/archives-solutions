#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void processOne() {
    vector<int> a(5);
    for (int &x : a) {
        cin >> x;
        x = x <= 127;
    }

    if (count(a.begin(), a.end(), 1) != 1)
        cout << "*\n";
    else
        cout << (char)(find(a.begin(), a.end(), 1) - a.begin() + 'A') << "\n";
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    for (int i = 0; i < n; i++)
        processOne();

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}