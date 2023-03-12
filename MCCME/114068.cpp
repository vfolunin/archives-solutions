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

    int len = 1;
    while (n > len) {
        n -= len;
        len++;
    }

    if (n < len) {
        string res = "1" + string(len - 1, '0');
        res[len - n] = '1';
        cout << res;
    } else {
        cout << "2" << string(len - 1, '0');
    }
}