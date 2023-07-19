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

    if (!n) {
        cout << 3;
        return 0;
    }

    string e = "2.7182818284590452353602875";
    if (e[n + 2] >= '5')
        e[n + 1]++;

    cout << e.substr(0, n + 2);
}