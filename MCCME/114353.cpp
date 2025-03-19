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

    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> prev(size, -1);
    vector<int> next(size, -1);
    for (int i = 0; i < size; i++) {
        if (i)
            prev[i] = i - 1;
        if (i + 1 < size)
            next[i] = i + 1;
    }

    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        int pb = prev[b], na = next[a];
        if (pb != -1)
            next[pb] = a;
        prev[a] = pb;
        next[a] = b;
        prev[b] = a;
        next[b] = na;
        if (na != -1)
            prev[na] = b;
    }

    for (int i = find(prev.begin(), prev.end(), -1) - prev.begin(); i != -1; i = next[i])
        cout << i + 1 << " ";
}