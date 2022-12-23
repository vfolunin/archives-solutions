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

    int size, queryCount;
    cin >> size >> queryCount;

    for (int i = 0, value = 0; i < queryCount; i++) {
        int count;
        cin >> count;

        for (int j = 0; j < count; j++, value = (value + 1) % size)
            cout << value + 1 << " ";
        cout << "\n";
    }
}