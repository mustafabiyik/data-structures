#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<ctime>
using namespace std;


//global variable decleration to keep movement number for each sorting algorithm
int movNumSel=0;
int movNumBub=0;
int movNumQ1=0;
int movNumQ2=0;
int movNumQ3=0;
int movNumQ4=0;
int movNumOWN=0;
const int cutoff=5;//change the cutoff which specifies the MustafaBiyikSort algorithm elements
//when number of elements in the array lower than 5 it is sorted with bubble sort otherwise it is sorted with the quick sort


template <class T>
void SwapSEL (T &k, T &m){// by reference!
T temp; // temp variable for swap
temp = k;
k = m;
m = temp;
movNumSel++;//to count movement for each swap operation for selection sort
}
//SELECTION SORT OF n ELEMENTS
template <class T>
void SelectionSort(T A[], int n){ // pass array variable!
int i, j,minIndex; // index of smallest item in each pass

for (i = 0; i < n-1; i++){ // start the scan at index i; set minIndex to i
minIndex = i;
// j scans the sublist A[i+1]...A[n-1]
        for (j = i+1; j < n; j++){
        // update minIndex if smaller element is found
                if (A[j] < A[minIndex]){
                minIndex = j;
                }
        }//smallest

SwapSEL(A[i], A[minIndex]);
}
}

template <class T>
void SwapBUB (T &k, T &m){// by reference!
T temp; // temp variable for swap
temp = k;
k = m;
m = temp;
movNumBub++;//to count movement for each swap operation for bubble sort
}

//Buble sort algorithm
// BubbleSort is passed an array A and list count n
template <class T>
void BubbleSort(T A[], int n){
int i, j,lastExchangeIndex; // Index of last exchange
i = n-1; // i is the index of last element in the sublist
while (i > 0){ //when LCI==0 then process finishes
        lastExchangeIndex = 0; // start lastExchangeIndex at 0
        for (j = 0; j < i; j++){
                if (A[j+1] < A[j]){ // exchange a pair and update lastExchangeIndex
                        SwapBUB(A[j],A[j+1]);
                        lastExchangeIndex = j;
                }
        }//end for
        i = lastExchangeIndex; // set i to index of the last exchange

}//end while
}


template <class T>
void SwapQ1 (T &k, T &m){// by reference!
T temp; // temp variable for swap
temp = k;
k = m;
m = temp;
movNumQ1++;
}

template <class T>
void QuickSort_1(T *A, int low, int high){
T pivot;
    if (low < high) {
        int ScanUp = low + 1; // Initialize ScanUp
        int ScanDown = high; // Initialize ScanDown
        pivot = A[low]; // Set pivot
while (true){
    while (A[ScanUp] <= pivot){
    ScanUp++; }// Increment ScanUp until pivot
    while (A[ScanDown] > pivot){
    ScanDown--; }// Decrement ScanDown until pivot

    if(ScanUp < ScanDown){
    // swap A[ScanDown] and A[ScanUp]
    SwapQ1(A[ScanDown],A[ScanUp]);}
    else{
    break;
    }
    }//end of while (true)

SwapQ1(A[ScanDown],A[low]);

//Recursive calls
QuickSort_1(A,low,ScanDown-1);
QuickSort_1(A, ScanDown+1,high);
}//end of if low < high
}

template <class T>
void SwapQ2 (T &k, T &m){// by reference!
T temp; // temp variable for swap
temp = k;
k = m;
m = temp;
movNumQ2++;
}

template<class T>//middle element is the pivot/////
void QuickSort_2(T *arr, int low, int high)
{
    int i = low;//is is the Scan up
    int j = high;//is scan down
    int middle=(i+j)/2;
    int pivot = arr[middle];
    int temp;

    while (i <= j)
    {
        while (arr[i] < pivot){
            i++;}
        while (arr[j] > pivot){ //j is looking for the values smaller than pivot if find then go out the while
            j--;}
        if (i <= j)
        {
            SwapQ2(arr[i],arr[j]);
            i++;
            j--;
        }
   }

    if (j > low){
        QuickSort_2(arr, low, j);}
    if (i < high){
        QuickSort_2(arr, i, high);}
}


template <class T>
void SwapQ3 (T &k, T &m){// by reference!
T temp; // temp variable for swap
temp = k;
k = m;
m = temp;
movNumQ3++;
}


