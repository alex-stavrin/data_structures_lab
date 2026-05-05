void node_visit_inorder(BTreeNode node, VisitFunc visit)
{
    if (node == NULL)
        return;
    for (int i = 0; i < node->count; i++)
    {
        node_visit_inorder(node->children[i], visit);
        
        visit(node->set_nodes[i]->value);
    }

    node_visit_inorder(node->children[node->count], visit);
}

void set_visit(Set set, VisitFunc visit) 
{
	node_visit_inorder(set->root, visit);
}