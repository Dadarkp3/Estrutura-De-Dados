// Created by Daiane Silva on 08/11/21.
//
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void start(node ** queue, int * size)
{
    (*queue)->next = NULL;
    *size = 0;
}

int isEmpty(node *queue)
{
    return queue->next == NULL;
}



node *alocate()
{
    node *new =(node *) malloc(sizeof(node));
    if(!new){
        printf("No memory available.\n");
        exit(1);
    }else{
        while (getchar() != '\n');
        scanf("%50[0-9a-zA-Z ]", new->title);
        while (getchar() != '\n');
        return new;
    }
}

void add(node ** queue, int *size)
{
    node *new = alocate();
    new->next = NULL;

    if(isEmpty(*queue))
        (*queue)->next = new;
    else{
        node *tmp = (*queue)->next;
        while(tmp->next != NULL) tmp = tmp->next;
        tmp->next = new;
    }
    (*size)++;
}

void removeNode(node ** queue, int * size){
    if((*queue)->next == NULL){
        printf("Lista Vazia\n");
    }else{
        node *tmp = (*queue)->next;
        (*queue)->next = tmp->next;
        printf("%s\n", tmp->title);
        freeNode(&(tmp));
        (*size)--;
    }
}

void freeNode(node ** queue){
    if(!isEmpty(*queue)){
        node *nextNode,
                *nodeInPlace;

        nodeInPlace = (*queue)->next;
        while(nodeInPlace != NULL){
            nextNode = nodeInPlace->next;
            free(nodeInPlace);
            nodeInPlace = nextNode;
        }
    }
}