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
    string s;
    cin >> n >> s;

    int res = 1;
    for (int i = n; i > 0; i -= s.size())
        res *= i;

    cout << res;
}