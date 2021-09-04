#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    vector<int> input, barrel(20, -1);
    while (1) {
        int x;
        cin >> x;

        if (x == 99)
            break;

        input.push_back(x - 1);
        barrel[x - 1] = x - 1;
    }
    cin.ignore();

    vector<int> output(20, -1);
    if (test)
        cout << "\n";
    while (1) {
        string line;
        getline(cin, line);

        if (line.empty())
            break;

        int x = stoi(line) - 1;
        while (barrel[x] == -1)
            rotate(barrel.begin(), barrel.begin() + 19, barrel.end());

        output[barrel[x]] = x;
        barrel[x] = -1;
    }

    for (int x : input) {
        cout << "Original position " << x + 1;
        if (output[x] != -1)
            cout << " parked in " << output[x] + 1 << "\n";
        else
            cout << " did not park\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}