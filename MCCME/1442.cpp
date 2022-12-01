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

    int n;
    cin >> n;

    long long a = 1, b = 1;
    for (int i = 0; i < n - 1; i++) {
        if (a * a == b * b * b) {
            a++;
            b++;
        } else if (a * a < b * b * b) {
            a++;
        } else {
            b++;
        }
    }

    cout << min(a * a, b * b * b);
}