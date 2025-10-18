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

    vector<int> a(size);
    iota(a.begin(), a.end(), 1);

    for (int i = 0; i < queryCount; i++) {
        int divisor;
        cin >> divisor;

        vector<int> b;
        for (int j = 0; j < a.size(); j++)
            if ((j + 1) % divisor)
                b.push_back(a[j]);
        a.swap(b);
    }

    for (int value : a)
        cout << value << "\n";
}