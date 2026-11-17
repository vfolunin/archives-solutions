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

    int size, targetRow, limit;
    cin >> size >> targetRow >> limit;

    int row = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value <= limit) {
            row++;
            if (row == targetRow) {
                cout << i - row + 1;
                return 0;
            }
        } else {
            row = 0;
        }
    }

    cout << "Too hot!";
}