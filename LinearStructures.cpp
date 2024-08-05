#include <bits/stdc++.h>

#define fast() cin.tie(NULL),cout.tie(0),ios_base::sync_with_stdio(false)
#define endCode return 0
#define el << "\n"

using namespace std;

template<class T>
class SingleLinkedList {

private:
    struct node {
        T data;
        node* next;
    };
    node *head, *tail;
    int size;

public:

    SingleLinkedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead (T item) {
        node *nw = new node;
        nw->data = item;
        if (head == nullptr) {
            nw->next = nullptr;
            head = nw;
            tail = nw;
        }
        else {
            nw->next = head;
            head = tail = nw;
        }
        size++;
    }

    void insertAtTail (T item) {
        node *nw = new node;
        nw->data = item;
        if (head == nullptr) {
            nw->next = nullptr;
            head = tail = nw;
        }
        else if (tail == head) {
            head->next = nw;
            nw->next = nullptr;
            tail = nw;
        }
        else {
            tail->next = nw;
            nw->next = nullptr;
            tail = nw;
        }
        size++;
    }

    void insertAt (T item, int i) {
        if (i < 0 || i > size)
            cout << "invalid index\n";
        else if (i == 0)
            insertAtHead(item);
        else if (i == size)
            insertAtTail(item);
        else {
            node *nw = new node, *temp = head;
            for (int j = 0; j < i-1; ++j)
                temp = temp->next;

            nw->data = item;
            nw->next = temp->next;
            temp->next = nw;
            size++;
        }
    }

