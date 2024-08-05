#include <bits/stdc++.h>

#include <utility>

#define endCode return 0
#define el << "\n"

using namespace std;

class Item
{
private:
    string itemName;
    string category;
    int price;
public:
    explicit Item(string i, string c, int p) {
        this->itemName = std::move(i);
        this->category = std::move(c);
        this->price = p;
    }
    bool operator > (const Item& i) const {
        return this->itemName > i.itemName;
    }
    bool operator < (const Item& i) const {
        return this->itemName < i.itemName;
    }
    void print() const {
        cout << "Name: " << itemName << ", Category: " << category << ", Price: " << price el el;
    }
    string getName() const {
        return this->itemName;
    }
    int getPrice() const {
        return this->price;
    }
};

struct Node
{
    Item data;
    Node* left{};
    Node* right{};
    int height;
    explicit Node(Item  t) : data(std::move(t)) {}
};

class BinarySearchTree {

private:
    Node *root;

public:

    BinarySearchTree() {
        root = nullptr;
    }
    Node* getRoot() {
        return root;
    }
    Node* inserting(Node *tmp, const Item& x, char choice) {
        if (tmp == nullptr) {
            tmp = new Node(x);
            tmp->left = tmp->right = nullptr;
        }
        else if (choice == '4' || choice == '5') {
            if (x > tmp->data)
                tmp->right = inserting(tmp->right, x, choice);
            else
                tmp->left = inserting(tmp->left, x, choice);
        }
        else {
            int p1 = x.getPrice(), p2 = tmp->data.getPrice();
            if (p1 <= p2)
                tmp->left = inserting(tmp->left, x, choice);
            else
                tmp->right = inserting(tmp->right, x, choice);
        }
        return tmp;
    }
    void insert(const Item& x, char choice) {
        root = inserting(root, x, choice);
    }
    Node* deleteNode(Node* tmp, const Item& x)
    {
        if (tmp == nullptr)
            return tmp;

        int p1 = x.getPrice(), p2 = tmp->data.getPrice();
        if (p1 > p2) {
            tmp->right = deleteNode(tmp->right, x);
            return tmp;
        }
        else if (p1 <= p2) {
            tmp->left = deleteNode(tmp->left, x);
            return tmp;
        }

        if (tmp->left == nullptr) {
            Node* temp = tmp->right;
            delete tmp;
            return temp;
        }
        else if (tmp->right == nullptr) {
            Node* temp = tmp->left;
            delete tmp;
            return temp;
        }
        Node* sp = tmp;
        Node* s = tmp->right;
        while (s->left != nullptr) {
            sp = s;
            s = s->left;
        }
        tmp->data = s->data;
        if (sp->left == s)
            sp->left = s->right;
        else
            sp->right = s->right;

        delete s;
        return tmp;
    }
    void ascPrint(Node*tmp) {
        if (tmp == nullptr)
            return;
        ascPrint(tmp->left);
        tmp->data.print();
        ascPrint(tmp->right);
    }
    void desPrint(Node*tmp) {
        if (tmp == nullptr)
            return;
        desPrint(tmp->right);
        tmp->data.print();
        desPrint(tmp->left);
    }
    void clear() {
        root = nullptr;
    }
};

class Heap {
private:
    vector<Item> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index].getPrice() < heap[parent].getPrice()) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }


//max heap
    void heapifyUp2(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index].getPrice() > heap[parent].getPrice()) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }


//max heap
    void heapifyDown2(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;
        int maximum= index;
        if (leftChild < heap.size() && heap[leftChild].getPrice() > heap[index].getPrice()) {
            maximum= leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild].getPrice() > heap[smallest].getPrice()) {
            maximum= rightChild;
        }
        if (maximum!= index) {
            swap(heap[index], heap[smallest]);
            heapifyDown2(maximum);
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;
        if (leftChild < heap.size() && heap[leftChild].getPrice() < heap[index].getPrice()) {
            smallest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild].getPrice() < heap[smallest].getPrice()) {
            smallest = rightChild;
        }
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    int findItemIndexByName(const string& name) {
        for (int i = 0; i < heap.size(); ++i) {
            if (heap[i].getName() == name) {
                return i;
            }
        }
        return -1;
    }

