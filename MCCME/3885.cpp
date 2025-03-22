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

    int minPos = min_element(a.begin(), a.end()) - a.begin();
    rotate(a.begin(), a.begin() + minPos, a.begin() + minPos + 1);

    for (int value : a)
        cout << value << " ";
}