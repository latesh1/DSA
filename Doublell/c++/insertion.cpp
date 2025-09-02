#include <bits/stdc++.h>
using namespace std;

struct Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertarrtodll(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* deleteHead(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node* deleteTail(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    Node* newtail = tail->back;
    newtail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

Node* deletek(Node* head, int k) {
    if (head == NULL) return NULL;

    int cnt = 0;
    Node* knode = head;
    while (knode != NULL) {
        cnt++;
        if (cnt == k) break;
        knode = knode->next;
    }

    // if k is larger than length
    if (knode == NULL) return head;

    Node* prev = knode->back;
    Node* front = knode->next;

    if (prev == NULL && front == NULL) {
        // only one node
        delete knode;
        return NULL;
    } else if (prev == NULL) {
        return deleteHead(head);
    } else if (front == NULL) {
        return deleteTail(head);
    }

    prev->next = front;
    front->back = prev;
    knode->next = nullptr;
    knode->back = nullptr;
    delete knode;
    return head;
}
void deleteNode(Node* temp){
    Node* prev=temp->back;
    Node* front = temp->next;
    if(front==NULL){
        prev->next =nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }
    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    free(temp);
}
Node* insertbeforehead(Node* head,int val){
    Node* newHead = new Node(val,head,nullptr);
    head->back=newHead;
    return newHead;
}
Node* insertBeforeTail(Node* head,int val){
    if(head->next==NULL){
        return insertbeforehead(head,val);
    }
    Node* tail=  head;
    while(tail->next!=NULL){
        tail=tail->next;
       }
       Node* prev = tail->back;
       Node* newNode = new Node(val,tail,prev);
       prev->next=newNode;
       tail->back = newNode;
       return head;
}
Node* insertbeforekthelement(Node* head,int k , int val){
    if(k==1){
        return insertbeforehead(head,val);

    }
    Node* temp = head;
    int cnt = 0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k)break;
        temp = temp->next;

    }
    Node* prev = temp->back;
    Node* newNode = new Node (val,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}
void insertBeforeNode(Node* node,int val){
    Node* prev =node->back;
    Node* newNode = new Node (val,node,prev);
    prev->next =newNode;
    node->back = newNode;
}

int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertarrtodll(arr);

    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deletek(head, 4); // delete 4th node
    // head = insertbeforehead(head,10);
    // head = insertBeforeTail(head,10);
    // head = insertbeforekthelement(head,1,10);
    insertBeforeNode(head->next,100);
    print(head);

    return 0;
}
