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

        for (vector<int> &stack : stacks) {
            for (int value : stack)
                cout << value << " ";
            cout << "\n";
        }
        cout << "---\n";
    }
}