#include <vector>
using namespace std;

bool f(int n) {
    static vector<int> memo(1e6 + 1, -1);
    int &res = memo[n];
    
    if (res != -1)
        return res;
    
    if (n == 1)
        return res = 1;
    
    res = 0;
    int sum = 0;
    for (; n; n /= 10)
        sum += (n % 10) * (n % 10);
    return res = f(sum);
}