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
 
    int size, targetValue;
    cin >> size >> targetValue;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value == targetValue) {
            cout << i + 1;
            return 0;
        }
    }

    cout << -1;
}