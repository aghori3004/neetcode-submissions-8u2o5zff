class LRUCache {
private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;
    list<pair<int, int>> cacheList; 

public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
    }
    
    int get(int key) {
        if (this->cacheMap.find(key) == this->cacheMap.end()) return -1;
        this->cacheList.splice(this->cacheList.begin(), this->cacheList, cacheMap[key]);
        return this->cacheMap[key] -> second;
    }
    
    void put(int key, int value) {
        if(this->cacheMap.find(key) != this->cacheMap.end()){
            this->cacheMap[key]->second = value;
            this->cacheList.splice(this->cacheList.begin(), this->cacheList, this->cacheMap[key]);
            return;
        } 
        if (this->cacheMap.size() == this -> capacity){
            this->cacheMap.erase(this->cacheList.back().first);
            this->cacheList.pop_back();
        } 
        this->cacheList.push_front({key, value});
        this->cacheMap[key] = this->cacheList.begin();
    }
};
