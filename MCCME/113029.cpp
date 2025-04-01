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

    int k, p, s;
    cin >> k >> p >> s;

    int a = min(k, s / (p * 2));
    int b = k > a ? s % (p * 2) / 2 : -1;

    cout << a << "\n" << b;
}