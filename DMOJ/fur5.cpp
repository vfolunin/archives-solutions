#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int n, char from, char aux, char to) {
    if (!n)
        return;

    rec(n - 1, from, to, aux);
    cout << from << to << "\n";
    rec(n - 1, aux, from, to);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    rec(n, 'A', 'B', 'C');
}