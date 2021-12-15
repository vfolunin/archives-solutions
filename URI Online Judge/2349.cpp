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

    int postCount, opCount, targetPost;
    cin >> postCount >> opCount >> targetPost;

    targetPost--;
    int res = !targetPost;

    int post = 0;
    for (int i = 0; i < opCount; i++) {
        int op;
        cin >> op;
        post = (post + op + postCount) % postCount;
        res += post == targetPost;
    }

    cout << res << "\n";
}