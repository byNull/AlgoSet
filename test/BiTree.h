#ifndef _BI_TREE_H__
#define _BI_TREE_H__

#pragma once

#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////
// predeclaration
//////////////////////////////////////////////////////////////////////////
template <typename ValueType>
struct BiTree;

template <typename ValueType>
struct DLinkList;


//////////////////////////////////////////////////////////////////////////
template <typename ValueType>
struct BiTree{
	ValueType value;
	struct BiTree *left;
	struct BiTree *right;

	BiTree(ValueType val = ValueType()) : value(val), left(NULL), right(NULL){

	}
};


//////////////////////////////////////////////////////////////////////////
template <typename ValueType>
struct DLinkList{
	ValueType value;
	struct DLinkList *prior;
	struct DLinkList *next;

	DLinkList(ValueType val = ValueType()) : value(val), prior(NULL), next(NULL){

	}
};




//////////////////////////////////////////////////////////////////////////
template <typename ValueType>
class Tree{
private:
	BiTree<ValueType> *root;
	//BiTree<ValueType> *cur;
	//static int         cnt;

	DLinkList<ValueType> *droot;

public:
	Tree() : droot(NULL), root(NULL)/*, cnt (0)*/{

	}

	~Tree(){
		if(root != NULL){
			destoryTree(root);
		}
	}

	void create(ValueType *pval, int N){
		if(root != NULL)
			destoryTree(root);
		createTree(root, pval, N);
	}

	BiTree<ValueType> *leftchild(BiTree<ValueType> *cur){
		return cur->left;
	}

	BiTree<ValueType> *rightchild(BiTree<ValueType> *cur){
		return cur->right;
	}

	DLinkList<ValueType> *getDLinkList(){
		traver(root);

		return (droot);
	}

	int size()const{
		return (cnt);
	}

private:
	void createTree(BiTree<ValueType> *r, ValueType *pval, int N){

		for ( int i = 0; i < N ; i++){
			r = insertNode(r, pval[i]);
			root = r;
		}
		//root = r;
	}

	BiTree<ValueType> * insertNode(BiTree<ValueType> *cur, ValueType val) {

		if(cur == NULL){
			BiTree<ValueType> *tmp = new BiTree<ValueType>(val);
			cur = tmp;
			return (cur);
		}else if(cur->value > val){
			//left insert
			cur->left = insertNode(cur->left, val);

			return (cur);
		}else{
			// right insert
			cur->right = insertNode(cur->right, val);

			return (cur);
		}

	}

	BiTree<ValueType> * destoryTree(BiTree<ValueType> *cur){
		if((cur->left == NULL) && (cur->right == NULL)){

			delete (cur);
			return (NULL);

		}else {
			if(cur->left != NULL){
				cur->left = destoryTree(cur->left);
			}
			if(cur->right != NULL){
				cur->right = destoryTree(cur->right);
			}

			cur = destoryTree(cur);

			return (cur);
		}
	}

	void traver(BiTree<ValueType> *cur)	{
		
		static DLinkList<ValueType> *pri_cur = NULL;

		if(cur != NULL){
			traver(leftchild(cur));

			DLinkList<ValueType> *tmpnode = new DLinkList<ValueType>(cur->value);

			if(pri_cur != NULL){
				tmpnode->prior = pri_cur;
				pri_cur->next  = tmpnode;
			}
			pri_cur = tmpnode;

			if(droot == NULL)
				droot = tmpnode;
			

//#define LENGTH
//			cnt++;
//#endif
			traver(rightchild(cur));
		}else if (cur == NULL)	{
			return;
		}
	}
};








#endif