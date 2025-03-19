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

    cout << "How many element of numeric array:";
    int size;
    cin >> size;

    vector<int> a(size);
    for (int i = 0; i < a.size(); i++) {
        cout << "The value of a[" << i + 1 << "] is:";
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    cout << "\n\nDESC:\n" << a.size() << " element of numeric array:\n";
    for (int i = 0; i < a.size(); i++)
        cout << "The value of a[" << i + 1 << "] is:" << a[i] << "\n";
}