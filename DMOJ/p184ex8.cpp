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
    
    vector<int> count(7);
    for (int i = 0; i < size; i++) {
        char c;
        cin >> c;

        count['A' <= c && c <= 'F' ? c - 'A' : 6]++;
    }

    for (int value : count)
        cout << value << "\n";
}