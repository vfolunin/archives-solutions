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

    int res = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                res++;
            }
        }
    }

    cout << res;
}