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
    while (n % 10 == 0) {
        n /= 10;
        res++;
    }

    if (n == 1)
        cout << res;
    else
        cout << "No";
}