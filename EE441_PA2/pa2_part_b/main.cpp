#include <iostream>
using namespace std;
//first craete the node class to create bst after that
class TreeNode{
public:
    TreeNode *left;//left pointer of the node
    TreeNode *right;//right pointer of the node
    int flightValue;//it defines the flight value 15--->6 flight value 1506
    TreeNode();
};

//constructor
TreeNode::TreeNode(){}
//function to delete node

class bstFlightPlan{
public://to reach outside of the class i defined them as public
bstFlightPlan(){}
TreeNode* root_tree;
TreeNode* AddFlight(int fnumber, TreeNode* adr);//addflight in the tree
TreeNode* RemoveFlight(int flight_number, TreeNode* tptr); //remove flight in the tree
TreeNode* SearchFlight(TreeNode* ptr, int flight_no); //search flight in the tree
TreeNode* findMin(TreeNode* ptr);//find minimum value in the tree
void printBinaryTree(TreeNode* dptr);//print the binary tree on command window

};
//to make remove and add flight methods easy flight_nos are sorted according to left
TreeNode* bstFlightPlan::AddFlight(int fnumber, TreeNode* adr)//addflight
    {
        if(adr == NULL)
        {
            adr = new TreeNode;//dynamic memory alocation for the node
            adr->flightValue = fnumber;//first treenode is added
            adr->left = NULL;//right and leftmost leaves maked as NULL
            adr->right = NULL;
        }
        else if(fnumber < adr->flightValue){//if added flight no is smaller than
            adr->left = AddFlight(fnumber, adr->left);}//create tree node left side
        else{
            adr->right = AddFlight(fnumber, adr->right);}//create tree node right side

        return adr;
    };

TreeNode* bstFlightPlan::findMin(TreeNode* ptr)
    {
        if(ptr!= NULL){//if the root pointer is null that means there exist node in the tree

        if(ptr->left == NULL){
         return ptr;}
        else{
            return findMin(ptr->left); }

            }//most leftpoint keeps the smallest number
    }

    TreeNode* bstFlightPlan::RemoveFlight(int flight_number, TreeNode* tptr) {
    TreeNode* temp;
    if(tptr == NULL){ return NULL;}//there is no member in the tree
        else if(flight_number < tptr->flightValue){//go to left due to sorting
            tptr->left = RemoveFlight(flight_number, tptr->left);}
        else if(flight_number > tptr->flightValue){//go to right
            tptr->right = RemoveFlight(flight_number, tptr->right);}
        else if(tptr->left && tptr->right)
        {
            temp = findMin(tptr->right);
            tptr->flightValue = temp->flightValue;
            tptr->right = RemoveFlight(tptr->flightValue, tptr->right);
        }
        else
        {//after redesigning session deallocate the memory
            temp = tptr;
            if(tptr->left == NULL){
                tptr = tptr->right;}
            else if(tptr->right == NULL){
                tptr = tptr->left;}
            delete temp;//deallocate memory
        }

        return tptr;
    }

    TreeNode* bstFlightPlan::SearchFlight(TreeNode* ptr, int flight_no) {//find the flight in the tree
    if(ptr!=NULL){
    if(flight_no < ptr->flightValue){//go left to find
    return SearchFlight(ptr->left, flight_no);
    }
    else if(flight_no > ptr->flightValue){//go right to find
    return SearchFlight(ptr->right, flight_no);
    }
    else{return ptr;}

    }
    }
    void bstFlightPlan::printBinaryTree(TreeNode* dptr) { //if the root of the tree not null print

        if(dptr == NULL){return;}
        printBinaryTree(dptr->left);
        if(dptr->flightValue<1000){
           cout <<"EE0"<<dptr->flightValue << " "<<endl;
        }
        else{cout<<"EE"<< dptr->flightValue << " "<<endl;}

        printBinaryTree(dptr->right);
    }


    TreeNode *initialFlightPlan(bstFlightPlan &BSTobject,TreeNode *root){//it returns Treenode pointer to store upcoming nodes
    /*
    initial route map
    EEWXYZ
    WX--->YZ
    WXYZ values designed accordingly
    01--->03
    01--->07
    01--->18
    07--->01
    15--->01
    18--->07
    */




    BSTobject.root_tree=root;
    BSTobject.root_tree=BSTobject.AddFlight(107,BSTobject.root_tree);
    BSTobject.root_tree=BSTobject.AddFlight(103,BSTobject.root_tree);
    BSTobject.root_tree=BSTobject.AddFlight(118,BSTobject.root_tree);
    BSTobject.root_tree=BSTobject.AddFlight(701,BSTobject.root_tree);
    BSTobject.root_tree=BSTobject.AddFlight(1501,BSTobject.root_tree);
    BSTobject.root_tree=BSTobject.AddFlight(1807,BSTobject.root_tree);

    return BSTobject.root_tree;


    }


int main()
{
    bstFlightPlan BSTobject;
    BSTobject.root_tree=NULL;
    BSTobject.root_tree=initialFlightPlan(BSTobject,BSTobject.root_tree);
    //BSTobject.root_tree=BSTobject.RemoveFlight(701,BSTobject.root_tree);
    cout<<" "<<endl;
    cout << "Flights"<<endl;
    BSTobject.printBinaryTree(BSTobject.root_tree);
    cout<<" "<<endl;



}
