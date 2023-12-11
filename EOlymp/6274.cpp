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

    int sum, value;
    cin >> sum >> value;

    for (int count = 1; 1; count++) {
        if (count * (count + 1) / 2 + value == sum) {
            cout << count;
            break;
        }
    }
}