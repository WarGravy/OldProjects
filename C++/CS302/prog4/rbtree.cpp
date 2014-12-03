/*
 * rbtree.cpp
 *
 */

#include "rbtree.h"
#include <stdint.h>
#include <stdio.h>

using namespace std;

RBTree::RBTree() {
        root_ = NULL;
}

RBTree::RBTree(int32_t key, void *data) {
        root_ = new RBTreeNode(NULL, key, data);
}

RBTreeNode *RBTree::queryTree(int key, int& comparisons ) {
        return queryTreeRecur_(this->root_, key, comparisons);
}

RBTreeNode *RBTree::queryTreeRecur_(RBTreeNode *tree, int32_t key, int& comparisons) {
        if (tree == NULL) {
                return NULL;
        }
        comparisons++;
        if (key < tree->getKey()) {
                return queryTreeRecur_(tree->getLeft(), key, comparisons);
        } else if (key > tree->getKey()) {
                return queryTreeRecur_(tree->getRight(), key, comparisons);
        } else {
                return tree;
        }

}

int32_t RBTree::size() {
        return count_(this->root_, 0);
}

int RBTree::maxDepth() {
        return maxDepthRecur_(this->root_);
}

int32_t RBTree::maxDepthRecur_(RBTreeNode *tree) {
        if (tree == NULL) {
                return 0;
        }
        int32_t leftDepth = maxDepthRecur_(tree->getLeft());
        int32_t rightDepth = maxDepthRecur_(tree->getRight());
        if (leftDepth > rightDepth) {
                return leftDepth + 1;
        } else {
                return rightDepth + 1;
        }
}

int32_t RBTree::deleteNode(int key, int& swaps, int& comparisons ) {
        RBTreeNode *z = queryTree( key, comparisons );
        RBTreeNode *y;
        RBTreeNode *x;
        if (z == NULL)
                return 0;
        if (z->getLeft() == NULL || z->getRight() == NULL) {
                y = z;
        } else {
                y = getSuccessor_(z);
        }
        if (y->getLeft() != NULL) {
                x = y->getLeft();
        } else {
                x = y->getRight();
        }
        if (x != NULL) {
                x->setParent(y->getParent());
        }
        if (y->getParent() == NULL) {
                this->root_ = x;

        } else {
                if (y == y->getParent()->getLeft()) {
                        y->getParent()->setLeft(y);
                } else {
                        y->getParent()->setRight(y);
                }
        }
        comparisons++;
        if (y != z) {

                z->setKey(y->getKey());
                z->setData(y->getData());
                swaps++;
        }
        return 0;
}

RBTreeNode *RBTree::createNode_(RBTreeNode *parent, short loc, int32_t key,
                void *data, int& comparisons) {
        RBTreeNode *tmp = new RBTreeNode(parent, key, data);
        comparisons++;
        if (loc == LEFT_)
                parent->setLeft(tmp);
        else
                parent->setRight(tmp);
        return tmp;
}

short RBTree::isValidRedBlackTree() {
        return isValidRedBlackTreeRecur_(this->root_);
}

short RBTree::isValidRedBlackTreeRecur_(RBTreeNode *tree) {
        if (tree == NULL)
                return 1;
        if (!isValidRedBlackTreeRecur_(tree->getLeft())) {
                return 0;
        }
        if (!isValidRedBlackTreeRecur_(tree->getRight())) {
                return 0;
        }
        if (tree->getParent() == NULL && tree->getColor() == BLACK_) {
                return 1;
        }
        if (tree->getColor() == RED_ && tree->getParent() != NULL && tree->getParent()->getColor()
                        == BLACK_) {
                return 1;
        }
        if (tree->getColor() == BLACK_ && tree->getParent() != NULL && tree->getParent()->getColor()
                        == BLACK_) {
                return 1;
        }
        return 0;
}

RBTreeNode *RBTree::insertNode(int32_t key, void *data, int& swaps, int& comparisons ) {
        return treeInsert_(this->root_, key, data, swaps, comparisons);
}

