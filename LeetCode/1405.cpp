class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> q;
        if (a)
            q.push({ a, 'a' });
        if (b)
            q.push({ b, 'b' });
        if (c)
            q.push({ c, 'c' });
        
        string res;
        while (!q.empty()) {
            auto [count, c] = q.top();
            q.pop();
            
            if (res.size() < 2 || res[res.size() - 2] != c || res[res.size() - 1] != c) {
                res += c;                
                if (count > 1)
                    q.push({ count - 1, c });
            } else if (!q.empty()) {
                auto [count2, c2] = q.top();
                q.pop();
                
                res += c2;                
                if (count2 > 1)
                    q.push({ count2 - 1, c2 });
                
                q.push({ count, c });
            } else {
                break;
            }
        }
        
        return res;
    }
};