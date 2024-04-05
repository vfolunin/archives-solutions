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

    deque<int> a(size);
    for (int &value : a)
        cin >> value;

    deque<int> b(size);
    for (int &value : b)
        cin >> value;

    int res = 0;
    while (!a.empty()) {
        while (a.front() != b.front()) {
            res++;
            a.push_back(a.front());
            a.pop_front();
        }

        res++;
        a.pop_front();
        b.pop_front();
    }

    cout << res;
}