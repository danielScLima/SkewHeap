// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "skewheap.h"

TEST_CASE( "Testing the insert calls in the heap", "[single-file]" )
{
    SECTION( "Inserting" )
	{
		SkewHeap f;
		
		SkewHeapNode* root = f.getRoot();
		REQUIRE (root == nullptr);
		
		f.insert(50);
		
		root = f.getRoot();
		
		REQUIRE (root != nullptr);
		REQUIRE (root->data == 50);
		
		f.insert(22);
		root = f.getRoot();
		
		REQUIRE (root != nullptr);
		REQUIRE (root->data == 22);
		REQUIRE (root->left != nullptr);
		REQUIRE (root->left->data == 50);
		REQUIRE (root->right == nullptr);
		
		f.insert(30);
		root = f.getRoot();
		
		REQUIRE (root != nullptr);
		REQUIRE (root->data == 22);
		REQUIRE (root->left != nullptr);
		REQUIRE (root->left->data == 30);
		REQUIRE (root->right != nullptr);
		REQUIRE (root->right->data == 50);
		
		f.insert(10);
		root = f.getRoot();
		
		REQUIRE (root != nullptr);
		REQUIRE (root->data == 10);
		REQUIRE (root->left != nullptr);
		REQUIRE (root->right == nullptr);
		REQUIRE (root->left->data == 22);
		REQUIRE (root->left->left->data == 30);
		REQUIRE (root->left->right->data == 50);
		
		
		f.insert(40);
		root = f.getRoot();
		
		REQUIRE (root != nullptr);
		REQUIRE (root->data == 10);
		REQUIRE (root->right != nullptr);
		REQUIRE (root->left != nullptr);
		REQUIRE (root->left->data == 40);
		REQUIRE (root->right->left->data == 30);
		REQUIRE (root->right->right != nullptr);
		REQUIRE (root->right->right->data == 50);
		
		f.insert(60);
		root = f.getRoot();
		
		REQUIRE (root != nullptr);
		REQUIRE (root->data == 10);
		REQUIRE (root->left->data == 22);
		REQUIRE (root->right->data == 40);
		
		REQUIRE (root->left->left->data == 50);
		REQUIRE (root->left->right->data == 30);
		
		REQUIRE (root->left->left->left->data == 60);
		
		f.insert(70);
		root = f.getRoot();
		
		REQUIRE (root != nullptr);
		REQUIRE (root->data == 10);
		REQUIRE (root->right->data == 22);
		REQUIRE (root->left->data == 40);
		REQUIRE (root->left->left->data == 70);
		
		REQUIRE (root->right->left->data == 50);
		REQUIRE (root->right->right->data == 30);
		
		REQUIRE (root->right->left->left->data == 60);
		
		f.insert(80);
		root = f.getRoot();
		
		REQUIRE (root->data == 10);
		
		REQUIRE (root->left->data == 22);
		REQUIRE (root->right->data == 40);
		
		REQUIRE (root->left->left->data == 30);
		REQUIRE (root->left->right->data == 50);
		
		REQUIRE (root->left->left->left->data == 80);
		REQUIRE (root->left->right->left->data == 60);
		
		REQUIRE (root->right->left->data == 70);
		
		f.insert(90);
		root = f.getRoot();
		
		REQUIRE (root->data == 10);
		
		REQUIRE (root->right->data == 22);
		REQUIRE (root->left->data == 40);
		
		REQUIRE (root->right->left->data == 30);
		REQUIRE (root->right->right->data == 50);
		
		REQUIRE (root->right->left->left->data == 80);
		REQUIRE (root->right->right->left->data == 60);
		
		REQUIRE (root->left->left->data == 90);
		REQUIRE (root->left->right->data == 70);
		
		f.insert(100);
		root = f.getRoot();
		
		REQUIRE(root->data == 10);
		
		REQUIRE(root->left->data == 22);
		REQUIRE(root->right->data == 40);
		
		REQUIRE(root->left->left->data == 50);
		REQUIRE(root->left->right->data == 30);
		
		REQUIRE(root->right->left->data == 90);
		REQUIRE(root->right->right->data == 70);
		
		REQUIRE(root->left->left->left->data == 100);
		REQUIRE(root->left->left->right->data == 60);
		
		REQUIRE(root->left->right->left->data == 80);
		
		f.insert(110);
		root = f.getRoot();
		
		REQUIRE(root->data == 10);
		
		REQUIRE(root->left->data == 40);
		REQUIRE(root->right->data == 22);
		
		REQUIRE(root->left->left->data == 70);
		REQUIRE(root->left->right->data == 90);
		
		REQUIRE(root->right->left->data == 50);
		REQUIRE(root->right->right->data == 30);
		
		REQUIRE(root->left->left->left->data == 110);
		
		REQUIRE(root->right->left->left->data == 100);
		REQUIRE(root->right->left->right->data == 60);
		
		REQUIRE(root->right->right->left->data == 80);
    }
	
}

