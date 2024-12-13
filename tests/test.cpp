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
  myrbt.remove(myrbt.getRoot(), myrbt.getRoot() -> jobNumber);
  ASSERT_TRUE( myrbt.getRoot() == nullptr);

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

  myrbt.remove(myrbt.getRoot(), myrbt.getRoot() -> jobNumber);
  ASSERT_TRUE(myrbt.getRoot() -> jobNumber == 3);
}

TEST_F(test_RBT, TestNewJob){
  RBT myrbt;
  Node* one = myrbt.newNode();
  one = myrbt.newJob(one, "customer", "month", "day", "year", "employee", "10.99", "true", "1.5");
  ASSERT_TRUE(one -> job -> customer == "customer");
  ASSERT_TRUE(one -> job -> date[0] == "month");
  ASSERT_TRUE(one -> job -> date[1] == "day");
  ASSERT_TRUE(one -> job -> date[2] == "year");
  ASSERT_TRUE(one -> job -> employee == "employee");
  ASSERT_TRUE(one -> job -> cost == "10.99");
  ASSERT_TRUE(one -> job -> paid == "true");
  ASSERT_TRUE(one -> job -> time == "1.5");

  myrbt.insert(myrbt.getRoot(), one);
  ASSERT_TRUE(myrbt.getRoot() -> job -> customer == "customer");
  ASSERT_TRUE(myrbt.getRoot() -> job -> date[0] == "month");
  ASSERT_TRUE(myrbt.getRoot() -> job -> date[1] == "day");
  ASSERT_TRUE(myrbt.getRoot() -> job -> date[2] == "year");
  ASSERT_TRUE(myrbt.getRoot() -> job -> employee == "employee");
  ASSERT_TRUE(myrbt.getRoot() -> job -> cost == "10.99");
  ASSERT_TRUE(myrbt.getRoot() -> job -> paid == "true");
  ASSERT_TRUE(myrbt.getRoot() -> job -> time == "1.5");
}

TEST_F(test_RBT, TestSave){
  RBT myrbt;
  Node* one = myrbt.newNode();
  one = myrbt.newJob(one, "1", "1", "1", "1", "1", "1", "1", "1");
  Node* two = myrbt.newNode();
  two= myrbt.newJob(two, "2", "2", "2", "2", "2", "2", "2", "2");
  Node* three = myrbt.newNode();
  three= myrbt.newJob(three, "3", "3", "3", "3", "3", "3", "3", "3");
  Node* four = myrbt.newNode();
  four = myrbt.newJob(four, "4", "4", "4", "4", "4", "4", "4", "4");
  Node* five = myrbt.newNode();
  five = myrbt.newJob(five, "5", "5", "5", "5", "5", "5", "5", "5");
  Node* six = myrbt.newNode();
  six = myrbt.newJob(six, "6", "6", "6", "6", "6", "6", "6", "6");
  Node* seven = myrbt.newNode();
  seven = myrbt.newJob(seven, "7", "7", "7", "7", "7", "7", "7", "7");
  Node* eight = myrbt.newNode();
  eight = myrbt.newJob(eight, "8", "8", "8", "8", "8", "8", "8", "8");
  
  myrbt.insert(myrbt.getRoot(), one);
  myrbt.insert(myrbt.getRoot(), two);
  myrbt.insert(myrbt.getRoot(), three);
  myrbt.insert(myrbt.getRoot(), four); 
  myrbt.insert(myrbt.getRoot(), five);
  myrbt.insert(myrbt.getRoot(), six); 
  myrbt.insert(myrbt.getRoot(), seven);
  myrbt.insert(myrbt.getRoot(), eight);

  myrbt.save();
}

TEST_F(test_RBT, TestLoad){
    RBT myrbt;
  Node* one = myrbt.newNode();
  one = myrbt.newJob(one, "1", "1", "1", "1", "1", "1", "1", "1");
  Node* two = myrbt.newNode();
  two= myrbt.newJob(two, "2", "2", "2", "2", "2", "2", "2", "2");
  Node* three = myrbt.newNode();
  three= myrbt.newJob(three, "3", "3", "3", "3", "3", "3", "3", "3");
  Node* four = myrbt.newNode();
  four = myrbt.newJob(four, "4", "4", "4", "4", "4", "4", "4", "4");
  Node* five = myrbt.newNode();
  five = myrbt.newJob(five, "5", "5", "5", "5", "5", "5", "5", "5");
  Node* six = myrbt.newNode();
  six = myrbt.newJob(six, "6", "6", "6", "6", "6", "6", "6", "6");
  Node* seven = myrbt.newNode();
  seven = myrbt.newJob(seven, "7", "7", "7", "7", "7", "7", "7", "7");
  Node* eight = myrbt.newNode();
  eight = myrbt.newJob(eight, "8", "8", "8", "8", "8", "8", "8", "8");
  
  myrbt.insert(myrbt.getRoot(), one);
  myrbt.insert(myrbt.getRoot(), two);
  myrbt.insert(myrbt.getRoot(), three);
  myrbt.insert(myrbt.getRoot(), four); 
  myrbt.insert(myrbt.getRoot(), five);
  myrbt.insert(myrbt.getRoot(), six); 
  myrbt.insert(myrbt.getRoot(), seven);
  myrbt.insert(myrbt.getRoot(), eight);

  myrbt.save();
  RBT newrbt;
  newrbt = newrbt.load(newrbt);
  ASSERT_TRUE(newrbt.getRoot() -> jobNumber == 4);
  ASSERT_TRUE(newrbt.getRoot() -> color == "BLACK");
  ASSERT_TRUE(newrbt.getRoot() -> right -> jobNumber == 6);
  ASSERT_TRUE(newrbt.getRoot() -> right -> color == "RED");
  ASSERT_TRUE(newrbt.getRoot() -> left -> jobNumber == 2);
  ASSERT_TRUE(newrbt.getRoot() -> left -> right -> jobNumber == 3);
  ASSERT_TRUE(newrbt.getRoot() -> left -> right -> color == "RED");
  ASSERT_TRUE(newrbt.getRoot() -> right -> right -> right -> jobNumber == 8);
  ASSERT_TRUE(newrbt.getRoot() -> right -> right -> right -> color == "RED");
}