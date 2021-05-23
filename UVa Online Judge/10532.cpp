#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int itemCount, queryCount;
    cin >> itemCount >> queryCount;

    if (!itemCount && !queryCount)
        return 0;

    map<int, int> idCount;
    for (int i = 0; i < itemCount; i++) {
        int id;
        cin >> id;
        idCount[id]++;
    }

    vector<long long> res(itemCount + 1);
    res[0] = 1;

    for (auto &[_, count] : idCount)
        for (int size = itemCount; size; size--)
            for (int last = count; last; last--)
                if (size >= last)
                    res[size] += res[size - last];
    
    cout << "Case " << test << ":\n";
    for (int i = 0; i < queryCount; i++) {
        int size;
        cin >> size;
        cout << res[size] << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}