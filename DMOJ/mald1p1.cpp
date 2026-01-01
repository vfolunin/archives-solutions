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

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    set<string> values;
    for (int i = 0; i < a.size(); i++) {
        if (a[i].find("yubo") != -1) {
            if (i)
                values.insert(a[i - 1]);

            values.insert(a[i]);

            if (i + 1 < a.size())
                values.insert(a[i + 1]);
        }
    }

    for (const string &s : values)
        cout << s << "\n";
}