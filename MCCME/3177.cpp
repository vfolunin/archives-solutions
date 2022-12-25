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
 
    vector<int> a;
    int value;

    while (cin >> value)
        a.push_back(value);

    int shift = a.back();
    a.pop_back();

    int size = a.size();
    shift = (shift % size + size) % size;
    rotate(a.begin(), a.end() - shift, a.end());

    for (int value : a)
        cout << value << " ";
}