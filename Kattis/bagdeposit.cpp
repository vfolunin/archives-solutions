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

    set<int> stacks;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value >> value;

        auto it = stacks.lower_bound(value);
        if (it != stacks.end())
            stacks.erase(it);
        stacks.insert(value);
    }

    cout << stacks.size();
}