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

    int h, w, n;
    cin >> h >> w >> n;
    n--;

    if (n < w || (h - 1) * w <= n || n % w == 0 || n % w == w - 1)
        cout << "YES";
    else
        cout << "NO";
}