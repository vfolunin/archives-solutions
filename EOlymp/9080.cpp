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

    int v, s;
    cin >> v >> s;

    s *= 1000;
    int t = (s + v - 1) / v;

    cout << (t + 1439) / 1440;
}