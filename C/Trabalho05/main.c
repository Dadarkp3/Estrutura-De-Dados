//
// Created by Daiane Silva on 08/11/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void)
{
    int size;
    node *queue = (node *) malloc(sizeof(node));
    if(!queue){
        printf("No memory available.\n");
        exit(1);
    }else{
        start(&queue, &size);
        int n;
        int selection;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &selection);
            if(selection == 1){
                add(&queue, &size);
            }else if(selection == 2){
                removeNode(&queue, &size);
            }
        }
        free(queue);
    }
}

