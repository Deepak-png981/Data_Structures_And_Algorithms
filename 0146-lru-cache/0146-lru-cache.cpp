class LRUCache {
    
public:
    class Node{
        public:
        int key;
        int val;
        Node* next;
        Node*prev;
        Node(int key_ , int val_){
            key = key_;
            val = val_;
        }
        
    };
    Node* head = new Node(-1 , -1);
    Node* tail = new Node(-1,-1);
    int cap;
    unordered_map<int , Node*>mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* newnode){
        Node* temp = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode->next = temp;
        temp->prev = newnode;
        
    }
    void deleteNode(Node* delnode){
        Node* delpre = delnode->prev;
        Node* delnext = delnode->next;
        delpre->next = delnext;
        delnext->prev = delpre;
    }
    int get(int key_) {
        if(mp.find(key_) != mp.end()){
            Node* resnode = mp[key_];
            int resval = resnode->val;
            //value store kerne ke baad ush node ko 
            //waha se erase kerke head ke kareeb create ker rhe hai
            //taki LRU ban ske
            mp.erase(key_);
            deleteNode(resnode);
            addNode(resnode);
            mp[key_] = head->next;
            return resval;
        }
        //agar key nhi hai to return -1
        return -1;
        
    }
    
    void put(int key_, int value) {
        //agar key already exist ker rhi hai to
        if(mp.find(key_) != mp.end()){
            Node* resval = mp[key_];
            mp.erase(key_);
            deleteNode(resval);
        }
        //agar capacity or size barabad ho jaye to
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        //CREATING the new node
        Node* newnode = new Node(key_ , value);
        addNode(newnode);
        mp[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */