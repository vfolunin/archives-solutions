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

    int minValue = *min_element(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++)
        if (a[i] == minValue)
            cout << i + 1 << " ";
}