#include <stdlib.h>

#include "pair_sum.h"



Pair pair_sum(int target, Vector numbers) {
	
	for(int i = 0; i < vector_size(numbers); i++)
	{
		int* current_number_ptr = vector_get_at(numbers, i);
		for(int j = 0; j < vector_size(numbers); j++)
		{
			if(j != i)
			{
				int* other_number_ptr = vector_get_at(numbers, j);
				int current_value = *current_number_ptr;
				int other_value = *other_number_ptr;
				if(current_value + other_value == target)
				{
					Pair new_pair = malloc(sizeof(Pair));
					new_pair->first = current_value;
					new_pair->second = other_value;
					return new_pair;
				}
			}
		}
	}

	return NULL;
}

int compare_int(Pointer p_a, Pointer p_b)
{
    int* a = p_a;
    int* b = p_b;
    int a_v = *a;
    int b_v = *b;
    return a_v - b_v;
}

void destroy_key(Pointer pointer)
{
	if(pointer)
	{
		free(pointer);
	}
}

// Δεσμεύει μνήμη για έναν ακέραιο, αντιγράφει το value εκεί και επιστρέφει pointer
int* create_int_for_map(int value) {
	int* pointer = malloc(sizeof(int));		// δέσμευση μνήμης
	*pointer = value;						// αντιγραφή του value στον νέο ακέραιο
	return pointer;
}

Pair pair_sum_using_map(int target, Vector numbers)
{
	Map map = map_create(compare_int, destroy_key, NULL);

	for(int i = 0; i < vector_size(numbers); i++)
	{
		int* current_value = vector_get_at(numbers, i);
		map_insert(map, current_value, current_value);
	}

	for(int i = 0; i < vector_size(numbers); i++)
	{
		int* a = vector_get_at(numbers, i);
		int* looking_b = create_int_for_map(target - *a);
		int* found_b = map_find(map, looking_b);
		if(found_b)
		{
			Pair new_pair = malloc(sizeof(Pair));
			new_pair->first = *a;
			new_pair->second = *found_b;
			return new_pair;		
		}
	}

	return NULL;
}