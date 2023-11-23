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

    if (size == 1) {
        cout << "NO";
        return 0;
    }

    cout << size / 2 << "\n";

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (i % 2)
            cout << value << " ";
    }
}