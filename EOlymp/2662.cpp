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

    int pos = 0, res = 0;
    for (int i = 0; i < size; i++) {
        int minI = min_element(a.begin() + i, a.end()) - a.begin();
        if (i != minI) {
            swap(a[i], a[minI]);
            if (i == pos || minI == pos) {
                res++;
                pos = i + minI - pos;
            }
        }
    }

    cout << res;
}