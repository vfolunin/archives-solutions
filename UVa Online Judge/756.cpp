#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a < 0)
        return 0;

    int res = 1;
    while ((d + res - a) % 23 || (d + res - b) % 28 || (d + res - c) % 33)
        res++;

    cout << "Case " << test << ": the next triple peak occurs in " << res << " days.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}