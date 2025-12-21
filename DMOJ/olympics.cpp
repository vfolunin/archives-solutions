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

    long long threshold, a, b, c;
    cin >> threshold >> a >> b >> c;

    long long score = a + b * 3 + c * 5;

    cout << (score > threshold ? 0 : (threshold - score) / 5 + 1);
}