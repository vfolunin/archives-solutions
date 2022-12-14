#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getLis(vector<int> &a) {
    vector<int> lisSize(a.size(), 1);
    vector<int> from(a.size(), -1);

    for (int i = 1; i < a.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && lisSize[i] < lisSize[j] + 1) {
                lisSize[i] = lisSize[j] + 1;
                from[i] = j;
            }
        }
    }

    vector<int> lis;
    for (int i = max_element(lisSize.begin(), lisSize.end()) - lisSize.begin(); i != -1; i = from[i])
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