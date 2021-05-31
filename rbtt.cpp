void fixRedRed(Node *x) {
	// if x is root color it black and return
	if (x == root) {
	x->color = BLACK;
	return;
	}

	// initialize parent, grandparent, uncle
	Node *parent = x->parent, *grandparent = parent->parent,
		*uncle = x->uncle();

	if (parent->color != BLACK) {
	if (uncle != NULL && uncle->color == RED) {
		// uncle red, perform recoloring and recurse
		parent->color = BLACK;
		uncle->color = BLACK;
		grandparent->color = RED;
		fixRedRed(grandparent);
	} else {
		// Else perform LR, LL, RL, RR
		if (parent->isOnLeft()) {
		if (x->isOnLeft()) {
			// for left right
			swapColors(parent, grandparent);
		} else {
			leftRotate(parent);
			swapColors(x, grandparent);
		}
		// for left left and left right
		rightRotate(grandparent);
		} else {
		if (x->isOnLeft()) {
			// for right left
			rightRotate(parent);
			swapColors(x, grandparent);
		} else {
			swapColors(parent, grandparent);
		}

		// for right right and right left
		leftRotate(grandparent);
		}
	}
	}
}
