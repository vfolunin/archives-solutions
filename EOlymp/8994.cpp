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

    string a, b;
    cin >> a >> b;

    for (char c : b) {
        if (a.find(c) == -1) {
            cout << "No";
            return 0;
        }
    }

    cout << "Ok";
}