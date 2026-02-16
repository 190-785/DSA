class MyLinkedList {
public:
    int val;
    MyLinkedList* next;
    MyLinkedList* head;

    MyLinkedList() { head = nullptr; }

    MyLinkedList(int x) {
        val = x;
        next = nullptr;
    }

    MyLinkedList(int x, MyLinkedList* node) {
        val = x;
        next = node;
    }

    int get(int index) {
        int count = 0;
        MyLinkedList* curr = head;
        while (curr != nullptr) {
            if (count == index) {
                return curr->val;
            }
            count++;
            curr = curr->next;
        }
        return -1;
    }

    void addAtHead(int val) {
        MyLinkedList* node = new MyLinkedList(val);
        node->next = head;
        head = node;
    }

    void addAtTail(int val) {
        MyLinkedList* node = new MyLinkedList(val);
        if (head == nullptr) {
            head = node;
            return;
        }
        MyLinkedList* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = node;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        int count = 0;
        MyLinkedList* curr = head;
        while (curr != nullptr) {
            if (count == index - 1) {
                MyLinkedList* node = new MyLinkedList(val);
                node->next = curr->next;
                curr->next = node;
                return;
            }
            count++;
            curr = curr->next;
        }
    }

    void deleteAtIndex(int index) {
        if (head == nullptr) {
            return;
        }
        if (index == 0) {
            MyLinkedList* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        int count = 0;
        MyLinkedList* curr = head;
        while (curr->next != nullptr) {
            if (count == index - 1) {
                MyLinkedList* temp = curr->next;
                curr->next = temp->next;
                delete temp;
                return;
            }
            count++;
            curr = curr->next;
        }
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
