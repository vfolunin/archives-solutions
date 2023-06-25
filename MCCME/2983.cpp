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

    int opCount, stackCount, sizeLimit;
    cin >> opCount >> stackCount >> sizeLimit;

    vector<vector<int>> stacks(stackCount);
    int size = 0, maxSize = 0;

    for (int i = 0; i < opCount; i++) {
        char type;
        int index, value;
        cin >> type >> index >> value;
        index--;

        if (type == '+') {
            if (size == sizeLimit) {
                cout << "Error";
                return 0;
            }

            stacks[index].push_back(value);
            size++;
            maxSize = max(maxSize, size);
        } else {
            if (stacks[index].empty() || stacks[index].back() != value) {
                cout << "Error";
                return 0;
            }

            stacks[index].pop_back();
            size--;
        }
    }

    if (size)
        cout << "Error";
    else
        cout << maxSize;
}