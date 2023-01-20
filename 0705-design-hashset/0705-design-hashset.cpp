class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next =NULL;
    }
};
class MyHashSet {
public:
    Node* head = NULL;
    MyHashSet() {
        
    }
    
    void add(int key) {
        Node*curr = head;
        while(curr != NULL){
            if(curr -> data == key)
                return;
            curr = curr->next;
        }
        Node* newnode = new Node(key);
        newnode -> next = head;
        head = newnode;
    }
    
    void remove(int key) {
        Node* curr = head , *prev = NULL;
        while(curr != NULL){
            if(curr->data == key)
                break;
            prev = curr;
            curr = curr->next;
        }
        if(curr == NULL)    return;
        if(prev == NULL) {
            head = head->next;
            return;
        }
        else
            prev->next = curr->next;
    }
    
    bool contains(int key) {
        Node* temp = head;
        while(temp != NULL){
            if(temp -> data == key)
                return true;
            temp = temp->next;
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