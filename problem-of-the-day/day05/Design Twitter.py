class Twitter:
    def __init__(self):
        self.user_tweets = {}  # key = userId : value = deque of their tweets
        self.user_follows = {} # key = userId : value = set of whom they follow
        self.clock = 0 # even though self.user_tweets preserves order for a user, we need a clock to compare tweet times across users

    def postTweet(self, userId: int, tweetId: int) -> None:
        if userId not in self.user_tweets:
            self.user_tweets[userId] = deque()
        
        if userId not in self.user_follows:
            self.user_follows[userId] = set([userId])

        self.user_tweets[userId].append((self.clock, tweetId))
        self.clock += 1
        if len(self.user_tweets[userId]) > 10:
            self.user_tweets[userId].popleft() # discard the oldest tweet

    def getNewsFeed(self, userId: int) -> List[int]:
        if userId not in self.user_follows:
            self.user_follows[userId] = set([userId])

        n = len(self.user_follows[userId])
        index_to_pick = [-1] * n # tracks current most recent tweet
        feed = []

        # we want to pick 10 max elements from n sorted lists 
        while len(feed) < 10:
            max_time = -1
            max_tweet = None
            max_followee = None

            for i, followee in enumerate(self.user_follows[userId]):
                # if possible, consider the last index (most recent tweet) of each followee 
                if followee in self.user_tweets and (-index_to_pick[i]) <= len(self.user_tweets[followee]):
                    time, tweet = self.user_tweets[followee][index_to_pick[i]]
                    if time > max_time:
                        max_time = time
                        max_tweet = tweet
                        max_followee = i

            if max_followee is None:  # no more tweets
                break

            index_to_pick[max_followee] -= 1  # move to previous index in the list for this followee
            feed.append(max_tweet)

        return feed

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId not in self.user_follows:
            self.user_follows[followerId] = set([followerId])

        self.user_follows[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followerId in self.user_follows and followeeId in self.user_follows[followerId]:
            self.user_follows[followerId].remove(followeeId)