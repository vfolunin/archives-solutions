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

    int size;
    cin >> size;

    for (int i = 0, j = 0, val = 1; i < size; i++, j++) {
        if (j == val) {
            j = 0;
            val++;
        }

        cout << val << " ";
    }
}