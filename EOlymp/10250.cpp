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

    int res = 0;
    while (n >= 3) {
        if (n % 3 == 0)
            n /= 3;
        else if (n % 3 == 1)
            n--;
        else
            n++;
        res++;
    }

    cout << res + n - 1;
}