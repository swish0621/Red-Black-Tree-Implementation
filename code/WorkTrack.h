#ifndef WORKTRACK_H__
#define WORKTRACK_H__

#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <fstream> 
#include <queue>
#include <sstream>

using namespace std;

struct Job {
    string customer;
    string date[3];
    string employee;
    string cost;
    string paid;
    string time;
};

struct Node {
    int jobNumber;
    string color;
    Node* left;
    Node* right;
    Node* parent;
    Job* job;
};

class RBT {
    public:

    Node* getRoot();

    void setRoot(Node* node);

    Node* newJob(Node* node, string customer, string month, string day, string year, string employee, string cost, string paid, string time);

    Node* newNode();

    void insert(Node* root, Node* node);

    void remove(Node* root, int jobNumber);

    Node* search(Node* root, int jobNumber);

    void save();

    RBT load(RBT newrbt);

    void clearSave();

    multimap<string, int> lookup;

    int jobCount = 1;

    private:

    //vector<string> currentEmployees;

    Node* root = nullptr;   
    
    Node* getParent(Node* root, Node* node);

    bool setChild(Node* parent, string direction, Node* child);

    bool replaceChild(Node* parent, Node* current, Node* newChild);

    void rotateLeft(Node* root, Node* node);

    void rotateRight(Node* root, Node* node);

    void BSTinsert(Node* root, Node* node);

    void BSTremove(Node* root, int job);

    void balance(Node* root, Node* node);

    Node* getGrandpa(Node* node);

    Node* getUncle(Node* node);

    void removeNode(Node* root, Node* node);

    Node* getPredecessor(Node* node);

    Node* getSibling(Node* node);

    bool nonNullAndRed(Node* node);

    bool nullOrBlack(Node* node);

    bool bothChildrenBlack(Node* node);

    void prepare(Node* root, Node* node);

    bool case1(Node* root, Node* node);

    bool case2(Node* root, Node* node, Node* sibling);

    bool case3(Node* root, Node* node, Node* sibling);

    bool case4(Node* root, Node* node, Node* sibling);

    bool case5(Node* root, Node* node, Node* sibling);

    bool case6(Node* root, Node* node, Node* sibling);

    string nodeToString(Node* node);
};

#endif // WORKTRACK_H__

