#include<iostream>
#include <fstream>
using namespace std;
const int maxSize=100;
class Sobokan{
private:
 char sobokanArray[6][8];
 int pos_x,pos_y;

public:
  Sobokan();//simple constructor
  Sobokan(const Sobokan &obj);// copy constructor
  Sobokan &operator=(const Sobokan &rhs);//assignment operator to copy
  ~Sobokan();// deconstructor to free the memory after execution
  bool move_up(); //move up method
  bool move_down(); //move down method
  bool move_left();//move left method
  bool move_right();//move right method
  bool is_solved() const; //puzzle is solved method
  void print_puzzle() const;//prints the text-based representation of the current state of the puzzle
  char getvalue(int x,int y) const;//to set the @ value
 // int getlocation_x(void) const;//to get matrix location of the player in terms of pos_X
  //int getlocation_y(void) const;//to get matrix location of the player in terms of pos_y
  void setPos(int x,int y);//to get @ value
  void setArray(int x,int y, char val);
};
/*
int Sobokan::getlocation_x() const{ // it returns the location of the player at x axis
return pos_x;
}
int Sobokan::getlocation_y() const{ // it returns the location of the player at y axis
return pos_y;
}
*/
void Sobokan::setArray(int x,int y, char val){//it changes the specified index in the array

sobokanArray[x][y]=val;


}
Sobokan::Sobokan(){ //simple constructor initialize the Sobokan array, in other method this specified array is used by loading text file

string path = "sample_puzzle.txt"; //it takes map from the text file

char dummy;
ifstream file;
file.open(path);
for(int i=0; i<6; i++){
 for(int j=0; j<8; j++){
 file >> noskipws >> sobokanArray[i][j];
 }

 file >> noskipws >> dummy;
}
file.close();


for(int k=0;k<6;k++){ //to detect initial position of the player
    for(int m=0;m<8;m++){
      if(sobokanArray[k][m]=='@'||sobokanArray[k][m]=='+') {
      pos_x=k;//according to the initial text lets specify the loaction of the player
      pos_y=m;
      }
    }}

}


Sobokan::Sobokan(const Sobokan &obj){// copy constructor, the parameter in copy constructor must be passed by reference to avoid recursively calling issue of the constructor

 //static data is copied from obj to current object
 for(int k=0;k<6;k++){
    for(int m=0;m<8;m++){
sobokanArray[k][m]=obj.sobokanArray[k][m];//for the array content

    }}
 pos_x=obj.pos_x;// positions copied the private members
 pos_y=obj.pos_y;

}


 Sobokan& Sobokan::operator=(const Sobokan &rhs){//assignment operator to copy
//content of the array must be same as the current object

 for(int k=0;k<6;k++){
    for(int m=0;m<8;m++){

 sobokanArray[k][m]=rhs.sobokanArray[k][m]; // array content is assigned with = operator on the static memory

    }}

 //copy static data members from rhs to the current object
 pos_x=rhs.pos_x;
 pos_y=rhs.pos_y;


 return *this;//this used to return a reference to the current object

 }


 Sobokan::~Sobokan(){// deconstructor to free the memory after execution after execution deconstructor automatically called

 }


