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

    cout << (h * w >= n && (n % h == 0 || n % w == 0) ? "YES" : "NO");
}