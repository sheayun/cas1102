#ifndef TREE_H
#define TREE_H

namespace TreeCAS1102 {

template<class T>
class SearchTree; // forward declaration

template<class T>
class TreeNode {
public:
    TreeNode(const T &theData, TreeNode<T> *left, TreeNode<T> *right)
        : data(theData), leftLink(left), rightLink(right) {}
    friend class SearchTree<T>;
private:
    T data;
    TreeNode<T> *leftLink;
    TreeNode<T> *rightLink;
}; // end class TreeNode

template<class T>
class SearchTree {
public:
    SearchTree() : root(nullptr) {}
    virtual ~SearchTree();
    void insert(const T &item);
    bool inTree(const T &item) const;
    void inorderShow() const;
private:
    void insert(const T &item, TreeNode<T> *&subtreeRoot);
    bool inTree(const T &target, TreeNode<T> *subtreeRoot) const;
    void deleteSubtree(TreeNode<T> *&subtreeRoot);
    void inorderShow(TreeNode<T> *subtreeRoot) const;
    TreeNode<T> *root;
}; // end class SearchTree

} // end namespace TreeCAS1102

#endif // TREE_H
