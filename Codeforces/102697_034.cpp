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

    int size, limit;
    cin >> size >> limit;

    int prev, cur = 0;
    for (int i = 0; i < size; i++) {
        prev = cur;
        cin >> cur;

        if (i && prev + limit < cur) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES\n";
}