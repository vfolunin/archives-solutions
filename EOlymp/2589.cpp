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

    int size;
    cin >> size;

    vector<vector<int>> stack(3);
    for (int i = 0; i < size; i++)
        stack[0].push_back(size - i);

    for (int type, count; cin >> type >> count; ) {
        for (int i = 0; i < count; i++) {
            stack[type].push_back(stack[type - 1].back());
            stack[type - 1].pop_back();
        }
    }

    for (int i = size - 1; i >= 0; i--)
        cout << stack.back()[i] << "\n";
}