public:
    void insert(const Item& x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    void deleteMin(const string& name) {
        int index = findItemIndexByName(name);
        if (heap.empty()) {
            cerr << "Heap is empty!";
        }

        heap[index] = heap.back();
        heap.pop_back();
        if (index < heap.size()) {
            heapifyDown(index);
            heapifyUp(index);
        }
    }

    void Print() {
        for (const auto& i : heap) {
            i.print();
        }
    }

    bool isEmpty() const {
        return heap.empty();
    }

    void ascPrint() {
        sort(heap.begin(), heap.end(), [](const Item& a, const Item& b) {
            return b > a;
        });
        Print();
    }

    void desPrint() {

        sort(heap.begin(), heap.end(), [](const Item& a, const Item& b) {
            return a > b;
        });
        Print();
    }

    void ascPrintByPrice() {

        sort(heap.begin(), heap.end(), [](const Item& a, const Item& b) {
            return a.getPrice() < b.getPrice();
        });
        Print();
    }

    void desPrintByPrice() {

        sort(heap.begin(), heap.end(), [](const Item& a, const Item& b) {
            return a.getPrice() > b.getPrice();
        });
        Print();
    }



    void ascPrint2() {
        sort(heap.begin(), heap.end(), [](const Item& a, const Item& b) {
            return b > a;
        });
        Print();
    }

    void desPrint2() {

        sort(heap.begin(), heap.end(), [](const Item& a, const Item& b) {
            return a > b;
        });
        Print();
    }

    void ascPrintByPrice2() {

        sort(heap.begin(), heap.end(), [](const Item& a, const Item& b) {
            return a.getPrice() > b.getPrice();
        });
        Print();
    }

    void desPrintByPrice2() {

        sort(heap.begin(), heap.end(), [](const Item& a, const Item& b) {
            return a.getPrice() < b.getPrice();
        });
        Print();
    }


};

class AVLTree {
public:
    Node* root;

    AVLTree() : root(nullptr) {}

    int height(Node* n) {
        return n ? n->height : -1;
    }

