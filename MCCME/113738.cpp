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

    int size, index, queryCount;
    cin >> size >> index >> queryCount;
    index--;

    for (int i = 0; i < queryCount; i++) {
        int shift;
        cin >> shift;
        shift %= size;

        if (shift == index)
            index = 0;
        else if (shift > index)
            index++;
    }

    cout << index + 1;
}