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
 
    int n, d;
    cin >> n >> d;

    int res = 0;
    while (n) {
        res += n % 10 == d;
        n /= 10;
    }

    cout << res;
}