bool Sobokan::move_up(){ //move up method sobokanarray content updated according to the specifications

    if(sobokanArray[pos_x-1][pos_y]=='#'){

     if(sobokanArray[pos_x][pos_y]=='@'){  //if there is no move oppurtunity does not change anything
            sobokanArray[pos_x][pos_y]='@';}//nothing change then after that return bool false from this method
        else if(sobokanArray[pos_x][pos_y]=='+'){
            sobokanArray[pos_x][pos_y]='+';}


    return false;}

    else if(sobokanArray[pos_x-1][pos_y]==' '||sobokanArray[pos_x-1][pos_y]=='.'){  //absolutely goes to up because there is available space
        if(sobokanArray[pos_x][pos_y]=='@'){                       //if player at the no target after passing i assign space
            sobokanArray[pos_x][pos_y]=' ';}//after player goes their previous space updated as blank
        else if(sobokanArray[pos_x][pos_y]=='+'){
            sobokanArray[pos_x][pos_y]='.';}//after player goes their previous space updated as point
         if(sobokanArray[pos_x-1][pos_y]==' '){
         sobokanArray[pos_x-1][pos_y]='@';} //at new location player is updated as @ because previous representation of the place is blank
         else{
         sobokanArray[pos_x-1][pos_y]='+'; //at new location player is updated as + because previous representation of the place is point
        }


        pos_x=pos_x-1;
        return true;
     }


     else if(sobokanArray[pos_x-1][pos_y]=='$'||sobokanArray[pos_x-1][pos_y]=='*'){//when previous two conditions not satisfied, it goes to up depends on the pos_x-2 value because other
if(pos_x>1){                                                                       //pos_x must be greater than the 1 otherwise, segmentation core error occurs
       if(sobokanArray[pos_x-2][pos_y]=='$'||sobokanArray[pos_x-2][pos_y]=='*'||sobokanArray[pos_x-2][pos_y]=='#'){

       if(sobokanArray[pos_x][pos_y]=='@'){  //if there is no move oppurtunity does not change anything
            sobokanArray[pos_x][pos_y]='@';} // no move
        else if(sobokanArray[pos_x][pos_y]=='+'){
            sobokanArray[pos_x][pos_y]='+';}// no move

       return false;}

       else if(sobokanArray[pos_x-2][pos_y]==' '||sobokanArray[pos_x-2][pos_y]=='.'){ // now the player can push the box available space
      ////location updates
       if(sobokanArray[pos_x-2][pos_y]==' '){
       sobokanArray[pos_x-2][pos_y]='$';//free space become the dollar after move
       }
       else{
       sobokanArray[pos_x-2][pos_y]='*';}//free space become the * after move

        if(sobokanArray[pos_x][pos_y]=='@'){
            sobokanArray[pos_x][pos_y]=' ';}//previous player expression updated
        else if(sobokanArray[pos_x][pos_y]=='+'){
            sobokanArray[pos_x][pos_y]='.';}//previous player expression updated

         if(sobokanArray[pos_x-1][pos_y]=='$'){
         sobokanArray[pos_x-1][pos_y]='@';}//current player expression updated
         else if(sobokanArray[pos_x-1][pos_y]=='*'){
         sobokanArray[pos_x-1][pos_y]='+';//current player expression updated
        }
        pos_x=pos_x-1;
        return true;
     }
     }


}

return false;
  }


bool Sobokan::move_down(){ //move down method sobokanarray content updated according to the specifications
    if(sobokanArray[pos_x+1][pos_y]=='#'){
     if(sobokanArray[pos_x][pos_y]=='@'){  //if there is no move oppurtunity does not change anything
            sobokanArray[pos_x][pos_y]='@';}
        else if(sobokanArray[pos_x][pos_y]=='+'){
            sobokanArray[pos_x][pos_y]='+';}

    return false;}

    else if(sobokanArray[pos_x+1][pos_y]==' '||sobokanArray[pos_x+1][pos_y]=='.'){//absolutely goes to down
        if(sobokanArray[pos_x][pos_y]=='@'){//if player at the no target after passing i assign space
            sobokanArray[pos_x][pos_y]=' ';}//previous player expression updated
        else if(sobokanArray[pos_x][pos_y]=='+'){
            sobokanArray[pos_x][pos_y]='.';}//previous player expression updated
         if(sobokanArray[pos_x+1][pos_y]==' '){
         sobokanArray[pos_x+1][pos_y]='@';}//current player expression updated
         else if(sobokanArray[pos_x+1][pos_y]=='*'){
         sobokanArray[pos_x+1][pos_y]='+';//current player expression updated
        }
        pos_x=pos_x+1;
        return true;
     }


     else if(sobokanArray[pos_x+1][pos_y]=='$'||sobokanArray[pos_x+1][pos_y]=='*'){//it goes to up depends ont he pos_x+2 value

       if(sobokanArray[pos_x+2][pos_y]=='$'||sobokanArray[pos_x+2][pos_y]=='*'||sobokanArray[pos_x+2][pos_y]=='#'){ // no availability of space

        if(sobokanArray[pos_x][pos_y]=='@'){  //if there is no move oppurtunity does not change anything
            sobokanArray[pos_x][pos_y]='@';}
        else if(sobokanArray[pos_x][pos_y]=='+'){
            sobokanArray[pos_x][pos_y]='+';}


       return false;}

       else if(sobokanArray[pos_x+2][pos_y]==' '||sobokanArray[pos_x+2][pos_y]=='.'){ //available to move but update the expression
       if(sobokanArray[pos_x+2][pos_y]==' '){
       sobokanArray[pos_x+2][pos_y]='$'; //update if pos_X+2 is available
       }
       else if(sobokanArray[pos_x+2][pos_y]=='.'){
       sobokanArray[pos_x+2][pos_y]='*';} //update if pos_X+2 is available

        if(sobokanArray[pos_x][pos_y]=='@'){//update the player previous location expression
            sobokanArray[pos_x][pos_y]=' ';}
        else if(sobokanArray[pos_x][pos_y]=='+'){
            sobokanArray[pos_x][pos_y]='.';}

         if(sobokanArray[pos_x+1][pos_y]=='$'){ //update the player current location expression
         sobokanArray[pos_x+1][pos_y]='@';}
         else if(sobokanArray[pos_x+1][pos_y]=='*'){
         sobokanArray[pos_x+1][pos_y]='+';
        }
        pos_x=pos_x+1;
        return true;
     }


}
return false;

  }


