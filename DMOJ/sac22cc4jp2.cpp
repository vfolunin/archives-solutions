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

    vector<string> a(size);
    for (int i = 0; i < queryCount; i++) {
        string type, value;
        int index;
        cin >> type >> value >> index;
        index--;

        if (type == "set")
            a[index] = value;
        else
            cout << (a[index] == value) << "\n";
    }
}