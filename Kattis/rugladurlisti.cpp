#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <bitset>
using namespace std;

using Bitset = bitset<10000>;

Bitset ask(int size, int bit) {
    vector<int> pos;
    for (int p = 0; p < size; p++)
        if (p & (1 << bit))
            pos.push_back(p);

    cout << "? " << pos.size();
    for (int p : pos)
        cout << " " << p + 1;
    cout << endl;

    Bitset res;
    for (int i = 0; i < pos.size(); i++) {
        int value;
        cin >> value;

        res.set(value - 1);
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<Bitset> bitsets;
    for (int bit = 0; (1 << bit) < size; bit++)
        bitsets.push_back(ask(size, bit));

    vector<int> res(size);
    for (int i = 0; i < res.size(); i++) {
        Bitset iSet;
        iSet.set();

        for (int bit = 0; bit < bitsets.size(); bit++) {
            if (i & (1 << bit))
                iSet &= bitsets[bit];
            else
                iSet &= ~bitsets[bit];
        }

        while (!iSet.test(res[i]))
            res[i]++;
    }

    cout << "!";
    for (int value : res)
        cout << " " << value + 1;
    cout << endl;
}