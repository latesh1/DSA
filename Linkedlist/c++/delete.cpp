#include <bits/stdc++.h>
using namespace std;
struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1 )
    {
        data = data1;
        next = nullptr;
    }
};

Node* convertarrtolink(vector<int> &arr){
    Node* head = new Node (arr[0]);
     Node* mover = head;
     for(int i =1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover=temp;
     }  
     return head;
};
Node* removesHead(Node* head){
    if(head==NULL) return head;
    Node* temp =head;
    head= head->next;
    delete temp;
    return head;
}
 void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head= head->next;

    }
    cout<<endl;
 }
int main()
{
    vector<int> arr = {12, 3, 8, 7};
    Node* head = convertarrtolink(arr); 
    // Node* temp = head;
    // while(temp){
    //     cout<<temp->data<<" ";
    //     temp=temp->next;
    // }
    head = removesHead(head);
    print(head);
}