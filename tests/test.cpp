// If you change anything in this file, your changes will be ignored
// in your homework submission.
// Chekout TEST_F functions bellow to learn what is being tested.
#include "../code/WorkTrack.h"
#include <gtest/gtest.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class test_RBT : public ::testing::Test {
protected:
  static void SetUpTestCase() {}

  static void TearDownTestCase() {}

  void SetUp() override {}

  void TearDown() override {}
};

TEST_F(test_RBT, TestConstructor) {
  RBT myRBT;
  ASSERT_TRUE(myRBT.getRoot() == nullptr);
}

TEST_F(test_RBT, TestnewNode) {
  RBT myRBT;
  Node* node = myRBT.newNode();
  ASSERT_TRUE(node);
  ASSERT_EQ(nullptr, node->left);
  ASSERT_EQ(nullptr, node->right);
  ASSERT_EQ(nullptr, node->parent);
  ASSERT_TRUE(node -> jobNumber == 1);
  ASSERT_TRUE(node -> color == "RED");
  ASSERT_TRUE(node -> job == nullptr);
  ASSERT_TRUE(myRBT.jobCount == 2);
}

TEST_F(test_RBT, TestInsert) {
  RBT myrbt;
  Node* one = myrbt.newNode();
  Node* two = myrbt.newNode();
  Node* three = myrbt.newNode();
  Node* four = myrbt.newNode();
  Node* five = myrbt.newNode();
  Node* six = myrbt.newNode();
  Node* seven = myrbt.newNode();
  Node* eight = myrbt.newNode();
  ASSERT_TRUE(myrbt.getRoot() == nullptr);
  
  myrbt.insert(myrbt.getRoot(), one);
  myrbt.insert(myrbt.getRoot(), two);
  myrbt.insert(myrbt.getRoot(), three);
  myrbt.insert(myrbt.getRoot(), four); 
  myrbt.insert(myrbt.getRoot(), five);
  myrbt.insert(myrbt.getRoot(), six); 
  myrbt.insert(myrbt.getRoot(), seven);
  myrbt.insert(myrbt.getRoot(), eight);
 
  ASSERT_TRUE(myrbt.getRoot() == four);
  ASSERT_TRUE((myrbt.getRoot() -> color) == "BLACK");
  ASSERT_TRUE((myrbt.getRoot() -> left) == two);
  ASSERT_TRUE((two -> color) == "RED");
  ASSERT_TRUE((myrbt.getRoot() -> left -> left) == one);
  ASSERT_TRUE((myrbt.getRoot() -> left -> right) == three);
  ASSERT_TRUE((one -> color) == "BLACK" && (three -> color) == "BLACK");
  ASSERT_TRUE((myrbt.getRoot() -> right) == six);
  ASSERT_TRUE((myrbt.getRoot() -> right -> left) == five);
  ASSERT_TRUE((myrbt.getRoot() -> right -> right) == seven);
  ASSERT_TRUE((myrbt.getRoot() -> right -> right -> right) == eight);
  ASSERT_TRUE((six -> color) == "RED" && (eight -> color) == "RED");
  ASSERT_TRUE((five -> color) == "BLACK" && (seven -> color) == "BLACK");
}

TEST_F(test_RBT, TestSearch){
  RBT myrbt;
  Node* one = myrbt.newNode();
  Node* two = myrbt.newNode();
  Node* three = myrbt.newNode();
  Node* four = myrbt.newNode();
  Node* five = myrbt.newNode();
  Node* six = myrbt.newNode();
  Node* seven = myrbt.newNode();
  Node* eight = myrbt.newNode();
  ASSERT_TRUE(myrbt.getRoot() == nullptr);
  
  myrbt.insert(myrbt.getRoot(), one);
  myrbt.insert(myrbt.getRoot(), two);
  myrbt.insert(myrbt.getRoot(), three);
  myrbt.insert(myrbt.getRoot(), four); 
  myrbt.insert(myrbt.getRoot(), five);
  myrbt.insert(myrbt.getRoot(), six); 
  myrbt.insert(myrbt.getRoot(), seven);
  myrbt.insert(myrbt.getRoot(), eight);

  ASSERT_EQ(myrbt.search(myrbt.getRoot(), 3), three);
  ASSERT_EQ(myrbt.search(myrbt.getRoot(), 8), eight);
  ASSERT_EQ(myrbt.search(myrbt.getRoot(), 5), five);
}

TEST_F(test_RBT, TestRemove){
  RBT myrbt;
  Node* one = myrbt.newNode();
  Node* two = myrbt.newNode();
  Node* three = myrbt.newNode();
  Node* four = myrbt.newNode();
  Node* five = myrbt.newNode();
  Node* six = myrbt.newNode();
  Node* seven = myrbt.newNode();
  Node* eight = myrbt.newNode();
  ASSERT_TRUE(myrbt.getRoot() == nullptr);
  
  myrbt.insert(myrbt.getRoot(), one);
  myrbt.insert(myrbt.getRoot(), two);
  myrbt.insert(myrbt.getRoot(), three);
  myrbt.insert(myrbt.getRoot(), four); 
  myrbt.insert(myrbt.getRoot(), five);
  myrbt.insert(myrbt.getRoot(), six); 
  myrbt.insert(myrbt.getRoot(), seven);
  myrbt.insert(myrbt.getRoot(), eight);

  ASSERT_TRUE(myrbt.getRoot() == four);
  myrbt.remove(myrbt.getRoot(), 6);
  ASSERT_TRUE((myrbt.getRoot() -> right -> jobNumber) == 7);
  ASSERT_TRUE(seven -> color == "RED");
  ASSERT_TRUE((myrbt.getRoot() -> right -> right -> jobNumber) == 8);
  ASSERT_TRUE((myrbt.getRoot() -> right -> left -> jobNumber) == 5);
  ASSERT_TRUE((five -> color == "BLACK") && (eight -> color == "BLACK"));
}