template<class T>
int RandomPivotPartition(T arr[], int low, int high)
{
    // Generate a randomValue number in between
    int randomValue = (rand() % (high - low))+low;

    // Swap arr[randomValue] with arr[high]
    SwapQ3(arr[randomValue], arr[low]);
    T pivot = arr[low];
    int i = low - 1;//scan up pointer
    int j = high + 1;//scan down pointer

    while (1) {

        do {//scan up find the value larger then pivot
            i++;
        } while (arr[i] < pivot);


        do {//scan down find value smaller then pivot
            j--;
        } while (arr[j] > pivot);

        if (i >= j){//j shows as the partitioning index
            return j;}

        SwapQ3(arr[i], arr[j]);
    }
}



  template<class T>
void QuickSort_3(T arr[], int low, int high)
{
    if (low < high) {
        int partition_index = RandomPivotPartition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        QuickSort_3(arr, low, partition_index);
        QuickSort_3(arr, partition_index + 1, high);
    }
}




template <class T>
void SwapQ4 (T &k, T &m){// by reference!
T temp; // temp variable for swap
temp = k;
k = m;
m = temp;
movNumQ4++;
}

template<class T>
int MedianPivotPartition(T arr[], int low, int high)
{
    // generate three random vlue then take median
    if((high-low)>=3){
            int random1=(rand() % (high - low))+low;
            int random2=(rand() % (high - low))+low;
            int random3=(rand() % (high - low))+low;
            if((random1<=random3 && random1>=random2)||(random1<=random2 && random1>=random3)){

                    SwapQ4(arr[random1], arr[low]);
            }
            else if((random2<=random3 && random2>=random1)||(random3<=random2 && random1>=random2)){

                    SwapQ4(arr[random2], arr[low]);
            }
            else if((random3<=random1 && random3>=random2)||(random1<=random3 && random2>=random3)){

                    SwapQ4(arr[random3], arr[low]);
            }

    }
     else if((high-low)==2){//median is the average of the two middle number
             int random1=(rand() % (high - low))+low;
             int random2=(rand() % (high - low))+low;
             /*while(random1==random2){
                      int random2=(rand() % (high - low))+low;
             }//now random numbers are different now*/
        int Median=(random1+random2)/2;
         SwapQ4(arr[Median], arr[low]);
     }

     else if((high-low)==1){

     int randomValue = (rand() % (high - low))+low;
    // Swap arr[randomValue] with arr[high]
    SwapQ4(arr[randomValue], arr[low]);

     }


    T pivot = arr[low];
    int i = low - 1;//scan up pointer
    int j = high + 1;//scan down pointer

    while (1) {

        do {//scan up find the value larger then pivot
            i++;
        } while (arr[i] < pivot);


        do {//scan down find value smaller then pivot
            j--;
        } while (arr[j] > pivot);

        if (i >= j){//j shows as the partitioning index
            return j;}

        SwapQ4(arr[i], arr[j]);
    }
}

  //low  starting index
  //high   ending index
  template<class T>
void QuickSort_4(T arr[], int low, int high)
{
    if (low < high) {
        int partition_index = MedianPivotPartition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        QuickSort_4(arr, low, partition_index);
        QuickSort_4(arr, partition_index + 1, high);
    }
}
/*Use quick sort to mostly sort the array, i.e. use quick sort to sort the
array until a defined cutoff size is reached (the array is going to be
mostly sorted). You can use another sorting algorithm on the entire
array to quickly complete the sorting.*/
//in this code I will use combination of the bubble sort and quick sort combinations
//after high-low smaller than 50 then I use bubble sort for
//arrays contain the higher number value than 5000 algorithm use
//quick sort


template <class T>
void SwapOWN (T &k, T &m){// by reference!
T temp; // temp variable for swap
temp = k;
k = m;
m = temp;
movNumOWN++;
}