TEST_CASE( "Testing the remove min calls in the heap", "[single-file]" )
{	
	SECTION( "Removing the min" )
	{
		SkewHeap f;
		f.insert(50);	
		f.insert(22);
		f.insert(30);
		f.insert(10);
		f.insert(40);
		
		SkewHeapNode* root = f.getRoot();
		
		REQUIRE (root != nullptr);
		REQUIRE (root->data == 10);
		
		REQUIRE (root->left->data == 40);
		REQUIRE (root->right->data == 22);
		
		REQUIRE (root->right->left->data == 30);
		REQUIRE (root->right->right->data == 50);
		
		SkewHeapNode* minNode = f.removeMin();
		REQUIRE (minNode->data == 10);
		delete minNode;
		
		root = f.getRoot();
		
		REQUIRE (root != nullptr);
		REQUIRE (root->data == 22);
		
		REQUIRE (root->left->data == 40);
		REQUIRE (root->right->data == 30);
		
		REQUIRE (root->left->left->data == 50);
		
		minNode = f.removeMin();
		REQUIRE (minNode->data == 22);
		delete minNode;
		
		root = f.getRoot();
		
		REQUIRE (root != nullptr);
		REQUIRE (root->data == 30);
		
		REQUIRE (root->left->data == 40);
		REQUIRE (root->left->left->data == 50);
		
		minNode = f.removeMin();
		REQUIRE (minNode->data == 30);
		delete minNode;
		
		root = f.getRoot();
		
		REQUIRE (root != nullptr);
		REQUIRE (root->data == 40);
		
		REQUIRE (root->left->data == 50);
		
		minNode = f.removeMin();
		REQUIRE (minNode->data == 40);
		delete minNode;
		
		root = f.getRoot();
		
		REQUIRE (root != nullptr);
		REQUIRE (root->data == 50);
		
		minNode = f.removeMin();
		REQUIRE (minNode->data == 50);
		delete minNode;
		
		root = f.getRoot();
		
		REQUIRE (root == nullptr);
    }
}

TEST_CASE( "Testing the search calls in the heap", "[single-file]" )
{	
	SECTION( "search calls" )
	{	
		SkewHeap f;
		f.insert(50);	
		f.insert(22);
		f.insert(30);
		f.insert(10);
		f.insert(40);
		
		REQUIRE (f.search(50));
		REQUIRE (f.search(22));
		REQUIRE (f.search(30));
		REQUIRE (f.search(10));
		REQUIRE (f.search(40));
		
		REQUIRE (!f.search(110));
	}
}

TEST_CASE( "Testing the search and remove min calls in the heap", "[single-file]" )
{	
	SECTION( "search calls" )
	{	
		SkewHeap f;
		f.insert(50);	
		f.insert(22);
		f.insert(30);
		f.insert(10);
		f.insert(40);
		
		REQUIRE (f.search(50));
		REQUIRE (f.search(22));
		REQUIRE (f.search(30));
		REQUIRE (f.search(10));
		REQUIRE (f.search(40));
		
		REQUIRE (!f.search(110));
		
		SkewHeapNode* minNode = f.removeMin(); //10
		REQUIRE (minNode->data == 10);
		delete minNode;
		
		REQUIRE (f.search(50));
		REQUIRE (f.search(22));
		REQUIRE (f.search(30));
		REQUIRE (!f.search(10));
		REQUIRE (f.search(40));
	}
}



