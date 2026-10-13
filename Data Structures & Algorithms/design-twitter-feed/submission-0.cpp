class Twitter {
private:
    int timestamp_ = 0;
    std::unordered_map<int, std::vector<int>> connections_;
    std::unordered_map<int, std::vector<std::pair<int, int>>> userPosts_;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userPosts_[userId].push_back(std::pair<int, int>(timestamp_, tweetId));
        ++timestamp_;
    }
    
    vector<int> getNewsFeed(int userId) {
        std::priority_queue<std::tuple<int, int, int, int>> race;
        std::vector<int> out;
        int startIndex = userPosts_[userId].size() - 1;
        if (!userPosts_[userId].empty()) {
            race.push({
                userPosts_[userId][startIndex].first,
                userPosts_[userId][startIndex].second,
                userId,
                startIndex
            });
        }
        for (auto& user : connections_[userId]){
            auto& posts = userPosts_[user];
            if (!posts.empty()){
                int startIndex = posts.size() - 1;
                race.push({posts[startIndex].first, posts[startIndex].second, user, startIndex});
            }
        }
        for (int i=0; i<10; ++i){
            if (race.empty()){
                continue;
            }
            auto winner = race.top();
            int tweetId = get<1>(winner);
            int user = get<2>(winner);
            int index = get<3>(winner);
            race.pop();
            if(index > 0){
                race.push({userPosts_[user][index - 1].first, userPosts_[user][index - 1].second, user, index - 1});
            }
            out.push_back(tweetId);
        }
        return out;
    }
    
    void follow(int followerId, int followeeId) {
        auto& followList = connections_[followerId];
        if (std::find(followList.begin(), followList.end(), followeeId) == followList.end()){
            followList.push_back(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = std::find(connections_[followerId].begin(), connections_[followerId].end(), followeeId);
        if (it != connections_[followerId].end()){
            connections_[followerId].erase(it);
        }
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