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

    int a, size;
    cin >> a >> size;

    for (int i = 0; i < size; i++) {
        int b;
        cin >> b;

        if (abs(a - b) <= 100)
            cout << "fite me! >:3\n";
        else
            cout << "go away! 3:<\n";
    }
}