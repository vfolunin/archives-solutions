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

    vector<int> indexes(1);
    int level = 0;

    for (int i = 0; i < size; i++) {
        string type, name;
        cin >> type >> name;

        int targetLevel = (type.size() - 7) / 3;
        while (level > targetLevel)
            level--;
        while (level < targetLevel) {
            level++;
            if (level == indexes.size())
                indexes.emplace_back();
            else
                indexes[level] = 0;
        }
        indexes[level]++;

        for (int j = 0; j <= level; j++)
            cout << indexes[j] << (j < level ? "." : " ");
        cout << name << "\n";
    }
}