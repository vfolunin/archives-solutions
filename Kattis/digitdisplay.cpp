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

    if (n == 1) {
        cout << "impossible";
        return 0;
    }

    string res(n / 2, '1');
    if (n % 2)
        res[0] = '7';

    cout << res;
}