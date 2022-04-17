#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<fstream>
#include<sstream>
using namespace std;

//Hash node class decleration
class HNode//Hash node class decleration
{
    public:
    long int key;
	HNode* next;
    HNode(long int keyVal)
        {
        key = keyVal;
	    this->next = NULL;
        }
};

//hash table class declerations
class hash_table
{
    private:
        HNode** HTable;//it holds the initial points of the
        int N;//bucket numbers default value
    public:
        hash_table(){}//constructor

        void InitHashTable(int nN){

                N=nN;
                    HTable = new HNode*[nN];
                    for (int i = 0; i < nN; i++)
                        HTable[i] = NULL;


        }
        ~hash_table()//destructor is the method of the hash_table class
        {
                    HNode* hvalue_keeper;
                    for (int i = 0; i < N; ++i)
                {
                        hvalue_keeper = HTable[i];//keep the hash values from 0 to N
                        while (hvalue_keeper != NULL)
                    {
                       //clear the all nodes on the hash table
                            HNode* prev_entry = hvalue_keeper;
                            hvalue_keeper = hvalue_keeper->next;
                            delete prev_entry;
                        }
                    }
                    delete[] HTable;//at the there is no node on the Htable destruct the table
        }

    //hash function is the method of the hash_table class
    //F means folding
    //M means middle squaring
    //T means Truncation
    int HashFunc(long int key, char HashFunction,int N){
    long int key_temp=key;
    int digit_number=0;//gives digit number of the key
    while(key_temp!=0){
               digit_number++;
               key_temp=key_temp/10;

    }
   key_temp=key;
   int *digits;//allocate memory for the digits
   digits=new int[digit_number];
    for(int i=0;i<digit_number;i++){
          //first digit 0th array
          //second digit 1st array elements
           digits[i]=key_temp%10;
            key_temp=key_temp/10;
    }

        if(HashFunction=='F'){
            int sum=0;//it holds the sum of the folded values
            int temp_digit_number=digit_number;//it keeps the digit number
            //folding operation according to the digit_number
            while(temp_digit_number!=0){
                if((temp_digit_number-3)>0){
                    sum=sum+digits[temp_digit_number-1]*100+digits[temp_digit_number-2]*10+digits[temp_digit_number-3];
                temp_digit_number=temp_digit_number-3;
                }
                else if((temp_digit_number-3)==0){
                    sum=sum+digits[temp_digit_number-1]*100+digits[temp_digit_number-2]*10+digits[temp_digit_number-3];
                    temp_digit_number=temp_digit_number-3;
                }

                  else if((temp_digit_number-2)==0){
                    sum=sum+digits[temp_digit_number-1]*10+digits[temp_digit_number-2];
                    temp_digit_number=temp_digit_number-2;
                }

                  else if((temp_digit_number-1)==0){
                    sum=sum+digits[temp_digit_number-1];
                    temp_digit_number=temp_digit_number-1;
                }

            }
            delete [] digits;
            return sum%N;


        }//end Folding if

        else if(HashFunction=='M'){
             int sum=0;
             int middle=digit_number/2;
             sum=digits[middle-1]+digits[middle]*10+digits[middle+1]*100;
             sum=sum*sum;//squre value
             sum=sum%N;//mod N of the squre value
            delete [] digits;
             return sum;

        }//end middle square

        else if(HashFunction=='T'){
           delete [] digits;

            return key%N;//mod N of the key

        }//end truncation if

 }

        //insert TC id is the method of the hash_table class
        void InsertKey(long int key,char HashFunction,int N)
        {
            int hashVal = HashFunc(key,HashFunction,N);//change hash function//////////////////
            HNode* prev = NULL;
            HNode* entry;
            entry=HTable[hashVal];
            while (entry != NULL)
            {
                prev = entry;//prev keeps the previous entry value
                entry = entry->next;
            }//when entry goes at the end of the linked list it goes out of while
           //now entry==NULL
                entry = new HNode(key);//assign entry to the key value
                if (prev == NULL)//there is no element in the specified hashVal
	        {
                    HTable[hashVal] = entry;
                }
	        else
	        {
                    prev->next = entry;
                }


        }
         //remove tc id is the method of the hash_table class
        void RemoveKey(long int key,char HashFunction,int N)
        {
            int hashVal = HashFunc(key,HashFunction,N);
            HNode* entry;
            entry = HTable[hashVal];
            HNode* prev = NULL;
            if (entry == NULL || entry->key != key)
            {
            	cerr<<"there is no node !!!"<<key<<endl;
                return;
            }
            while (entry->next!= NULL)
	    {
                prev = entry;
                entry = entry->next;
            }
            if (prev != NULL)//prev->entry->next delete entry to remove
            {
                prev->next = entry->next;
            }
            delete entry;//delete the entry from the linked list
            cout<<"Hnode Deleted"<<endl;
        }
        //search TC ID is the method of the hash_table class
        int SearchKey(long int key,char HashFunction,int N)//if specified key exist it returns 1 otherwise 0
        {
            int hashVal = HashFunc(key,HashFunction,N);//it returns the key value according to the specified hash function
            HNode* entry;
            entry= HTable[hashVal];
            while (entry != NULL)
	    {
                if (entry->key == key)
	        {
                cout<<"specified key exists"<<endl;
                   return 1;
                }
                entry = entry->next;
            }
            cout<<"specified key does not exist"<<endl;
            return 0;//no key found
        }

