class Solution {
    long long ipToNum(string &s) {
        stringstream ss(s);
        long long res = 0;
        for (int i = 0; i < 4; i++) {
            int part;
            ss >> part;
            ss.get();
            res = (res << 8) + part;
        }
        return res;
    }

    string numToCidr(long long num, int k) {
        stringstream ss;
        for (int i = 3; i >= 0; i--)
            ss << ((num >> (i * 8)) & 0xff) << (i ? "." : "/");
        ss << k;
        return ss.str();
    }

public:
    vector<string> ipToCIDR(string &lIp, int count) {
        long long l = ipToNum(lIp), r = l + count;
        vector<string> res;

        while (l < r) {
            int p = 32;
            while ((l & ((1LL << p) - 1)) || l + (1LL << p) > r)
                p--;
            
            res.push_back(numToCidr(l, 32 - p));

            l += 1LL << p;
        }

        return res;
    }
};