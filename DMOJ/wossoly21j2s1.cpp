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

    string code(10, ' ');
    for (char &c : code)
        cin >> c;

    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        int index;
        cin >> index;

        cout << code[index];
    }
}