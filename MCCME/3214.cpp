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

    set<int> values;

    for (int i = 0; i < 2; i++) {
        int l, r;
        cin >> l >> r;

        for (int value = l; value <= r; value++) {
            if (!values.count(value)) {
                cout << value << " ";
                values.insert(value);
            }
        }
    }

    int value;
    cin >> value;

    if (!values.count(value))
        cout << value << " ";

    cout << "END.";
}