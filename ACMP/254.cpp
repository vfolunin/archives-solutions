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

    vector<int> res = a;
    
    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int oldValue, newValue;
        cin >> oldValue >> newValue;

        for (int i = 0; i < a.size(); i++)
            if (a[i] == oldValue)
                res[i] = newValue;
    }

    for (int value : res)
        cout << value << " ";
}