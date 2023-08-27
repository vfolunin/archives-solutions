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

    int size, percent;
    cin >> size >> percent;

    cout << "[";
    for (int i = 0; i < size; i++)
        cout << (i < size * percent / 100 ? "*" : ".");
    cout << "]";
}