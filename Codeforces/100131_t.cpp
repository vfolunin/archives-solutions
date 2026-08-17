#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int queryCount;
    cin >> queryCount;

    unordered_map<int, int> pos;
    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;

        if (!pos.count(a))
            pos[a] = a;
        if (!pos.count(b))
            pos[b] = b;

        swap(pos[a], pos[b]);

        cout << abs(pos[a] - pos[b]) << "\n";
    }
}