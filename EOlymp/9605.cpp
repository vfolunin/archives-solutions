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
    for (int i = 0; i < 3; i++) {
        int size;
        cin >> size;

        for (int j = 0; j < size; j++) {
            int value;
            cin >> value;
            
            a.push_back(value);
        }
    }

    sort(a.begin(), a.end());

    for (int value : a)
        cout << value << " ";
}