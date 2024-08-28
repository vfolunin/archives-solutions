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

    int sum, a, b;
    cin >> sum >> a >> b;

    int res = 0;
    for (int i = 0; i * a <= sum; i++)
        res += (sum - i * a) % b == 0;

    cout << res;
}