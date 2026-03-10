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