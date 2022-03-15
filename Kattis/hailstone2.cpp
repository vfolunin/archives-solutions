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

    long long n;
    cin >> n;

    int res = 1;
    while (n > 1) {
        if (n % 2)
            n = n * 3 + 1;
        else
            n /= 2;
        res++;
    }

    cout << res;
}