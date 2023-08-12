#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long a, b;
    cin >> a >> a >> b;

    unordered_set<int> ancestors;
    for (; a; a /= 2)
        ancestors.insert(a);

    while (!ancestors.count(b))
        b /= 2;

    cout << b;
}