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

    vector<int> a;
    for (int value; cin >> value; ) {
        a.push_back(value);

        if (cin.peek() == '\n')
            break;
    }

    vector<int> b;
    for (int value; cin >> value; )
        b.push_back(value);

    vector<int> res(a.size() + b.size() - 1);
    for (int ai = 0; ai < a.size(); ai++)
        for (int bi = 0; bi < b.size(); bi++)
            res[ai + bi] += a[ai] * b[bi];

    for (int value : res)
        cout << value << " ";
}