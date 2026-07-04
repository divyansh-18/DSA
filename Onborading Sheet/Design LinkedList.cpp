class MyLinkedList {

    struct Node {
        int val;
        Node* prev;
        Node* next;

        Node(int x) {
            val = x;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* headDummy;
    Node* tailDummy;
    int size;

    Node* getNode(int index) {

        Node* current;

        if(index < size / 2) {

            current = headDummy->next;

            for(int i = 0; i < index; i++) {
                current = current->next;
            }

        } else {

            current = tailDummy->prev;

            for(int i = size - 1; i > index; i--) {
                current = current->prev;
            }
        }

        return current;
    }

public:

    MyLinkedList() {

        headDummy = new Node(0);
        tailDummy = new Node(0);

        headDummy->next = tailDummy;
        tailDummy->prev = headDummy;

        size = 0;
    }

    int get(int index) {

        if(index < 0 || index >= size)
            return -1;

        return getNode(index)->val;
    }

    void addAtHead(int val) {

        addAtIndex(0, val);
    }

    void addAtTail(int val) {

        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {

        if(index < 0 || index > size)
            return;

        Node* prevNode;
        Node* nextNode;

        if(index == size) {

            prevNode = tailDummy->prev;
            nextNode = tailDummy;

        } else {

            nextNode = getNode(index);
            prevNode = nextNode->prev;
        }

        Node* newNode = new Node(val);

        newNode->prev = prevNode;
        newNode->next = nextNode;

        prevNode->next = newNode;
        nextNode->prev = newNode;

        size++;
    }

    void deleteAtIndex(int index) {

        if(index < 0 || index >= size)
            return;

        Node* deleteNode = getNode(index);

        Node* prevNode = deleteNode->prev;
        Node* nextNode = deleteNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete deleteNode;

        size--;
    }
};