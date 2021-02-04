#include <iostream>
#include <iomanip>
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

    int prev;
    cin >> prev;

    long long res = 0;
    for (int i = 1; i < n; i++) {
        int cur;
        cin >> cur;

        if (cur < prev)
            res += prev - cur;
        else
            prev = cur;
    }
    
    cout << res;
}