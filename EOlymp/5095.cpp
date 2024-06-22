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
    cin >> a >> a >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string res;
    for (int i = 0; i < a.size() || i < b.size(); i++) {
        int digitA = (i < a.size() ? a[i] - '0' : 0);
        int digitB = (i < b.size() ? b[i] - '0' : 0);
        res.push_back((digitA != digitB) + '0');
    }

    while (res.size() > 1 && res.back() == '0')
        res.pop_back();

    reverse(res.begin(), res.end());

    cout << res;
}