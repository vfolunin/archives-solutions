#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int d2, m2, y2;
    scanf("%d/%d/%d", &d2, &m2, &y2);
    int d1, m1, y1;
    scanf("%d/%d/%d", &d1, &m1, &y1);

    cout << "Case #" << test << ": ";
    if (y2 < y1 || y2 == y1 && m2 < m1 || y2 == y1 && m2 == m1 && d2 < d1)
        cout << "Invalid birth date\n";
    else {
        int age = y2 - y1;
        if (m2 < m1 || m2 == m1 && d2 < d1)
            age--;

        if (age > 130)
            cout << "Check birth date\n";
        else
            cout << age << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}