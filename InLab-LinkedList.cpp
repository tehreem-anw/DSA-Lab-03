#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class LinkedList{
    Node* head;
    Node* tail;
    public:
    LinkedList(){
        head = tail = NULL;
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        Node* temp = head;
        newNode->next = temp;
        head = newNode;
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
    void pop_front(){
        if(head == NULL){
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == NULL) {
            tail = NULL;
        }
    }
    void pop_back(){
         if(head == NULL){
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        tail = prev;
        delete temp;
    }
    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    LinkedList l1;
    cout << "Push front" << endl;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.print();

    cout << "Push back" << endl;
    l1.push_back(6);
    l1.push_back(7);
    l1.push_back(8);
    l1.print();

    cout << "Pop front" << endl;
    l1.pop_front();
    l1.print();

    cout << "Pop back" << endl;
    l1.pop_back();
    l1.print();

    return 0;
}
