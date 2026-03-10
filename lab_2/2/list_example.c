#include <stdlib.h>
#include <stdio.h>

#include "ADTList.h"

// Δεσμεύει μνήμη για έναν ακέραιο, αντιγράφει το value εκεί και επιστρέφει pointer
int* create_int(int value) {
	int* pointer = malloc(sizeof(int));		// δέσμευση μνήμης
	*pointer = value;						// αντιγραφή του value στον νέο ακέραιο
	return pointer;
}

void destroy_int(Pointer pointer)
{
	free(pointer);
}

int main() {
	List list = list_create(destroy_int);

	// προσθήκη των αριθμών από το 0 έως 9 στη λίστα
	for (int i = 0; i < 10; i++)
	{
		int* new_int = create_int(i);
		list_insert_next(list, list_last(list), new_int);
	}

	int sum = 0;
	for(ListNode current_list_node = list_first(list); current_list_node != LIST_EOF; current_list_node = list_next(list, current_list_node))
	{
		int* value_ptr = (int*)list_node_value(list, current_list_node);
		sum += *value_ptr;
		printf("%d \t", *value_ptr);
	}
	printf("\nSum is: %d\n", sum);

	list_destroy(list);
} 