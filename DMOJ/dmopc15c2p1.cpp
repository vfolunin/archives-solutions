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

    int num, den;
    cin >> num >> den;

    int res = num;
    while (num >= den) {
        int count = num / den;
        res += count;
        num = count + num % den;
    }

    cout << res;
}