RBTreeNode *RBTree::treeInsert_(RBTreeNode *tree, int32_t key, void *data, int& swaps, int& comparisons) {
        RBTreeNode *inserted;
        comparisons++;
        if (key < tree->getKey()) {
                if (tree->getLeft() == NULL) {
                        inserted = createNode_(tree, LEFT_, key, data, comparisons);
                        insertFix_(inserted, swaps, comparisons);
                } else {
                        inserted = treeInsert_(tree->getLeft(), key, data, swaps, comparisons);
                }
        } else {
                if (tree->getRight() == NULL) {
                        inserted = createNode_(tree, RIGHT_, key, data, comparisons);
                        //printf("Inserted %d On Right\n", key);
                        insertFix_(inserted, swaps, comparisons);
                } else {
                        inserted = treeInsert_(tree->getRight(), key, data, swaps, comparisons);
                }
        }
        //FIX Location
        return inserted;
}

void RBTree::insertFix_(RBTreeNode *node, int& swaps, int& comparisons) {
        RBTreeNode *z = node;
        RBTreeNode *y = NULL;
        while (z != NULL && z->getParent() != NULL && z->getParent()->getColor()
                        == RED_) {
                if (z->getParent()->getParent() != NULL) {
                        if (z->getParent() == z->getParent()->getParent()->getLeft()) {
                                //case 1,2,3
                                y = uncle_(z);
                                if (y != NULL && y->getColor() == RED_) {
                                        //case 1
                                        //RECOLOR
                                        z->getParent()->setColor(BLACK_);
                                        y->setColor(BLACK_);
                                        z->getParent()->getParent()->setColor(RED_);
                                        z = z->getParent()->getParent();
                                        continue;
                                } else {
                                        if (z == z->getParent()->getRight()) {
                                                //case 2
                                                z = z->getParent();
                                                rotateLeft_(z);
                                                swaps++;
                                        }
                                        z->getParent()->setColor(BLACK_);
                                        z->getParent()->getParent()->setColor(RED_);
                                        rotateRight_(z->getParent()->getParent());
                                        swaps++;
                                        //case 3
                                }
                        } else {
                                //case 4,5,6
                                y = uncle_(z);

                                if (y != NULL && y->getColor() == RED_) {
                                        //case 4
                                        //RECOLOR
                                        z->getParent()->setColor(BLACK_);
                                        y->setColor(BLACK_);
                                        z->getParent()->getParent()->setColor(RED_);
                                        z = z->getParent()->getParent();
                                } else {
                                        if (z == z->getParent()->getLeft()) {
                                                //case 5
                                                z = z->getParent();
                                                rotateRight_(z);
                                                swaps++;
                                        }
                                        //case 6
                                        z->getParent()->setColor(BLACK_);
                                        z->getParent()->getParent()->setColor(RED_);
                                        rotateLeft_(z->getParent()->getParent());
                                        swaps++;
                                }
                        }
                } else {
                        break;
                }
        }
        this->root_->setColor(BLACK_);
}

RBTreeNode *RBTree::uncle_(RBTreeNode *myNode) {
        RBTreeNode *myGPNode = grandparent_(myNode);
        if (myGPNode == NULL) {
                return NULL;
        }
        if (myNode->getParent() == myGPNode->getLeft()) {
                return myGPNode->getRight();
        } else {
                return myGPNode->getLeft();
        }
}

short RBTree::rotateRight_(RBTreeNode *myNode) {
        //printf("Rotate Right Of %d\n", myNode->key);
        //cool operation...
        if (myNode->getLeft() == NULL)
                return 1;
        RBTreeNode *leftNode = myNode->getLeft();
        RBTreeNode *correctParent = myNode->getParent();
        //let's fix the parent's links first...
        if (correctParent != NULL) {
                if (myNode == correctParent->getLeft()) {
                        correctParent->setLeft(leftNode);
                } else {
                        correctParent->setRight(leftNode);
                }
        }
        myNode->setLeft(leftNode->getRight());
        leftNode->setRight(myNode);
        leftNode->setParent(myNode->getParent());
        myNode->setParent(leftNode);

        if (this->root_ == myNode) {
                this->root_ = leftNode;
                leftNode->setParent(NULL);
        }
        return 0;
}

