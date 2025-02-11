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
    int aSum = 0;
    for (int &value : a) {
        cin >> value;
        aSum += value;
    }

    int bSize;
    cin >> bSize;

    vector<int> b(bSize);
    int bSum = 0;
    for (int &value : b) {
        cin >> value;
        bSum += value;
    }

    for (int value : (aSum * bSize > bSum * aSize ? a : b))
        cout << value << " ";
}