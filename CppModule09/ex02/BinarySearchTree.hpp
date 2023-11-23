/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpachec <adpachec@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:05:11 by adpachec          #+#    #+#             */
/*   Updated: 2023/11/22 11:17:01 by adpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARYSEARCHTREE_HPP
# define BINARYSEARCHTREE_HPP

template<typename T>
class TreeNode
{
	public:
		T value;
		TreeNode *left, *right;
		TreeNode(const T& val);
};

template<typename T>
class BinarySearchTree
{
	private:
		TreeNode<T>* root;
		void insertNode(TreeNode<T>*& node, const T& value);
		void inorderTraversal(TreeNode<T>* node, void (*visit)(T&)) const;
		void destroyTree(TreeNode<T>* node);

	public:
		BinarySearchTree();
		~BinarySearchTree();
		void insertValue(const T& value);
		void inorderTraversal(void (*visit)(T&)) const;
};

#endif // BINARYSEARCHTREE_HPP
