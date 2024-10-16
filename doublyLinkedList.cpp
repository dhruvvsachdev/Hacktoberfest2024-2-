#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    
    Node(int data1,Node* next1, Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};
Node* convertArray2DLL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=prev->next;
    }
    
    return head;
}
Node* delhead(Node* head){
    
    if(head==NULL || head->next==NULL){
        return nullptr;
    }
    Node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    
    return head;
}


Node* delTail(Node* head){
    Node* p=head;
    Node* q=head->next;
    
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    
    p->next=nullptr;
    q->back=nullptr;
    delete q;
    
    return head;
}


Node* delAtKthNode(Node* head,int index){
    Node* temp=head;
    int count=0;
    
    while(temp!=NULL){
        temp=temp->next;
        count++;
        
        if(count==index)
        break;
    }
    
    Node* prev=temp->back;
    Node* front=temp->next;
    
    if(prev==NULL && front==NULL){
        delete temp;
        return nullptr;
    }
    
    else if(prev==NULL){
        head=delhead(head);
        return head;
    }
    
    else if(front==NULL){
        head=delTail(head);
        return head;
    }
    
    else{
        prev->next=front;
        front->back=prev;
        
        temp->next=NULL;
        temp->back=NULL;
        
        free(temp);
        
        return head;
    }
}

Node* InsertBeforeHead(Node* head, int val){
    Node* newHead=new Node(val,head,nullptr);
    head->back=newHead;
    
    return newHead;
}

Node* InsertionBeforeTail(Node* head,int val){
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* prev=temp->back;
    
  Node* newNode=new Node(val,temp,prev);
   prev->next=newNode;
  temp->back=newNode;
 
  
  return head;
    
}
void PrintLL(Node* head){
    Node* temp=head;
    
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
}
int main(){
    vector<int> arr={1,2,3,4,5,6,7};
    
   Node* head=convertArray2DLL(arr);
   PrintLL(head);
   cout << endl;

 
 
 head=InsertBeforeHead(head,10);
 PrintLL(head);
  cout << endl;
  head=InsertionBeforeTail(head,69);
  PrintLL(head);
  cout << endl;
   
   return 0;
}
