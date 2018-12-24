#include "priority_queue.h"

int indexx = 0, list[MAX], count = -1;
type priority_queue[MAX], temp;

void swap(int index1, int index2) {
    temp = priority_queue[index1];
    priority_queue[index1] = priority_queue[index2];
    priority_queue[index2] = temp;
}

void check_priority_top(int tempIndex) {
    while(priority_queue[tempIndex].key < priority_queue[dad(tempIndex)].key) {
        swap(tempIndex, dad(tempIndex));
        tempIndex = dad(tempIndex);
    }
}

void check_priority_bottom(int tempIndex) {
    count++;
    while(tempIndex < indexx){
        if(right(tempIndex) < indexx && priority_queue[left(tempIndex)].key > priority_queue[right(tempIndex)].key) {
            swap(tempIndex, right(tempIndex));
            list[count] = tempIndex = right(tempIndex);
        }else if(left(tempIndex) < indexx){
            swap(tempIndex,left(tempIndex));
            list[count] = tempIndex = left(tempIndex);
        }else
          	break;
    }
}

void pop(){
    priority_queue[0].key = 11234567;
    check_priority_bottom(0);  
}

int empty() {
    return priority_queue[0].key != 11234567;  
}

void push(type element) {
    if(count == -1) {
        priority_queue[indexx] = element;
        check_priority_top(indexx++);
    }else{
        priority_queue[list[count]] = element;
        check_priority_top(list[count--]);
    }
}

type top(){
    if(empty())
        return priority_queue[0];
}