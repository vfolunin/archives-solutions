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

    vector<int> pos(2);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        pos[value] = i;
    }

    cout << min(pos[0], pos[1]) + 1;
}