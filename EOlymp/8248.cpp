#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> zFunction(vector<int> &a) {
    vector<int> z(a.size());

    int blockL = 0, blockR = 0;
    for (int i = 1; i < a.size(); i++) {
        int blockLen = 0;

        if (i <= blockR)
            blockLen = min(z[i - blockL], blockR - i + 1);

        while (i + blockLen < a.size() && a[i + blockLen] == a[blockLen])
            blockLen++;

        z[i] = blockLen;

        if (blockR < i + blockLen - 1) {
            blockL = i;
            blockR = i + blockLen - 1;
        }
    }

    return z;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> p(size);
    for (int &value : p)
        cin >> value;

    vector<int> a(size);
    int value = 1;
    for (int i = 1; i < size; i++) {
        if (!p[i])
            a[i] = value++;
        else
            a[i] = a[p[i] - 1];
    }

    for (int value : zFunction(a))
        cout << value << " ";
}