#include <vector>
#include <string>
using namespace std;

long long solve(const string &s, int size) {
    vector<long long> l(26), r(26);
    for (char c : s)
        if (c != ' ')
            r[c - 'a']++;
    
    long long res = 0;
    for (char c : s) {
        if (c == ' ')
            continue;

        r[c - 'a']--;
        for (int i = 0; i < l.size(); i++)
            res += l[i] * r[i];
        l[c - 'a']++;
    }
    return res;
}