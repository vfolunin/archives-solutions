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
    int bestScore = -1;

    for (int i = 0; i < size; i++) {
        string name;
        int a, b;
        cin >> name >> a >> b;

        if (bestScore < a * b || bestScore == a * b && bestName > name) {
            bestScore = a * b;
            bestName = name;
        }
    }

    cout << bestName;
}