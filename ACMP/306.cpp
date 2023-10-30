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

    string s;
    for (int i = 0; i < size; i++)
        s.push_back(i % 2 ? 'R' : 'B');

    deque<char> res;
    while (1) {
        res.push_front(s.back());
        s.pop_back();
        
        if (s.empty())
            break;

        res.push_front(res.back());
        res.pop_back();
    }

    for (char c : res)
        cout << c;
}