template <class T>
void MustafaBiyikSort(T *A, int low, int high){
T pivot;
int n_val=high-low;
n_val=n_val+1;//value of the number of elements
    if (low < high) {

        if(n_val>=cutoff){//quick sort implementation
         int ScanUp = low + 1; // Initialize ScanUp
        int ScanDown = high; // Initialize ScanDown
        pivot = A[low]; // Set pivot
    while (true){
            while (A[ScanUp] <= pivot){
                    ScanUp++; }// Increment ScanUp until pivot

            while (A[ScanDown] > pivot){
                    ScanDown--; }// Decrement ScanDown until pivot

                    if(ScanUp < ScanDown){
                    // swap A[ScanDown] and A[ScanUp]
                            SwapOWN(A[ScanDown],A[ScanUp]);
                            }
                    else{
                    break;
                    }
    }//end of while (true)

            SwapOWN(A[ScanDown],A[low]);
            //Recursive calls

         MustafaBiyikSort(A,low,ScanDown-1);
          MustafaBiyikSort(A, ScanDown+1,high);



        }

        else if(n_val<cutoff){

                    //bubble sort part of the algorithm
        int y, x,lastExchangeIndex; // Index of last exchange
        y = high; // y is the index of last element in the sublist
        while (y > low){ //when LCI==0 then process finishes
        lastExchangeIndex = low; // start lastExchangeIndex at 0
        for (x = low; x < high; x++){
                if (A[x+1] < A[x]){ // exchange a pair and update lastExchangeIndex
                        SwapOWN(A[x],A[x+1]);
                        lastExchangeIndex = x;
                }
        }//end for
        y = lastExchangeIndex; // set y to index of the last exchange

}//end while
        }





}//end of if low < high
}

// to print an array
template<class T>
void printarr(T *arr, int N)
{
    for (int i = 0; i < N; ++i){
      cout << arr[i]<<"  --  ";}
cout<<" "<<endl;
}



