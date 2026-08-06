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

    int limit;
    cin >> limit;

    int res = 0;
    for (int a = 1; a <= limit; a++) {
        for (int b = a; b <= limit; b++) {
            int c = a ^ b;
            res += c <= limit && b <= c && c < a + b;
        }
    }

    cout << res;
}