bool Sobokan::move_left(){ //move left method sobokanarray content updated according to the specifications
    if(sobokanArray[pos_x][pos_y-1]=='#'){

     if(sobokanArray[pos_x][pos_y]=='@'){  //if there is no move oppurtunity does not change anything
            sobokanArray[pos_x][pos_y]='@';}
        else if(sobokanArray[pos_x][pos_y]=='+'){
            sobokanArray[pos_x][pos_y]='+';}


    return false;}

    else if(sobokanArray[pos_x][pos_y-1]==' '||sobokanArray[pos_x][pos_y-1]=='.'){//absolutely goes to left
        if(sobokanArray[pos_x][pos_y]=='@'){//if player at the no target after passing, i assign space
            sobokanArray[pos_x][pos_y]=' ';}
        else if(sobokanArray[pos_x][pos_y]=='+'){ //update the player previous location expression
            sobokanArray[pos_x][pos_y]='.';}
         if(sobokanArray[pos_x][pos_y-1]==' '){//update the player current location expression
         sobokanArray[pos_x][pos_y-1]='@';}
         else if(sobokanArray[pos_x][pos_y-1]=='*'){
         sobokanArray[pos_x][pos_y-1]='+';
        }
        pos_y=pos_y-1;
        return true;
     }


     else if(sobokanArray[pos_x][pos_y-1]=='$'||sobokanArray[pos_x][pos_y-1]=='*'){//it goes to up depends ont he pos_y-2 value

       if(sobokanArray[pos_x][pos_y-2]=='$'||sobokanArray[pos_x][pos_y-2]=='*'||sobokanArray[pos_x-2][pos_y]=='#'){ // no available space to move

        if(sobokanArray[pos_x][pos_y]=='@'){  //if there is no move oppurtunity does not change anything
            sobokanArray[pos_x][pos_y]='@';}
        else if(sobokanArray[pos_x][pos_y]=='+'){
            sobokanArray[pos_x][pos_y]='+';}

       return false;}
       else if(sobokanArray[pos_x][pos_y-2]==' '||sobokanArray[pos_x][pos_y-2]=='.'){//space is available to move box
       if(sobokanArray[pos_x][pos_y-2]==' '){//update the box current location expression
       sobokanArray[pos_x][pos_y-2]='$';
       }
       else if(sobokanArray[pos_x][pos_y-2]=='.'){
       sobokanArray[pos_x][pos_y-2]='*';}

        if(sobokanArray[pos_x][pos_y]=='@'){//update the player previous location expression
            sobokanArray[pos_x][pos_y]=' ';}
        else if(sobokanArray[pos_x][pos_y]=='+'){
            sobokanArray[pos_x][pos_y]='.';}
         if(sobokanArray[pos_x][pos_y-1]=='$'){//update the player current location expression
         sobokanArray[pos_x][pos_y-1]='@';}
         else if(sobokanArray[pos_x][pos_y-1]=='*'){
         sobokanArray[pos_x][pos_y-1]='+';
        }
        pos_y=pos_y-1;
        return true;
     }


}

return false;
  }


