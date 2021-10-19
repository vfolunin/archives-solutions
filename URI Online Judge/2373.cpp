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

    int res = 0;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b)
            res += b;
    }
    
    cout << res << "\n";
}