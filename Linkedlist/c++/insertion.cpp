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
Node* removeTail(Node* head){
    // check for single element in ll where head and tail are same 
    if(head == NULL || head->next ==NULL)return NULL;
    // copy of head
    Node* temp = head;
    // check for the element close to nullptr
   while(temp->next->next !=NULL){
       temp=temp->next; 
   }
//    delete the tail
   delete temp->next;
//    set the element before tail to point to null
   temp->next = nullptr;
   return head;
}
Node* removeK(Node* head,int k){
    if(head==NULL )return head;
    if(k==1){
        Node*temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt =0;
    Node* temp = head;
    Node* prev =NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev =temp;
        temp = temp->next;

    }
    return head;
}
Node* removeelement(Node* head,int el){
    if(head==NULL )return head;
    if(head->data ==el){
        Node*temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    Node* temp = head;
    Node* prev =NULL;
    while(temp!=NULL){
    
        if(temp->data==el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev =temp;
        temp = temp->next;

    }
    return head;
}
Node* insertHead(Node*head ,int val){
    Node* temp =new Node (val,head);
    return temp;
}
Node* inserttail(Node* head,int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp =head;
    while(temp->next!=NULL){
       temp=temp->next;
      
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
     return head;
}
Node* insertPosition(Node*head,int el ,int k){
    if(head==NULL){
        if(k==1){
            return new Node(el);
        }else{
            return head;
        }
    }
    if(k==1){
        return new Node (el,head);
    }
    int cnt =0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        if(cnt==(k-1)){
            Node* x = new Node(el,temp->next);
            temp->next =x;
            break; 
        }
        temp= temp->next;
    }
    return head;
}
Node* insertbeforevalue(Node* head, int el, int val) {
    if (head == NULL) {
        return NULL; // Empty list
    }

    // If value to insert before is at the head
    if (head->data == val) {
        Node* newNode = new Node(el);
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        if (temp->next->data == val) {
            Node* newNode = new Node(el);
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }

    // If val not found, return head unchanged
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
   
    // head = insertHead(head,120);
    head = insertbeforevalue(head,100,7);
    print(head);
}