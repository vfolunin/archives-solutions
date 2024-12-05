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

    cout << "  ";
    for (int i = 0; i < size; i++)
        cout << "H ";
    cout << "\n  ";
    for (int i = 0; i < size; i++)
        cout << "| ";
    cout << "\nH-";
    for (int i = 0; i < size; i++)
        cout << "C-";
    cout << "OH\n  ";
    for (int i = 0; i < size; i++)
        cout << "| ";
    cout << "\n  ";
    for (int i = 0; i < size; i++)
        cout << "H ";
}