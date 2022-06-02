/*
Generic of a binary node
@param T, represents the datatype stored in the binary node.
*/
template <typename T>
struct BinaryNode {
	T element;
	BinaryNode* left;
	BinaryNode* right;

	/*
	lvalue constructor
	
	@param theElement, data to be stored in node
	@param other_left, pointer to child binary node on the left. Can be a nullptr.
	@param other_right, pointer to child binary node on the right. Can be a nullptr.
	
	@returns Binary node with data, theElement, with left and right children*/
	BinaryNode(const T& theElement, BinaryNode* other_left, BinaryNode* other_right)
		: element{ theElement }, left{ other_left }, right{ other_right } {};

	/*
	rvalue constructor

	@param theElement, data to be stored in node.
	@param other_left, pointer to child binary node on the left. Can be a nullptr.
	@param other_right, pointer to child binary node on the right. Can be a nullptr.

	@returns Binary node with data, theElement, with left and right children*/
	BinaryNode(T && theElement, BinaryNode* other_left, BinaryNode* other_right)
		: element{ std::move(theElement) }, left{ other_left }, right{ other_right } {};

};

/*
Generic Binary Search Tree Implementation

@param Comparable, represents the datatype stored in Binary Search Tree.
	Must implement comparison operators '==', '!=', '<', '>'.
*/
template <typename Comparable>
class BinarySearchTree {

private:
	BinaryNode<Comparable>* root;

	/*
	Method to insert an element into a Binary Search Tree
	
	@param x, a Comparable object to insert.
	@param t, a pointer to a binary node acting as a [sub]root.
	
	*/
	void insert(const Comparable& x, BinaryNode<Comparable>*& t) {
		BinaryNode<Comparable>* insert_node = contains(x, t);	// check if object already exists in [sub]tree
		if (insert_node != nullptr) {	//	do not insert if object already exists
			return;
		};
		*insert_node = new BinaryNode<Comparable>(x, nullptr, nullptr);	// else insert object at position it should be 
																		// contains operation already determines position object should be
	};

	/*
	Method to insert an element into a Binary Search Tree

	@param x, an rvalue Comparable object to insert.
	@param t, a pointer to a binary node acting as a [sub]root.

	*/
	void insert(Comparable&& x, BinaryNode<Comparable>*& t) {
		BinaryNode<Comparable>* insert_node = contains(x, t); // check if object already exists in [sub]tree
		if (insert_node != nullptr) {	//	do not insert if object already exists
			return;
		};
		*insert_node = new BinaryNode<Comparable>(x, nullptr, nullptr);	// else insert object at position it should be 
																		// contains operation already determines position object should be
	};

	/*
	Method to remove an element from a Binary Search Tree

	@param x, a Comparable object to be removed.
	@param t, a pointer to a binary node acting as a [sub]root.

	*/
	void remove(const Comparable& x, BinaryNode<Comparable>*& t) {
		BinaryNode<Comparable>* contained = contains(x, t);	// check if object exists in [sub]tree
		if (contained == nullptr) {	//	return if object is not in [sub]tree
			return;
		}

		if (contained->left == nullptr || contained->right == nullptr) {	//	if object to be deleted has 1 or no children
			BinaryNode<Comparable>* oldnode = contained;	// point to old binary node to free up space
			contained = (contained->left != nullptr )? contained->left : contained->right;	// assign child to deleted parent's position
			delete oldnode;
			return;
		}
		else {	//	object has 2 children
			BinaryNode<Comparable>* minRight = findMin(t->right);
			contained->element = minRight->element;	//	replace element to be deleted with smallest element in right subtree
			remove(minRight->element, minRight);	// delete smallest element in right subtree
		}
		
	};

	/*
	Finds binary node with the smallest element in [sub]tree
	@param t, binary node that is a [sub]tree
	@returns Comparable binary node containing the smallest element in the [sub]tree
	*/
	BinaryNode<Comparable>* findMin(BinaryNode<Comparable>* t) const {
		while (t->left != nullptr) {
			t = t->left;	// traverse to leftmost node in [sub]tree t
		}
		return t;
	};

	/*
	Finds binary node with the largest element in [sub]tree
	@param t, binary node that is a [sub]tree
	@returns Comparable binary node containing the largest element in the [sub]tree
	*/
	BinaryNode<Comparable>* findMax(BinaryNode<Comparable>* t) const {
		while (t->right != nullptr) {
			t = t->right;	// traverse to rightmost node in [sub]tree t
		}
		return t;
	};
	
