#pragma once

#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <stack>


class BinarySearchTree
{
	friend class TransferWindowManager;
private:
	TreeNode * m_root;

	void _clear(TreeNode* parent_node)
	{
		if (parent_node->m_left != NULL)
		{
			_clear(parent_node->m_left);
			parent_node->m_left = NULL;
		}

		if (parent_node->m_right != NULL)
		{
			_clear(parent_node->m_right);
			parent_node->m_right = NULL;
		}

		delete parent_node;
	}

public:
	BinarySearchTree() { m_root = NULL; }
	~BinarySearchTree()
	{
		if(m_root != NULL)
		{
			clear();
			m_root = NULL;
		}
	}

	void clear()
	{
		_clear(m_root);
	}

	TreeNode * getRoot() const { return m_root; }

	void insert(SoccerPlayerData& data)
	{
		TreeNode* parent = NULL;
		TreeNode* current = m_root;
		TreeNode* new_node = new TreeNode(data);

		if (m_root == NULL)
		{
			m_root = new_node;
		}
		else
		{
			do
			{
				parent = current;

				if (new_node->m_data.m_ability < parent->m_data.m_ability)
				{
					current = current->m_left;
				}
				else
				{
					current = current->m_right;
				}
			} while (current != NULL);

			if (new_node->m_data.m_ability < parent->m_data.m_ability)
			{
				parent->m_left = new_node;
			}
			else
			{
				parent->m_right = new_node;
			}
		}
	}

	void deletion(int ability) // ability = key
	{
		TreeNode* node_to_be_deleted = m_root;
		TreeNode* q = NULL; //q is the parent of p

		while (node_to_be_deleted && (ability != node_to_be_deleted->m_data.m_ability))
		{
			q = node_to_be_deleted;
			if (ability < node_to_be_deleted->m_data.m_ability)
			{
				node_to_be_deleted = node_to_be_deleted->m_left;
			}
			else
			{
				node_to_be_deleted = node_to_be_deleted->m_right;
			}
		}

		//**Delete a Leaf Node**
		if (node_to_be_deleted == NULL) return;

		if (node_to_be_deleted->m_left == NULL && node_to_be_deleted->m_right == NULL)
		{
			if (q == NULL) //node to be deleted is m_root. 
				m_root = NULL;
			else if (q->m_left == node_to_be_deleted)
				q->m_left = NULL;
			else //if(q->m_right == parent)
				q->m_right = NULL;

			delete node_to_be_deleted;
			return;
		}
		//**********************

		//**node_to_be_deleted only has right child
		if (node_to_be_deleted->m_left == NULL && node_to_be_deleted->m_right != NULL)
		{
			if (q == NULL)
				m_root = node_to_be_deleted->m_right;
			else if (q->m_left == node_to_be_deleted)
				q->m_left = node_to_be_deleted->m_right;
			else
				q->m_right = node_to_be_deleted->m_right;

			delete node_to_be_deleted;
			return;
		}
		else if (node_to_be_deleted->m_right == NULL && node_to_be_deleted->m_left != NULL)
		{
			if (q == NULL)
				m_root = node_to_be_deleted->m_left;
			else if (q->m_left == node_to_be_deleted)
				q->m_left = node_to_be_deleted->m_left;
			else
				q->m_right = node_to_be_deleted->m_left;

			delete node_to_be_deleted;
			return;
		}
		//*****************************

		//**Parent has right and left child. 
		// find the largest node in the left subtree
		if (node_to_be_deleted->m_left != NULL &&
			node_to_be_deleted->m_right != NULL)
		{
			//q 제거 될 노드의 부모
			//node_to_be_deleted 제거 될 노드
			//node_to_be_changed 바뀔 노드

			TreeNode* prevprev = node_to_be_deleted;
			TreeNode* prev = node_to_be_deleted->m_left;

			while (prev->m_right)
			{
				prevprev = prev;
				prev = prev->m_right;
			}
			
			node_to_be_deleted->m_data = prev->m_data;
			if (node_to_be_deleted == prevprev)
				node_to_be_deleted->m_left = prev->m_left;
			else
				prevprev->m_right = prev->m_left;

			delete prev;
		}
		//*****************************

	}

	std::vector<TreeNode*> getNodes()
	{
		std::vector<TreeNode*> nodes_vec;

		std::stack<TreeNode*> nodes;
		TreeNode* node = m_root;

		while (node != NULL || nodes.empty() == false)
		{
			/* Reach the left most Node of the
			curr Node */
			while (node != NULL)
			{
				/* place pointer to a tree node on
				the stack before traversing
				the node's left subtree */
				nodes.push(node);
				node = node->m_left;
			}

			/* Current must be NULL at this point */
			node = nodes.top();
			nodes.pop();

			nodes_vec.push_back(node);

			/* we have visited the node and its
			left subtree.  Now, it's right
			subtree's turn */
			node = node->m_right;

		} /* end of while */

		return nodes_vec;
	}

	void visit(TreeNode* current)
	{
		std::cout << current->m_data << " ";
	}

	TreeNode* search(TreeNode* current, int ability)
	{
		if (current == NULL)
			return NULL;

		if (ability == current->m_data.m_ability)
		{
			return current;
		}
		else if (ability < current->m_data.m_ability)
		{
			search(current->m_left, ability);
		}
		else
		{
			search(current->m_right, ability);
		}
	}

	friend std::ostream& operator<<(std::ostream& os, const BinarySearchTree& tree) {

		std::stack<TreeNode*> nodes;
		TreeNode * node = tree.getRoot();

	
		while (node != NULL || nodes.empty() == false)
		{
			/* Reach the left most Node of the
			curr Node */
			while (node != NULL)
			{
				/* place pointer to a tree node on
				the stack before traversing
				the node's left subtree */
				nodes.push(node);
				node = node->getLeftNode();
			}

			/* Current must be NULL at this point */
			node = nodes.top();
			nodes.pop();

			os << node << std::endl;
			/* we have visited the node and its
			left subtree.  Now, it's right
			subtree's turn */
			node = node->getRightNode();

		} /* end of while */

		return os;
	}
};
