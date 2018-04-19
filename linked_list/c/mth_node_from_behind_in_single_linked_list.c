#include <stdio.h>
#include <stdlib.h>

typedef struct single_linked_list_node {
    int data;
    struct single_linked_list_node * next;
} sll_node;

    
sll_node *create_node(int data) {
     sll_node *new_node = (sll_node *)malloc(sizeof(sll_node)); 
     new_node->data = data;
     new_node->next = NULL;
     return new_node;
}

sll_node *insert_data(int data, sll_node *head) {
    sll_node *temp_node = head;
    sll_node *new_node = create_node(data);
    if (temp_node == NULL)
       return new_node;
    
    while(temp_node->next != NULL)
       temp_node = temp_node->next;
 
   temp_node->next = new_node;
   return head;
}

void print_list(sll_node *head) {

    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

sll_node* find_mth_node_from_last(sll_node *head, int m) {
    
    sll_node *current = head, *m_behind = head;
    if (head == NULL)
        return NULL;
   
    while(m > 0){
        if (current->next != NULL)
            current = current->next;
        else
            return NULL;
        m--;
    }

    while (current != NULL) {
        current = current->next;
        m_behind = m_behind->next;
    }

    return m_behind;
}

int main() {
    
    sll_node *head = insert_data(1, NULL);
    head = insert_data(2, head);
    head = insert_data(3, head);
    head = insert_data(4, head);
    head = insert_data(5, head);
    head = insert_data(6, head);
    head = insert_data(7, head);
    head = insert_data(8, head);
    head = insert_data(9, head);    
    head = insert_data(10, head);
    head = insert_data(11, head);
    head = insert_data(12, head);
    head = insert_data(13, head);
    head = insert_data(14, head);
    head = insert_data(15, head);
    print_list(head);

    printf("3rd data from last %d\n", ((sll_node *)find_mth_node_from_last(head, 3))->data);
    printf("5th data from last %d\n", ((sll_node *)find_mth_node_from_last(head, 5))->data);
    return 0;
}

  
  

