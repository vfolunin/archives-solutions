#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;

    list<string> values(size);
    for (string &value : values)
        cin >> value;

    vector<list<string>::iterator> iterators;
    for (auto it = values.begin(); it != values.end(); it++)
        iterators.push_back(it);

    for (int i = 0; i < queryCount; i++) {
        int index;
        string value;
        cin >> index >> value;

        if (value == "L")
            iterators[index]--;
        else if (value == "R")
            iterators[index]++;
        else
            iterators[index] = values.insert(iterators[index], value);
    }

    for (string &value : values)
        cout << value << " ";
}