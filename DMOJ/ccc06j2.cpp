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

    int a, b;
    cin >> a >> b;

    int res = 0;
    for (int ai = 1, bi = 9; ai < 10; ai++, bi--)
        res += ai <= a && bi <= b;

    if (res == 1)
        cout << "There is 1 way to get the sum 10.";
    else
        cout << "There are " << res << " ways to get the sum 10.";
}