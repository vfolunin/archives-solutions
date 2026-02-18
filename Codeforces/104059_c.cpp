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

    set<int> closed;
    for (int i = 0; i < queryCount; i++) {
        char type;
        cin >> type;

        if (type == '-') {
            int v;
            cin >> v;
            v--;

            closed.insert(v);
        } else if (type == '+') {
            int v;
            cin >> v;
            v--;

            closed.erase(v);
        } else {
            int a, b;
            cin >> a >> b;
            a--;
            b--;

            if (closed.count(a) || closed.count(b)) {
                cout << "impossible\n";
                continue;
            }

            if (a > b)
                swap(a, b);

            auto aIt = closed.lower_bound(a), bIt = closed.lower_bound(b);
            if (aIt == closed.end() || b < *aIt || bIt == closed.end() && (closed.empty() || a < *closed.begin()))
                cout << "possible\n";
            else
                cout << "impossible\n";
        }
    }
}