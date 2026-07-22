class MyHashSet {
public:
    MyHashSet() {}
    vector<int>mp;
    void add(int key) {
        if(contains(key))return;
        int low=0;
        int high=mp.size()-1;
        while(low<=high){
            int mid=(high+low)/2;
            if(mp[mid]>key)high=mid-1;
            else low=mid+1;
        }
        mp.insert(mp.begin()+low,key);
    }
    
    void remove(int key) {
        if(!contains(key))return;
        int low=0;
        int high=mp.size()-1;
        while(low<=high){
            int mid=(high+low)/2;
            if(mp[mid]==key){
                mp.erase(mp.begin()+mid);
                return;
            }
            else if(mp[mid]>key)high=mid-1;
            else low=mid+1;
        }
        
    }
    
    bool contains(int key) {
        int low=0;
        int high=mp.size()-1;
        while(low<=high){
            int mid=(high+low)/2;
            if(mp[mid]>key)high=mid-1;
            else if(mp[mid]<key)low=mid+1;
            else return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */