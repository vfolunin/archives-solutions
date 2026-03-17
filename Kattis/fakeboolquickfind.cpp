#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;

    vector<int> id(size);
    iota(id.begin(), id.end(), 0);

    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;

        a = id[a];
        b = id[b];
        if (a > b)
            swap(a, b);

        for (int &value : id)
            if (value == b)
                value = a;
    }

    for (int value : id)
        cout << value << " ";
}