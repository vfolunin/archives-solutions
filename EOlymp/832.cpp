#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getLis(vector<int> &a) {
    vector<int> lisLast(a.size() + 1, 1e9);
    lisLast[0] = -1e9;
    vector<int> lisLastIndex(a.size() + 1, -1);
    vector<int> from(a.size(), -1);

    for (int i = 0; i < a.size(); i++) {
        int lisSize = lower_bound(lisLast.begin(), lisLast.end(), a[i]) - lisLast.begin();
        lisLast[lisSize] = a[i];
        lisLastIndex[lisSize] = i;
        from[i] = lisLastIndex[lisSize - 1];
    }

    int lisSize = a.size();
    while (lisLast[lisSize] == 1e9)
        lisSize--;

    vector<int> lis;
    for (int i = lisLastIndex[lisSize]; i != -1; i = from[i])
        lis.push_back(a[i]);
    reverse(lis.begin(), lis.end());

    return lis;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> lis = getLis(a);

    cout << lis.size() << "\n";
    for (int value : lis)
        cout << value << " ";
}