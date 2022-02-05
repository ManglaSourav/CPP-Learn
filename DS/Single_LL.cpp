#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class LinkedList {

public:
    Node *head = NULL;

    bool insert(int data) {

//      in c++
        Node *newNode = new Node();
//        in c
/*       struct Node *newNode = (struct Node *)malloc(sizeof(struct Node))
 */
        newNode->data = data;
        newNode->next = NULL;

//        for empty head
        if (head == NULL) {
            head = newNode;
            return true;
        }
        Node *tempNode = head;
        while (tempNode->next != NULL) {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
        return true;
    }

    void printList() {
        if (head == NULL) {
            return;
        }
        Node *tempHead = head;
        while (tempHead != NULL) {
            cout << tempHead->data << " ";
            tempHead = tempHead->next;
        }
        return;
    }

    void deleteFirst() {

        if (head == NULL)
            return;

        Node *tempNode = head;
        head = head->next;
        int data = tempNode->data;
        free(tempNode);
//        return data;

    }

};

//int main() {
//    LinkedList l1;
//    l1.insert(12);
//    l1.insert(11);
//    l1.insert(10);
//    l1.printList();
//    l1.deleteFirst();
////    cout << endl << l1.deleteFirst() << endl;
//    l1.printList();
//    return 0;
//}
