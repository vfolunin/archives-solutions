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

    int size, index, finishValue;
    cin >> size >> index >> finishValue;
    index--;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    for (int i = 0; 1; i++) {
        if (index < 0) {
            cout << "left\n" << i;
            break;
        }
        if (index >= size) {
            cout << "right\n" << i;
            break;
        }
        if (a[index] == finishValue) {
            cout << "magic\n" << i;
            break;
        }
        if (a[index] == 1e9) {
            cout << "cycle\n" << i;
            break;
        }
        int value = a[index];
        a[index] = 1e9;
        index += value;
    }
}