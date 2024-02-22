#include <iostream>

using namespace std;

typedef struct LinkedList
{
    int  data;
    struct LinkedList *next;
}sll;

void displaySLL(sll **head) {

    sll *cur =  *head;

    while(cur) {
        cout << cur->data << endl;
        cur = cur->next;
    }
}

void reverseLinkedList(sll **head) {
    sll *cur = *head;
    sll *prev = NULL;
    sll *nxt = NULL;

    while (cur) {
        nxt = cur->next;
        cur->next = prev;
        prev= cur;
        cur = nxt;
    }
    *head = prev;
}



void insertDataInSLL(sll **head, int val){

    sll *tmp = NULL;
    //cout << val << endl;
    if (*head == NULL) {
        tmp = new sll;

        if (tmp != NULL ) {
            tmp->data = val;
            tmp->next = NULL;
        }

        *head = tmp;
        return;

    }else {
        sll *cur = *head;
        sll *prev = NULL;

        while (cur) {
            //cout << cur->data << endl;
            prev = cur;
            cur = cur->next;
        }
        tmp  = new sll;

        if (tmp != NULL) {
            tmp->data = val;
            tmp->next = NULL;
        }

        if (prev) {
            prev->next = tmp;
            return;
        }
        cur->next = tmp;
        *head = cur;
    }
}



int main() {

    sll *Head = NULL;

    insertDataInSLL(&Head, 1);
    insertDataInSLL(&Head, 2);
    insertDataInSLL(&Head, 3);
    insertDataInSLL(&Head, 4);
    insertDataInSLL(&Head, 5);
    insertDataInSLL(&Head, 6);
    reverseLinkedList(&Head);
    displaySLL(&Head);



    cout << "Linked Program" << endl; 
    return 0;
}