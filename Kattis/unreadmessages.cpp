#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int senderCount, messageCount;
    cin >> senderCount >> messageCount;

    unordered_map<int, int> last;
    long long res = 0;
    for (int i = 1; i <= messageCount; i++) {
        int sender;
        cin >> sender;

        res += senderCount - (i - last[sender]);
        last[sender] = i;

        cout << res << "\n";
    }
}