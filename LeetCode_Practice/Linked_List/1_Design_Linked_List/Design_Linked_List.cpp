class Node {
public:
    int val;
    Node *next;
    Node(int x) {
        val = x;
        next = NULL;
    }
};

class MyLinkedList {
public:
    Node *head;
    Node *tail;
    int size;
    
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if (index >= size) {
            return -1;
        }
        if (index == 0) {
            return head->val;
        }
        if (index > 0) {
            Node *tmp = head;
            for (int i = 0; i < index; i++) {
                tmp = tmp->next;
            }
            return tmp->val;
        }
        else {
            return -1;
        }
    }
    
    void addAtHead(int val) {
        Node *node = new Node(val);
        if (size == 0) {
            head = node;
            tail = node;
            size++;
            return;
        }
        if (size > 0) {
            node->next = head;
            head = node;
            size++;
            return;
        }
        return;
    }
    
    void addAtTail(int val) {
        if (size == 0) {
            addAtHead(val);
            return;
        }
        if (size > 0) {
            Node *node = new Node(val);
            tail->next = node;
            tail = node;
            size++;
            return;
        }
    }
    
    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        if (index > size) {
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        // Traverse
        Node *node = new Node(val);
        Node *tmp = head;
        for (int i = 0; i < index-1; i++) {
            tmp = tmp->next;
        }
        node->next = tmp->next;
        tmp->next = node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index <= 0) {
            Node *tmp = head->next;
            head = tmp;
            size--;
            return;
        }
        if (index > size-1) {
            return;
        }
        if (index == size-1) {
            Node *tmp = head;
            for (int i = 0; i < index-1; i++) {
                tmp = tmp->next;
            }
            tail = tmp;
            size--;
            return;
        }
        Node *trav1 = head;
        Node *trav2;
        for (int i = 0; i < index-1; i++) {
            trav1 = trav1->next;
        }
        trav2 = trav1->next->next;
        trav1->next = trav2;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */