//
// Created by daiane-silva on 15/08/2021.
//

#include <stdio.h>
#include <stdbool.h>

#define SIZE 4


int vector[SIZE];
int last = -1;


bool checkFullList(){
	if(last == SIZE-1){
		return true;
	}
	return false;	
}

void message(char message[]){
	  printf("%s\n", message);
} 

void fullListMessage(){
	message("The list is full.");
}

bool add(int number){
	if(checkFullList()){
		fullListMessage();
		return false;
	}
	last++;
	vector[last] = number;
	message("The number was add to the list.");
	return true;
}

void first(){
	printf("First: %d\n", vector[0]);	
}

void isEmpty(){
	if(last == -1){
		printf("The list is empty\n");
	}else{
		printf("The list is not empty\n");
	}
}

bool removed(int number){
	for(int i = 0; i <= last; i++){
		if(vector[i] == number){
			for(int j = i; j <= last; j++){
				vector[j] = vector[j + 1]; 
			}
			last--;
			message("The number was removed from the list.");
			return true;
		}
	}
	message("The number was not in the list.");
	return false;
}

void print(){
	for(int i = 0; i <= last; i++){
		printf("%d\n", vector[i]);
	}
}

int main(){
	add(20);
	removed(20);
	add(10);
	removed(1);
	removed(10);
	add(40);
	print();
	removed(40);
	print();
	isEmpty();
	add(20);
	isEmpty();
}
