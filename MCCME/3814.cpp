#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void set1(int index);

void set0(int index) {
    if (index == 1) {
        cout << "-1 ";
        return;
    }
    set1(index - 1);
    cout << -index << " ";
    set0(index - 1);
}

void set1(int index) {
    if (index == 1) {
        cout << "1 ";
        return;
    }
    set1(index - 1);
    cout << index << " ";
    set0(index - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int size;
    cin >> size;

    for (int i = size; i; i--)
        set1(i);
}