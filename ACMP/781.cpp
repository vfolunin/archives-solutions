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

    vector<long long> ways = { 0, 2, 4 };
    for (int i = 3; i <= n; i++)
        ways.push_back(ways[i - 1] + ways[i - 2]);

    cout << ways[n];
}