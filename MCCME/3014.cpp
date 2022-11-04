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

    int h, w, n;
    cin >> h >> w >> n;

    int den = n / h;
    cout << (w + den - 1) / den;
}