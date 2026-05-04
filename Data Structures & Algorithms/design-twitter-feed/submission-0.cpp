class Twitter {
public:
    int time;
    unordered_map<int,unordered_set<int>> followmap;
    unordered_map<int,vector<pair<int,int>>> tweetmap;
    Twitter() {
        time=0;
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweetmap[userId].push_back({time++,tweetId});
        
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> feed=tweetmap[userId];

        for(int followeeId: followmap[userId]){
            feed.insert(feed.end(),tweetmap[followeeId].begin(),tweetmap[followeeId].end());
        }
        sort(feed.begin(),feed.end(),[](auto &a,auto &b){
            return a.first>b.first;

        });

        vector<int> res;
        for (int i = 0; i < min(10, (int)feed.size()); ++i) {
            res.push_back(feed[i].second);
        }
        return res;
        
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            followmap[followerId].insert(followeeId);
        }
        
    }
    
    void unfollow(int followerId, int followeeId) {
        followmap[followerId].erase(followeeId);
        
    }
};
