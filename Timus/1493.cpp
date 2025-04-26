#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isLucky(int n) {
    vector<int> sum(2);
    for (int i = 0; i < 6; i++) {
        sum[i < 3] += n % 10;
        n /= 10;
    }
    return sum[0] == sum[1];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << (isLucky(n - 1) || isLucky(n + 1) ? "Yes" : "No");
}