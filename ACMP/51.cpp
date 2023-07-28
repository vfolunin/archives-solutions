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

    int res = n;
    while (n > s.size()) {
        n -= s.size();
        res *= n;
    }

    cout << res;
}