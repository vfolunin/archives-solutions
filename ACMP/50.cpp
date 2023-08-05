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
    cin >> a >> b;

    int bSize = b.size();
    b += b;

    int res = 0;
    for (int i = 0; i + bSize <= a.size(); i++)
        res += b.find(a.substr(i, bSize)) != -1;

    cout << res;
}