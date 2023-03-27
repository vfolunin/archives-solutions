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

    for (int i = 1; i < a.size(); i++) {
        int index = i;
        while (index && a[index] > a[(index - 1) / 2]) {
            swap(a[index], a[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    for (int value : a)
        cout << value << " ";
}