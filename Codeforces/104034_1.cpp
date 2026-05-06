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

    long long a, b, t;
    cin >> a >> b >> t;

    cout << min((a - t % a) % a, (b - t % b) % b);
}