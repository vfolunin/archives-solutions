struct MaxStack {
    vector<int> s, m;
    
    void push(int v) {
        s.push_back(v);
        if (m.empty() || v > m.back())
            m.push_back(v);
        else
            m.push_back(m.back());
    }
    
    int pop() {
        int res = s.back();
        s.pop_back();
        m.pop_back();
        return res;
    }
    
    bool empty() {
        return s.empty();
    }
    
    int getMax() {
        return m.empty() ? -1e9 : m.back();
    }
};

struct MaxQueue {
    MaxStack in, out;
    
    void push(int v) {
        in.push(v);
    }
    
    void pop() {
        if (out.empty())
            while (!in.empty())
                out.push(in.pop());
        out.pop();
    }
    
    int getMax() {
        return max(in.getMax(), out.getMax());
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &a, int k) {
        MaxQueue window;
        for (int i = 0; i < k; i++)
            window.push(a[i]);
        vector<int> res = { window.getMax() };
        
        for (int i = k; i < a.size(); i++) {
            window.pop();
            window.push(a[i]);
            res.push_back(window.getMax());
        }
        
        return res;
    }
};