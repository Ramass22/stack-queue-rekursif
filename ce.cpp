
// #include <iostream>
// using namespace std;

// struct Node{
//     int data;
//     Node* next;
// }; // <-- harus ada titik koma

// void insertFirst(Node*& head, int value){
//     Node* newNode = new Node;
//     newNode->data = value;
//     newNode->next = head;
//     head = newNode;
// }

// int main(){
//     Node* head = NULL; // awalnya kosong

//     // isi data
//     insertFirst(head, 50);
//     insertFirst(head, 70);

//     Node* temp = head;

//     while (temp != NULL) {
//         cout << temp->data;
//         if (temp->next != NULL) {
//             cout << " -> ";
//         }
//         temp = temp->next;
//     }

//     return 0;
// }
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void insertFirst(int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertLast(int value) {
    Node* newNode = createNode(value);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertNext(Node* prevNode, int value) {
    if (prevNode == nullptr) {
        cout << "Node sebelumnya tidak boleh NULL\n";
        return;
    }
    Node* newNode = createNode(value);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != nullptr) {
        prevNode->next->prev = newNode;
    } else {
        tail = newNode;
    }
    prevNode->next = newNode;
}

void printForward() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    insertFirst(10);   // List: 10
    insertFirst(5);    // List: 5 10
    insertLast(20);    // List: 5 10 20
    insertLast(30);    // List: 5 10 20 30

    cout << "List awal: ";
    printForward();

    // Sisipkan setelah node kedua (yaitu setelah 10)
    insertNext(head->next, 15);  
    cout << "Setelah insertNext(10, 15): ";
    printForward();

    return 0;
}