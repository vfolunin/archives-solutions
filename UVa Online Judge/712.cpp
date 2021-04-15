#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int depth;
    cin >> depth;

    if (!depth)
        return 0;

    vector<int> order(depth);
    for (int i = 0; i < depth; i++) {
        string token;
        cin >> token;
        order[token.back() - '1'] = i;
    }

    string resMask;
    cin >> resMask;

    int queryCount;
    cin >> queryCount;

    cout << "S-Tree #" << test << ":\n";
    for (int i = 0; i < queryCount; i++) {
        string mask;
        cin >> mask;

        int index = 0;
        for (int bit = 0; bit < depth; bit++)
            index |= (mask[bit] - '0') << (depth - 1 - order[bit]);
        cout << resMask[index];
    }
    cout << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}