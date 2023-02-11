class Solution {
    string getHost(string &url) {
        return url.substr(0, url.find('/', 7));
    }

public:
    vector<string> crawl(string &start, HtmlParser &parser) {
        unordered_set<string> visited;
        queue<string> q;

        visited.insert(start);
        q.push(start);

        string host = getHost(start);

        while (!q.empty()) {
            string v = q.front();
            q.pop();

            for (string &to : parser.getUrls(v)) {
                if (getHost(to) == host && !visited.count(to)) {
                    visited.insert(to);
                    q.push(to);
                }
            }
        }

        return { visited.begin(), visited.end() };
    }
};