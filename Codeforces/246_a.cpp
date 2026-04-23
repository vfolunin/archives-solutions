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

    if (size <= 2) {
        cout << -1;
    } else {
        for (int i = size; i > 0; i--)
            cout << i << " ";
    }
}