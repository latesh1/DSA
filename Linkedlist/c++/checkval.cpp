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
int lengthofll(Node* head){
    int count=0;
    Node* temp = head;
     while(temp){
        // cout<<temp->data<<" ";
        temp=temp->next;
        count++;
    }
    return count;
}
int checkifpresent(Node* head,int val){
    Node *temp = head;
    while(temp){
        if(temp->data==val)return 1;
        temp = temp->next;
    }
    return 0;
}

int main()
{
    vector<int> arr = {12, 3, 8, 7};
    Node* head = convertarrtolink(arr); 
    cout <<checkifpresent(head,8);
   
}