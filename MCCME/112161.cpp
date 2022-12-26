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

    if (1 <= n && n <= 12) {
        vector<string> res = { "winter", "spring", "summer", "autumn" };
        cout << res[n % 12 / 3];
    } else {
        cout << "NO";
    }
}