bool Sobokan::move_right(){ //move right method sobokanarray content updated according to the specifications
    if(sobokanArray[pos_x][pos_y+1]=='#'){


     if(sobokanArray[pos_x][pos_y]=='@'){  //if there is no move oppurtunity does not change anything
            sobokanArray[pos_x][pos_y]='@';}
        else if(sobokanArray[pos_x][pos_y]=='+'){
            sobokanArray[pos_x][pos_y]='+';}



    return false;}

    else if(sobokanArray[pos_x][pos_y+1]==' '||sobokanArray[pos_x][pos_y+1]=='.'){//absolutely goes to right
        if(sobokanArray[pos_x][pos_y]=='@'){//if player at the no target after passing i assign space
            sobokanArray[pos_x][pos_y]=' ';}
        else if(sobokanArray[pos_x][pos_y]=='+'){
            sobokanArray[pos_x][pos_y]='.';}
         if(sobokanArray[pos_x][pos_y+1]==' '){//update the player current location expression
         sobokanArray[pos_x][pos_y+1]='@';}
         else if(sobokanArray[pos_x][pos_y+1]=='.'){
         sobokanArray[pos_x][pos_y+1]='+';
        }
        pos_y=pos_y+1;
        return true;
     }


     else if(sobokanArray[pos_x][pos_y+1]=='$'||sobokanArray[pos_x][pos_y+1]=='*'){//it goes to up depends ont he pos_y-2 value

       if(sobokanArray[pos_x][pos_y+2]=='$'||sobokanArray[pos_x][pos_y+2]=='*'||sobokanArray[pos_x+2][pos_y]=='#'){


        if(sobokanArray[pos_x][pos_y]=='@'){  //if there is no move oppurtunity does not change anything
            sobokanArray[pos_x][pos_y]='@';}
        else if(sobokanArray[pos_x][pos_y]=='+'){
            sobokanArray[pos_x][pos_y]='+';}

       return false;}

       else if(sobokanArray[pos_x][pos_y+2]==' '||sobokanArray[pos_x][pos_y+2]=='.'){
       if(sobokanArray[pos_x][pos_y+2]==' '){ //update the box current location expression
       sobokanArray[pos_x][pos_y+2]='$';
       }
       else if(sobokanArray[pos_x][pos_y+2]=='.'){
       sobokanArray[pos_x][pos_y+2]='*';}

        if(sobokanArray[pos_x][pos_y]=='@'){//update the player previous location expression
            sobokanArray[pos_x][pos_y]=' ';}
        else if(sobokanArray[pos_x][pos_y]=='+'){
            sobokanArray[pos_x][pos_y]='.';}
         if(sobokanArray[pos_x][pos_y+1]=='$'){//update the player current location expression
         sobokanArray[pos_x][pos_y+1]='@';}
         else if(sobokanArray[pos_x][pos_y+1]=='*'){
         sobokanArray[pos_x][pos_y+1]='+';
        }
        pos_y=pos_y+1;
        return true;
     }


}

return false;
  }


char Sobokan::getvalue(int x,int y) const{//to get the specified location from the private array we need public method to get content of the array from outside

return sobokanArray[x][y];
}

void Sobokan::setPos(int x,int y){//to set @ value beacause pos_x and pos_y members are private, we need public method to set theese to reach content of the array from outside
  pos_x=x;
  pos_y=y;
}

bool Sobokan::is_solved() const{ //puzzle is solved method there is no change in the content therefore const is used
        for(int i=0; i<6; i++){
            for(int j=0; j<8; j++){
                if( sobokanArray[i][j]=='$'){
                return false;
                // when the puzzle is solved all of the boxes at the target location therefore there is no dollar expression in the array
                }

 }
 }


return true;//if there is no dollar sign return true

 }

void Sobokan::print_puzzle()const{//prints the text-based representation of the current state of the puzzle there is no change in the content therefore const is used

for(int i=0; i<6; i++){
            for(int j=0; j<8; j++){ // column and row is the private member they are can be arranged in the class
                cout<<sobokanArray[i][j];
 }

 }
 cout<<' '<<endl;
  cout<<' '<<endl;
}


template<class T>
class StackQueue{
private:
T StackQueueList[maxSize];
int Front;
int Rear;
int Count;// it is used to identify array empty or full
public:
StackQueue();//to initialize data parameters
void pushFront(const T &value); //store a new element at the front of the storage
T  popFront();          // removes and returns the element at the front of the storage
T  popRear();           // removes and returns the element at the rear of the storage
T FrontMember() const; //it returns the current front value
int isEmpty() const;   //it returns 1 if stackqueuelist is empty
int isFull()  const;   //it returns 1 if stackqueuelist is full
int lengthList() const; //gives length of the stackqueuelist
};

