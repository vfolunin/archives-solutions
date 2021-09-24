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

    int a, b, n;
    cin >> a >> b >> n;

    vector<int> winner(1e6 + 1);
    winner[0] = 2;
    for (int i = 1; i < winner.size(); i++) {
        if (winner[i - 1] == 2 || i >= a && winner[i - a] == 2 || i >= b && winner[i - b] == 2)
            winner[i] = 1;
        else
            winner[i] = 2;
    }

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        cout << (winner[k] == 1 ? 'A' : 'B');
    }
}