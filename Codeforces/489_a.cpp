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

    cout << a.size() - 1 << "\n";
    for (int i = 0; i < a.size() - 1; i++) {
        int j = min_element(a.begin() + i, a.end()) - a.begin();
        swap(a[i], a[j]); 

        cout << i << " " << j << "\n";
    }
}