	/*
	* Determines if an object Comparable is in BST
	*
	* @param x, a Comparable const object
	* @param t, a pointer to a Comparable BinaryNode  (a [sub]tree)
	*
	* @returns a nullptr if x is not contained in [sub]tree, a pointer to a Comparable BinaryNode otherwise
	*/
	bool isContained(const Comparable& x, BinaryNode<Comparable>* t) const {
		while (t != nullptr) {
			if (t.element == x) {	// check if element is at given node
				return true;
			}
			else if (x < t.element) {
				t = t->left;	// proceed to left subtree if element x is less than element at t
			}
			else {
				t = t->right;	// proceed to right subtree otherwise
			}
		}

		return false;	// x is not contained in [sub]tree rooted at t

	};

	/*
	* Determines if an object Comparable is in BST
	* 
	* @param x, a Comparable const object 
	* @param t, a pointer to a Comparable BinaryNode  (a [sub]tree)
	* 
	* @returns a nullptr if x is not contained in [sub]tree, a pointer to a Comparable BinaryNode otherwise
	*/
	BinaryNode<Comparable>* contains(const Comparable& x, BinaryNode<Comparable>* t) const {
		while (t != nullptr) {
			if (t.element == x) {	// check if element is at given node
				return t;
			}
			else if (x < t.element) {	
				t = t->left;	// proceed to left subtree if element x is less than element at t
			}
			else {
				t = t->right;	// proceed to right subtree otherwise
			}
		}

		return nullptr;	// element is not in [sub]tree rooted at t
	};

	
	//BinaryNode<Comparable>* clone(BinaryNode<Comparable>* t) const {
	//};

public:
	/*
	Public lvalue insert method

	@param x, a Comparable object to be inserted into tree
	*/
	void insert(const Comparable& x) {
		insert(x, root);	// call to private method
	};

	/*
	Public lvalue insert method

	@param x, a Comparable object to be inserted into tree
	*/
	void insert(const Comparable& x) {
		insert(x, root);	// call to private method
	};

	/*
	Public rvalue insert method

	@param x, a Comparable object to be inserted into tree
	*/
	void insert(Comparable&& x) {
		insert(x, root);	// call to private method
	};

	bool isContained(const Comparable& x) {
		return isContained(x, root);

	}

	BinaryNode<Comparable>* contains(const Comparable& x) {
		return contains(x, root)

	}



	/*
	Public remove method

	@param x, a Comparable object to be removed
	*/
	void remove(const Comparable& x) {
		remove(x, root);	// call to private method
	};

	/*
	Public method to remove all binary nodes in [sub]tree rooted at argument except argument.

	@param t, a pointer to a Comparable Binary Node pointer
	*/
	void makeEmpty(BinaryNode<Comparable>*& t) {
		//post-order recursive processing used
		if (t != nullptr) {	// base case
			makeEmpty(t->left);	// recursive call
			makeEmpty(t->right);	// recursive call
			remove(t->element, t);	// removal of node, aka processing
		}	
	};

	/*
	Public method to clone all binary nodes in [sub]tree rooted at argument.

	@param t, a pointer to a Comparable Binary Node pointer.
	*/
	BinaryNode<Comparable>* clone(BinaryNode<Comparable>* t) const {
		if (t != nullptr) {
			return new BinaryNode<Comparable>(t->element, clone(t->left), clone(t->right);	// recursively clone rest of [sub]tree
		}
		return nullptr;
	}; 

	/*
	Constructor for Binary Search Tree

	@param element, lvalue Comparable object.
	@returns Binary Search Tree with root containining element and empty left and right child.
	*/
	BinarySearchTree(const Comparable& element) {
		root = new BinaryNode<Comparable>(element, nullptr, nullptr);
	}

	/*
	Constructor for Binary Search Tree

	@param element, rvalue Comparable object.
	@returns Binary Search Tree with root containining element and empty left and right child.
	*/
	BinarySearchTree(Comparable&& element){
		root = new BinaryNode<Comparable>(element, nullptr, nullptr);
	}

	/*
	Constructor for Binary Search Tree

	@param r, Comparable Binary Node.
	@returns A cloned Binary Search Tree containing all nodes from argument r.
	*/
	BinarySearchTree(const BinaryNode<Comparable>*& r) : root{clone(r)} {
	}

	~BinarySearchTree() {
		makeEmpty(root);
		delete root;
	}

	

};
