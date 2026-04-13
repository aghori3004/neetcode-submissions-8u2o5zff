class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cacheList;
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()) return -1;
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);

        return cacheMap[key] -> second;
    }
    
    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()){
            cacheMap[key] -> second = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            return;
        }

        if (cacheList.size()==capacity){
            int lruKey = cacheList.back().first;
            cacheList.pop_back();
            cacheMap.erase(lruKey);
        }

        cacheList.push_front({key, value});

        cacheMap[key] = cacheList.begin();
    }
};
