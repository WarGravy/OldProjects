#include "adt3.h"
class QueType;
struct TreeNode
{
  ItemType info;
  TreeNode* left;
  TreeNode* right;
};

bool iTreeType::IsFull() const
// Returns true if there is no room for another item 
//  on the free store; false otherwise.
{
  TreeNode* location;
  try
  {
    location = new TreeNode;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}

bool iTreeType::IsEmpty() const
// Returns true if the tree is empty; false otherwise.
{
  return root == NULL;
}

int iCountNodes(TreeNode* tree);

int iTreeType::GetLength() const
// Calls recursive function CountNodes to count the 
// nodes in the tree.
{
  return iCountNodes(root);
}


int iCountNodes(TreeNode* tree)
// Post: returns the number of nodes in the tree.
{
  if (tree == NULL)
    return 0;
  else 
    return iCountNodes(tree->left) + iCountNodes(tree->right) + 1;
}

void iRetrieve(TreeNode* tree, 
     ItemType& item, bool& found);

ItemType iTreeType::GetItem(ItemType item, bool& found)
// Calls recursive function iRetrieve to search the tree for item.
{
  iRetrieve(root, item, found);
  return item;
}


void iRetrieve(TreeNode* tree, 
     ItemType& item, bool& found)
// Recursively searches tree for item.
// Post: If there is an element someItem whose key matches item's,
//       found is true and item is set to a copy of someItem; 
//       otherwise found is false and item is unchanged.
{
  if (tree == NULL)
    found = false;                     // item is not found.
  else if (item < tree->info)      
    iRetrieve(tree->left, item, found); // Search left subtree.
  else if (item > tree->info)
    iRetrieve(tree->right, item, found);// Search right subtree.
  else
  {
    item = tree->info;                 // item is found.
    found = true;
   }
} 

void FindNode(TreeNode* tree, ItemType item,
     TreeNode*& nodePtr, TreeNode*& parentPtr)
// Post: If a node is found with the same key as itemπs, then 
//       nodePtr points to that node and parentPtr points to its 
//       parent node. If the root node has the same key as itemπs,
//       parentPtr is NULL. If no node has the same key, then 
//       nodePtr is NULL and parentPtr points to the node in the 
//       tree that is the logical parent of item.

{
  nodePtr = tree;
  parentPtr = NULL;
  bool found = false;
  while (nodePtr != NULL && !found)
  {
    if (item < nodePtr->info)
    {
      parentPtr = nodePtr;
      nodePtr = nodePtr->left;
    }
    else if (item > nodePtr->info)
    {
      parentPtr = nodePtr;
      nodePtr = nodePtr->right;
    }
    else
      found = true;
  }
}
void iGetPredecessor(TreeNode* tree, ItemType& data);
void iDelete(TreeNode*& tree, ItemType item);

void iDeleteNode(TreeNode*& tree)
// iDeletes the node pointed to by tree.
// Post: The user's data in the node pointed to by tree is no 
//       longer in the tree.  If tree is a leaf node or has only 
//       non-NULL child pointer the node pointed to by tree is 
//       iDeleted; otherwise, the user's data is replaced by its 
//       logical predecessor and the predecessor's node is iDeleted.
{
  ItemType data;
  TreeNode* tempPtr;

  tempPtr = tree;
  if (tree->left == NULL)
  {
    tree = tree->right;
    delete tempPtr;
  }
  else if (tree->right == NULL)
  {
    tree = tree->left;
    delete tempPtr;
  }
  else
  {
    iGetPredecessor(tree->left, data);
    tree->info = data;
    iDelete(tree->left, data);
  }
}

void iDelete(TreeNode*& tree, ItemType item)
// iDeletes item from tree.
// Post:  item is not in tree.
{
  if (item < tree->info)
    iDelete(tree->left, item);   // Look in left subtree.
  else if (item > tree->info)
    iDelete(tree->right, item);  // Look in right subtree.
  else
    iDeleteNode(tree);           // Node found; call iDeleteNode.
}   

void iGetPredecessor(TreeNode* tree, ItemType& data)
// Sets data to the info member of the right-most node in tree.
{
  while (tree->right != NULL)
    tree = tree->right;
  data = tree->info;
}


void iTreeType::PutItem(ItemType item)
// Post: item is in tree.
{
  TreeNode* newNode;
  TreeNode* nodePtr;
  TreeNode* parentPtr;

  newNode = new TreeNode;
  newNode->info = item;
  newNode->left = NULL;
  newNode->right = NULL;

  FindNode(root, item, nodePtr, parentPtr);
  
  if (parentPtr == NULL)		// Insert as root.
    root = newNode;
  else if (item < parentPtr->info)
    parentPtr->left = newNode;
  else parentPtr->right = newNode;
}



void iTreeType::iDeleteItem(ItemType item)
// Post: There is no node in the tree whose info member 
//       matches item. 
{
  TreeNode* nodePtr;
  TreeNode* parentPtr;
 
  FindNode(root, item, nodePtr, parentPtr);

  if (nodePtr == root)
    iDeleteNode(root);
  else
    if (parentPtr->left == nodePtr)
      iDeleteNode(parentPtr->left);
    else iDeleteNode(parentPtr->right);
}

void iPrintTree(TreeNode* tree, std::ofstream& outFile) 
// Prints info member of items in tree in sorted order on outFile.
{
  if (tree != NULL)
  {
    iPrintTree(tree->left, outFile);   // Print left subtree.
    outFile << tree->info;
    iPrintTree(tree->right, outFile);  // Print right subtree.
  }
}

void iTreeType::Print(std::ofstream& outFile) const
// Calls recursive function Print to print items in the tree.
{
  iPrintTree(root, outFile);
}

iTreeType::iTreeType()
{
  root = NULL;
}

void iDestroy(TreeNode*& tree);

iTreeType::~iTreeType()
// Calls recursive function iDestroy to iDestroy the tree.
{
  iDestroy(root);
}


void iDestroy(TreeNode*& tree)
// Post: tree is empty; nodes have been deallocated.
{
  if (tree != NULL)
  {
    iDestroy(tree->left);
    iDestroy(tree->right);
    delete tree;
  }
}

void iTreeType::MakeEmpty()
{
  iDestroy(root);
  root = NULL;
}


void iCopyTree(TreeNode*& copy, 
     const TreeNode* originalTree);

iTreeType::iTreeType(const iTreeType& originalTree)
// Calls recursive function iCopyTree to copy originalTree 
//  into root.
{
  iCopyTree(root, originalTree.root);
}

void iTreeType::operator= 
     (const iTreeType& originalTree)
// Calls recursive function iCopyTree to copy originalTree 
// into root.
{
  {
  if (&originalTree == this)
    return;             // Ignore assigning self to self
  iDestroy(root);      // Deallocate existing tree nodes
  iCopyTree(root, originalTree.root);
  }

}
void iCopyTree(TreeNode*& copy, 
     const TreeNode* originalTree)
// Post: copy is the root of a tree that is a duplicate 
//       of originalTree.
{
  if (originalTree == NULL)
    copy = NULL;
  else
  {
    copy = new TreeNode;
    copy->info = originalTree->info;
    iCopyTree(copy->left, originalTree->left);
    iCopyTree(copy->right, originalTree->right);
  }
}
// Function prototypes for auxiliary functions.

void iPreOrder(TreeNode*, QueType&);
// Enqueues tree items in iPreOrder.


void iInOrder(TreeNode*, QueType&);
// Enqueues tree items in iInOrder.


void iPostOrder(TreeNode*, QueType&);
// Enqueues tree items in iPostOrder.


void iTreeType::ResetTree(OrderType order)
// Calls function to create a queue of the tree elements in 
// the desired order.
{
  switch (order)
  {
    case PRE_ORDER : iPreOrder(root, preQue);
                     break;
    case IN_ORDER  : iInOrder(root, inQue);
                     break;
    case POST_ORDER: iPostOrder(root, postQue);
                     break;
  }
}


void iPreOrder(TreeNode* tree, 
     QueType& preQue)
// Post: preQue contains the tree items in iPreOrder.
{
  if (tree != NULL)
  {
    preQue.Enqueue(tree->info);
    iPreOrder(tree->left, preQue);
    iPreOrder(tree->right, preQue);
  }
}


void iInOrder(TreeNode* tree, 
     QueType& inQue)
// Post: inQue contains the tree items in iInOrder.
{
  if (tree != NULL)
  {
    iInOrder(tree->left, inQue);
    inQue.Enqueue(tree->info);
    iInOrder(tree->right, inQue);
  }
}


void iPostOrder(TreeNode* tree, 
     QueType& postQue)
// Post: postQue contains the tree items in iPostOrder.
{
  if (tree != NULL)
  {
    iPostOrder(tree->left, postQue);
    iPostOrder(tree->right, postQue);
    postQue.Enqueue(tree->info);
  }
}


ItemType iTreeType::GetNextItem (OrderType order, bool& finished)
// Returns the next item in the desired order.
// Post: For the desired order, item is the next item in the queue.
//       If item is the last one in the queue, finished is true; 
//       otherwise finished is false.
{
  finished = false;
  ItemType item;
  switch (order)
  {
    case PRE_ORDER  : preQue.Dequeue(item);
                      if (preQue.IsEmpty())
                        finished = true;
                      break;
    case IN_ORDER   : inQue.Dequeue(item);
                      if (inQue.IsEmpty())
                        finished = true;
                      break;
    case  POST_ORDER: postQue.Dequeue(item);
                      if (postQue.IsEmpty())
                        finished = true;
                      break;
  }
  return item;
}



