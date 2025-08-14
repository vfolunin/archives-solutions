#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int res = 0;
    while (n > 1) {
        if (n % 2)
            n += 2 * n + 1;
        else
            n /= 2;
        res++;
    }

    cout << res;
}