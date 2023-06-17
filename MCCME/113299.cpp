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

    int letterCount, len;
    cin >> letterCount >> len;

    if (len == 1) {
        cout << max(letterCount - 2, 0);
        return 0;
    }

    long long res = letterCount - 1;
    for (int i = 0; i < len - 2; i++)
        res *= letterCount;
    res *= letterCount - 1;

    cout << res;
}