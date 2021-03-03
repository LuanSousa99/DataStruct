#include <stdio.h>
#include <stdlib.h>
#include "hashmap1.h"

int main(){
	struct DataItem* HashArray[SIZE];

	for(int i = 0; i < SIZE; i++)
		HashArray[i] = NULL;

	insertionHM(HashArray,2,10);
	insertionHM(HashArray,2,34);
	insertionHM(HashArray,43,2);
	insertionHM(HashArray,5,130);
	insertionHM(HashArray,7,20);
	insertionHM(HashArray,12,100);
	PrintHM(HashArray);

	struct DataItem* item = searchHM(HashArray,2);

	if(item)
		printf("Item key: %d || data: %d\n",item->key,item->data);

	deletionHM(HashArray,item);
	item = searchHM(HashArray,2);
	deletionHM(HashArray,item);
	PrintHM(HashArray);

	return 0;
}	

int deletionHM(struct DataItem* HashArray[],struct DataItem* item){
	if(item == NULL){
		printf("Não há o que deletar!\n\n");
		return -1;
	}	

	int index = hashcode(item->key);

	while(HashArray[index] != NULL){
		if(HashArray[index]->data == item->data){
			struct DataItem* dummy = (struct DataItem* ) calloc(1,sizeof(struct DataItem* ));
			dummy->key = dummy->data = -1;
			HashArray[index] = dummy;
			return 1;

		}
		
		index++;
		index %= SIZE;	
	}	
}	

struct DataItem* searchHM(struct DataItem* HashArray[],int key){
	int index = hashcode(key);

	while(HashArray[index] != NULL){
		if(HashArray[index]->key == key){
			return HashArray[index];
		}	

		index++;
		index %= SIZE;
	}	

	return NULL;
}	

int insertionHM(struct DataItem* HashArray[],int key,int data){
	struct DataItem* NewItem = (struct DataItem* ) calloc(1,sizeof(struct DataItem*));
	NewItem->data = data;
	NewItem->key = key;

	int index = hashcode(key);

	while((HashArray[index] != NULL) && (HashArray[index]->key != -1)){
		index++;
		index %= SIZE;
	}	

	HashArray[index] = NewItem;

	return 1;
}	

int PrintHM(struct DataItem* HashArray[]){
	for(int i = 0; i < SIZE; i++){
		if((HashArray[i] != NULL) && (HashArray[i]->key != -1)){
			printf("Key: %4d || Data: %4d\n",HashArray[i]->key,HashArray[i]->data);
		}	

		else{
			printf("--\n");
		}	
	}	

	printf("\n\n");
}	

int hashcode(int key){
	int x = key % SIZE;

	return x;
}	
