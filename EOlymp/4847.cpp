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

    map<string, int> priorityOf;
    set<pair<int, string>> pairs;

    for (string op; cin >> op; ) {
        if (op == "POP") {
            cout << prev(pairs.end())->second << " " << prev(pairs.end())->first << "\n";

            priorityOf.erase(prev(pairs.end())->second);
            pairs.erase(prev(pairs.end()));
        } else {
            string s;
            int priority;
            cin >> s >> priority;

            pairs.erase({ priorityOf[s], s });
            priorityOf[s] = priority;
            pairs.insert({ priorityOf[s], s });
        }
    }
}