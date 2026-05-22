#include<iostream>
#include "Tree.h"

namespace TreeCAS1102 {

template<class T>
void SearchTree<T>::insert(const T &item, TreeNode<T> *&subtreeRoot)
{
    if (subtreeRoot == nullptr) {
        subtreeRoot = new TreeNode<T>(item, nullptr, nullptr);
    } else if (item < subtreeRoot->data) {
        insert(item, subtreeRoot->leftLink);
    } else { // item >= subtreeRoot->data
        insert(item, subtreeRoot->rightLink);
    }
}

template<class T>
void SearchTree<T>::insert(const T &item) { insert(item, root); }

template<class T>
bool SearchTree<T>::inTree(const T &item, TreeNode<T> *subtreeRoot) const
{
    if (subtreeRoot == nullptr) {
        return false;
    } else if (item == subtreeRoot->data) {
        return true;
    } else if (item < subtreeRoot->data) {
        return inTree(item, subtreeRoot->leftLink);
    } else { // item >= subtreeRoot->data
        return inTree(item, subtreeRoot->rightLink);
    }
}

template<class T>
bool SearchTree<T>::inTree(const T &item) const { return inTree(item, root); }

template<class T>
void SearchTree<T>::inorderShow(TreeNode<T> *subtreeRoot) const
{
    if (subtreeRoot != nullptr) {
        inorderShow(subtreeRoot->leftLink);
        std::cout << subtreeRoot->data << " ";
        inorderShow(subtreeRoot->rightLink);
    }
}

template<class T>
void SearchTree<T>::inorderShow() const { inorderShow(root); }

template<class T>
void SearchTree<T>::deleteSubtree(TreeNode<T> *&subtreeRoot)
{
    if (subtreeRoot != nullptr) {
        deleteSubtree(subtreeRoot->leftLink);
        deleteSubtree(subtreeRoot->rightLink);
        delete subtreeRoot;
        subtreeRoot = nullptr;
    }
}

template<class T>
SearchTree<T>::~SearchTree() { deleteSubtree(root); }

} // end namespace TreeCAS1102
