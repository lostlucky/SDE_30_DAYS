class LRUCache {
    
    struct ListNode{
        
        int key, value;
        ListNode *next, *prev;
        
        ListNode(int key, int value){
            this -> key = key;
            this -> value = value;
            next = NULL;
            prev = NULL;
        }
        
    };
    
    int capacity;
    unordered_map<int, ListNode*>node;
    ListNode *head, *tail;
    
public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
        head = new ListNode(0,0);
        tail = new ListNode(0,0);
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        
        if(!node.count(key)) return -1;
        
        ListNode* curr = node[key];
        
        if(curr -> prev) curr -> prev -> next = curr -> next;    // Removing the node from existing position
        if(curr -> next) curr -> next -> prev = curr -> prev;
        
        curr -> prev = head;                    // Adding links of curr to front
        curr -> next = head -> next;
        
        curr -> prev -> next = curr;            // Inserting the node
        curr -> next -> prev = curr;
        
        return node[key] -> value;
        
    }
    
    void put(int key, int value) {
        
        if(node.count(key)){
            node[key] -> value = value;
            get(key);
        }
        
        else{
            
            if(!capacity){
                                                     
                ListNode* toDelete = tail -> prev;
                                                    
                toDelete -> prev -> next = tail;
                tail -> prev = toDelete -> prev;
                
                toDelete -> prev = NULL;
                toDelete -> next = NULL;
                node.erase(toDelete -> key);
                toDelete = NULL;
                delete toDelete;
                
            }
            
            else capacity--;
            
            ListNode *curr = new ListNode(key, value);   // Inserting the node
            node[key] = curr;
            get(key);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
