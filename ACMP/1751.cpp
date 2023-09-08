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

    int i = 0;
    while (i + 1 < size && a[i + 1] * 2 < width)
        i++;

    cout << a[i];
    if (width % 2 == 0 || a[i] != width / 2)
        cout << " " << a[i + 1];
}