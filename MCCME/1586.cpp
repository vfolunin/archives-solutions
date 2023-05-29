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

    int size, shift;
    cin >> size >> shift;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    shift = (size - shift % size) % size;
    rotate(a.begin(), a.begin() + shift, a.end());

    for (int value : a)
        cout << value << " ";
}