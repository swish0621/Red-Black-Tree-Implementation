#include "WorkTrack.h"

Node* RBT::getRoot(){
  if (root == nullptr){
    return nullptr;
  }
  return root;
}

void RBT::setRoot(Node* node){
    node -> color = "BLACK";
    root = node;
}

Node* RBT::newNode(){
    Node* node(new Node);
    node -> jobNumber = jobCount;
    jobCount++;
    node -> left = nullptr;
    node -> right = nullptr;
    node -> parent = nullptr;
    node -> color = "RED";
    node -> job = nullptr;
    return node;
}

Node* RBT::newJob(Node* node, string customer, string month, string day, string year, 
                 string employee, string cost, string paid, string time){
    Job* job(new Job);
    job -> customer = customer;
    lookup.insert(std::pair<string, int> (customer, node -> jobNumber));
    job -> date[0] = month; job -> date[1] = day; job -> date[2] = year;
    job -> employee = employee;
    job -> cost = cost;
    job -> paid = paid;
    job -> time = time;
    node -> job = job;
    return node;
}

Node* RBT::search(Node* root, int jobNumber){
    Node* cursor = root;
    while (cursor != nullptr){
        if (jobNumber == cursor -> jobNumber){
            return cursor;
        }
        else if (jobNumber < cursor -> jobNumber){
            cursor = cursor ->  left;
        }
        else {
            cursor = cursor -> right;
        }
    }
    return nullptr;
}

bool RBT::setChild(Node* parent, string direction, Node* child){
    if (direction != "LEFT" && direction != "RIGHT"){
        return false;
    }
    if (direction == "LEFT"){
        parent -> left = child;
    }
    if (direction == "RIGHT"){
        parent -> right = child;
    }
    if (child != nullptr){
        child -> parent = parent;
    }
    return true;
}

bool RBT::replaceChild(Node* parent, Node* current, Node* newChild){
    if (parent -> left == current){
        return setChild(parent, "LEFT", newChild);
    }
    else if (parent -> right == current){
        return setChild(parent, "RIGHT", newChild);
    }
    return false;
}

void RBT::rotateLeft(Node* root, Node* node){
    Node* rlChild  = node -> right -> left;
    if (node -> parent != nullptr){
        replaceChild(node -> parent, node, node -> right);
    }
    else {
        setRoot(node -> right);
        getRoot() -> parent = nullptr;
    }
    setChild(node -> right, "LEFT", node);
    setChild(node, "RIGHT", rlChild);
}

void RBT::rotateRight(Node* root, Node* node){
    Node* lrChild = node -> left -> right;
    if (node -> parent != nullptr){
        replaceChild(node -> parent, node, node -> left);
    }
    else {
        setRoot(node -> left);
        getRoot() -> parent = nullptr;
    }
    setChild(node -> left, "RIGHT", node);
    setChild(node, "LEFT", lrChild);
}

void RBT::insert(Node* root, Node* node){
    BSTinsert(root, node);
    balance(root, node);
}

void RBT::BSTinsert(Node* root, Node* node){
    if (root == nullptr){
        setRoot(node);
    }
    else {
        Node* cursor = root;
        while (cursor != nullptr){
            if (node -> jobNumber < cursor -> jobNumber){
                if (cursor -> left == nullptr){
                    cursor -> left = node;
                    cursor = nullptr;
                }
                else {
                    cursor = cursor -> left;
                }
            }
            else {
                if (cursor -> right == nullptr){
                    cursor -> right = node;
                    cursor = nullptr;
                }
                else {
                    cursor = cursor -> right;
                }
            }
        }
    }
    node -> parent = getParent(root, node);
}

Node* RBT::getParent(Node* root, Node* node){
    if (root == nullptr){
      return root;
    }
    if (root -> left == node || root -> right == node){
      return root;
    }
    if (node -> jobNumber < root -> jobNumber){
      return getParent(root -> left, node);
    }
    return getParent(root -> right, node);
}

Node* RBT::getGrandpa(Node* node){
    if (node -> parent == nullptr){
        return nullptr;
    }
    return node -> parent -> parent;
}

Node* RBT::getUncle(Node* node){
    Node* grandpa = nullptr;
    if (node -> parent  != nullptr){
        grandpa = node -> parent -> parent;
    }
    if (grandpa == nullptr){
        return nullptr;
    }
    if (grandpa -> left == node -> parent){
        return grandpa -> right;
    }
    else {
        return grandpa -> left;
    }
}

