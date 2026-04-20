///////////////////////////////////////////////////////////
//
// Υλοποίηση του ADT Priority Queue μέσω ταξινομημένης λίστας.
//
///////////////////////////////////////////////////////////

#include <stdlib.h>
#include <assert.h>

#include "ADTPriorityQueue.h"
#include "ADTList.h"			// Η υλοποίηση του PriorityQueue χρησιμοποιεί List


// Ενα PriorityQueue είναι pointer σε αυτό το struct
struct priority_queue {
	List list;
	CompareFunc compare_function;
};

// Βοηθητικές συναρτήσεις //////////////////////////////////////////////////////////////////

// Αρχικοποιεί την ταξινομημένη λίστα από τα στοιχεία του vector values.
static void naive_initialize_list(PriorityQueue pqueue, Vector values) {
	int size = vector_size(values);
	for(int i = 0; i < size; i++)
	{
		pqueue_insert(pqueue, vector_get_at(values, i));
	}
}

PriorityQueue pqueue_create(CompareFunc compare, DestroyFunc destroy_value, Vector values) {
	PriorityQueue pqueue = malloc(sizeof(*pqueue));
	pqueue->compare_function = compare;

	pqueue->list = list_create(destroy_value);

	if (values != NULL)
		naive_initialize_list(pqueue, values);

	return pqueue;
}

int pqueue_size(PriorityQueue pqueue) 
{
	return list_size(pqueue->list);
}

Pointer pqueue_max(PriorityQueue pqueue) 
{
	List our_list = pqueue->list;
	return list_node_value(our_list, list_first(our_list));
}

void pqueue_insert(PriorityQueue pqueue, Pointer value) 
{
	List our_list = pqueue->list;
	ListNode current_node = list_first(our_list);
	ListNode previous_node = LIST_BOF;

	CompareFunc compare_function = pqueue->compare_function;

	while(current_node != LIST_EOF && 
		compare_function(value, list_node_value(our_list, current_node)) < 0
	)
	{
		previous_node = current_node;
		current_node = list_next(our_list, current_node);
	}

	list_insert_next(our_list, previous_node, value);
}

void pqueue_remove_max(PriorityQueue pqueue) {
	list_remove_next(pqueue->list, LIST_BOF);
}

DestroyFunc pqueue_set_destroy_value(PriorityQueue pqueue, DestroyFunc destroy_value) {
	return list_set_destroy_value(pqueue->list, destroy_value);
}

void pqueue_destroy(PriorityQueue pqueue) {
	list_destroy(pqueue->list);
	free(pqueue);
}