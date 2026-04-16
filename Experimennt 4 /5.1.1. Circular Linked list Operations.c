#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;

// Create a new node with given data
NODE createNodeInCLL(int data) {
    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Create CLL with n nodes
NODE createCLL(int n) {
    NODE first = NULL, last = NULL, temp;
    int x;

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        temp = (NODE)malloc(sizeof(struct node));
        temp->data = x;
        temp->next = NULL;

        if(first == NULL) {
            first = last = temp;
            last->next = first;
        } else {
            last->next = temp;
            last = temp;
            last->next = first;
        }
    }
    return first;




}

// Traverse CLL
void traverseListInCLL(NODE first) {
    NODE temp = first;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != first);

    printf("\n");


}

// Insert at given position in CLL
NODE insertAtPositionInCLL(NODE first, int pos, int x) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = x;

    if(pos == 1) {
        if(first == NULL) {
            temp->next = temp;
            return temp;
        }
        NODE last = first;
        while(last->next != first)
            last = last->next;

        temp->next = first;
        last->next = temp;
        first = temp;
        return first;
    }

    NODE cur = first;
    for(int i = 1; i < pos-1 && cur->next != first; i++)
        cur = cur->next;

    if(cur->next == first && pos > 2) {
        printf("Position not found\n");
        free(temp);
        return first;
    }

    temp->next = cur->next;
    cur->next = temp;
    return first;




}

// Delete node at given position in CLL
NODE deleteAtPositionInCLL(NODE first, int pos) {
    NODE temp, cur;

    if(pos == 1) {
        if(first->next == first) {
            printf("Deleted element: %d\n", first->data);
            free(first);
            return NULL;
        }

        NODE last = first;
        while(last->next != first)
            last = last->next;

        temp = first;
        printf("Deleted element: %d\n", temp->data);
        first = first->next;
        last->next = first;
        free(temp);
        return first;
    }

    cur = first;
    for(int i = 1; i < pos-1 && cur->next != first; i++)
        cur = cur->next;

    if(cur->next == first) {
        printf("Position not found\n");
        return first;
    }

    temp = cur->next;
    printf("Deleted element: %d\n", temp->data);
    cur->next = temp->next;
    free(temp);
    return first;


}

// Reverse CLL
NODE reverseCLL(NODE first) {
    NODE prev = NULL, cur = first, next;
    NODE last = first;

    while(last->next != first)
        last = last->next;

    do {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    } while(cur != first);

    first->next = prev;
    first = prev;
    return first;


}

// Concatenate two CLLs
NODE concatCLL(NODE first, NODE second) {
    if(first == NULL) return second;
    if(second == NULL) return first;

    NODE last1 = first;
    while(last1->next != first)
        last1 = last1->next;

    NODE last2 = second;
    while(last2->next != second)
        last2 = last2->next;

    last1->next = second;
    last2->next = first;

    return first;


}

int main() {
    NODE first = NULL, second = NULL;
    int x, pos, op, n;

    while (1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                first = createCLL(n);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 5:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    traverseListInCLL(first);   // <-- display reversed list
                }
                break;
            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d", &n);
                second = createCLL(n);
                first = concatCLL(first, second);
                printf("Concatenated CLL:\n");
                traverseListInCLL(first);
                break;
            case 7:
                exit(0);
        }
    }
}
