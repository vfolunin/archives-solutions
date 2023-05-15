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
 
    int aSize;
    cin >> aSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    int bSize;
    cin >> bSize;

    vector<int> b(bSize);
    for (int &value : b)
        cin >> value;

    vector<int> res(a.size() + b.size());
    merge(a.begin(), a.end(), b.begin(), b.end(), res.begin());

    for (int value : res)
        cout << value << " ";
}