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

    string row;
    getline(cin, row);

    while (1) {
        getline(cin, row);
        if (row[0] == '_')
            break;

        char byte = 0;
        for (int i : {1, 2, 3, 4, 5, 7, 8, 9})
            byte = byte * 2 + (row[i] == 'o');
        cout << byte;
    }
}