        //print hash table is the method of the hash_table class
        void printHashTable()
        {
            int i;
            for (i = 0; i < N; ++i)
            {
                HNode* entry = HTable[i];
                cout<<"\n TC ID number according to N value: "<<i<<"\n N: "<<i;
                while (entry!=NULL)
                {
                    cout<<"-> "<<entry->key;
                    entry = entry->next;
                }
                cout<<endl;
            }
        }
            int collisionMeter(){//it shows us the collision number during the loading of the IDs for each trial
                    //i record the collision numbers
                   //null entries implies there is no id and they are empty
                    //loaded_id_number-(N_value-null_entries)=collisions
                    //loaded_id=200 in our case
                    int null_entries=0;
                    int i;
                    for (i = 0; i < N; ++i)
                    {
                        HNode* entry = HTable[i];

                        if (entry==NULL){
                        null_entries=null_entries+1;
                        }


                    }
                    int collisions=N-null_entries;
                    collisions=200-collisions;
                    return  collisions;
                }
};
//main function
/*
Performance Evaluation
hash table is initialized with size of 100
200 T.C. IDs have been generated randomly
these numbers aded one by one
Results are following;
1) For loading factor of the each hash functions are equal
because N=100 and we load 200 ID for three cases then loadinf factor
equal to 2 for three of them.
2) Folding hash function 115 collisions
   Truncation hash function 113 collisions
   Middle squaring hash function 178 collisions
3) between three of them collision number highest at the Middle squaring hash function
it is expected because we take the square this increase the collision probability

*/
int main()
{
    int N;///////////look at that dada
    hash_table hashObject;
    long int key;
    int operation;
    char HashFunction;//specify the hash function type
    while (true)
    {

        cout<<"Operations on Hash Table"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"1. Initialize Hash Table"<<endl;
        cout<<"2. Load T.C. ID Numbers from file"<<endl;
        cout<<"3. Add new T.C. ID Number"<<endl;
        cout<<"4. Delete a T.C. ID Number"<<endl;
        cout<<"5. Search for a T.C. ID Number"<<endl;
        cout<<"6. Print out Hash Table"<<endl;
        cout<<"7. Print out Collision number"<<endl;
        cout<<"Enter operation number: ";
        cin>>operation;


        if(operation==1){//initialite with N and hash function
            //ask N and hash function
        cout<<"Enter N value to initialization: ";
        cin>>N;
        cout<<"Enter character to specify hash function \n'F for folding'\n'M for middle squaring'\n'T for truncation' : ";
        cin>>HashFunction;
        hashObject.InitHashTable(N);



        }
        else if(operation==2){//load TC ID from the file
        string line;
        long int TC_string[200];
        ifstream myfile ("hash_table_init200.txt");
        if (myfile.is_open())
        {
        int i=0;
        while ( getline (myfile,line) )
        {//line is the string
        stringstream converter(line);
        long int x = 0;
        converter >> x;

        TC_string[i]=x;
        //(long int key,char HashFunction,int N)
        hashObject.InsertKey(x,HashFunction,N);//load tc ID number into the hash table
        //cout << TC_string[i] <<endl;

        i++;
        }
        myfile.close();
        }
        else cout << "Unable to open file";




        }
        else if(operation==3){//insert key

            cout<<"Enter new T.C ID number to be inserted: ";
            cin>>key;
            //(long int key,char HashFunction,int N)
            hashObject.InsertKey(key,HashFunction,N);

        }
        else if(operation==4){//delete key
            cout<<"Enter T.C ID number to be deleted: ";
            cin>>key;
            //(long int key,char HashFunction,int N)
            hashObject.RemoveKey(key,HashFunction,N);

        }
        else if(operation==5){//search key
            cout<<"Enter a T.C. ID Number to be searched: ";
            cin>>key;
            //(long int key,char HashFunction,int N)
            int temp=hashObject.SearchKey(key,HashFunction,N);
            if (temp== 1)
            {
	        cout<<"key: "<<key<<" is found"<<endl;
	        }
            else if(temp==0){

             cout<<"key: "<<key<<" is NOT found!!"<<endl;
            }

        }
        else if(operation==6){//print hash table on the command window
        hashObject.printHashTable();

        }
         else if(operation==7){//print hash table on the command window
        cout<<HashFunction<<"-->"<<hashObject.collisionMeter()<<endl;
        }
        else{

            exit(1);
        }


    }
    return 0;
}

