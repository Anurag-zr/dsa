//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
// Node *flatten(Node *root)
// {
//   // Your code here
//   if(root==NULL) return root;
//   if(root->next == NULL) return root;
   
//   Node* cur = root;
//   Node* prev = new Node(0);
//   Node* botm = cur;
//   Node* next = cur->next;
   
   
//   while(botm->data<=next->data && botm!=NULL){
//       prev = botm;
//       botm = botm->bottom;
//   }
   
//   cout<<prev->data<<endl;
//   if(prev->data == 0){
//   prev->bottom = flatten(next);
//   cur = prev->bottom;
//   }
//   else{
//       prev->bottom = flatten(next);
//   }
//   Node* temp = prev;
   
//   while( temp->bottom!=NULL && temp->bottom->data<=botm->data){
//       temp=temp->bottom;
//   }
   
//   botm->bottom = temp->bottom;
//   temp->bottom = botm;
   
//   cur->next=NULL;
   
//   return cur;
  
// }

Node* merge(Node* a,Node* b){
    Node* temp = new Node(0);
    Node* res = temp;
    
    while(a!=NULL &&  b!=NULL){
        if(a->data<=b->data){
            temp->bottom =a;
            a=a->bottom;
            temp=temp->bottom;
        }
        else{
            temp->bottom = b;
            b=b->bottom;
            temp=temp->bottom;
        }
    }
    
    if(a==NULL && b!=NULL){
        while(b!=NULL){
            temp->bottom = b;
            b=b->bottom;
            temp=temp->bottom;
        }
    }
    
    if(b==NULL && a!=NULL){
        while(a!=NULL){
            temp->bottom = a;
            a=a->bottom;
            temp=temp->bottom;
        }
    }
    
    return res->bottom;
}

Node* flatten(Node* root){
    if(root==NULL) return NULL;
    if(root->next==NULL) return root;
    
    Node* cur= root;
    
    cur->next = flatten(cur->next);
    
    // while(cur->next->next!=NULL) cur=cur->next;
    
    Node* a = cur; Node* b=cur->next;
    
    Node* temp = new Node(0);
    temp->bottom = merge(a,b);
    
    cur->next=NULL;
    
    
    return temp->bottom;

}

