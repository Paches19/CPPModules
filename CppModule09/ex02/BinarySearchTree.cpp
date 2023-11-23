/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:05:08 by adpachec          #+#    #+#             */
/*   Updated: 2023/11/22 11:16:55 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BinarySearchTree.hpp"

template<typename T>
BinarySearchTree<T>::BinarySearchTree() : root(NULL) {}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	destroyTree(root);
}

template<typename T>
void BinarySearchTree<T>::insertNode(TreeNode<T>*& node, const T& value) {
	if (node == NULL)
		node = new TreeNode<T>(value);
	else if (value < node->value)
		insert(node->left, value);
	else
		insert(node->right, value);
}

template<typename T>
void BinarySearchTree<T>::inorderTraversal(TreeNode<T>* node, void (*visit)(T&)) const
{
	if (node != NULL)
	{
		inorderTraversal(node->left, visit);
		visit(node->value);
		inorderTraversal(node->right, visit);
	}
}

template<typename T>
void BinarySearchTree<T>::destroyTree(TreeNode<T>* node)
{
	if (node != NULL)
	{
		destroyTree(node->left);
		destroyTree(node->right);
		delete node;
	}
}

template<typename T>
void BinarySearchTree<T>::insertValue(const T& value) {
	insert(root, value);
}

template<typename T>
void BinarySearchTree<T>::inorderTraversal(void (*visit)(T&)) const
{
	inorderTraversal(root, visit);
}
