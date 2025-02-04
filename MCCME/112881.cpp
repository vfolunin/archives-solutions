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

    int size, iterationCount;
    cin >> size >> iterationCount;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    for (int i = 0; i < iterationCount; i++) {
        vector<int> b(a.size());
        for (int value : a)
            if (value)
                b[value - 1]++;

        if (a == b)
            break;

        a.swap(b);
    }

    for (int value : a)
        cout << value << " ";
}