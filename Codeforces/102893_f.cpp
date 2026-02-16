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

    int t1, v1, t2, v2;
    cin >> t1 >> v1 >> t2 >> v2;

    if (t2 < 0 && v2 >= 10)
        cout << "A storm warning for tomorrow! Be careful and stay home if possible!";
    else if (t2 < t1)
        cout << "MCHS warns! Low temperature is expected tomorrow.";
    else if (v2 > v1)
        cout << "MCHS warns! Strong wind is expected tomorrow.";
    else
        cout << "No message";
}