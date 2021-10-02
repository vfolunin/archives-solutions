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

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (!x) {
            cout << "NULL\n";
        } else {
            if (x % 2)
                cout << "ODD ";
            else
                cout << "EVEN ";
            if (x > 0)
                cout << "POSITIVE\n";
            else
                cout << "NEGATIVE\n";
        }
    }
}