#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "ADTPriorityQueue.h"
#include "ADTSet.h"

int compare_int(Pointer p_a, Pointer p_b)
{
    int* a = p_a;
    int* b = p_b;
    int a_v = *a;
    int b_v = *b;
    return a_v - b_v;
}

void destroy_value(Pointer pointer)
{
    free(pointer);
}

// Δεσμεύει μνήμη για έναν ακέραιο, αντιγράφει το value εκεί και επιστρέφει pointer
int* create_int(int value) {
	int* pointer = malloc(sizeof(int));		// δέσμευση μνήμης
	*pointer = value;						// αντιγραφή του value στον νέο ακέραιο
	return pointer;
}

int* create_random_int()
{
    int random_num = rand() % 101;
    return create_int(random_num);
}

int main() {
    
    srand(time(NULL));

    PriorityQueue priority_queue = pqueue_create(compare_int, destroy_value, NULL);

    for(int i = 0; i < 20; i++)
    {
        int* random_value = create_random_int();
        pqueue_insert(priority_queue, random_value);
    }

    for(int i = 0; i < 20; i++)
    {
        int* current_value = pqueue_max(priority_queue);
        printf("%d\t", *current_value);
        pqueue_remove_max(priority_queue);
    }
    printf("\n\n");

    Set set = set_create(compare_int, destroy_value);

    for(int i = 0; i < 20; i++)
    {
        int* random_value = create_random_int();
        set_insert(set, random_value);
    }

    for(SetNode current_node = set_first(set); current_node != SET_EOF; current_node = set_next(set,current_node))
    {
        int* current_value = set_node_value(set, current_node);
        printf("%d\t", *current_value);
    }
    printf("\n");
}
