#include <iostream>
using namespace std;

struct Node {
   int data;
   struct Node *next;
};

struct Node* head = NULL;

void insertAtHead(Node* &head, int data) {
//    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* node = new Node();
    node->data = data;
    node->next = head;
    head = node;
}


void insertAtLast(Node* &head, int val){

    Node* newNode = new Node();

    newNode->data = val;
    newNode->next = NULL;

    if(head==NULL){
        head = newNode;
        return;
    }
    
    Node* tempNode = head;
    while(tempNode->next!=NULL)
        tempNode = tempNode->next;

    tempNode->next = newNode;

}

void insertAtPos(int n, int val, Node* &head){
    Node* newNode = new Node();

    newNode->data = val;
    newNode->next = NULL;        
        
    Node* tempNode = head; 
        

    for(int i = 1; i<n; i++){
        tempNode = tempNode->next;
    }
        
    newNode->next= tempNode->next;

    tempNode->next = newNode;

}

void deleteAtFirst(Node* &head){
   if(head==NULL){
      return;
   }
   Node *temp = new Node();
   *temp = *head;
   *head = *head->next;
   free(temp);
   return;
}

void deleteAtEnd(Node* &head){
    Node *prev = new Node();
    Node *temp = new Node();

    *temp= *head;
    while(temp->next!=NULL){
        prev= temp;
        temp=temp->next;
    }
   free(temp);
   prev->next= NULL;
   return;
}

void deleteAtPos(Node* &head, int pos){
    if(head == NULL)
        return;

    Node* temp = head;

    while(temp != NULL && pos > 1){
        temp = temp->next;
        pos--;
    }

    if (temp == NULL || temp->next == NULL)
        return;

    Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void print(Node* &head) {
   Node* ptr = new Node();
   ptr = head;
   cout<<"LINKED LIST IS: "<<endl;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}

void findNthFromEnd(Node* &head, int n){
    Node* h, *s = head;
    while(n){
        s = s->next;
        n--;
    }
    while(s->next!=NULL){
        h = h->next;
        s= s->next;
    }
    cout<<"Nth Node from End: "<<s->data<<endl;
}

void mid(Node* &head){
    int count = 0;
    Node *s = head;
    while(s!=NULL){
        count++;
        s = s->next;
    }
    int mid = count/2;
    if(count&1==0)
        --mid;
    s = head;
    while(mid--)
        s = s->next;

    cout<<"MID AT: "<<s->data<<endl;
}

void midSlowAndFast(Node* &head){
    Node* slow, *fast = head;

    while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<"MID AT: "<<slow->data<<endl;
}

int main(){

    insertAtHead(head, 5);
    insertAtHead(head, 6);
    insertAtHead(head, 7);
    insertAtLast(head, 8);
    insertAtHead(head, 10);
    insertAtHead(head, 11);

    insertAtPos(1, 9, head);
    // deleteAtEnd(head);
    // deleteAtPos(head, 2);
    // mid(head);
    midSlowAndFast(head);
    findNthFromEnd(head, 4);
    print(head);

    return 0;

}
