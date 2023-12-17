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

    for (int i = 0; i + 1 < a.size(); i++) {
        for (int j = 0; j + 1 < a.size(); j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);

        for (int value : a)
            cout << value << " ";
        cout << "\n";
    }
}