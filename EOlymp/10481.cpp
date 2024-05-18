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
    for (int a = 1; a <= n; a++)
        for (int b = 1; a * b <= n; b++)
            for (int c = 1; a * b * c <= n; c++)
                res++;

    cout << res;
}