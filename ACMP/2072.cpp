#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int f(int n) {
    if (n % 2 == 0)
        return f(n / 2) + 5;
    if (n % 5 == 0)
        return f(n / 5) + 2;
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int target;
    cin >> target;

    int res = 1;
    while (f(res) != target)
        res++;

    cout << res;
}