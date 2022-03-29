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

    vector<int> p(size);
    for (int &value : p) {
        cin >> value;
        value--;
    }

    int res = 0;
    for (int i = 0; i < size; i++) {
        while (p[i] != i) {
            swap(p[i], p[p[i]]);
            res++;
        }
    }

    cout << res;
}