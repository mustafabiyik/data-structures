//first crete the node class to create bst after that

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int to_use_store=0;
class eeAirLines{//it contains the methods to create routes
private:
 int numCity;//number of vertices
 int numRoute;//number of edges
 int **wholeRoutes;//pointer for adjacency matrix
 int *label;//it will show us the label of the cities int the matrix
//for example if we have 5*5 matrix that means 5 vertex and these cities are not 0,1,2,3,4 in the given list
//label[0]=1 means 5*5 array's first row and first column implies first city in the list
//label[1]=3 means 5*5 array's second row and second column implies second city in the list
//label[2]=7 means 5*5 array's third row and third column implies second city in the list
//label[3]=15 means array for initial map case
//label[4]=18 means array
public:

 eeAirLines(int n);
 ~eeAirLines();
 void addCity(int city_no);                       //add vertex to the graph, and update labels and 5*5 matrix according to the added city no in the city list
 void removeCity(int city_no);                      //remove vvertex from the graph,
 int searchCity(string city_name) const;               //determines the if city on the graph or not, it is constant function does not change anything
 void addRoute(int init,int dest,int fare);          //add the edge to the graph, init--->dest with fare
 void removeRoute(int init,int dest);               //remove  the edge from the graph
 int searchRoute(int init,int dest) const;              //it specifies that desired route exist or not according to that it returns true or false
 void listRoutes() const;//                           //it lists the possible routes between cities thanks to the print function
 int getLabel(int city_no);                      //get specified marked city value
 int city() const;                       //number of cities means number vertices
 int routes() const;                   //number of routes edges
 int getfare(int v1, int v2); //return fare value in the specified matrix location
 void setFare(int v1, int v2,int fare);
 void setlabel(int i,int lab);
 string takeCityName(int city_no) const; //it returns the city name from the output
};
string eeAirLines::takeCityName(int city_no) const{

string line;
string city[20];
ifstream myfile ("citylist.txt");
if (myfile.is_open())
{
int i=0;
while ( getline (myfile,line) )
{
city[i]=line;

i++;
}
myfile.close();
}
else {cout << "Unable to open file";}

return city[city_no-1]; //because city array starting from the 0 therefore city_no-1 gives the location of the string

}




void eeAirLines::setlabel(int i,int lab){//set the label value
label[i]=lab;
}
// Constructor
eeAirLines::eeAirLines(int n){      //n means city number to specify the vertex number
int i;
numCity = n;
numRoute = 0;
label = new int[numCity];           // Initialize label array
for (i=0; i < numCity; i++){
label[i] = 0;}                  //initially labels hold 0 value
                                // Make matrix, it is not possible to create 2D array with a single new operation. Size is numCity*numCity
wholeRoutes = new int*[numCity]; //wholeRoutes matrix holds the 2D array which contains the routes between the cities
for(i=0; i < numCity; i++)
wholeRoutes[i] = new int[numCity];//dynamic memory allocation
    for(i=0; i < numCity; i++){ // Initialize to 0
        for (int j=0; j < numCity; j++){
            wholeRoutes[i][j] = 0;}}//initialize with 0 to 2D matrix
}
// Destructor, Return dynamically allocated memory

eeAirLines::~eeAirLines(){
for(int i=0;i<numCity;i++){//deallocate the memory which allocated for wholeRoutes 2D matrix
delete [] wholeRoutes[i];
}
delete [] wholeRoutes;
delete [] label; //deallocate memory which allocated for available cities to fly
}

void eeAirLines::addRoute(int init,int dest,int fare) { // Set edge (init, dest) to "fare"
//it takes initial and final city, corresponding location in the matrix assigned as fare value
int inital;
int destination;
for(int i=0;i<numCity;i++){
    if(label[i]==init){
        inital=i;//matrix location
    }
     if(label[i]==dest){
        destination=i;//label converted into teh matrix location in numcity*numcity
    }
}

if (wholeRoutes[inital][destination]==0){
numRoute++;
wholeRoutes[inital][destination] = fare;}
}

