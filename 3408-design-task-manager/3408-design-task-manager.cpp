class TaskManager {
public:
    set<tuple<int, int, int>> st;
    unordered_map<int, set<tuple<int, int, int>>> mpp;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &task : tasks) {
            auto it = st.insert({-task[2], -task[1], task[0]}).first;
            mpp[task[1]] = it;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        auto it = st.insert({-priority, -taskId, userId}).first;
        mpp[taksId] = it;
    }
    
    void edit(int taskId, int newPriority) {
        auto it = mpp.find(taskId);
        if(it != mpp.end()) {
            st.erase(it->second);
            auto jt = st.insert({-priority, -taskId, it->second->get<2>}).first;
            mpp[taksId] = jt;
        }
    }
    
    void rmv(int taskId) {
        auto it = mpp.find(taskId);
        if (it != mpp.end()) {
            st.erase(it->second);
            mpp.erase(taskId);
        }
    }
    
    int execTop() {
        auto [p, t, u] = *st.begin();
        st.erase(st.begin());
        return u;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */