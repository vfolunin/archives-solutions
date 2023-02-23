class Solution {
    unordered_set<string> visited;
    queue<string> q;
    string host;

    mutex m;
    condition_variable cv;
    int workerCount = 0;

    string getHost(string &url) {
        return url.substr(0, url.find('/', 7));
    }

    void bfs(HtmlParser &parser) {
        while (1) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&]() { return !q.empty() || !workerCount; });

            if (q.empty())
                break;

            string v = q.front();
            q.pop();

            workerCount++;            
            lock.unlock();

            for (string &to : parser.getUrls(v)) {
                if (getHost(to) == host && !visited.count(to)) {
                    lock.lock();
                    visited.insert(to);
                    q.push(to);
                    lock.unlock();
                }
            }

            lock.lock();
            workerCount--;
            cv.notify_all();
        }
    }

public:
    vector<string> crawl(string &start, HtmlParser &parser) {
        visited.insert(start);
        q.push(start);

        host = getHost(start);

        vector<future<void>> futures;
        for (int i = 0; i < 5; i++)
            futures.push_back(async(&Solution::bfs, this, ref(parser)));

        for (auto &f : futures)
            f.get();        

        return { visited.begin(), visited.end() };
    }
};