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
    for (int a = 1; a * a < n; a++) {
        for (int b = a; a * b < n; b++) {
            res++;
            res += a != b;
        }
    }

    cout << res;
}