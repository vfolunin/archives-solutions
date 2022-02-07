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
    string a, b;
    cin >> n >> a >> b;

    n %= 2;
    for (int i = 0; i < a.size(); i++) {
        if ((a[i] ^ n) != b[i]) {
            cout << "Deletion failed\n";
            return 0;
        }
    }

    cout << "Deletion succeeded\n";
}