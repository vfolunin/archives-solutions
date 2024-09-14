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

    string bestName;
    int bestValue = 0;

    for (int i = 0; i < size; i++) {
        string name;
        int value;
        cin >> name >> value;
        
        if (bestValue < value) {
            bestName = name;
            bestValue = value;
        }
    }

    cout << bestName;
}