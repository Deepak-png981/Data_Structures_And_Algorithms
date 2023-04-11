class LRUCache {
public:
    class Node{
        public:
        int key , val;
        Node* prev;
        Node* next;
        Node(int key_ , int value){
            key = key_;
            val = value;
        }
    };
    Node* head = new Node(-1 , -1);
    Node* tail = new Node(-1 , -1);
    int cap;
    unordered_map<int ,Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* newnode){
        Node* temp = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode -> next = temp;
        temp -> prev = newnode;
    }
    void deleteNode(Node* delnode){
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    int get(int key_) {
        if(mp.find(key_) != mp.end()){
            Node* resnode = mp[key_];
            int resval = resnode->val;
            //delete and insert
            mp.erase(key_);
            deleteNode(resnode);
            addNode(resnode);
            mp[key_] = head->next;
            return resval;
        }
        return -1;
    }
    
    void put(int key_, int value) {
        if(mp.find(key_) != mp.end()){
            Node* resnode = mp[key_];
            mp.erase(key_);
            deleteNode(resnode);
        }
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
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