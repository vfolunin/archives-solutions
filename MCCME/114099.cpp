#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    deque<int> res;
    while (!a.empty()) {
        res.push_back(a.back());
        a.pop_back();

        if (!a.empty()) {
            res.push_front(a.back());
            a.pop_back();
        }
    }

    for (int value : res)
        cout << value << " ";
}