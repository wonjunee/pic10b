/*

Luke Elissiry's solution to the problem 2.

*/

/* Accessor: check_if_sorted
	Checks if a binary tree is a binary search tree.
	Returns true if it is a binary search tree and false
	otherwise.
*/
bool BinaryTree::check_if_sorted() const {
	// Start checking at root, if root exists.
	if (root != NULL)
		return root->check_order(INT_MIN, INT_MAX);
	return false;
}

/* Accessor: check_order
	Recursive function which assists binary tree check_if_sorted function.
*/

bool Node::check_order(int min, int max) const {
	// Note: "+/- 1" ensures unique entries.

	// Check left child
	if (left != NULL) {
		/*
		The left child should be less than the parent and 
		greater than node left of parent (minimum).
		Return false if at least one condition is true:
			1) Left child is greater than parent.
			2) Left child is less than minimum.
			3) Left check's order of its children and returns false.
				Note that maximum is updated.
		*/
		if ( /*1*/ left->data > data - 1 || /*2*/ left->data < min || /*3*/ !(left->check_order(min, data - 1)))
			return false;
	}
	// Check right child
	if (right != NULL) {
		/*
		The right child should be greater than the parent and
		less than node right of parent (maximum).
		Return false if at least one condition is true:
			1) Right child is less than parent.
			2) Right child is greater than maximum.
			3) Right child check's order of its children and returns false.
				Note that minimum is updated.
		*/
		if ( /*1*/ right->data < data + 1 || /*2*/ right->data > max || /*3*/ !(right->check_order(data + 1, max)))
			return false;
	}
	return true;
}