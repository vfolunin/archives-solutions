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

    bool found = 0;
    for (int i = 0; i < a.size(); ) {
        if (i + 1 == a.size() || a[i + 1] != "Present!") {
            cout << a[i] << "\n";
            found = 1;
            i++;
        } else {
            i += 2;
        }
    }

    if (!found)
        cout << "No Absences";
}