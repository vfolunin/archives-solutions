#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getLisSize(vector<int> &a) {
    vector<int> lisSize(a.size(), 1);

    for (int i = 1; i < a.size(); i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i] && lisSize[i] < lisSize[j] + 1)
                lisSize[i] = lisSize[j] + 1;

    return *max_element(lisSize.begin(), lisSize.end());
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    cout << getLisSize(a);
}