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

    int a, b, n;
    cin >> a >> b >> n;

    cout << (a > (b + n - 1) / n ? "Yes" : "No");
}