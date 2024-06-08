class Twitter {
public:
    unordered_map<int,unordered_set<int>>ds;
    //This Data Structure will store list of twitter users and corresponding to each user there will be a set consiting of userid whom the user follow;
    vector<pair<int,int>>posts;
    //this vector will store the list of posts ::each post will have a tweetId and
    //the userId of the user Who posted it
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {

        posts.push_back({tweetId,userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        //If current user tries to retrieve 10 most recent post then he will be able to retrieve the posts that he himself posted or the post posted by another user whom current user follow
        vector<int>ans;

        //Iterate from last of posts since we want most recent
        int count=1;
        for(int i=posts.size()-1;i>=0&&count<=10;i--){
            int Post_UserId=posts[i].second;
            int post_Id=posts[i].first;
            if(Post_UserId==userId||ds[userId].find(Post_UserId)!=ds[userId].end()){
                ans.push_back(post_Id);
                count++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        //If A follows B then in a set corresponding to A  insert B
        ds[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        //If A unfollows B then from a set corresponding to A remove B
        ds[followerId].erase(followeeId);
    }
};