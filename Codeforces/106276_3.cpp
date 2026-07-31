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

    long long a, b;
    cin >> a >> b;

    long long d = min(a, b / a);

    set<long long> res = { d, d * d, d * d * d };
    res.erase(a);
    res.erase(b);

    cout << *res.begin();
}