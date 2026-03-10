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

    long long h, w, n;
    cin >> h >> w >> n;

    cout << ((h + n - 1) / n) * ((w + n - 1) / n);
}