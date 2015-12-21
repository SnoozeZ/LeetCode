class LRUCache{
private:
    struct CacheContent{
        int key;
        int val;
        CacheContent(int x, int y): key(x), val(y){}
    };
    int cap;
    list<CacheContent> val_list;
    unordered_map<int, list<CacheContent>::iterator> key_it;
    
    void moveToHead(int key){
        list<CacheContent>::iterator it = key_it[key];
        val_list.push_front(*it);
        key_it[key] = val_list.begin();
        val_list.erase(it);
    }
    
public:
    LRUCache(int capacity):cap(capacity) {
    }
    
    int get(int key) {
        if(key_it.count(key) == 0)
            return -1;
        moveToHead(key);
        return key_it[key]->val;
    }
    
    void set(int key, int value) {
        if(key_it.count(key) == 0){ //key not existed
            if(val_list.size() >= cap){
                //key_it.erase(val_list.end()->key);
                key_it.erase(val_list.back().key);
                //val_list.erase(val_list.end()-1);
                val_list.pop_back();
            }
            CacheContent tmp(key, value);
            val_list.push_front(tmp);
            key_it[key] = val_list.begin();
        }else{//key existed
            key_it[key]->val = value;
            moveToHead(key);
        }
    }
    
};
