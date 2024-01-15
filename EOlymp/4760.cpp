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

    vector<int> a;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value)
            a.push_back(value);
    }

    a.resize(size);

    for (int value : a)
        cout << value << " ";
}