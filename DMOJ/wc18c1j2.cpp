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

    string a;
    cin >> a;

    for (int i = 0; i < 5; i++) {
        string b;
        cin >> b;

        if (a == b) {
            cout << "Y";
            return 0;
        }
    }

    cout << "N";
}