template<class T>
StackQueue<T>::StackQueue():Front(0),Rear(0),Count(0){ //initialize the private members
}
template<class T>
int StackQueue<T>::isFull() const{// template decleration of isFull method outside the class

return (Count==maxSize);

}

template<class T>
int StackQueue<T>::isEmpty() const{// template decleration of isEmpty method outside the class

return (Count==0);

}

template<class T>
int StackQueue<T>::lengthList() const{// template decleration of legthList method outside the class

return Count;

}

template<class T>
void StackQueue<T>::pushFront(const T &value){ //store a new element at the front of the storage

if(isFull()){                                  //if the maxSize==count, no more value cannot be stored
cerr<<"over flow"<<endl;
exit(1);
}
Count++;                                     //each push count increase that means lenght of the array increase
if(Front==0){                         //if front goes to negative, segmentation fault occur therefore to avoid them add maxSize
Front=Front+maxSize;}
StackQueueList[Front-1]=value;        //store the value the front
Front=(Front-1)%maxSize;               //normalize the last front index with maxSize


}
template<class T>
T StackQueue<T>::popFront(){         // removes and returns the element at the front of the storage

T temp;
if(isEmpty()){
cerr<<"empty !!!"<<endl;
exit(1);
}
Count--;                  //each pop count decrease that means lenght of the array decrease
temp=StackQueueList[Front];
Front=(Front+1)%maxSize;   //front index increase
return temp;              // return the temp which holds the previous Front value

}
template<class T>
T StackQueue<T>::popRear(){         // removes and returns the element at the rear of the storage
T temp;//it is flag variable
if(isEmpty()){
cerr<<"empty !!!"<<endl;
exit(1);
}
if(Rear==0){            //if rear goes to negative, segmentation fault occur therefore to avoid them, i add maxSize to the Rear
Rear=Rear+maxSize;}
Count--;
temp=StackQueueList[Rear-1]; //each rear pop operation decrease the rear index, last rear value storen at the temp
Rear=(Rear-1)%maxSize;  //rear index dercrease after the pop operation
return temp;

}
template<class T>
T  StackQueue<T>::FrontMember() const{ //it returns the current front value

return StackQueueList[Front];
}



int main(){
char button;
Sobokan SobokanGame;
Sobokan A;// lets define other object to assign value
StackQueue<Sobokan> lastmovement; //create object
while(SobokanGame.is_solved()!=1){
cout<<"enter the button "<<endl;
cin>>button;//take input from the user
switch(button){
/*w, a, s, d keys should move the player to up, left, down and right, respectively. If the move
is valid, the puzzle state is stored in the stack-queue, and printed to the console*/
case 'w':
if(SobokanGame.move_up()){
       lastmovement.pushFront(SobokanGame);
SobokanGame.print_puzzle();

}
break;

case 'a':
        if(SobokanGame.move_left()){ //if available then move occur, it pushed to teh stack

        lastmovement.pushFront(SobokanGame);
        SobokanGame.print_puzzle();//after pushing call the print_puzzle

        }

break;

case 's':
        if(SobokanGame.move_down()){ //if available then move occur, it pushed to teh stack
     lastmovement.pushFront(SobokanGame);
        SobokanGame.print_puzzle();//after pushing call the print_puzzle
}
break;

case 'd':
       if(SobokanGame.move_right()){ //if available then move occur, it pushed to teh stack
        lastmovement.pushFront(SobokanGame);
         SobokanGame.print_puzzle();//after pushing call the print_puzzle
break;
}

//z key undoes the last valid move. The last puzzle state is also removed from the queue-stack.
case 'z':

       lastmovement.popFront(); //to reach previous state, do free pop from the front
       //A object is used as a flag
       A=lastmovement.popFront();//aasing lastmovement to the object A
       SobokanGame=A;//assign the A back to the Sobokangame to undo operation
       SobokanGame.print_puzzle();//print after the undo


break;

//replays all the moves starting from the initial state. All puzzle states are to be printed to the console in order
case 'r':
    int k= lastmovement.lengthList();// takes the length of the stacklist
    for(int i=0;i<k;i++){
    A=lastmovement.popRear(); //after using assing operator print from the first one thanks to teh popRear method
//All puzzle states are to be printed to the console in order
    A.print_puzzle();

    }


break;


}}

return 0;

}

