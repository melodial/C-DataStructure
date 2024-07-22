#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* bikinNodeBaru(int data){
	struct Node* newNode = 
	 (struct Node*)malloc(sizeof(struct Node));
	 
	 newNode->data = data;
	 newNode->next = NULL;
	 return newNode;
}
//cocok untuk queue
void insertDiBelakang(struct Node** head,int data){
	struct Node* newNode = bikinNodeBaru(data);
	
	if(*head == NULL){ // mengecek apakah node berisi NULL
		*head = newNode; //jika iya, set head pointer ke node baru
		return;
	}
	struct Node* temp = *head; //bikin variabel temp untuk traverse list
	while(temp->next != NULL){//traverse sampai di akhir node
		temp = temp->next;
	}
	temp->next = newNode;// set next pointernya node terakhir agar menununjuk node baru
}

void printTheList(struct Node* head){
	struct Node* temp = head;
	while(temp != NULL){
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}
int main(){
	//node dimulai dari NULL
	struct Node* head = NULL;
	
	insertDiBelakang(&head,1);
	insertDiBelakang(&head,2);
	insertDiBelakang(&head,3);
	insertDiBelakang(&head,4);
	insertDiBelakang(&head,5);
	insertDiBelakang(&head,6);
	printf("Linked list: ");
	printTheList(head);
}
