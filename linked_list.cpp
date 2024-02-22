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

int lenOfLinkedList(sll **head){

    sll *cur = *head;
    int len = 0;
    while(cur){
        len = len + 1;
        cur = cur->next;
    }

    return len;
}


void appendLinkedList(sll **newHead, sll *node){

    sll * cur = *newHead;
    sll *prev = NULL;

    if (cur == NULL) {
        *newHead = node;
        return;
    }

    while (cur) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = node;
}


void splitLinkedList(sll **head) {

    sll *odd = NULL;
    sll *even = NULL;
    sll *cur = *head;
    sll *nxt = NULL;
    sll *prev = NULL;

    if (!cur) {
        cout << "Split is not possible" << endl;
    }

    if (lenOfLinkedList(head) < 3) {
        cout << "Split is not need becuase it's only two elements" << endl;
    }

    while(cur) {

        // ODD 
        if ((cur->data) % 2 != 0 ) {
            nxt = cur->next;
            cur->next = NULL;
            appendLinkedList(&odd, cur);
            cur = nxt;

        }else {
            nxt = cur->next;
            cur->next = NULL;
            appendLinkedList(&even, cur);
            cur = nxt;
        }
    }

    cur = odd;

    while (cur) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = even;

    *head = odd;
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
    insertDataInSLL(&Head, 7);
    insertDataInSLL(&Head, 8);
    insertDataInSLL(&Head, 9);
    insertDataInSLL(&Head, 10);
    //reverseLinkedList(&Head);
    cout << lenOfLinkedList(&Head) << endl;
    //splitLinkedList(&Head);
    displaySLL(&Head);

    cout << "Linked Program" << endl; 
    return 0;
}