    int getBalance(Node* n) {
        return n ? height(n->left) - height(n->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* addItem(Node* node, const Item& newItem) {
        if (!node) return new Node(newItem);

        if (newItem < node->data)
            node->left = addItem(node->left, newItem);
        else if (newItem > node->data)
            node->right = addItem(node->right, newItem);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && newItem < node->left->data)
            return rightRotate(node);

        if (balance < -1 && newItem > node->right->data)
            return leftRotate(node);

        if (balance > 1 && newItem > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && newItem < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* minValue(Node* node) {
        Node* current = node;
        while (current->left)
            current = current->left;
        return current;
    }

    Node* removeItem(Node* root, const string& name) {
        if (!root) return root;

        Item tempItem(name, "", 0);
        if (tempItem < root->data)
            root->left = removeItem(root->left, name);
        else if (tempItem > root->data)
            root->right = removeItem(root->right, name);
        else {
            if (!root->left || !root->right) {
                Node* temp = root->left ? root->left : root->right;
                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                delete temp;
            } else {
                Node* temp = minValue(root->right);
                root->data = temp->data;
                root->right = removeItem(root->right, temp->data.getName());
            }
        }

        if (!root) return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inOrder(Node* root) const {
        if (!root) return;
        inOrder(root->left);
        root->data.print();
        inOrder(root->right);
    }

    void preOrder(Node* root) const {
        if (!root) return;
        root->data.print();
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(Node* root) const {
        if (!root) return;
        postOrder(root->left);
        postOrder(root->right);
        root->data.print();
    }
};

void readItems(istream& inputFile, char kindOfTree) {
    string itemName, category, line;
    int price, c = 0;
    getline(inputFile, line);
    vector<Item>items;
    char choice;

    while (getline(inputFile, line))
    {
        if (c == 0)
        {
            itemName = line;
            c++;
        }
        else if (c == 1)
        {
            category = line;
            c++;
        }
        else if (c == 2)
        {
            price = stoi(line);
            Item i(itemName, category, price);
            items.push_back(i);
            c = 0;
        }
    }

    if (kindOfTree == '1') {
        BinarySearchTree tree;
        while (true) {
            cout << "Choose wanted algorithm of tree which you need:\n"
                    "1- Add Item.\n"
                    "2- Remove Item.\n"
                    "3- Display the Item data normally.\n"
                    "4- Display all the items sorted by their name ascending.\n"
                    "5- Display all the items sorted by their name descending.\n"
                    "6- Display all the items sorted by their prices ascending.\n"
                    "7- Display all the items sorted by their prices descending.\n"
                    "0- Stop program.\n"
                    "Your choice =========> ";
            cin >> choice;
            if (choice == '1') {
                cout << "Item need to add Note: first line for name, second line for category third line "
                        "for price:\n";
                cin.ignore();
                getline(cin, itemName);
                getline(cin, category);
                string p;
                getline(cin, p);
                price = stoi(p);
                Item i(itemName, category, price);
                items.push_back(i);
            }
            else if (choice == '2') {
                tree.clear();
                int t = 0;
                bool done = false;
                string name;
                cout << "Item need to remove Note: input its Name: \n";
                cin.ignore();
                getline(cin, name);
                vector<Item>(v);
                for (const auto& i : items) {
                    tree.insert(i, choice);
                    if (name == i.getName() && !done)
                        done = true;
                    else
                        v.push_back(i);
                    if (!done)
                        t++;
                }
                items = v;
                Node *tmp = tree.getRoot();
                tree.deleteNode(tmp, items[t]);
            }
            else if (choice == '3') {
                for (const auto& i : items)
                    i.print();
            }
            else if (choice == '4' || choice == '6') {
                tree.clear();
                for (const auto& i : items)
                    tree.insert(i, choice);
                Node *tmp = tree.getRoot();
                tree.ascPrint(tmp);
            }
            else if (choice == '5' || choice == '7') {
                tree.clear();
                for (const auto& i : items)
                    tree.insert(i, choice);
                Node *tmp = tree.getRoot();
                tree.desPrint(tmp);
            }
            else if (choice == '0')
                break;
            else
                cerr << "Invalid input, try again!\n";
        }
    }
    else if (kindOfTree == '2') {
        Heap heap;
        for (const auto& i : items)
            heap.insert(i);
        while (true) {
            cout << "CHOOSE MAX HEAP (1) OR MIN HEAP (2):  ";
            cin >> choice;
            if (choice == '2'){
                cout << "Choose wanted algorithm of heap which you need:\n"
                        "1- Add Item.\n"
                        "2- Remove Item.\n"
                        "3- Display the Item data normally.\n"
                        "4- Display all the items sorted by their name ascending.\n"
                        "5- Display all the items sorted by their name descending.\n"
                        "6- Display all the items sorted by their prices ascending.\n"
                        "7- Display all the items sorted by their prices descending.\n"
                        "0- Stop program.\n"
                        "Your choice =========> ";
                cin >> choice;
                if (choice == '1') {
                    cout << "Item need to add Note: first line for name, second line for category third line for price:\n";
                    cin.ignore();
                    getline(cin, itemName);
                    getline(cin, category);
                    string p;
                    getline(cin, p);
                    price = stoi(p);
                    Item i(itemName, category, price);
                    heap.insert(i);
                    items.push_back(i);
                }
                else if (choice == '2') {
                    cout << "Item need to remove Note: input its Name: \n";
                    cin.ignore();
                    getline(cin, itemName);
                    auto it = find_if(items.begin(), items.end(), [&](const Item& i) {
                        return i.getName() == itemName;
                    });
                    if (it != items.end()) {
                        heap.deleteMin(itemName);
                        items.erase(it);
                    } else {
                        cout << "Item not found!\n";
                    }
                }
                else if (choice == '3') {
                    for (const auto& i : items)
                        i.print();
                }
                else if (choice == '4') {
                    heap.ascPrint();
                }
                else if (choice == '5') {
                    heap.desPrint();
                }
                else if (choice == '6') {
                    heap.ascPrintByPrice();
                }
                else if (choice == '7') {
                    heap.desPrintByPrice();
                }
                else if (choice == '0')
                    break;
                else
                    cerr << "Invalid input, try again!\n";
            }
            else if (choice == '1'){

            cout << "Choose wanted algorithm of heap which you need:\n"
                    "1- Add Item.\n"
                    "2- Remove Item.\n"
                    "3- Display the Item data normally.\n"
                    "4- Display all the items sorted by their name ascending.\n"
                    "5- Display all the items sorted by their name descending.\n"
                    "6- Display all the items sorted by their prices ascending.\n"
                    "7- Display all the items sorted by their prices descending.\n"
                    "0- Stop program.\n"
                    "Your choice =========> ";
            cin >> choice;
            if (choice == '1') {
                cout << "Item need to add Note: first line for name, second line for category third line for price:\n";
                cin.ignore();
                getline(cin, itemName);
                getline(cin, category);
                string p;
                getline(cin, p);
                price = stoi(p);
                Item i(itemName, category, price);
                heap.insert(i);
                items.push_back(i);
            }
            else if (choice == '2') {
                cout << "Item need to remove Note: input its Name: \n";
                cin.ignore();
                getline(cin, itemName);
                auto it = find_if(items.begin(), items.end(), [&](const Item& i) {
                    return i.getName() == itemName;
                });
                if (it != items.end()) {
                    heap.deleteMin(itemName);
                    items.erase(it);
                } else {
                    cout << "Item not found!\n";
                }
            }
            else if (choice == '3') {
                for (const auto& i : items)
                    i.print();
            }
            else if (choice == '4') {
                heap.ascPrint2();
            }
            else if (choice == '5') {
                heap.desPrint2();
            }
            else if (choice == '6') {
                heap.ascPrintByPrice2();
            }
            else if (choice == '7') {
                heap.desPrintByPrice2();
            }
            else if (choice == '0')
                break;
            else
                cerr << "Invalid input, try again!\n";
        }
    }
    }
    else {
        AVLTree tree;
        while (true) {
            cout << "Choose an option:\n"
                 << "1- Add Item.\n"
                 << "2- Remove Item.\n"
                 << "3- Display the Item data normally.\n"
                 << "4- Display all the items sorted by name ascending.\n"
                 << "5- Display all the items sorted by name descending.\n"
                 << "6- Display all the items sorted by price ascending.\n"
                 << "7- Display all the items sorted by price descending.\n"
                 << "0- Stop program.\n"
                 << "Your choice: ";
            cin >> choice;

            if (choice == '1') {
                cout << "Enter Item details (name, category, price):\n";
                cin.ignore();
                getline(cin, itemName);
                getline(cin, category);
                string p;
                getline(cin, p);
                price = stoi(p);
                Item i(itemName, category, price);
                items.push_back(i);
                tree.root = tree.addItem(tree.root, i);
            } else if (choice == '2') {
                cout << "Enter Item name to remove:\n";
                cin.ignore();
                getline(cin, itemName);
                items.erase(remove_if(items.begin(), items.end(), [&](const Item& i) {
                    return i.getName() == itemName;
                }), items.end());
                tree.root = tree.removeItem(tree.root, itemName);
            } else if (choice == '3') {
                for (const auto& i : items) i.print();
            } else if (choice == '4') {
                sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
                    return a.getName() < b.getName();
                });
                for (const auto& i : items) i.print();
            } else if (choice == '5') {
                sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
                    return a.getName() > b.getName();
                });
                for (const auto& i : items) i.print();
            } else if (choice == '6') {
                sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
                    return a.getPrice() < b.getPrice();
                });
                for (const auto& i : items) i.print();
            } else if (choice == '7') {
                sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
                    return a.getPrice() > b.getPrice();
                });
                for (const auto& i : items) i.print();
            } else if (choice == '0') {
                break;
            } else {
                cerr << "Invalid input, try again!\n";
            }
        }
    }
}

int main()
{
    ifstream InputFile("Items.txt");
    if (!InputFile)
    {
        cerr << "Error, can't open this InputFile!\n";
        cerr << "Note: \"Items\" is the InputFile name of your input InputFile and his source is \".txt\"!\n";
        return 1;
    }

    cout << "Choose wanted kind of tree which you need:\n"
            "1- Binary Search Tree.\n"
            "2- Heap.\n"
            "3- AVL Tree.\nYour choice ======> ";
    char choice;
    cin >> choice;

    switch (choice) {
        case '1':
            readItems(InputFile, '1');
            break;
        case '2':
            readItems(InputFile, '2');
            break;
        case '3':
            readItems(InputFile, '3');
            break;
        default:
            cerr << "Invalid input!";
            break;
    }
    InputFile.close();

    endCode;
}