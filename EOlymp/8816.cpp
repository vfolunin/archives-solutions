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

    int n, p;
    cin >> n >> p;

    long long res = 1;
    for (int i = 1; i <= p; i++)
        res *= n;

    cout << res;
}