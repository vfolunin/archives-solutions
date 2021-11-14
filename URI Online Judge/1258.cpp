#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Shirt {
    string name, color, size;

    bool operator < (const Shirt &that) const {
        if (color != that.color)
            return color < that.color;
        if (size != that.size)
            return size > that.size;
        return name < that.name;
    }
};

bool solve(int test) {
    int shirtCount;
    cin >> shirtCount;

    if (!shirtCount)
        return 0;

    vector<Shirt> shirts(shirtCount);
    for (auto &[name, color, size] : shirts) {
        cin.ignore();
        getline(cin, name);
        cin >> color >> size;
    }

    sort(shirts.begin(), shirts.end());

    if (test)
        cout << "\n";
    for (auto &[name, color, size] : shirts)
        cout << color << " " << size << " " << name << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}