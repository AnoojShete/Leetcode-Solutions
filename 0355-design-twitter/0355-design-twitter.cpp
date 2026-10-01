class Twitter {
public:
    unordered_map<int, unordered_set<int>> follows; // user -> following
    unordered_map<int, vector<pair<int, int>>> tweets; // user -> [time, tweet]
    int count = 0; // tweets
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++count, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> news;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for(auto [cnt, tweet] : tweets[userId]) {
            pq.push({cnt, tweet});
            if(pq.size() > 10) pq.pop();
        }
        for(auto following : follows[userId]) {
            for(auto [cnt, tweet] : tweets[following]) {
                pq.push({cnt, tweet});
                if(pq.size() > 10) pq.pop();
            }
        }
        while(!pq.empty()) news.push_back(pq.top().second), pq.pop();
        reverse(news.begin(), news.end());
        return news;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */