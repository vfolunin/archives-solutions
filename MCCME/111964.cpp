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

    vector<vector<int>> stacks(3);
    stacks[0] = { 5, 4, 3, 2, 1 };

    int opCount;
    cin >> opCount;
    
    for (int i = 0; i < opCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        stacks[b].push_back(stacks[a].back());
        stacks[a].pop_back();

        int rows = 0;
        for (vector<int> &stack : stacks)
            rows = max<int>(rows, stack.size());

        for (int row = rows - 1; row >= 0; row--) {
            for (vector<int> &stack : stacks) {
                int value = row < stack.size() ? stack[row] : 0;
                cout << string(5 - value, ' ') << string(2 * value, '-') << string(6 - value, ' ');
            }
            cout << "\n";
        }
        cout << "\n";
    }
}