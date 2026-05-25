#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long g = gcd(b, d);
    long long resA = d / g, resC = b / g;
    long long resB = resC * c, resD = resA * a;

    cout << resA << " " << resB << " " << resC << " " << resD;
}