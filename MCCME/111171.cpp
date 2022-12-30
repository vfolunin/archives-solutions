#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iterator>
using namespace std;

vector<int> readInts() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    vector<int> a;
    int value;
    while (ss >> value)
        a.push_back(value);

    return a;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a = readInts();
    vector<int> b = readInts();

    vector<int> c;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));

    for (int value : c)
        cout << value << " ";
}