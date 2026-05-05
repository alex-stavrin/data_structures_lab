void set_visit(Set set, VisitFunc visit) 
{
	for(SetNode node = set_first(set); node != SET_EOF; node = set_next(set, node)) 
	{
		Pointer node_value = set_node_value(set, node);
		visit(node_value);
	}
}

/*

    ---Trees---

    AVL Tree : self balancing binary search tree
    BST Tree : binary search tree
    B-Tree : self balancing tree that maintains sorted data

    ---Complexity of naive set visit---

    AVL Tree : set_first + n * set_next = O(logn) + n * O(logn) = O(logn) + O(nlogn) = O(nlogn)
    BST tree : set_first + n * set_next =  O(n) + n * O(n) =  O(n^2)
    B-Tree : set_first + n * set_next = O(logn) + n * O(logn) = O(nlogn)
*/