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

    vector<int> seen(10);

    for (int i = 1; 1; i++) {
        int value;
        cin >> value;

        if (seen[value]) {
            cout << i;
            break;
        }

        seen[value] = 1;
    }
}