void eeAirLines::removeRoute(int init, int dest) { // Delete edge (init, dest)

int inital;
int destination;
for(int i=0;i<numCity;i++){
    if(label[i]==init){
        inital=i;//matrix location
    }
     if(label[i]==dest){
        destination=i;//label converted into teh matrix location in numcity*numcity
    }
}


if (wholeRoutes[inital][destination]!= 0)
numRoute--;
wholeRoutes[inital][destination] = 0;//if fare between teh two cities is 0 that means there is no route
}

int eeAirLines::searchRoute(int init, int dest) const{ // Is (init,dest) an route?
    int inital;
int destination;
for(int i=0;i<numCity;i++){
    if(label[i]==init){
        inital=i;//matrix location
    }
     if(label[i]==dest){
        destination=i;//label converted into teh matrix location in numcity*numcity
    }
}
if(wholeRoutes[inital][destination]!=0){
return wholeRoutes[inital][destination];}
}

int eeAirLines::searchCity(string city_name) const{ //if the city no exist boolean returns true otherwise false
string line;
string city[20];
ifstream myfile ("citylist.txt");
if (myfile.is_open())
{
int i=0;
while ( getline (myfile,line) )
{
city[i]=line;
i++;
}
myfile.close();
}
else {cout << "Unable to open file";}


for(int i=0;i<20;i++){//find the searched city's city_no
    if(city[i]==city_name){//label keeps the city no of the airlines
        for(int j=0;j<numCity;j++){

        if(label[j]==(i+1)){
        return (i+1);}//after finding identity of the city lets return the city_no after validation
        //validate city in route map or not


        //because array index starts from the 0
    }
}
}}
void eeAirLines::setFare(int v1, int v2,int fare) { // Return weight of (v1,v2)
 int inital;
int destination;
for(int i=0;i<numCity;i++){
    if(label[i]==v1){
        inital=i;//matrix location
    }
     if(label[i]==v2){
        destination=i;//label converted into teh matrix location in numcity*numcity
    }
}
wholeRoutes[inital][destination]=fare;
}
int eeAirLines::getfare(int v1, int v2) { // Return weight of (v1,v2)
 int inital;
int destination;
for(int i=0;i<numCity;i++){
    if(label[i]==v1){
        inital=i;//matrix location
    }
     if(label[i]==v2){
        destination=i;//label converted into teh matrix location in numcity*numcity
    }
}
return wholeRoutes[inital][destination];
}
int eeAirLines::city() const{
    return numCity;}
int eeAirLines::routes() const{
    return numRoute;}

int eeAirLines::getLabel(int city_no){//return the index in the label matrix
for(int i=0;i<numCity;i++){
    if(label[i]==city_no){
        return i;
    }
}
}

void eeAirLines::addCity(int city_no) //add vertex to the graph, and update labels and 5*5 matrix according to the added city no in the city list
{
    //create 1D and 2D temp arrays to keep values in the array beacause we need to resize the initial array and label
int **tempwholeRoutes;//pointer for adjacency matrix
int *templabel;
int i;
int k=numCity;  //same size with the numcity to copy the initial values to resize

templabel = new int[k];
for (i=0; i < k; i++){
templabel[i] = label[i];}    //label values transferred to templabel

tempwholeRoutes = new int*[k];
for(i=0; i < k; i++){
tempwholeRoutes[i] = new int[k];}//dynamic memory allocation for temp variable
    for(i=0; i < k; i++){
        for (int j=0; j < k; j++){
            tempwholeRoutes[i][j] = wholeRoutes[i][j];}}//transfer the values

//now templabel and tempwholeRoutes keep the values firstly we need to deallocate memory for label and whole routes
//then increase label and numCity by 1
for(int i=0;i<numCity;i++){//deallocate the memory which allocated for wholeRoutes 2D matrix
delete [] wholeRoutes[i];
}
delete [] wholeRoutes;
delete [] label; //deallocate memory which allocated for available cities to fly
//resizing and the transferring back the values
numCity = numCity+1;

label = new int[numCity];           // Initialize label array
for (i=0; i < numCity-1; i++){ //city added as last member
label[i] = templabel[i];}
label[numCity-1]=city_no;//add new city as last label

wholeRoutes = new int*[numCity]; //wholeRoutes matrix holds the 2D array which contains the routes between the cities
for(i=0; i < numCity; i++){
wholeRoutes[i] = new int[numCity];}//dynamic memory allocation after added new city dimension increases +1
int j;
     for(i=0; i < numCity; i++){ //last row and last column for the new added city
        for (j=0; j < numCity; j++){
        if(i<(numCity-1)&&j<(numCity-1)){
            wholeRoutes[i][j] = tempwholeRoutes[i][j];}
        else{ wholeRoutes[i][j] =0;}


            }}//transfer back to the resized array
//deallocate the dynamic memory which allocated for the temp arrays
for(int i=0;i<k;i++){//deallocate the memory which allocated for wholeRoutes 2D matrix
delete [] tempwholeRoutes[i];
}
delete [] tempwholeRoutes;
delete [] templabel; //deallocate memory which allocated for available cities to fly
// now we have resized array and label which keeps the initial values
}


