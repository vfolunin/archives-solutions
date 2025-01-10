#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    cout << test << ". ";

    n *= 3;

    cout << (n % 2 ? "odd " : "even ");

    n = (n + 1) / 2;
    n *= 3;
    n /= 9;

    cout << n << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}