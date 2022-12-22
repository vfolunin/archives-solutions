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
    n--;

    string res;
    while (n >= 2) {
        res += n % 2 ? '5' : '0';
        n /= 2;
    }
    res += n ? '5' : '0';

    reverse(res.begin(), res.end());
    cout << res;
}