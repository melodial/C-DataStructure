#include<stdio.h>
#include<stdlib.h>

//membuat struct untuk nodenya
struct Node{
	int data;
	struct Node* next;
};

//membuat node baru
struct Node*/**<-tipe data**/ buatNode/**<-nama function**/(int data/**parameter**/){
	struct Node* newNode =
	 (struct Node* /**ini tipe data**/)malloc(sizeof(struct Node /**tipe data juga**/));
	 //untuk mengecek apakah memory untuk pembuatan node berhasil dialokasikan atau tidak
	 if(!newNode){
	 	printf("memory erorr\n");
	 	return NULL;
	 }
	 
	 newNode->data = data; //ini bagian value
	 newNode->next = NULL; // ini bagian alamat next node
	 return newNode;
}

//insert node di awal
void insertDiAwal(struct Node** head, int data){
	struct Node* newNode = buatNode(data);//memanggil fungsi buat node
	newNode->next = *head; //menjadikan node baru sebagai head dan menunjuk ke node berikutnya
	*head = newNode;
}

//untuk ngeprint listnya
void printList(struct Node* head){
	struct Node* temp = head;
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp = temp->next; //menunjuk pada node berikutnya
	}
	printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertDiAwal(&head, 1);
    insertDiAwal(&head, 2);
    insertDiAwal(&head, 3);
    insertDiAwal(&head, 4);
 

    printf("Linked List: ");
    printList(head);

  

    return 0;
}

