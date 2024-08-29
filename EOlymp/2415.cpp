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

    unsigned long long n;
    cin >> n;

    int res = 0;
    while (n % 2 == 0) {
        res++;
        n /= 2;
    }

    cout << res;
}