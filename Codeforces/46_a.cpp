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

    int value = 0;
    for (int i = 1; i < size; i++) {
        value = (value + i) % size;

        cout << value + 1 << " ";
    }
}