void RBT::balance(Node* root, Node* node){
    if (node -> parent == nullptr){
        node -> color = "BLACK";
        return;
    }
    if (node -> parent -> color == "BLACK"){
        return;
    }
    Node* parent = node -> parent;
    Node* grandpa = getGrandpa(node);
    Node* uncle = getUncle(node);
    if (uncle != nullptr && uncle -> color == "RED"){
        parent -> color = uncle -> color = "BLACK";
        grandpa -> color = "RED";
        balance(root, grandpa);
        return;
    }
    if (node == parent -> right && parent == grandpa -> left){
        rotateLeft(root, parent);
        node = parent;
        parent = node -> parent;
    }
    else if (node == parent -> left && parent == grandpa -> right){
        rotateRight(root, parent);
        node = parent;
        parent = node -> parent;
    }
    parent -> color = "BLACK";
    grandpa -> color = "RED";
    if (node == parent -> left){
        rotateRight(root, grandpa);
    }
    else {
        rotateLeft(root, grandpa);
    }
}

void RBT::remove(Node* root, int jobNumber){
    Node* node = search(root, jobNumber);
    if (node != nullptr){
        removeNode(root, node);
    }
}

void RBT::removeNode(Node* root, Node* node){
    if ((node -> left != nullptr) && (node -> right != nullptr)){
        Node* predecessor = getPredecessor(node);
        int num = predecessor -> jobNumber;
        Job* job = predecessor -> job;
        removeNode(root, predecessor);
        node -> jobNumber = num;
        node -> job = job;
        return;
    }
    if (node -> color == "BLACK"){
        prepare(root, node);
    }
    BSTremove(root, node -> jobNumber);

}

void RBT::BSTremove(Node* root, int job) {
    Node* parent = nullptr;
    Node* current = root;
    while (current != nullptr){
        if (current -> jobNumber == job){
            if (current -> left == nullptr && current -> right == nullptr){
                if (parent == nullptr){
                    root = nullptr;
                }
                else if (parent -> left == current){
                    parent -> left = nullptr;
                }
                else {
                    parent -> right = nullptr;
                }
                return;
            }
            else if(current -> right == nullptr){
                if (parent == nullptr){
                    root = current -> left;
                }
                else if(parent -> left == current){
                    parent -> left = current -> left;
                }
                else {
                    parent -> right = current -> left;
                }
                return;
            }
            else if(current -> left == nullptr){
                if (parent == nullptr){
                    root = current -> right;
                }
                else if(parent -> left == current){
                    parent -> left = current -> right;
                }
                else {
                    parent -> right = current -> right;
                }
                return;
            }
            else {
                Node* successor = current -> right;
                while (successor -> left != nullptr){
                    successor = successor -> left;
                }
                current -> jobNumber = successor -> jobNumber;
                parent = current;
                current = current -> right;
                job = successor -> jobNumber;
            }
        }
        else if (current -> jobNumber < job){
            parent = current;
            current = current -> right;
        }
        else {
            parent = current;
            current = current -> left;
        }
    }
    return;
}

Node* RBT::getPredecessor(Node* node){
    node = node -> left;
    while (node -> right != nullptr){
        node = node -> right;
    }
    return node;
}

Node* RBT::getSibling(Node* node){
    if (node -> parent != nullptr){
        if (node == node -> parent -> left){
            return node -> parent -> right;
        }
        return node -> parent -> left;
    }
    return nullptr;
}

bool RBT::nonNullAndRed(Node* node){
    if (node == nullptr){
        return false;
    }
    return (node -> color == "RED");
}

bool RBT::nullOrBlack(Node* node){
    if (node == nullptr){
        return true;
    }
    return(node -> color == "BLACK");
}

bool RBT::bothChildrenBlack(Node* node){
    if (node -> left != nullptr && (node -> left -> color == "RED")){
        return false;
    }
    if (node -> right != nullptr && (node -> right -> color == "RED")){
        return false;
    }
    return true;
}

void RBT::prepare(Node* root, Node* node){
    if (case1(root, node)){
        return;
    }
    Node* sibling = getSibling(node);
    if (case2(root, node, sibling)){
        sibling = getSibling(node);
    }
    if (case3(root,node, sibling)){
        return;
    }
    if (case4(root, node, sibling)){
        return;
    }
    if (case5(root, node, sibling)){
            sibling = getSibling(node);
    }
    if (case6(root, node, sibling)){
        sibling = getSibling(node);
    }
    sibling -> color = node -> parent -> color;
    node -> parent -> color = "BLACK";
    if (node == node -> parent -> left){
        sibling -> right -> color = "BLACK";
        rotateLeft(root, node -> parent);
    }
    else {
        sibling -> left -> color = "BLACK";
        rotateRight(root, node -> parent);
    }
}

