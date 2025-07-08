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

    int a, b, index;
    cin >> a >> b >> index;

    vector<int> res = { a - b, a, b, b - a, -a, -b };

    cout << res[index % res.size()];
}