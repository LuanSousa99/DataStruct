#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dict.h"

int main(){
	DICT* D = IniciarDict(INITIAL_SIZE);
	
	InsertDict(&D,"chave","TESTE1");
	InsertDict(&D,"chave","TESTE2");
	InsertDict(&D,"chave","TESTE3");
	InsertDict(&D,"t1","TESTE4");
	InsertDict(&D,"key","TESTE5");
	InsertDict(&D,"t2","TESTE6");
	
	PrintDict(D);
	
	DeleteDict(D,"chave","TESTE2");
	PrintDict(D);
	DeleteDict(D,"chave","TESTE1");
	PrintDict(D);
	DeleteDict(D,"chave","TESTE3");
	PrintDict(D);
	DeleteDict(D,"t2","TESTE6");
	
	PrintDict(D);

	ID* aux = searchDict(D,"t1");
	
	if(aux != NULL)
		printf("Aux nome: %s || aux key: %s\n",aux->name,aux->key);
	
	FreeDict(&D);
	return 0;
}	

int GrowDict(DICT** D){
	DICT* D2 = IniciarDict((*D)->size * 2);
	DICT* swap = NULL;
	
	D2->n = (*D)->n;

	for(int i = 0; i < (*D)->size; i++){
		ID* aux = (*D)->table[i];
		D2->table[i] = aux;
	}	
	
	swap = *D;
	*D = D2;
	D2 = swap;
	

}	

int DeleteDict(DICT* D,char* key,char* name){
	int h = hashcode(D,key) % D->size;
	ID* aux = D->table[h];
	ID* prev = aux;
	
	


	if(aux == NULL)
		return -1;	
	
	if(strcmp(name,aux->name) == 0){
		printf("First\n");
		D->table[h] = aux->next;
		return 1;
	}	

	while(aux != NULL){
		
		if(strcmp(name,aux->name) == 0){
			break;
		}	
		
		prev = aux;
		aux = aux->next;
	}	


		

	prev->next = aux->next;
	
	
}	

int InsertDict(DICT** D,char* key,char* name){
	int h = 0;
	ID* aux = (ID* ) calloc(1,sizeof(ID*));

	aux->name = (char* ) name;
	aux->key = (char* ) key;
	aux->next = NULL;


	h = hashcode(*D,key) % (*D)->size;


	aux->next = (*D)->table[h];
	(*D)->table[h] = aux;

	(*D)->n += 1;

	if((*D)->n >= (*D)->size)
		GrowDict(D);

	return 1;

}	

ID* searchDict(DICT* D,char* key){
	int h = hashcode(D,key) % D->size;

	ID* aux = D->table[h];
	
	if(aux != NULL){

		while(aux != NULL){
			if(strcmp(key,aux->key) == 0){
				printf("Achamos!\n\n");
				return aux;
			}	

			aux = aux->next;
		}	
	}

	return NULL;
}	

void PrintDict(DICT* D){
	for(int i = 0; i < D->size; i++){
		int x = 0;
		ID* aux = D->table[i];
		
		if(aux != NULL)
			printf("Indice %d: ",i);
		
		while(aux != NULL){
			printf("Nome: %4s  Key: %4s ||",aux->name,aux->key);
			aux = aux->next;
			x = 1;
		}	
		
		if(x == 1)
			printf("\n");
	}	

	printf("***------------------***\n\n");
}	

void FreeDict(DICT** D){
	ID* aux;
	
	for(int i = 0; i < (*D)->size; i++){
		aux = (*D)->table[i];

		while(aux != NULL){
			ID* temp = aux;
			aux = aux->next;
			free(temp);
			temp->next = NULL;
		}	
	}	

	*D = NULL;
}	

DICT* IniciarDict(int size){
	DICT* d = (DICT* ) calloc(1,sizeof(DICT* ));

	d->n = 0;
	d->size = size;
	
	d->table = (ID** ) calloc(size,sizeof(ID** ));

	for(int i = 0; i < d->size; i++)
		d->table[i] = NULL;

	return d;
}	

int hashcode(DICT* D,char* key){
	char* k = (char* ) key;


	int h = 0;

	while(*k != '\0'){
		h = (h * D->size) + *k;
		(k)++;
	}	

	return h;
}	
