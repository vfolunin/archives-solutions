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

    int zeroCount = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value)
            cout << value << " ";
        else
            zeroCount++;
    }

    for (int i = 0; i < zeroCount; i++)
        cout << "0 ";
}