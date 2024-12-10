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
  // This function runs only once before any TEST_F function
  static void SetUpTestCase() {
    std::ofstream outgrade("./total_grade.txt");
    if (outgrade.is_open()) {
      outgrade.clear();
      outgrade << (int)0;
      outgrade.close();
    }
  }

  // This function runs after all TEST_F functions have been executed
  static void TearDownTestCase() {
    std::ofstream outgrade("./total_grade.txt");
    if (outgrade.is_open()) {
      outgrade.clear();
      outgrade << (int)(100 * total_grade / max_grade);
      outgrade.close();

      std::cout << "Total Grade is : " << (int)(100 * total_grade / max_grade)
                << std::endl;
    }
  }

  void add_points_to_grade(double points) {
    if (!::testing::Test::HasFailure()) {
      total_grade += points;
    }
  }

  // this function runs before every TEST_F function
  void SetUp() override {}

  // this function runs after ever TEST_F function
  void TearDown() override {
    std::ofstream outgrade("./total_grade.txt");
    if (outgrade.is_open()) {
      outgrade.clear();
      outgrade << (int)(100 * total_grade / max_grade);
      outgrade.close();
    }
  }

  static double total_grade;
  static double max_grade;
};

double test_RBT::total_grade = 0;
double test_RBT::max_grade = 100;

TEST_F(test_RBT, TestConstructor) {
  RBT myRBT;
  ASSERT_TRUE(myRBT.getRoot() == nullptr);
  add_points_to_grade(1);
}

TEST_F(test_RBT, TestnewNode) {
  RBT myRBT;
  Node* node = myRBT.newNode();
  ASSERT_TRUE(node);
  add_points_to_grade(1);
  ASSERT_EQ(nullptr, node->left);
  add_points_to_grade(1);
  ASSERT_EQ(nullptr, node->right);
  add_points_to_grade(1);
  ASSERT_EQ(nullptr, node->parent);
  add_points_to_grade(1);
  ASSERT_TRUE(node -> jobNumber == 1);
  add_points_to_grade(1);
  ASSERT_TRUE(node -> color == "RED");
  add_points_to_grade(1);
  ASSERT_TRUE(node -> job == nullptr);
  add_points_to_grade(1);
  ASSERT_TRUE(myRBT.jobCount == 2);
  add_points_to_grade(1);
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
  add_points_to_grade(1);
  ASSERT_TRUE((myrbt.getRoot() -> color) == "BLACK");
  add_points_to_grade(1);
  ASSERT_TRUE((myrbt.getRoot() -> left) == two);
  add_points_to_grade(1);
  ASSERT_TRUE((two -> color) == "RED");
  add_points_to_grade(1);
  ASSERT_TRUE((myrbt.getRoot() -> left -> left) == one);
  add_points_to_grade(1);
  ASSERT_TRUE((myrbt.getRoot() -> left -> right) == three);
  add_points_to_grade(1);
  ASSERT_TRUE((one -> color) == "BLACK" && (three -> color) == "BLACK");
  add_points_to_grade(1);
  ASSERT_TRUE((myrbt.getRoot() -> right) == six);
  add_points_to_grade(1);
  ASSERT_TRUE((myrbt.getRoot() -> right -> left) == five);
  add_points_to_grade(1);
  ASSERT_TRUE((myrbt.getRoot() -> right -> right) == seven);
  add_points_to_grade(1);
  ASSERT_TRUE((myrbt.getRoot() -> right -> right -> right) == eight);
  add_points_to_grade(1);
  ASSERT_TRUE((six -> color) == "RED" && (eight -> color) == "RED");
  add_points_to_grade(1);
  ASSERT_TRUE((five -> color) == "BLACK" && (seven -> color) == "BLACK");
  add_points_to_grade(1);
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