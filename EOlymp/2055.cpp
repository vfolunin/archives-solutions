#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    vector<int> s;
    queue<int> q;
    priority_queue<int> pq;
    bool isStack = 1, isQueue = 1, isPQueue = 1;

    for (int i = 0; i < n; i++) {
        int type, val;
        cin >> type >> val;

        if (type == 1) {
            s.push_back(val);
            q.push(val);
            pq.push(val);
        } else {
            isStack &= !s.empty() && s.back() == val;
            isQueue &= !q.empty() && q.front() == val;
            isPQueue &= !pq.empty() && pq.top() == val;
            if (!s.empty())
                s.pop_back();
            if (!q.empty())
                q.pop();
            if (!pq.empty())
                pq.pop();
        }
    }

    if (isStack + isQueue + isPQueue > 1)
        cout << "not sure\n";
    else if (isStack)
        cout << "stack\n";
    else if (isQueue)
        cout << "queue\n";
    else if (isPQueue)
        cout << "priority queue\n";
    else
        cout << "impossible\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}