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

    vector<string> a = {
        "---------------------",
        "||||\\   \\   /   |   |",
        "|   |    \\ /    |   |",
        "||||/     |     |   |",
        "|   |     |     |   |",
        "||||/     |      \\_/ ",
        "---------------------"
    };

    for (string &row : a)
        cout << row << "\n";
}