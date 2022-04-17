#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
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
 int fare(int v1, int v2) const; //return fare value in the specified matrix location
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
cout <<i+1<<"-"<<city[i] <<endl;
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
}};

int eeAirLines::fare(int v1, int v2) const{ // Return weight of (v1,v2)
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
int main()
{
 eeAirLines routeadd(5);

initializeRouteMap(routeadd);
//routeadd.addRoute(10,1,rand()%1000);
 routeadd.listRoutes();

    return 0;
}




