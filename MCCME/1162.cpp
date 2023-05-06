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

    for (int i = a.size() / 2; i >= 0; i--) {
        int index = i;
        while (index * 2 + 1 < a.size()) {
            int maxChild = index * 2 + 1;
            if (maxChild + 1 < a.size() && a[maxChild] < a[maxChild + 1])
                maxChild++;
            if (a[index] >= a[maxChild])
                break;
            swap(a[index], a[maxChild]);
            index = maxChild;
        }
    }

    for (int value : a)
        cout << value << " ";
}