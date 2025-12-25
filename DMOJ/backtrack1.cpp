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

    vector<long long> ways(n + 1, 1);
    for (int i = 1; i < ways.size(); i++)
        for (int j = 1; j * 2 <= i; j++)
            ways[i] += ways[i - j * 2];

    cout << ways[n];
}