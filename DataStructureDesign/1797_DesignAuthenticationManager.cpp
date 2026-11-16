class AuthenticationManager {

struct Token {
    string id;
    int expiration;
};

list<Token> tList;
unordered_map<string, list<Token>::iterator> tMap;
int ttl;

public:
    AuthenticationManager(int timeToLive) : ttl(timeToLive) {
        
    }
    
    void generate(string tokenId, int currentTime) {
        auto it = tList.insert(
            tList.end(),
            {tokenId, currentTime + ttl}
        );

        tMap[tokenId] = it;
    }
    
    void renew(string tokenId, int currentTime) {
        auto tIt = tMap.find(tokenId);

        if (tIt != tMap.end() && tIt->second->expiration > currentTime) {
            tIt->second->expiration = currentTime + ttl;
            tList.splice(tList.end(), tList, tIt->second);
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        auto tIt = tList.begin();

        while (tIt != tList.end() && tIt->expiration <= currentTime) {
            auto id = tIt->id;
            tIt = tList.erase(tList.begin());
            tMap.erase(id);
        }

        return tList.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
