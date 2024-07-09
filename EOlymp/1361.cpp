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

    if (n == 1) {
        cout << 0;
        return 0;
    }

    int res = 1;
    while (n % (res + 1))
        res++;

    cout << res;
}