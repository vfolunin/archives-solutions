class Solution {
public:
    string splitLoopedString(vector<string> &a) {
        vector<string> b = a;
        for (string &s : b)
            reverse(s.begin(), s.end());

        string res;

        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[i].size(); j++) {
                string candidate = a[i].substr(j), end = a[i].substr(0, j);
                for (int di = 1; di < a.size(); di++)
                    candidate += max(a[(i + di) % a.size()], b[(i + di) % a.size()]);
                candidate += end;
                res = max(res, candidate);
                
                candidate = b[i].substr(j);
                end = b[i].substr(0, j);
                for (int di = 1; di < a.size(); di++)
                    candidate += max(a[(i + di) % a.size()], b[(i + di) % a.size()]);
                candidate += end;
                res = max(res, candidate);
            }
        }

        return res;
    }
};