/*

Solution based on Chenxin Yang's idea

*/

bool BinaryTree::is_it_binary() const
{
	vector<int> nodes;
	if(root != NULL)
	{
		nodes = root->get_nodes();
	}
	for(int i=1; i<nodes.size(); ++i)
	{
		if(nodes[i] < nodes[i-1]) return false;
	}
	return true;
}


vector<int> Node::get_nodes() const
{
	vector<int> nodes, r;
	if (left != NULL)
	{
		nodes = left->get_nodes();
	}

	nodes.push_back(data);

	if (right != NULL)
	{
		r = right->get_nodes();
		for(int i=0; i<r.size(); ++i) nodes.push_back(r[i]);
	}
	return nodes;
}
