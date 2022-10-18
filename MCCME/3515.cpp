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

    if (0 < n && n < h * w && (n % h == 0 || n % w == 0))
        cout << "YES";
    else
        cout << "NO";
}