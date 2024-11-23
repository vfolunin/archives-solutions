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

    int res = 2;
    n--;

    while (n > 1) {
        res++;
        n /= 2;
    }

    cout << res;
}