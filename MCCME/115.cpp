#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int zeroCount(int n) {
    int res = 0;
    while (n > 9) {
        res += n % 10 == 0;
        n /= 10;
    }
    return res + (!n);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
 
    cout << zeroCount(n);
}