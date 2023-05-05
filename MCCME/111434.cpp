#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void line(int spaces, int stars) {
    cout << string(spaces, ' ') << string(stars, '*') << "\n";
}

void triangle(int spaces, int size) {
    for (int i = 1; i <= size; i++)
        line(spaces - i, i * 2 - 1);
}

void tree(int size) {
    for (int i = 1; i <= size; i++)
        triangle(size, i);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int n;
    cin >> n;

    tree(n);
}