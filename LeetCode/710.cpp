class Solution {
    minstd_rand gen;
    uniform_int_distribution<int> distr;
    unordered_map<int, int> to;
    
public:
    Solution(int n, vector<int> &a) {
        int limit = n - a.size() - 1;
        distr = uniform_int_distribution(0, limit);
        
        sort(a.begin(), a.end());
        int destination = limit;
        
        for (int value : a) {
            if (value <= limit) {
                do {
                    destination++;
                } while (binary_search(a.begin(), a.end(), destination));
                to[value] = destination;
            }
        }
    }
    
    int pick() {
        int res = distr(gen);
        if (to.count(res))
            res = to[res];
        return res;
    }
};