class MyHashMap {
public:
    MyHashMap() {}
    vector<pair<int,int>>mp;
    void put(int key, int value) {
        int low=0;
        int high=mp.size()-1;
        while(low<=high){
            int mid=(high+low)/2;
            if(mp[mid].first==key){
                mp[mid].second=value;
                return;
            }
            if(mp[mid].first>key)high=mid-1;
            else low=mid+1;
        }
        mp.insert(mp.begin()+low,{key,value});
    }
    
    int get(int key) {
        int low=0;
        int high=mp.size()-1;
        while(low<=high){
            int mid=(high+low)/2;
            if(mp[mid].first==key)return mp[mid].second;
            else if(mp[mid].first>key)high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
    
    void remove(int key) {
        int low=0;
        int high=mp.size()-1;
        while(low<=high){
            int mid=(high+low)/2;
            if(mp[mid].first==key){
                mp.erase(mp.begin()+mid);
                return;
            }
            else if(mp[mid].first>key)high=mid-1;
            else low=mid+1;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */