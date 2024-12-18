#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> lis(vector<int> &a) {
    vector<int> lisSize(a.size(), 1), from(a.size(), -1);

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && lisSize[i] < lisSize[j] + 1) {
                lisSize[i] = lisSize[j] + 1;
                from[i] = j;
            }
        }
    }

    vector<int> res;
    for (int i = max_element(lisSize.begin(), lisSize.end()) - lisSize.begin(); i != -1; i = from[i])
        res.push_back(a[i]);
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    for (int value : lis(a))
        cout << value << " ";
}