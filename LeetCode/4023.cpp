class Solution {
    long long rec(int l, int r, int lastLeft, vector<int> &requests, vector<vector<vector<long long>>> &memo) {
        long long &res = memo[l][r][lastLeft];
        if (res != -1)
            return res;
        
        if (!l && r == requests.size() - 1)
            return res = 0;
        
        res = 1e18;
        long long remainingCount = requests.size() - (r - l + 1);
        long long from = requests[lastLeft ? l : r];
        if (l)
            res = min(res, rec(l - 1, r, 1, requests, memo) + remainingCount * abs(from - requests[l - 1]));
        if (r + 1 < requests.size())
            res = min(res, rec(l, r + 1, 0, requests, memo) + remainingCount * abs(from - requests[r + 1]));
        return res;
    }

public:
    long long elevatorRequests(int floorCount, int start, vector<int> &requests) {
        sort(requests.begin(), requests.end());
        int i = lower_bound(requests.begin(), requests.end(), start) - requests.begin();
        if (i == requests.size() || requests[i] != start)
            requests.insert(requests.begin() + i, start);
        
        vector memo(requests.size(), vector(requests.size(), vector<long long>(2, -1)));
        return rec(i, i, 1, requests, memo);
    }
};