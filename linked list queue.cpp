#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct queue{
	struct Node* depan;
	struct Node* belakang;
};

//operasi enqueue untuk menambah element ke akhir queue
void enqueue(struct queue* q, int data){
	struct Node* newNode = 
	(struct Node*)malloc(sizeof(struct Node));
	
	newNode->data = data;
	newNode->next = NULL;
	
	if(q->belakang == NULL){
		q->depan = q->belakang = newNode;
		return;
	}
	
	q->belakang->next = newNode;
	q->belakang = newNode;
	printf("%d enqueue ke queue\n",data);
}
//operasi dequeue untuk menghilangkan dan mengembalikan elemen terdepan dari queue
int dequeue(struct queue* q){
	struct Node* temp = q->depan;
	int dequeued = temp->data;
	q->depan = q->depan->next;
	
	if(q->depan == NULL){
		q->belakang = NULL;
	}
	
	free(temp);
	return dequeued;
}

//operasi peek mengembalikan elemen terdepan tanpa menghilangkannya
int peek(struct queue* q){
	if(q->depan == NULL){
		printf("queue kosong\n");
		return -1;
	}
	return q->depan->data;
}
//untuk mengecek apakah queue masih ada
int kosongKah(struct queue* q){
	return q->depan == NULL;
}

int main(){
	struct queue* q = 
	(struct queue*)malloc(sizeof(struct queue));
	
	q->depan = q->belakang = NULL;
	
	enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
	
	printf("element terdepannya->  %d\n", peek(q));
    printf("%d dequeued dari queue\n", dequeue(q));
    printf("element terdepannya-> %d\n", peek(q));

    if (kosongKah(q)) {
        printf("Queue kosong\n");
    } else {
        printf("masih ada Queuenya\n");
    }

    return 0;
}

