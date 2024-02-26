#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    string s = string(62, '0') + string(2, '1');
    for (int i = 0; i < n - 1; i++)
        next_permutation(s.begin(), s.end());

    cout << stoull(s, 0, 2);
}