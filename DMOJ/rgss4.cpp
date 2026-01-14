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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> res = a;
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i])
                res[i] = max(res[i], res[j] + a[i]);

    cout << *max_element(res.begin(), res.end());
}