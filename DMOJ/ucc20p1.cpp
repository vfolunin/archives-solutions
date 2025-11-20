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

    string a, b;
    cin >> a >> a >> b;

    int res = 0;
    for (int i = 0; i < a.size(); i++)
        res += a[i] == '0' && b[i] == '0';

    cout << res;
}