class Solution {
    void rec(string &s, int i, vector<string> &ip, vector<string> &ips) {
        if (i == s.size()) {
            if (ip.size() == 4)
                ips.push_back(ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3]);
            return;
        }
        
        if (ip.size() > 4)
            return;
        
        for (int size = 1; size <= 3 && i + size <= s.size(); size++) {
            int val = stoi(s.substr(i, size));
            if (0 <= val && val <= 255 && (size == 1 || s[i] != '0')) {
                ip.push_back(to_string(val));
                rec(s, i + size, ip, ips);
                ip.pop_back();
            }
        }
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ip, ips;
        rec(s, 0, ip, ips);
        return ips;
    }
};