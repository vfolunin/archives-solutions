#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long a, b, c;
    cin >> a >> b >> c;

    long long ab = a * b;

    if (ab >= c) {
        cout << ab / c;
        ab %= c;
    }

    stringstream ss;
    ss.precision(20);
    ss << fixed << (double)ab / c;

    cout << ss.str().substr(1);
}