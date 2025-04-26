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
    
    vector<int> count(6);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value]++;
    }

    if (count[3])
        cout << "None";
    else if (count[5] == size)
        cout << "Named";
    else if (count[5] >= count[4])
        cout << "High";
    else
        cout << "Common";
}