bool RBT::case1(Node* root, Node* node){
    if ((node -> color == "RED") || node -> parent == nullptr){
        return true;
    }
    else {
        return false;
    }
}

bool RBT::case2(Node* root, Node* node, Node* sibling){
    if (sibling -> color == "RED"){
        node -> parent -> color = "RED";
        sibling -> color = "BLACK";
        if (node == node -> parent -> left){
            rotateLeft(root, node -> parent);
        }
        else {
            rotateRight(root, node -> parent);
        }
        return true;
    }
    return false;
}

bool RBT::case3(Node* root, Node* node, Node* sibling){
    if ((node -> parent -> color == "BLACK") && bothChildrenBlack(sibling)){
        sibling -> color = "RED";
        prepare(root, node -> parent);
        return true;
    }
    return false;
}

bool RBT::case4(Node* root, Node* node, Node* sibling){
    if ((node -> parent -> color == "RED") && bothChildrenBlack(sibling)){
        node -> parent -> color = "BLACK";
        sibling -> color = "RED";
        return true;
    }
    return false;
}

bool RBT::case5(Node* root, Node* node, Node* sibling){
    if (nonNullAndRed(sibling -> left) && nullOrBlack(sibling -> right)
        && (node == node -> parent -> left)){
        sibling -> color = "RED";
        sibling -> left -> color = "BLACK";
        rotateRight(root, sibling);
        return true;
    }
    return false;
}

bool RBT::case6(Node* root, Node* node, Node* sibling){
    if (nullOrBlack(sibling -> left) && nonNullAndRed(sibling -> right) 
        && (node == node -> parent -> right)){
        sibling -> color = "RED";
        sibling -> right -> color = "BLACK";
        rotateLeft(root, sibling);
        return true;
    }
    return false;
}

void RBT::save(){
    std::ofstream file("../data.txt", std::ios::trunc);
    if (file.is_open()){ 
        vector<vector<Node*> > structure;
        if (root == nullptr){
        return;
        }
        queue <Node*> queue;
        queue.push(root);
        while (queue.empty() != true){
            int levelSize = queue.size();
            vector<Node*>level;
            for (int i = 0 ; i < levelSize ; i++){
                Node* cursor = queue.front();
                queue.pop();
                level.push_back(cursor);
                if (cursor -> left != nullptr){
                queue.push(cursor -> left);
                }
                if (cursor -> right != nullptr){
                    queue.push(cursor -> right);
                }
            }
            structure.push_back(level);
        }
        for (int i = 0 ; i < structure.size() ; i++){
            for (int j = 0 ; j < structure.at(i).size() ; j++){
                file << nodeToString(structure.at(i).at(j)) << endl;
            }
        }
    }
    else { 
        cout << "ERROR";
    }
}

RBT RBT::load(RBT newrbt){
    std::ifstream file("../data.txt");
    vector<vector<string> >(data);
    if (file.is_open()){
        while (file){
            string str;
            if (!getline(file, str)){break;}
            istringstream ss(str);
            vector<string>(record);
            while(ss){
                string str;
                if(!getline(ss, str, ',')){break;}
                record.push_back(str);
            }
            data.push_back(record);
        }
        for (int i = 0 ; i < data.size() ; i++){
            Node* node = newrbt.newNode();
            node = newrbt.newJob(node, data.at(i).at(1), data.at(i).at(2), data.at(i).at(3),
            data.at(i).at(4), data.at(i).at(5), data.at(i).at(6), data.at(i).at(7),
            data.at(i).at(8)); 
            node -> jobNumber = stoi(data.at(i).at(0)); 
            newrbt.insert(newrbt.getRoot(), node);
        }
        newrbt.jobCount = data.size() + 1;
    }
    return newrbt;
}

void clearSave(){
    std::ofstream file("../data.txt", std::ios::trunc);
    if (file.is_open()){
        file.close();
    }
}

string RBT::nodeToString(Node* node){
    string str = "";
    if (node == nullptr){
        return str + "#";
    }
    str += to_string(node -> jobNumber) + ",";
    str += node -> job -> customer + ",";
    str += node -> job -> date[0] + ",";
    str += node -> job -> date[1] + ",";
    str += node -> job -> date[2] + ",";
    str += node -> job -> employee + ",";
    str += node -> job -> cost + ",";
    str += node -> job -> paid + ",";
    str += node -> job -> time + ",";
    return str;
}
