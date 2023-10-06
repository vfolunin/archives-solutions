class TodoList {
    unordered_map<int, set<pair<int, int>>> userTasks;
    unordered_map<int, unordered_map<string, set<pair<int, int>>>> userTagTasks;
    unordered_map<int, vector<string>> taskTags;
    unordered_map<int, string> taskName;
    unordered_map<int, int> taskDeadline;
    int nextTaskId = 1;

public:    
    int addTask(int userId, const string &name, int deadline, const vector<string> &tags) {
        userTasks[userId].insert({ deadline, nextTaskId });
        for (const string &tag : tags)
            userTagTasks[userId][tag].insert({ deadline, nextTaskId });
        taskTags[nextTaskId] = tags;
        taskName[nextTaskId] = name;
        taskDeadline[nextTaskId] = deadline;
        return nextTaskId++;
    }
    
    vector<string> getAllTasks(int userId) {
        vector<string> res;
        for (auto &[deadline, taskId] : userTasks[userId])
            res.push_back(taskName[taskId]);
        return res;
    }
    
    vector<string> getTasksForTag(int userId, const string &tag) {
        vector<string> res;
        for (auto &[deadline, taskId] : userTagTasks[userId][tag])
            res.push_back(taskName[taskId]);
        return res;        
    }
    
    void completeTask(int userId, int taskId) {
        if (!taskDeadline.count(taskId) || !userTasks[userId].count({ taskDeadline[taskId], taskId }))
            return;
        userTasks[userId].erase({ taskDeadline[taskId], taskId });
        for (string &tag : taskTags[taskId])
            userTagTasks[userId][tag].erase({ taskDeadline[taskId], taskId });
        taskTags.erase(taskId);
        taskName.erase(taskId);
        taskDeadline.erase(taskId);
    }
};