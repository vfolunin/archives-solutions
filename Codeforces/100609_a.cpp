#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("ate.in", "r", stdin);
    freopen("ate.out", "w", stdout);
 
    int sum;
    cin >> sum;

    int res = 0;
    for (int a = 0; a < 100 && a <= sum; a++) {
        int b = sum - a;
        res += 0 <= b && b < 100;
    }

    cout << res;
}