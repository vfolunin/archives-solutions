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

    vector<int> winner(n + 1, 2);
    for (int i = 1; i <= n; i++)
        for (int j : { 1, 2, 1000 })
            if (i >= j && winner[i - j] == 2)
                winner[i] = 1;

    cout << winner[n];
}