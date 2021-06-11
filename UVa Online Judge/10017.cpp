#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int diskCount, moveCount;
    cin >> diskCount >> moveCount;

    if (!diskCount)
        return 0;

    vector<vector<int>> a(3);
    for (int i = diskCount; i; i--)
        a[0].push_back(i);

    vector<int> moves = { 1, 2, 12 };
    if (diskCount % 2)
        swap(moves[0], moves[1]);

    cout << "Problem #" << test << "\n\n";
    for (int move = 0; move <= moveCount; move++) {
        for (int i = 0; i < 3; i++) {
            cout << (char)('A' + i) << "=>";
            for (int j = 0; j < a[i].size(); j++)
                cout << (j ? " " : "   ") << a[i][j];
            cout << "\n";
        }
        cout << "\n";

        if (move < moveCount) {
            int from = moves[move % 3] / 10, to = moves[move % 3] % 10;
            if (a[from].empty() || !a[to].empty() && a[from].back() > a[to].back())
                swap(from, to);
            a[to].push_back(a[from].back());
            a[from].pop_back();
        }
    }    
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}