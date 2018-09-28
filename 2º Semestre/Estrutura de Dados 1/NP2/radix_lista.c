#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct _contato{
    char nome[40];
    char fone[30];
    struct _contato *ant;
    struct _contato *prox;
}TpContato;


*radixSort(TpContato *listHead){

    TpContato *ptrArray[10] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    TpContato *tempPtr;
    TpContato *headPtr =  listHead;
    int index, count, i;

    for(index=2; index >= 0; index--){
        for(count=0; count <= 9; count++){
            headPtr = listHead;

            while(headPtr->next != NULL){
                if(headPtr->itemArray[index] == count){
                    tempPtr = ptrArray[count];
                    
                    if(tempPtr == NULL){
                        int number = headPtr->item;
                        tempPtr = new TpContato(number);
                    }else{
                        while(tempPtr->next != NULL){
                            tempPtr = tempPtr->next;
                        }
                        tempPtr->next = new TpContato(headPtr->item);
                    }
                }
               headPtr = headPtr->next;
            }
        }
          headPtr = listHead;

            while(headPtr->next != NULL){
                for(i=0; i<=9; i++){
                    tempPtr = ptrArray[i];

                    while(tempPtr->next != NULL){
                        headPtr->item = tempPtr->item;
                        headPtr = headPtr->next;
                        tempPtr = tempPtr->next;
                    }
                }
            }
    }

    return listHead;
}