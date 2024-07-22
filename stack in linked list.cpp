#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
//operasi push untuk menambah element diatas puncak stack
void push(struct Node** top,int data){
	//bikin node baru
	struct Node* newNode = 
	(struct Node*)malloc(sizeof(struct Node));
	
	newNode->data = data;
	newNode->next = *top;
	*top = newNode;
	printf("%d push ke stack\n",data);
}
//operasi pop untuk menghilangkan element dan mengembalikan element puncak dari stack
int poop(struct Node** top){

	struct Node* temp = *top;
	*top = (*top)->next;
	int pooped = temp->data;
	free(temp);
	return pooped;
}
//operasi peek untuk return elemen puncak tanpa menghilangkannya
int peek(struct Node* top){
	//mengecek apakah masih ada element puncaknya stack
	if(top == NULL){
		printf("stack is empty\n");
		return -1;
	}
	return top->data;
}

//mengecek apakah stack sudah kosong
int kosongKah(struct Node* top){
	return top == NULL;
}

int main(){
	struct Node* stack = NULL; //inisialisasi stack kosongan
	
	push(&stack,10);
	push(&stack,20);
	push(&stack,30);
	
	printf("element puncaknya adalah %d\n", peek(stack));
    printf("%d dikeluarkan dari stack\n", poop(&stack));
	printf("element puncaknya adalah %d\n", peek(stack));
	
	if(kosongKah(stack)){
		printf("stack kosong\n");
	}else{
		printf("stack ada isinya \n");
	}
	return 0;
}