    void removeAtHead () {
        if (head == nullptr)
            cerr << "List is already empty!";
        else {
            node *temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }

    void removeAtTail () {
        if (head == nullptr)
            cerr << "List is already empty!";
        else {
            node *temp = head;
            for (int i = 0; i < size-2; ++i) {
                temp = temp->next;
            }
            temp->next = nullptr;
            tail = temp;
            delete temp;
            size--;
        }
    }

    void removeAt (int i) {
        if (i < 0 || i >= size)
            cerr << "Invalid index!\n";
        else if (i == 0)
            removeAtHead();
        else if (i == size - 1)
            removeAtTail();
        else {
            node *temp = head;
            for (int j = 0; j < i-1; ++j)
                temp = temp->next;

            temp->next = temp->next->next;
            delete temp;
            size--;
        }
    }

    T retrieveAt (int i) {
        if (i < 0 || i >= size)
            cerr << "Invalid index!\n";
        else if (i == 0)
            return head->data;
        else if (i == size - 1)
            return tail->data;
        else {
            node *temp = head;
            for (int j = 0; j < i; ++j){
                temp = temp->next;
            }
            return temp->data;
        }
    }

    void replaceAt (T newItem, int i) {
        if (i < 0 || i >= size)
            cerr << "Invalid index!\n";
        else {
            node* temp = head;
            for (int j = 0; j < i; ++j) {
                temp = temp->next;
            }
            temp->data = newItem;
        }
    }

    bool isExist (T item) {
        node* temp = head;
        for (int i = 0; i < size; ++i) {
            if (temp->data == item)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool isItemAtEqual (T item, int i) {
        if (i < 0 || i >= size)
            cerr << "Invalid index!\n";
        else {
            node* temp = head;
            for (int j = 0; j < i; ++j) {
                temp = temp->next;
            }
            return item == temp->data;
        }
    }

    void swap (int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 || secondItemIdx >= size)
            cerr << "Invalid index!\n";
        else {
            node* temp1 = head, *temp2 = head, *pt1, *pt2;
            if (firstItemIdx != secondItemIdx && abs(firstItemIdx-secondItemIdx) > 1) {
                node *nt1, *nt2;
                int a = min(firstItemIdx, secondItemIdx), b;
                a == firstItemIdx ? b = secondItemIdx : b = firstItemIdx;
                for (int i = 0; i < a; ++i) {
                    if (i == a-1)
                        pt1 = temp1;
                    temp1 = temp1->next;
                }
                for (int i = 0; i < b; ++i) {
                    if (i == b-1)
                        pt2 = temp2;
                    temp2 = temp2->next;
                }
                if (temp1 == head && temp2 == tail)
                {
                    node* temp = temp1->next;
                    temp1->next = nullptr;
                    pt2->next = temp1;
                    tail = temp1;
                    temp2->next = temp;
                    pt2 = nullptr;
                    head = temp2;
                }
                else if (temp1 == head)
                {
                    node* temp = temp1->next;
                    temp1->next = temp2->next;
                    pt1 = pt2;
                    pt2->next = temp1;
                    pt2 = nullptr;
                    temp2->next = temp;
                    head = temp2;
                }
                else if (temp2 == tail)
                {
                    node* temp = pt2;
                    temp2->next = temp1->next;
                    pt2 = pt1;
                    pt1->next = temp2;
                    temp1->next = nullptr;
                    temp->next = temp1;
                    tail = temp1;
                }
                else
                {
                    node *const n = temp1->next, *const p = pt1;
                    temp1->next = temp2->next;
                    pt1 = pt2;
                    pt2->next = temp1;
                    temp2->next = n;
                    pt2 = p;
                    p->next = temp2;
                }
            }
            else if (abs(firstItemIdx-secondItemIdx) == 1) {
                int a = min(firstItemIdx, secondItemIdx), b = a+1;
                for (int i = 0; i < a; ++i) {
                    if (i == a-1)
                        pt1 = temp1;
                    temp1 = temp1->next;
                }
                for (int i = 0; i < b; ++i) {
                    if (i == b-1)
                        pt2 = temp2;
                    temp2 = temp2->next;
                }
                if (temp1 == head && temp2 == tail)
                {
                    temp2->next = temp1;
                    temp1->next = nullptr;
                    head = temp2;
                    tail = temp1;
                }
                else if (temp1 == head)
                {
                    temp1->next = temp2->next;
                    temp2->next = head;
                    head = temp2;
                }
                else if (temp2 == tail)
                {
                    temp2->next = temp1;
                    temp1->next = nullptr;
                    pt1->next = temp2;
                    tail = temp1;
                }
                else
                {
                    node* temp = pt1;
                    temp1->next = temp2->next;
                    pt1 = temp2;
                    temp2->next = temp->next;
                    pt2 = temp;
                    temp->next = temp2;
                }
            }
        }
    }

    bool isEmpty () {
        return head == nullptr;
    }

    int linkedListSize () {
        return size;
    }

    void clear () {
        node *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    void print () {
        node *temp;
        temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout el;
    }
};

template<class T>
class CircularLinkedList {

private:
    struct node {
        T data;
        node* next;
    };
    node *head, *tail;
    int size;

public:

    CircularLinkedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead (T item) {
        node *nw = new node;
        nw->data = item;
        if (head == nullptr) {
            nw->next = nullptr;
            head = nw;
            tail = nw;
        }
        else {
            nw->next = head;
            head = tail = nw;
        }
        size++;
    }

    void insertAtTail (T item) {
        node *nw = new node;
        nw->data = item;
        if (head == nullptr) {
            nw->next = nullptr;
            head = tail = nw;
        }
        else if (tail == head) {
            head->next = nw;
            nw->next = head;
            tail = nw;
        }
        else {
            tail->next = nw;
            nw->next = head;
            tail = nw;
        }
        size++;
    }

    void insertAt (T item, int i) {
        if (i < 0 || i > size)
            cout << "invalid index\n";
        else if (i == 0)
            insertAtHead(item);
        else if (i == size)
            insertAtTail(item);
        else {
            node *nw = new node, *temp = head;
            for (int j = 0; j < i-1; ++j)
                temp = temp->next;

            nw->data = item;
            nw->next = temp->next;
            temp->next = nw;
            size++;
        }
    }

    void removeAtHead () {
        if (head == nullptr)
            cerr << "List is already empty!";
        else {
            node *temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }

    void removeAtTail () {
        if (head == nullptr)
            cerr << "List is already empty!";
        else {
            node *temp = head;
            for (int i = 0; i < size-2; ++i) {
                temp = temp->next;
            }
            temp->next = head;
            tail = temp;
            size--;
        }
    }

    void removeAt (int i) {
        if (i < 0 || i >= size)
            cerr << "Invalid index!\n";
        else if (i == 0)
            removeAtHead();
        else if (i == size - 1)
            removeAtTail();
        else {
            node *temp = head;
            for (int j = 0; j < i-2; ++j)
                temp = temp->next;

            temp->next = temp->next->next;
            size--;
        }
    }

    T retrieveAt (int i) {
        if (i < 0 || i >= size)
            cerr << "Invalid index!\n";
        else if (i == 0)
            return head->data;
        else if (i == size - 1)
            return tail->data;
        else {
            node *temp = head;
            for (int j = 0; j < i; ++j){
                temp = temp->next;
            }
            return temp->data;
        }
    }

    void replaceAt (T newItem, int i) {
        if (i < 0 || i >= size)
            cerr << "Invalid index!\n";
        else {
            node* temp = head;
            for (int j = 0; j < i; ++j) {
                temp = temp->next;
            }
            temp->data = newItem;
        }
    }

    bool isExist (T item) {
        node* temp = head;
        for (int i = 0; i < size; ++i) {
            if (temp->data == item)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool isItemAtEqual (T item, int i) {
        if (i < 0 || i >= size)
            cerr << "Invalid index!\n";
        else {
            node* temp = head;
            for (int j = 0; j < i; ++j) {
                temp = temp->next;
            }
            return item == temp->data;
        }
    }

    void swap (int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 || secondItemIdx >= size)
            cerr << "Invalid index!\n";
        else {
            node* temp1 = head, *temp2 = head, *pt1, *pt2;
            if (firstItemIdx != secondItemIdx && abs(firstItemIdx-secondItemIdx) > 1) {
                node *nt1, *nt2;
                int a = min(firstItemIdx, secondItemIdx), b;
                a == firstItemIdx ? b = secondItemIdx : b = firstItemIdx;
                for (int i = 0; i < a; ++i) {
                    if (i == a-1)
                        pt1 = temp1;
                    temp1 = temp1->next;
                }
                for (int i = 0; i < b; ++i) {
                    if (i == b-1)
                        pt2 = temp2;
                    temp2 = temp2->next;
                }
                if (temp1 == head && temp2 == tail)
                {
                    node* temp = temp1->next;
                    temp1->next = head;
                    pt2->next = temp1;
                    tail = temp1;
                    temp2->next = temp;
                    pt2 = nullptr;
                    head = temp2;
                }
                else if (temp1 == head)
                {
                    node* temp = temp1->next;
                    temp1->next = temp2->next;
                    pt1 = pt2;
                    pt2->next = temp1;
                    pt2 = tail;
                    temp2->next = temp;
                    head = temp2;
                }
                else if (temp2 == tail)
                {
                    node* temp = pt2;
                    temp2->next = temp1->next;
                    pt2 = pt1;
                    pt1->next = temp2;
                    temp1->next = head;
                    temp->next = temp1;
                    tail = temp1;
                }
                else
                {
                    node *const n = temp1->next, *const p = pt1;
                    temp1->next = temp2->next;
                    pt1 = pt2;
                    pt2->next = temp1;
                    temp2->next = n;
                    pt2 = p;
                    p->next = temp2;
                }
            }
            else if (abs(firstItemIdx-secondItemIdx) == 1) {
                int a = min(firstItemIdx, secondItemIdx), b = a+1;
                for (int i = 0; i < a; ++i) {
                    if (i == a-1)
                        pt1 = temp1;
                    temp1 = temp1->next;
                }
                for (int i = 0; i < b; ++i) {
                    if (i == b-1)
                        pt2 = temp2;
                    temp2 = temp2->next;
                }
                if (temp1 == head && temp2 == tail)
                {
                    temp2->next = temp1;
                    temp1->next = head;
                    head = temp2;
                    tail = temp1;
                }
                else if (temp1 == head)
                {
                    temp1->next = temp2->next;
                    temp2->next = head;
                    head = temp2;
                }
                else if (temp2 == tail)
                {
                    temp2->next = temp1;
                    temp1->next = head;
                    pt1->next = temp2;
                    tail = temp1;
                }
                else
                {
                    node* temp = pt1;
                    temp1->next = temp2->next;
                    pt1 = temp2;
                    temp2->next = temp->next;
                    pt2 = temp;
                    temp->next = temp2;
                }
            }
        }
    }

    bool isEmpty () {
        return head == nullptr;
    }

    int linkedListSize () {
        return size;
    }

    void clear () {
//        node *temp;
//        while (head != tail)
//        {
//            temp = head;
//            head = head->next;
//        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void print () {
        if (isEmpty())
            cout << "Array is empty!\n";
        else {
            node *temp;
            temp = head;
            while (temp != tail) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << tail->data el;
        }
    }
};

template <class T>
class DoubleLinkedList {

private:
    struct node {
        T data;
        node* next;
        node* prev;
    };
    node *head,*tail;
    int size;

public:

    DoubleLinkedList(int s = 0) {
        size = s;
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead (T item) {
        node *nw = new node;
        nw->data = item;
        if (head == nullptr) {
            nw->prev = nw->next = nullptr;
            head = tail = nw;
        }
        else {
            nw->next = head;
            head->prev = nw;
            nw->prev = nullptr;
            head = nw;
        }
        size++;
    }

    void insertAtTail (T item) {
        node *nw = new node;
        nw->data = item;
        if (head == nullptr) {
            nw->prev = nw->next = nullptr;
            head = tail = nw;
        }
        else {
            nw->prev = tail;
            nw->next = nullptr;
            tail->next = nw;
            tail = nw;
        }
        size++;
    }

    void insertAt (T item, int i) {
        if (i < 0 || i > size)
            cerr << "Invalid index!\n";
        else if (i == 0)
            insertAtHead(item);
        else if (i == size)
            insertAtTail(item);
        else {
            node *nw = new node, *temp = head;
            for (int j = 0; j < i; ++j)
                temp = temp->next;

            nw->data = item;
            nw->next = temp;
            nw->prev = temp->prev;
            temp->prev->next = nw;
            temp->prev = nw;
            size++;
        }
    }

    void removeAtHead () {
        if (head == nullptr)
            cout << "list is already empty";
        else {
            node *temp = head;
            head = head->next;
            delete temp;
            head->prev = nullptr;
            size--;
        }
    }

    void removeAtTail () {
        if (head == nullptr)
            cout << "list is already empty";
        else {
            node *temp = tail;
            tail = tail->prev;
            delete temp;
            tail->next = nullptr;
            size--;
        }
    }

    void removeAt (int i) {
        if (i < 0 || i >= size)
            cerr << "Invalid index!\n";
        else if (i == 0)
            removeAtHead();
        else if (i == size - 1)
            removeAtTail();
        else {
            node *temp = head;
            for (int j = 0; j < i; ++j)
                temp = temp->next;

            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
            size--;
        }
    }

    T retrieveAt (int i) {
        if (i < 0 || i >= size)
            cerr << "Invalid index!\n";
        else if (i == 0)
            return head->data;
        else if (i == size - 1)
            return tail->data;
        else {
            node *temp = head;
            for (int j = 0; j < i; ++j){
                temp = temp->next;
            }
            return temp->data;
        }
    }

    void replaceAt (T newItem, int i) {
        if (i < 0 || i >= size)
            cerr << "Invalid index!\n";
        else {
            node *temp = head;
            for (int j = 0; j < i; ++j) {
                temp = temp->next;
            }
            temp->data = newItem;
        }
    }

    bool isExist (T item) {
        node* temp = head;
        for (int i = 0; i < size; ++i) {
            if (temp->data == item)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool isItemAtEqual (T item, int i) {
        if (i < 0 || i >= size)
            cerr << "Invalid index!\n";
        node* temp = head;
        for (int j = 0; j < i; ++j) {
            temp = temp->next;
        }
        return item == temp->data;
    }

    void swap (int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 || secondItemIdx >= size)
            cerr << "Invalid index!\n";
        else {
            node *temp1 = head, *temp2 = head;
            if (firstItemIdx != secondItemIdx && abs(firstItemIdx - secondItemIdx) > 1) {
                int a = min(firstItemIdx, secondItemIdx), b;
                a == firstItemIdx ? b = secondItemIdx : b = firstItemIdx;
                for (int i = 0; i < a; ++i) {
                    temp1 = temp1->next;
                }
                for (int i = 0; i < b; ++i) {
                    temp2 = temp2->next;
                }

                if (temp1 == head && temp2 == tail) {
                    node *temp = temp1->next;
                    temp1->next = nullptr;
                    temp1->prev = temp2->prev;
                    temp2->prev->next = temp1;
                    tail = temp1;
                    temp2->next = temp;
                    temp2->prev = nullptr;
                    temp->prev = temp2;
                    head = temp2;
                } else if (temp1 == head) {
                    node *temp = temp1->next;
                    temp1->next = temp2->next;
                    temp1->prev = temp2->prev;
                    temp2->next->prev = temp1;
                    temp2->prev->next = temp1;
                    temp2->prev = nullptr;
                    temp2->next = temp;
                    temp->prev = temp2;
                    head = temp2;
                } else if (temp2 == tail) {
                    node *temp = temp2->prev;
                    temp2->next = temp1->next;
                    temp2->prev = temp1->prev;
                    temp1->next->prev = temp2;
                    temp1->prev->next = temp2;
                    temp1->next = nullptr;
                    temp1->prev = temp;
                    temp->next = temp1;
                    tail = temp1;
                } else {
                    node *const n = temp1->next, *const p = temp1->prev;
                    temp1->next = temp2->next;
                    temp1->prev = temp2->prev;
                    temp2->next->prev = temp1;
                    temp2->prev->next = temp1;
                    temp2->next = n;
                    temp2->prev = p;
                    n->prev = temp2;
                    p->next = temp2;
                }
            } else if (abs(firstItemIdx - secondItemIdx) == 1) {
                int a = min(firstItemIdx, secondItemIdx), b = a + 1;
                for (int i = 0; i < a; ++i) {
                    temp1 = temp1->next;
                }
                for (int i = 0; i < b; ++i) {
                    temp2 = temp2->next;
                }

                if (temp1 == head && temp2 == tail) {
                    node *temp = temp1;
                    temp1->next = nullptr;
                    temp1->prev = temp->prev;
                    temp2->next = temp2->prev;
                    temp2->prev = nullptr;
                    head = temp2;
                    tail = temp1;
                } else if (temp1 == head) {
                    node *temp = temp1;
                    temp1->next = temp2->next;
                    temp1->prev = temp->next;
                    temp2->next->prev = temp1;
                    temp2->next = temp1;
                    temp2->prev = nullptr;
                    temp2->next = temp;
                    head = temp2;
                } else if (temp2 == tail) {
                    node *temp = temp2;
                    temp2->next = temp1->prev;
                    temp2->prev = temp1->prev;
                    temp1->prev->next = temp2;
                    temp1->next = nullptr;
                    temp1->prev = temp->next;
                    temp->next = temp1;
                    tail = temp1;
                } else {
                    node *temp = temp1->prev;
                    temp1->next = temp2->next;
                    temp1->prev = temp2;
                    temp2->next->prev = temp1;
                    temp2->next = temp->next;
                    temp2->prev = temp;
                    temp->next = temp2;
                }
            }
        }
    }

    bool isEmpty () {
        return head == nullptr;
    }

    int linkedListSize () {
        return size;
    }

    void clear () {
        node *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    void print () {
        node *current;
        current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout el;
    }
};

template<class T>
class StackLinkedList {

private:
    struct Node {
        T value;
        Node* next;
        Node(T val) : value(val), next(nullptr) {}
    };
    Node* topNode;

public:
    StackLinkedList() {
        topNode = nullptr;
    }

    void push(T element) {
        Node* newNode = new Node(element);
        newNode->next = topNode;
        topNode = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Error: Stack Underflow\n";
            return -1;
        }
        T poppedValue = topNode->value;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return poppedValue;
    }

    int top() {
        if (isEmpty()) {
            cout << "Error: Stack is empty\n";
            return -1;
        }
        return topNode->value;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    int stackSize() {
        int count = 0;
        Node* current = topNode;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack: ";
        Node* current = topNode;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

template<class T>
class StackArray {

private:
    static const int MAX_SIZE = 100;
    int stack[MAX_SIZE];
    int topIndex;

public:

    StackArray() {
        topIndex = -1;
    }

    void push (T item) {
        if (topIndex < MAX_SIZE - 1) {
            topIndex++;
            stack[topIndex] = item;
        }
    }

    T pop () {
        if (!isEmpty()) {
            int topElement = stack[topIndex];
            topIndex--;
            return topElement;
        }
        else {
            return INT_MIN;
        }
    }

    T top () {
        if (!isEmpty()) {
            return stack[topIndex];
        }
        else {
            return INT_MIN;
        }
    }

    bool isEmpty () {
        return topIndex == -1;
    }

    int stackSize () {
        return topIndex + 1;
    }

    void clear () {
        topIndex = -1;
    }

    void print () {
        for (int i = topIndex; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

template<class T>
class QueueLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node* front;
    Node* rear;
    int size;

public:

    QueueLinkedList() : front(nullptr), rear(nullptr), size(0) {}

    void enqueue (T item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    T dequeue () {
        if (isEmpty()) {
            cerr << "Error: Queue is empty";
            exit;
        }
        Node* temp = front;
        T value = temp->data;
        front = front->next;
        delete temp;
        size--;
        return value;
    }

    T first () {
        if (isEmpty()) {
            cerr << "Queue is empty";
            exit;
        }
        return front->data;
    }

    bool isEmpty () {
        return size == 0;
    }

    int queueSize () {
        return size;
    }

    void clear () {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void print () {
        if (isEmpty()) {
            cout << "Queue is empty";
            return;
        }
        cout << "Queue elements: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

template<class T>
class QueueArray {
private:
    T* elements;
    int front;
    int rear;
    int capacity;
    int size;

public:
    explicit QueueArray(int capacity = 10) : front(0), rear(-1), capacity(capacity), size(0) {
        elements = new T[capacity];
    }

    void enqueue(T item) {
        if (isFull()) {
            cerr << "Queue is full\n";
        }
        else {
            rear = (rear + 1) % capacity;
            elements[rear] = item;
            size++;
        }
    }

    T dequeue() {
        if (isEmpty()) {
            cerr << "Queue is empty\n";
        }
        else {
            T value = elements[front];
            front = (front + 1) % capacity;
            size--;
            return value;
        }
    }

    T first() {
        if (isEmpty()) {
            cerr << "Queue is empty\n";
        }
        else
            return elements[front];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    int queueSize() {
        return size;
    }

    void clear() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        }
        else {
            cout << "Queue elements: ";
            int current = front;
            for (int i = 0; i < size; ++i) {
                cout << elements[current] << " ";
                current = (current + 1) % capacity;
            }
            cout el;
        }
    }
};

int main()
{
    fast();



    endCode;
}