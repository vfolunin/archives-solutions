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

    int size, count;
    cin >> size >> count;

    if (size == count) {
        cout << string(size, 'a');
    } else if (count < 3 || count > size) {
        cout << -1;
    } else {
        cout << string(count - 3, 'a');
        for (int i = count - 3, c = 0; i < size; i++, c = (c + 1) % 3)
            cout << (char)(c + 'a');
    }
}