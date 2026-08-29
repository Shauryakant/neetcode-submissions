class Node{
    public:
    int val;
    int key;
    Node* next;
    Node* prev;
    Node(int val,int key) {
        this->val=val;
        this->key=key;
        next=nullptr;
        prev=nullptr;
    }
};
class LRUCache {
public:
    int capacity;
    Node* head=new Node(0,-1);
    Node* tail=new Node(0,-1);
    unordered_map<int,Node*>m;
    
    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void insertAthead(Node* n) {
        head->next->prev=n;
        n->next=head->next;
        head->next=n;
        n->prev=head;
    }
    void deleteAtPos(Node* n) {
        n->prev->next=n->next;
        n->next->prev=n->prev;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        else {
            Node* node=m[key];
            deleteAtPos(node);
            insertAthead(node);
            return node->val;
        }
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()) {
            m[key]->val=value;
            deleteAtPos(m[key]);
            insertAthead(m[key]);
        }
        else {
            if(capacity==0) {
                Node* n=tail->prev;
                deleteAtPos(tail->prev);
                m.erase(n->key);
                Node* node=new Node(value,key);
                m[key]=node;
                insertAthead(node);
            }
            else {
                Node* node=new Node(value,key);
                m[key]=node;
                insertAthead(node);
                capacity--;
            }
        }
    }
};
