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

    int size, threshold;
    cin >> size >> threshold;

    for (int i = 0; i < size; i++) {
        string name;
        int value;
        cin >> name >> value;

        cout << name << " will " << (value <= threshold ? "not " : "") << "advance\n";
    }
}