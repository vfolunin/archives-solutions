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

    string name;
    double percentage;
    int size;
    cin >> name >> percentage >> size;
    cin.ignore();

    int count = 0;
    for (int i = 0; i < size; i++) {
        string s;
        getline(cin, s);

        count += s == "ekki plast";
    }

    cout << (count <= size * percentage ? "Jebb" : "Neibb");
}