void eeAirLines::removeCity(int city_no)     //remove city from the graph,
{
    //create 1D and 2D temp arrays to keep values in the array beacause we need to resize the initial array and label
int **tempwholeRoutes;//pointer for adjacency matrix
int *templabel;
int i;
int k=numCity;  //same size with the numcity to copy the initial values to resize

templabel = new int[k];
for (i=0; i < k; i++){
templabel[i] = label[i];}    //label values transferred to templabel

tempwholeRoutes = new int*[k];
for(i=0; i < k; i++){
tempwholeRoutes[i] = new int[k];}//dynamic memory allocation for temp variable
    for(i=0; i < k; i++){ // Initialize to 0
        for (int j=0; j < k; j++){
            tempwholeRoutes[i][j] = wholeRoutes[i][j];}}//transfer the values

//now templabel and tempwholeRoutes keep the values firstly we need to deallocate memory for label and whole routes
//then increase label and numCity by 1
for(int i=0;i<k;i++){//deallocate the memory which allocated for wholeRoutes 2D matrix
delete [] wholeRoutes[i];
}
delete [] wholeRoutes;
delete [] label; //deallocate memory which allocated for available cities to fly
//resizing and the transferring back the values
numCity = numCity-1;

label = new int[numCity];           // Initialize label array
int j=0;
for (i=0; i < k; i++){ //k  keeps the initial numCity value before resizing
if(templabel[i]!=city_no){
label[j]=templabel[i];//when city no exist in the templabel this value not transferred to the modified
j=j+1;
}
}


wholeRoutes = new int*[numCity]; //wholeRoutes matrix holds the 2D array which contains the routes between the cities
for(i=0; i < numCity; i++)
wholeRoutes[i] = new int[numCity];//dynamic memory allocation after removed the city dimension decreases by 1
int c,r;
c=0;
r=0;
    for(i=0; i < k; i++){ //last row and last column for the new added city
    c=0;
            if(templabel[i]!=city_no){//skip the removed row not transfer it to the resized one
        for (int j=0; j < k; j++){
                if(templabel[j]!=city_no){
            wholeRoutes[r][c] = tempwholeRoutes[i][j];
            c=c+1;}
            }
           r=r+1;} }


        //transfer back to the resized array


//deallocate the dynamic memory which allocated for the temp arrays
for(int i=0;i<k;i++){//deallocate the memory which allocated for wholeRoutes 2D matrix
delete [] tempwholeRoutes[i];
}
delete [] tempwholeRoutes;
delete [] templabel; //deallocate memory which allocated for available cities to fly
// now we have resized array and label which keeps the initial values





}

 void eeAirLines::listRoutes() const{
string line;
string city[20];
ifstream myfile ("citylist.txt");
if (myfile.is_open())
{
int i=0;
while ( getline (myfile,line) )
{
city[i]=line;
i++;
}
myfile.close();
}
else {cout << "Unable to open file";}

 for(int i=0;i<numCity;i++){

    for(int j=0;j<numCity;j++){
         if(wholeRoutes[i][j]!=0){
            cout<<"("<<city[label[i]-1]<<"--->"<<city[label[j]-1]<<","<<wholeRoutes[i][j]<<")"<<endl;
         }
    }

 }
 }
