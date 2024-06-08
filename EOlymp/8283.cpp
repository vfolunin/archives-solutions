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

    int size, targetIndex;
    cin >> size >> targetIndex;
    targetIndex--;

    for (int i = 1, index = 0; i <= size; i++, index = (index + 6) % size) {
        if (index == targetIndex) {
            cout << i;
            return 0;
        }
    }

    cout << 0;
}