int main(){
    int N;///size
    int operation;
    int *array;
    int Size;
    double elapsed_time_bubble=0;
    double elapsed_time_Select=0;
    double elapsed_time_Q_1=0;
    double elapsed_time_Q_2=0;
    double elapsed_time_Q_3=0;
    double elapsed_time_Q_4=0;
    double elapsed_time_own=0;

    while (true)
    {

        cout<<"Operations about Sorting"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"1. Initialize input array randomly"<<endl;
        cout<<"2. Load input array from a file"<<endl;
        cout<<"3. Perform Bubble Sort"<<endl;
        cout<<"4. Perform Quick Sort"<<endl;
        cout<<"5. Perform Selection Sort"<<endl;
        cout<<"6. Perform Your Own Sort"<<endl;
        cout<<"7. Compare sorting algorithms"<<endl;
        cout<<"8. for 5 random arrays print  average number of comparisons, number of data moves and elapsed time"<<endl;
        cout<<"Enter operation number: ";
        cin>>operation;


        if(operation==1){//initialite with N the array

        cout<<"Enter N value to initialization: ";
        cin>>N;

          array = new int [N];
        for (int i=0; i < N; i++){//initializes the array with random numbers
         array[i] = rand()%(10*N);}//initialize array with random numbers

        }
        ///////////////////
        else if(operation==2){//load number from the file
        string line;
        ifstream myfile ("input_array.txt");
        if (myfile.is_open())
        {
        int i=0;
        while ( getline (myfile,line)&&i<N)//get line from the file
        {//line is the string
        stringstream converter(line);
        int x = 0;
        converter >> x;

        //load array with the file
         array[i] = x;


        i++;
        }
        myfile.close();
        }

        else cout << "Unable to open file";

        }
         ///////////////////////
        else if(operation==3){//bubble sort on the array
          double start = double(clock());
          BubbleSort(array,N);
          double finish = double(clock());
           elapsed_time_bubble = finish - start;

            printarr(array,N);

        }
        else if(operation==4){//quick sort on the array
        char pivot;
         cout<<"Enter how the pivot is selected: "<<endl;
         cout<<"'F':first element as pivot"<<endl;
         cout<<"'D':middle element as pivot"<<endl;
         cout<<"'R':random element as pivot"<<endl;
         cout<<"'M': median of 3 randomly chosen elements"<<endl;
         cin>>pivot;
         if(pivot=='F'){
              double start = double(clock());
              QuickSort_1(array, 0, N-1);
              double finish = double(clock());
               elapsed_time_Q_1 = finish - start;

               printarr(array,N);

         }
         else  if(pivot=='D'){
             double start = double(clock());
              QuickSort_2(array, 0, N-1);
              double finish = double(clock());
               elapsed_time_Q_2 = finish - start;

               printarr(array,N);
         }
           else  if(pivot=='R'){
                double start = double(clock());
              QuickSort_3(array, 0, N-1);
              double finish = double(clock());
               elapsed_time_Q_3 = finish - start;

               printarr(array,N);

         }
           else  if(pivot=='M'){
             double start = double(clock());
              QuickSort_4(array, 0, N-1);
              double finish = double(clock());
               elapsed_time_Q_4 = finish - start;

               printarr(array,N);

         }

        }
        else if(operation==5){//selection sort on the array

              double start = double(clock());
              SelectionSort(array, N);
              double finish = double(clock());
               elapsed_time_Select = finish - start;

               printarr(array,N);




        }
        else if(operation==6){//own sorting algorithm

             double start = double(clock());
              MustafaBiyikSort(array, 0, N-1);
              double finish = double(clock());
              elapsed_time_own = finish - start;

            printarr(array, N);


        }


         else if(operation==7){
        /*Runs all the 7 algorithms and prints out the statistics about
        these algorithms for the same input array. These statistics includes the
        number of data comparisons, the number of data moves, and the time
        required for the sort. */
        //number of data moves can be find ny the swap number
        //number of data comparison can be found by if

          //PRINT THE MEASUREMENTS
              cout<<"--------------------------------------------------------------------------------------------"<<endl;
       cout<<"  Array size: " <<N<<" numbers"<<endl;
       cout<<"  Algorithm   #comparisons  #moves    time (msec)"<<endl;
       cout<<"  Bubble         "<<N*(N-1)/2 <<"       "<<movNumBub<<"     "<<elapsed_time_bubble<<" msec"<<endl;
       cout<<"  Selection      "<<(N-2)*(N-1)/2<<"       "<<movNumSel<<"       "<<elapsed_time_Select <<" msec"<<endl;
       cout<<"  Quick_1        "<<N*(N+1)/2<<"       "<<movNumQ1<<"      "<<elapsed_time_Q_1 <<" msec"<<endl;
       cout<<"  Quick_2        "<<N*(N+1)/2<<"       "<<movNumQ2<<"      "<<elapsed_time_Q_2<<" msec"<<endl;
       cout<<"  Quick_3        "<<N*(N+1)/2<<"       "<<movNumQ3<<"      "<<elapsed_time_Q_3<<" msec"<<endl;
       cout<<"  Quick_4        "<<N*(N+1)/2<<"       "<<movNumQ4<<"      "<<elapsed_time_Q_4<<" msec"<<endl;

       if(Size<cutoff){
       cout<<"  OWN            "<<N*(N-1)/2<<"       "<<movNumOWN<<"      "<<elapsed_time_own<<" msec"<<endl;
       }
       else if(Size>=cutoff){
       cout<<"  OWN            "<<N*(N+1)/2<<"        "<<movNumOWN<<"      "<<elapsed_time_own<<" msec"<<endl;

       }
       cout<<"--------------------------------------------------------------------------------------------"<<endl;

        }

        else if(operation==8){
        cout<<"Enter size value to compare 5 different arrasy for perf. evaluation: ";
        cin>>Size;//100,1000,5000,10000,25000
        //dynamically memory alocation
          /*int *randArray;
          int *randArrayB;
          int *randArrayS;
          int *randArrayQ1;
          int *randArrayQ2;
          int *randArrayQ3;
          int *randArrayQ4;
          int *randArrayOwn;
          randArray = new int [Size];
          randArrayB = new int [Size];
          randArrayS = new int [Size];
          randArrayQ1 = new int [Size];
          randArrayQ2 = new int [Size];
          randArrayQ3 = new int [Size];
          randArrayQ4 = new int [Size];
          randArrayOwn = new int [Size];*/
          int randArray[Size];
          int randArrayB[Size];
          int randArrayS[Size];
          int randArrayQ1[Size];
          int randArrayQ2[Size];
          int randArrayQ3[Size];
          int randArrayQ4[Size];
          int randArrayOwn[Size];



         elapsed_time_bubble=0;
         elapsed_time_Select=0;
         elapsed_time_Q_1=0;
         elapsed_time_Q_2=0;
         elapsed_time_Q_3=0;
         elapsed_time_Q_4=0;
         elapsed_time_own=0;

        for(int i=0;i<5;i++)
        {


            for(int j=0; j<Size; j++){
            randArray[j]=rand()%(10*Size);
            randArrayB[j]= randArray[j];
            randArrayS[j]= randArray[j];
            randArrayQ1[j]= randArray[j];
            randArrayQ2[j]= randArray[j];
            randArrayQ3[j]= randArray[j];
            randArrayQ4[j]= randArray[j];
            randArrayOwn[j]= randArray[j];
            }
            //find total sorting time of the all sorting types
            //randArrays include the same content
            //elapsed time variables contains the total time for 5 arrays
            //i will divide total time by 5
          double start = double(clock());
          BubbleSort(randArrayB,Size);
          double finish = double(clock());
           elapsed_time_bubble = elapsed_time_bubble+(finish - start);

           start = double(clock());
              QuickSort_1(randArrayQ1, 0, Size-1);
               finish = double(clock());
               elapsed_time_Q_1 = elapsed_time_Q_1+(finish - start);

                start = double(clock());
              QuickSort_2(randArrayQ2, 0, Size-1);
               finish = double(clock());
               elapsed_time_Q_2 = elapsed_time_Q_2+(finish - start);

                start = double(clock());
              QuickSort_3(randArrayQ3, 0, Size-1);
               finish = double(clock());
               elapsed_time_Q_3 = elapsed_time_Q_3+(finish - start);

             start = double(clock());
            QuickSort_4(randArrayQ4, 0,Size-1);
             finish = double(clock());
            elapsed_time_Q_4 = elapsed_time_Q_4+(finish - start);

             start = double(clock());
              SelectionSort(randArrayS, Size);
               finish = double(clock());
               elapsed_time_Select = elapsed_time_Select+(finish - start);

                 start = double(clock());
              MustafaBiyikSort(randArrayOwn, 0, Size-1);
               finish = double(clock());
              elapsed_time_own = elapsed_time_own+(finish - start);



            //now calculate fır the arrays movements elapsed time and comparisons
            // collect statistics

        }
      //PRINT THE MEASUREMENTS
       cout<<"--------------------------------------------------------------------------------------------"<<endl;
       cout<<"  Array size: " <<Size<<" numbers"<<endl;
       cout<<"  Algorithm   #comparisons  #moves    time (msec)"<<endl;
       cout<<"  Bubble         "<<Size*(Size-1)/2 <<"       "<<movNumBub/5<<"     "<<elapsed_time_bubble/5<<" msec"<<endl;
       cout<<"  Selection      "<<(Size-2)*(Size-1)/2<<"       "<<movNumSel/5<<"       "<<elapsed_time_Select/5 <<" msec"<<endl;
       cout<<"  Quick_1        "<<Size*(Size+1)/2<<"       "<<movNumQ1/5<<"      "<<elapsed_time_Q_1/5 <<" msec"<<endl;
       cout<<"  Quick_2        "<<Size*(Size+1)/2<<"       "<<movNumQ2/5<<"      "<<elapsed_time_Q_2/5<<" msec"<<endl;
       cout<<"  Quick_3        "<<Size*(Size+1)/2<<"       "<<movNumQ3/5<<"      "<<elapsed_time_Q_3/5<<" msec"<<endl;
       cout<<"  Quick_4        "<<Size*(Size+1)/2<<"       "<<movNumQ4/5<<"      "<<elapsed_time_Q_4/5<<" msec"<<endl;

       if(Size<cutoff){
       cout<<"  OWN            "<<Size*(Size-1)/2<<"       "<<movNumOWN/5<<"      "<<elapsed_time_own/5<<" msec"<<endl;
       }
       else if(Size>=cutoff){
       cout<<"  OWN            "<<Size*(Size+1)/2<<"        "<<movNumOWN/5<<"      "<<elapsed_time_own/5<<" msec"<<endl;

       }
       cout<<"--------------------------------------------------------------------------------------------"<<endl;
       //DELETE TO FREE MEMORY
          /*  delete [] randArray;
            delete [] randArrayB;
            delete [] randArrayQ1;
            delete [] randArrayQ2;
            delete [] randArrayQ3;
            delete [] randArrayQ4;
            delete [] randArrayS;
            delete [] randArrayOwn;*/

        }



        else{

            exit(1);
        }


    }
    return 0;
}