void initializeRouteMap(eeAirLines &routeadd){

 // random numbers on every program run
  //setlabel(int i,int lab); i is index lab is teh city no

    routeadd.setlabel(0,1);
    routeadd.setlabel(1,3);
    routeadd.setlabel(2,7);
    routeadd.setlabel(3,15);
    routeadd.setlabel(4,18);
    //label setting needed for just initialization after that we can handle with remove and add city methods
    routeadd.addRoute(18, 7,rand()%1000);
    routeadd.addRoute(7, 1,rand()%1000);
    routeadd.addRoute(1, 7,rand()%1000);
    routeadd.addRoute(1, 18,rand()%1000);
    routeadd.addRoute(1, 3,rand()%1000);
    routeadd.addRoute(15, 1,rand()%1000);
   //cout<<routeadd.searchCity("North Kirchoff")<<endl;



    // print the adjacency list representation of the above graph
    //routeadd.listRoutes();

 }

class TreeNode{
private:
  int OccupancyRate;
public:
    TreeNode *left;//left pointer of the node
    TreeNode *right;//right pointer of the node
    int flightValue;//it defines the flight value 15--->6 flight value 1506
    void setOccupancyRate(int rate);//set occupancy
    int getOccupancyRate() const;//get occupancy
    TreeNode();
};

//constructor
TreeNode::TreeNode(){}

void TreeNode::setOccupancyRate(int rate){//to absolute change
OccupancyRate=rate;

}
int TreeNode::getOccupancyRate() const{
return OccupancyRate;

}
//function to delete node

class bstFlightPlan{
public://to reach outside of the class i defined them as public
bstFlightPlan(){}
TreeNode* root_tree;
TreeNode* AddFlight(int fnumber, TreeNode* adr,int rate);//addflight in the tree
TreeNode* RemoveFlight(int &flight_number, TreeNode* &tptr); //remove flight in the tree
TreeNode* SearchFlight(TreeNode* ptr, int flight_no); //search flight in the tree
TreeNode* findMin(TreeNode* ptr);//find minimum value in the tree
//int *GetOccupancyArray(TreeNode *adr);//it returns the occupancy of the flights as array
//int *FlightNumberArray(TreeNode *adr);//it stores the flight numbers as array
//TreeNode* SetOccupancyRate(TreeNode* ptr, int flight_no,int rate);//set the OR in the tree specified node corresponding the city_no
//int GetOccupancyRate(TreeNode* ptr, int flight_no);//get occupancy rate corresponding ciy_no
void printBinaryTree(TreeNode* dptr);//print the binary tree on command window

};


/*
int *bstFlightPlan::GetOccupancyArray(TreeNode *adr)//it returns the occupancy of the flights as array
{
if(to_use_store==0){
int occupancyArray[40];
to_use_store=to_use_store+1;
}
if(adr!=NULL){
GetOccupancyArray(adr->left);


GetOccupancyArray(adr->right);
}}*/
//int *bstFlightPlan::FlightNumberArray(TreeNode *adr);//it stores the flight numbers as array

