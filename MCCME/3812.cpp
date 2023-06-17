#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int n, int from);

void rec(int n, int from, int aux, int to) {
    if (!n)
        return;

    rec(n - 1, from, to, aux);
    cout << n << " " << from << " " << to << "\n";
    rec(n - 1, aux, from, to);
}

void rec(int n, int from) {
    if (!n)
        return;

    int to = n % 2 ? 2 : 3;
    if (from == to) {
        rec(n - 1, from);
    } else {
        int aux = 6 - from - to;
        rec(n - 1, from, to, aux);
        cout << n << " " << from << " " << to << "\n";
        rec(n - 1, aux);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    rec(n, 1);
}