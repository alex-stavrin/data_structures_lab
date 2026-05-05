void node_visit_rec(SetNode node, VisitFunc visit) {
	if (node == NULL)
		return;

	node_visit_rec(node->left, visit);
	visit(node->value);
	node_visit_rec(node->right, visit);
}

void set_visit(Set set, VisitFunc visit) 
{
	node_visit_rec(set->root, visit);
}