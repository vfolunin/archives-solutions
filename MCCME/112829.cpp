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

    int width, size;
    cin >> width >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int res = 0, to = -1;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] && to < i) {
            res++;
            to = i + width - 1;
        }
    }

    cout << res;
}