//to make remove and add flight methods easy flight_nos are sorted according to left
TreeNode* bstFlightPlan::AddFlight(int fnumber, TreeNode* adr,int rate)//addflight
    {
        if(adr == NULL)
        {
            adr = new TreeNode;//dynamic memory alocation for the node
            adr->flightValue = fnumber;//first treenode is added
            adr->left = NULL;//right and leftmost leaves maked as NULL
            adr->right = NULL;
            adr->setOccupancyRate(rate);
        }
        else if(fnumber < adr->flightValue){//if added flight no is smaller than
            adr->left = AddFlight(fnumber, adr->left,rate);}//create tree node left side
        else{
            adr->right = AddFlight(fnumber, adr->right,rate);}//create tree node right side

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

    TreeNode* bstFlightPlan::RemoveFlight(int &flight_number, TreeNode* &tptr) {
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
    else{return ptr;}//return the searched flight pointer

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
    void elementNumberFinder(TreeNode* dptr, int &NofElements) { //if the root of the tree not null print

        if(dptr == NULL){return;}
        elementNumberFinder(dptr->left,NofElements);
        NofElements=NofElements+1;
        elementNumberFinder(dptr->right,NofElements);
    }
    void returnElementsArray(TreeNode* dptr, int &i,int *&arrayA) {//return array

        if(dptr == NULL){return;}
        returnElementsArray(dptr->left,i,arrayA);
        arrayA[i]=dptr->flightValue;
        i=i+1;
        returnElementsArray(dptr->right,i,arrayA);
    }

    TreeNode *initialFlightPlan(bstFlightPlan &BSTobject,TreeNode *root){//it returns Treenode pointer to store upcoming nodes



    BSTobject.root_tree=root;
    BSTobject.root_tree=BSTobject.AddFlight(107,BSTobject.root_tree,rand()%100);
    BSTobject.root_tree=BSTobject.AddFlight(103,BSTobject.root_tree,rand()%100);
    BSTobject.root_tree=BSTobject.AddFlight(118,BSTobject.root_tree,rand()%100);
    BSTobject.root_tree=BSTobject.AddFlight(1501,BSTobject.root_tree,rand()%100);
    BSTobject.root_tree=BSTobject.AddFlight(1807,BSTobject.root_tree,rand()%100);
    BSTobject.root_tree=BSTobject.AddFlight(701,BSTobject.root_tree,rand()%100);

    return BSTobject.root_tree;


    }
//to change content of the discarded and unpopular flights we need to use pass by reference
    void CancelUnpopularFlights(bstFlightPlan &BSTobject,TreeNode *&root,int OT_value,int *&discarded,int *&unpopular,int &flag){
    //store unpopular and discarded in array and then return this array from the function


//to examine consecutive two month occupancies we need to flag
int  *arrayA;
int k=0;
int NofElements=0;//it keeps the element number in the
elementNumberFinder(root,NofElements);
arrayA=new int[NofElements];
//arrayA keeps the elements in the binary tree and number of elements keep the element number
returnElementsArray(root, k, arrayA);
TreeNode *pt;
pt=new TreeNode;
int *unpopular1;
unpopular1=new int[NofElements];
int *unpopular2;
unpopular2=new int[NofElements];
int c=0;//initialize the array index keepers
int u=0;
flag=flag+1;//it keeps the month number

for(int i=0;i<NofElements;i++){
        pt=BSTobject.SearchFlight(BSTobject.root_tree,arrayA[i]);//control the flight it returns the searched
        //node pointer
        pt->setOccupancyRate(rand()%100);//each month occupancy rate is changed according to the this change


   if(pt->getOccupancyRate()<OT_value){
    if(flag%2==1){//in the odd months
     unpopular1[i]=pt->getOccupancyRate();
//flight must be discarded case
      if(unpopular1[i]<OT_value&&unpopular2[i]<OT_value){//there is discarded issue
//unpopular2 keeps the previous month OT in this case
//unpopular1 keeps the current month OT in this case
cout<<"discarded "<<c<<"-"<<pt->flightValue<<endl;
            discarded[c]=pt->flightValue;
            c=c+1;

             BSTobject.RemoveFlight(pt->flightValue,root);

           }
//flight is unpopular case
           else if(unpopular1[i]<OT_value&&unpopular2[i]>OT_value){
cout<<"unpopular "<<u<<"-"<<pt->flightValue<<endl;
            unpopular[u]=pt->flightValue;
            u=u+1;


           }

for(int i=0;i<NofElements;i++){//due to segmentation error initialize the array contents

    unpopular2[i]=100;


}
        }
    if(flag%2==0){//in the even months
            //unpopular also second month if consecuent two month is lower than the threshold then discard that one
            unpopular2[i]=pt->getOccupancyRate();
             if(unpopular1[i]<OT_value&&unpopular2[i]<OT_value){//there is discarded issue
//unpopular1 keeps the previous month OT in this case
//unpopular2 keeps the current month OT in this case
cout<<"discarded "<<c<<"-"<<pt->flightValue<<endl;
            discarded[c]=pt->flightValue;

        BSTobject.RemoveFlight(discarded[c],root);
          c=c+1;
           }

           else if(unpopular2[i]>OT_value&&unpopular1[i]<OT_value){
cout<<"unpopular "<<c<<"-"<<pt->flightValue<<endl;


           unpopular[u]=pt->flightValue;
           u=u+1;

           }

           }

           }

    }

}
//: Use the outputs of CANCELUNPOPULARFLIGHTS to update the routemap in a)
void DiscardUnpopularRoutesAndPrices(eeAirLines &routeadd,int *&discarded,int *&unpopular){
int arr;
int dep;
//specify the range we will take array values
int i=0;
cout<<"Discarded Routes & Routes on Discount"<<endl;

while(discarded[i]/100>=1&&discarded[i]/100<=20&&discarded[i]%100>=1&&discarded[i]%100<=20){
    dep=discarded[i]/100;//it gives us the departure of the route
    arr=discarded[i]%100;//it gives arrival city no
    cout<<"("<<routeadd.takeCityName(dep)<<"--->"<<routeadd.takeCityName(arr)<<")"<<"Route Discarded"<<endl;
    routeadd.removeRoute(dep,arr);

  i++;
}
//to decrase the prices of the routes
i=0;
while(unpopular[i]/100>=1&&unpopular[i]/100<=20&&unpopular[i]%100>=1&&unpopular[i]%100<=20){
   dep=unpopular[i]/100;//it gives us the departure of the route
    arr=unpopular[i]%100;//it gives arrival city no
cout<<"(";
    cout<<routeadd.takeCityName(dep)<<"--->"<<routeadd.takeCityName(arr)<<routeadd.getfare(dep,arr)/2<<")"<<"is 50% Off"<<endl;
    routeadd.setFare(dep,arr,routeadd.getfare(dep,arr)/2);

  i++;
}
}















int main()
{
int OT_value;
    cout<<"enter the Occupancy Treshold value"<<endl;
    cin>>OT_value;

    bstFlightPlan BSTobject;
    BSTobject.root_tree=NULL;
    BSTobject.root_tree=initialFlightPlan(BSTobject,BSTobject.root_tree);
    TreeNode *tempkeeper;//tempkeeper holds the root of the tree
    tempkeeper= BSTobject.root_tree;
    BSTobject.printBinaryTree(tempkeeper);
    int NofElements;
    elementNumberFinder(tempkeeper,NofElements);
    int *discarded;
    discarded=new int[NofElements];
    int *unpopular;
    unpopular=new int[NofElements];

    int flag=0;
CancelUnpopularFlights(BSTobject,tempkeeper,OT_value,discarded,unpopular,flag);
 BSTobject.printBinaryTree(tempkeeper);
CancelUnpopularFlights(BSTobject,tempkeeper,OT_value,discarded,unpopular,flag);
 //BSTobject.printBinaryTree(BSTobject.root_tree);

//CancelUnpopularFlights(BSTobject.root_tree,OT_value,discarded,unpopular,flag);
 BSTobject.printBinaryTree(tempkeeper);
 CancelUnpopularFlights(BSTobject,tempkeeper,OT_value,discarded,unpopular,flag);
 BSTobject.printBinaryTree(tempkeeper);

 CancelUnpopularFlights(BSTobject,tempkeeper,OT_value,discarded,unpopular,flag);
 BSTobject.printBinaryTree(tempkeeper);




}
