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

    int prevValue = -1e9;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (prevValue <= value) {
            prevValue = value;

            cout << value << " ";
        }
    }
}