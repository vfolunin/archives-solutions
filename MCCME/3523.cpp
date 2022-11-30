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
 
    vector<int> a(3);
    for (int &value : a)
        cin >> value;
    sort(a.begin(), a.end());

    vector<int> b(3);
    for (int &value : b)
        cin >> value;
    sort(b.begin(), b.end());

    if (a == b)
        cout << "Boxes are equal";
    else if (a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2])
        cout << "The first box is smaller than the second one";
    else if (a[0] >= b[0] && a[1] >= b[1] && a[2] >= b[2])
        cout << "The first box is larger than the second one";
    else
        cout << "Boxes are incomparable";
}