short RBTree::rotateLeft_(RBTreeNode *myNode) {
        //printf("Rotate Left Of %d\n", myNode->key);
        //cool operation...
        if (myNode->getRight() == NULL)
                return 1;
        RBTreeNode *rightNode = myNode->getRight();
        RBTreeNode *correctParent = myNode->getParent();
        //let's fix the parent's links first...
        if (correctParent != NULL) {
                if (myNode == correctParent->getLeft()) {
                        correctParent->setLeft(rightNode);
                } else {
                        correctParent->setRight(rightNode);
                }
        }
        myNode->setRight(rightNode->getLeft());
        rightNode->setLeft(myNode);
        rightNode->setParent(myNode->getParent());
        myNode->setParent(rightNode);
        if (this->root_ == myNode) {
                this->root_ = rightNode;
                rightNode->setParent(NULL);
        }
        return 0;
}

short RBTree::isLeaf_(RBTreeNode *node, int& comparisons ) {
        comparisons++;
        if (node->getLeft() == NULL && node->getRight() == NULL)
                return 1;
        return 0;
}

int32_t RBTree::count_(RBTreeNode *node, int num) {
        if (node == NULL) {
                return num;
        }
        return count_(node->getLeft(), count_(node->getRight(), ++num));
}

void RBTree::printPaths( int& comparisons ) {
        RBTreeNode *path[1000];
        printPathsRecur_(this->root_, path, 0, comparisons);
}

void RBTree::printPathsRecur_(RBTreeNode *node, RBTreeNode **path, int pathLen, int& comparisons) {
        if (node == NULL)
                return;

        path[pathLen++] = node;
        if (isLeaf_(node, comparisons)) {
                int32_t i;
                for (i = 0; i < pathLen; i++) {
                        printf("%d ", path[i]->getKey());
                }
                printf("\n");
                return;
        }
        printPathsRecur_(node->getLeft(), path, pathLen, comparisons);
        printPathsRecur_(node->getRight(), path, pathLen, comparisons);
}

void RBTree::printTree() {
        printTreeRecur_(this->root_);
}

void RBTree::printTreeRecur_(RBTreeNode *node) {
        if (node == NULL) {
                return;
        }
        printTreeRecur_(node->getLeft());
        printf("%d ", node->getKey());
        printTreeRecur_(node->getRight());
}

RBTreeNode *RBTree::getSuccessor_(RBTreeNode *node) {
        if (node->getRight() != NULL) {
                return getMinimum_(node->getRight());
        }
        RBTreeNode *x = node;
        RBTreeNode *y = node->getParent();
        while (y != NULL && x == y->getRight()) {
                x = y;
                y = y->getParent();
        }
        return y;
}

RBTreeNode *RBTree::getPredecessor_(RBTreeNode *node) {
        if (node->getLeft() != NULL) {
                return getMaximum_(node->getLeft());
        }
        RBTreeNode *x = node;
        RBTreeNode *y = node->getParent();
        while (y != NULL && x == y->getLeft()) {
                x = y;
                y = y->getParent();
        }
        return y;
}
RBTreeNode *RBTree::grandparent_(RBTreeNode *myNode) {
        if ((myNode != NULL) && (myNode->getParent() != NULL)) {
                return myNode->getParent()->getParent();
        } else {
                return NULL;
        }
}

RBTreeNode *RBTree::getMinimum_(RBTreeNode *tree) {
        if (tree == NULL) {
                return NULL;
        }
        if (tree->getLeft() != NULL) {
                return getMinimum_(tree->getLeft());
        }
        return tree;
}

RBTreeNode *RBTree::getMinimum() {
        return getMinimum_(this->root_);
}

RBTreeNode *RBTree::getMaximum() {
        return getMaximum_(this->root_);
}

RBTreeNode *RBTree::getMaximum_(RBTreeNode *tree) {
        if (tree == NULL) {
                return NULL;
        }
        if (tree->getRight() != NULL) {
                return getMaximum_(tree->getRight());
        }
        return tree;
}
RBTree::~RBTree() {
        delete this->root_;
}


