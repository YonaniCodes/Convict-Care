#include<iostream>
#include<string.h>
#include<fstream>
#include<math.h>
/*
    Group Members           ID
Amha Friew             BDU1405455
Arsema Degu           BDU1405454
Biruk Temesgen       BDU1405453
Tsion Bantegize       BDU1405438
Yonas Awoke           BDU1405437
Rodas Enyew           BDU1411071
*/
using namespace std;
int yonasFunctionI(char x[],char z[]);
int long countAllPrisoner();
//unsigned int numberOfprisoners; //holds the number of prisoners to be entered once

short int navigator;


struct Prisoner {

char ID[12];
char name[25];
char gender[6];
int age;  // data field
char committedCrime[30];
char dateOfRelease[12];
char  lengthOfSentence[10];

Prisoner *next;
                                 // pointer field
Prisoner *prev;


};
Prisoner *starNode=NULL;
Prisoner *endNode=NULL;

bool checkIdExists(char id[]) {
    Prisoner* temp = starNode;
    while (temp != NULL) {
        if (strcmp(temp->ID,id)==0) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void addPrisonerFromNotePad()
{
  char txtFile[20];
  cout<<"enter the file name you want to insert from and use the APROPRIATE .txt and  FORMAT: ";
  cin>>txtFile;
    ifstream file(txtFile);
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }

    Prisoner* newNode=new Prisoner;
    while ( file >>newNode->ID>> newNode->name >>newNode->gender  >>newNode->age>>newNode->committedCrime>> newNode->dateOfRelease
		   >>newNode->lengthOfSentence) {
        newNode->next = starNode;
        newNode->prev = NULL;
        if (starNode != NULL) {
            starNode->prev = newNode;
        }
        else {
            endNode = newNode;
        }
        starNode = newNode;
        newNode = new Prisoner;
    }

    file.close();
    cout << "Nodes inserted at the beginning of the linked list from the file" << endl;
}
void addPrisonerAtTheBeginning()
{//creating new node
    Prisoner* newNode = new Prisoner;
            cout << "Enter ID: ";

             int county= countAllPrisoner();
               for (int i = 0; i <= county; i++) {
                    cin >> newNode->ID;
        if (checkIdExists(newNode->ID)) {
            cout << "Error: ID " << newNode->ID << " already exists in list." << endl;
            return;
        }
    }
            cout << "Enter name: ";
            cin >> newNode->name;
            cout << "Enter gender: ";
            cin >> newNode->gender;
             do{
    cout << "Enter correct age from 18 above: ";

    cin >> newNode->age;}
    while(newNode->age<18||newNode->age>130);


            cout << "Enter committed crime: ";
            cin >> newNode->committedCrime;
              cout << "Enter the date of release in DD-MM-YYYY format: ";
            cin >> newNode->dateOfRelease;
            cout << "Enter length of sentence: ";
            cin >> newNode->lengthOfSentence;

            newNode->prev = NULL;
            newNode->next = starNode;
            if (starNode != NULL) {
                starNode->prev = newNode;
            }
            starNode = newNode;




}
void addPrisonerAtTheMiddle(){
    Prisoner* prevNode= new Prisoner;



    // Create a new node
    Prisoner* newNode = new Prisoner;
    cout << "Enter ID: ";
    cin >> newNode->ID;//check id is being doubled
     int county= countAllPrisoner();

    for (int i = 0; i <= county; i++) {
        if (checkIdExists(newNode->ID)) {
           cout << "Error: ID " << newNode->ID << " already exists in list." << endl;
            return;
       }
    }
    cout << "Enter name: ";
    cin >> newNode->name;
    cout << "Enter gender: ";
    cin >> newNode->gender;
     do{
    cout << "Enter correct age starting from 18: ";

    cin >> newNode->age;}
    while(newNode->age<18||newNode->age>130);


    cout << "Enter committed crime: ";
    cin >> newNode->committedCrime;
   cout << "Enter the date of release in DD-MM-YYYY format: ";
    cin >> newNode->dateOfRelease;
    cout << "Enter length of sentence: ";
    cin >> newNode->lengthOfSentence;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(starNode==NULL)
    {
        starNode=newNode;
        endNode=newNode;
    }
    else{
    char key[20];//declaring a key for where to be inserted
    cout<<"enter a name to insert after: "<<endl;
    cin>>key;
    int p=0;
    Prisoner *i=starNode;
    while(i!=NULL){

        if(stricmp(i->name,key)==0){
            newNode->next=i->next;
            newNode->prev=i;
            i->next=newNode;
            p=1;
            break;
            }
        else i=i->next;

    }
    if(p==0){
        cout<<key<<" no such name exists"<<endl;

    }
    else if(p==1)
        cout<<"node has been inserted"<<endl;
    else{
        cout<<"error has occured please retry"<<endl;
        return;
    }


}
}








void addPrisonerAtTheEnd(){

// new node creation


        Prisoner *newNode = new Prisoner;
        cout << "Enter the ID: ";
        cin >> newNode->ID;
// check id for duplicate

         int county= countAllPrisoner();
               for (int i = 0; i <= county; i++) {
        if (checkIdExists(newNode->ID)) {
            cout << "Error: ID " << newNode->ID << " already exists in list." << endl;
            return;
        }
    }
        cout << "Enter the name: ";
        cin >>newNode->name;
        cout << "Enter the gender: ";
        cin >> newNode->gender;
         do{
    cout << "Enter correct age above 18: ";

    cin >> newNode->age;}
    while(newNode->age<18||newNode->age>130);


        cout << "Enter the committed crime: ";
        cin >> newNode->committedCrime;
        cout << "Enter the date of release in DD-MM-YYYY format: ";
        cin >> newNode->dateOfRelease;
        cout << "Enter the length of sentence: ";
        cin >> newNode->lengthOfSentence;

    newNode->prev=NULL;
    newNode->next = NULL;
    if (starNode== NULL) {
        starNode= endNode = newNode;
        newNode->prev = NULL;
    }
    else {
        endNode->next = newNode;
        newNode->prev = endNode;
        endNode= newNode;
	    }
	}




void deleteAtTheEnd(){
//check if start is null and perform operations
    if (starNode == NULL) {
        cout << "List is empty" << endl;
        //chek if start next is null
    } else if (starNode->next == NULL) {
        delete starNode;
        starNode= NULL;
    } else {
        Prisoner* temp = starNode;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }
}
void deleteAll(){
    if(starNode==NULL)
        cout<<"list is empty";
    else{
    string choice;
    cout<<"are you sure?";
    cin>>choice;
    if(choice=="yes"|| choice=="Yes")
    {
    starNode=NULL;
    endNode=NULL;
    }
    else
        return;
}}
void deleteAtTheBeginning(){
//check if start is null
	 if (starNode == NULL) {
        cout << "List is empty" << endl;
        // check if start next is null
    } else if (starNode->next == NULL) {
        delete starNode;
        starNode= NULL;
    } else {
        Prisoner * temp = starNode;
        starNode = starNode->next;
        starNode->prev = NULL;
        delete temp;
    }
}
 void deleteByName()
{


    //check if start is null
    if (starNode == NULL) {
        cout << "List is empty" << endl;
    }
     else {
             char nameToDelete[25];
    cout << "Enter name of node to delete: ";
    cin >> nameToDelete;
        Prisoner* temp = starNode;
        while (temp != NULL) {
            if (strcmp(temp->name, nameToDelete) == 0) {

                if (temp == starNode) {//incase name is the 1st element
                    starNode= temp->next;
                    if (starNode != NULL) {//making sure that the start maintains its rule
                        starNode->prev = NULL;
                    }
                } else if (temp->next == NULL) {
                    temp->prev->next = NULL;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
                cout << "Node with name " << nameToDelete << " deleted" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Node with name " << nameToDelete << " not found" << endl;
    }
}
void deleteByAge()
{

    if (starNode == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    else{
            short age;
    cout << "Enter age of node to delete: ";
    cin >> age;
    Prisoner* temp = starNode;
    while (temp != NULL) {
        if (temp->age == age) {
            if (temp == starNode) {// if it is on start
                starNode = temp->next;
                starNode->prev = NULL;
                delete temp;
                return;// if this is the case then return back to main
            }

            temp->prev->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            delete temp;
            return;
        }
        temp = temp->next;
    }

    cout << "No node found with age " << age << "." << endl;

}}
void deleteByGender()
{

    if (starNode == NULL) {
        cout << "List is empty." << endl;
        return;// if so then go back
    }
    else{
            char gender[6];
    cout << "Enter gender of node to delete: ";
    cin >> gender;
    Prisoner* temp = starNode;
    while (temp != NULL) {
        if (strcmp(temp->gender, gender) == 0) {
            if (temp == starNode) {//if it is on start
                starNode = temp->next;
                starNode->prev = NULL;
                delete temp;
                return;
            }

            temp->prev->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            delete temp;
            return;
        }
        temp = temp->next;
    }

    cout << "No node found with gender " << gender << "." << endl;

}}
void deleteByID()
{

    if (starNode == NULL) {
        cout << "List is empty \n";
    } else {
        char ID[12];
    cout << "Enter the ID of the node to be deleted: ";
    cin >> ID;
        Prisoner* temp = starNode;
        while (temp != NULL && strcmp(temp->ID, ID) != 0) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Node not found with ID: " << ID << "\n";
        } else {//since we want all to be checked we used if all the way
            if (temp == starNode) {
                starNode = temp->next;
            }
            if (temp->prev != NULL) {//if the previous of current node is not null
                temp->prev->next = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            delete temp;
            cout << "Node deleted with ID: " << ID << "\n";
        }
    }

}
void deleteByDateOfRelease()
{
    if(starNode==NULL){
        cout << "List is empty \n";
    } else {

  char dateOfRelease[12];
    cout << "Enter the date of release to delete a node: ";
    cin >> dateOfRelease;
    Prisoner* currNode = starNode;
    while (currNode != NULL) {// checking if cuurent node is not null
        if (strcmp(currNode->dateOfRelease, dateOfRelease) == 0) {
            if (currNode == starNode) {
                starNode= currNode->next;
                if (starNode != NULL) {
                    starNode->prev = NULL;
                }
            } else {// perform these operations if the above if codes are ignored
                currNode->prev->next = currNode->next;
                if (currNode->next != NULL) {
                    currNode->next->prev = currNode->prev;
                }
            }
            delete currNode;
            return;
        }
        currNode = currNode->next;
    }
    }
}
void deleteByLengthOfSentence()
{
    if (starNode== NULL) {
        cout << "List is empty" << endl;
        return;
    }
    else{
            //requiring to enter length of sentence to be deleted
 char lengthOfSentence[10];
       cout<<"enter length of sentence"<<endl;
       cin>>lengthOfSentence;
    Prisoner* temp = starNode;
    while (temp != NULL) {
        if (strcmp(temp->lengthOfSentence, lengthOfSentence) == 0) {
            if (temp == starNode) {
                starNode = temp->next;
                if (starNode != NULL) {
                    starNode->prev = NULL;
                }
            }
            else {
                temp->prev->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }
            }
            delete temp;
            cout << "Node with length of sentence "<< lengthOfSentence << "deleted successfully" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Node with length of sentence "<< lengthOfSentence << "not found" << endl;


}}
void deleteByCommittedCrime()
{
    if (starNode == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    else{
            //requesting to enter crime to be deleted
       char committedCrime[12] ;
        cout<<"enter crime to be deleted"<<endl;
        cin>>committedCrime;
    Prisoner* temp = starNode;
    while (temp != NULL) {
        if (strcmp(temp->committedCrime, committedCrime) == 0) {
            if (temp == starNode) {
                starNode = temp->next;
                if (starNode != NULL) {
                    starNode->prev = NULL;
                }
            }
            else {
                temp->prev->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }
            }
            delete temp;
            cout << "Node with committed crime "" << committedCrime << "" deleted successfully" << endl;
            return;//if condition is met return to main
        }
        temp = temp->next;
    }
    cout << "Node with committed crime "" << committedCrime << "" not found" << endl;

    }
}
void deleteByMaxAge()
{

if(starNode==NULL){
    cout<<"list is empty"<<endl;
}
else
{
    Prisoner *x=NULL;
    Prisoner *i=starNode;
    float m=0;
    while(i!=NULL){
        if (i->age>m){
            m=i->age;
        }
        i=i->next;
    }
    x=starNode;

    Prisoner *temp;
    while(x!=NULL){
        if(x->age==m&&x==starNode){
            temp=x;
            x=x->next;
            starNode=x;
            x->prev=NULL;
            temp->next=NULL;
            delete temp;
        }
        else if(x->age==m&&x==endNode){
            temp=x;
            x=x->prev;
            endNode=x;
            x->next=NULL;
            temp->prev=NULL;
            delete temp;

        }
        else if((x->age==m)&&(x!=starNode||x!=endNode)){
            temp=x;
            x=x->next;
            temp->prev->next=x;
            x->prev=temp->prev;
            temp->prev=NULL;
            temp->next=NULL;
            delete temp;

        }
    }


}}
void deleteByNodeNumber()
{

    // Check if the list is empty
    if (starNode == NULL) {
        cout << "List is empty. No node to delete." << endl;
        return;
    }
    else{

            int position;
    cout<<"enter a position to delete";
    cin>>position;
    Prisoner* current = starNode;

    // If the node to be deleted is the first node
    if (position == 1) {
        starNode = current->next;
        if (starNode != NULL) {
            starNode->prev = NULL;
        }
        delete current;
        cout << "Node at position " << position << " deleted." << endl;
        return;
    }

    // Traverse the list to find the node
    int count = 1;
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }

    // If the node is not found
    if (current == NULL) {
        cout << "Node at position " << position << " not found." << endl;
        return;
    }

    // If the node to be deleted is the last node
    if (current->next == NULL) {
        current->prev->next = NULL;
        delete current;
        cout << "Node at position " << position << " deleted." << endl;
        return;
    }

    // If the node to be deleted is in the middle
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    cout << "Node at position " << position << " deleted." << endl;
}
}

void getAverageAge()
{
 float total = 0;
    float b = 0;
    Prisoner* i = starNode;
    do
    {
        total = (total + (i->age));
        b = b + 1;
        i = i->next;
    } while (i != NULL);
    float Avg_age = (total / b);
    cout << "the average age is   " << Avg_age << endl;
}
void getMaximumAge()
{
Prisoner* curr = starNode;
    int maxage = 0;
    while (curr != NULL)
    {
        if (curr->age > maxage)
        {
            maxage = curr->age;
        }

        curr = curr->next;
    }
    cout << "The maximum age is " << maxage<<endl;
}
void getMinimumAge()
{

    int minage = starNode->age;
    Prisoner* curr = starNode;
    do
    {
        if (curr->age < minage){
          minage = curr->age;
		}
        curr = curr->next;
    }
while (curr != NULL);
cout << "The minimum age is " << minage<<endl;
}
void getMaximuLengthOfSentence()
{          Prisoner* curr = starNode;


	 char maxLengthofSentence[12];
     strcpy(maxLengthofSentence,curr->lengthOfSentence);

    do
    {
        if (strnicmp(curr->lengthOfSentence,"life",4)==0){


          strcpy(maxLengthofSentence,curr->lengthOfSentence);
               break;
		}

        else if(yonasFunctionI(maxLengthofSentence,curr->lengthOfSentence)==-1
        )
                strcpy(maxLengthofSentence,curr->lengthOfSentence);

        curr = curr->next;
    }

    while(curr!=NULL);

     cout<<"The maximum length of sentence is:"<<maxLengthofSentence<<endl<<endl;
}
void getMinimumLengthOfSentence()
 {          Prisoner* curr = starNode;
	 char minLengthofSentence[12];
     strcpy(minLengthofSentence,curr->lengthOfSentence);

    do


    {
          if(yonasFunctionI(minLengthofSentence,curr->lengthOfSentence)==1)
          {
              if (strnicmp(curr->lengthOfSentence,"life",4)==0)
               continue;

             strcpy(minLengthofSentence,curr->lengthOfSentence);

          }


        curr = curr->next;
    }

    while(curr!=NULL);

     cout<<"The minimum length of sentence is:"<<minLengthofSentence<<endl<<endl;
}

void       displaySearchedPrisoner( Prisoner  *temp){
    cout<<endl<<endl<<endl<<"-------------------------------------------------------"<<endl<<endl;
	          cout << "Name: " << temp->name << endl;
		      cout << "ID: " << temp->ID << endl;
		      cout << "Gender: " << temp->gender << endl;
		      cout << "Age: " << temp->age << endl;
		      cout << "Committed Crime: " << temp->committedCrime << endl;
		      cout << "Date of Release: " << temp->dateOfRelease << endl;
		      cout << "Length of Sentence: " << temp->lengthOfSentence << endl;
    cout<<endl<<endl<<endl<<"-------------------------------------------------------"<<endl<<endl;

}
void searchByName() // allows the user to search Prisoner by their name
{
  Prisoner *temp = starNode;
  int counter = 0;
  if (starNode == NULL)
  {
    cout << "There are no registered prisoners." << endl;
  }
  char fname[20];
  cout << "Enter prisoner name to search by name: ";
  cin >> fname;

  while (temp != NULL)
   {
    	if (stricmp(temp->name, fname) == 0)
		{
           displaySearchedPrisoner(temp);

		      counter++;
    	}
    	temp = temp->next;
  	}
  if (counter == 0)
  {
  	cout << "No prisoners found with that name." << endl;
  }
}
void searchByAge() // allows the user to search Prisoner by their Age
{
	 Prisoner *temp=starNode;
	 if (starNode == NULL)
	 {
	 	  cout << "There are no registered prisoners." << endl;
	 }
     int key;
     cout<<"Enter Prisoner age to search by age"<<endl;
     cin>>key;
     int counter=0;

     while(temp!=NULL)
     {
         if(temp->age==key)
         {
             displaySearchedPrisoner(temp);
             counter++;
         }
         temp=temp->next;
     }
     if (counter == 0)
	 {
    	cout << "No prisoners found with that name." << endl;
  	 }
}

void searchByGender() // allows the user to search Prisoner by their Gender
{
	Prisoner *temp=starNode;
	if (starNode == NULL)
	 {
	 	  cout << "There are no registered prisoners." << endl;
	 }
     char key[10];
     cout<<"Enter Prisoner gender to search by gender"<<endl;
     cin>>key;
     int counter=0;

     while(temp!=NULL)
     {
         if (strnicmp(temp->gender, key,1) == 0)
         {
             displaySearchedPrisoner(temp);
             counter++;
         }
         temp=temp->next;
     }
     if (counter == 0)
	 {
   		 cout << "No prisoners found with that name." << endl;
  	 }
}

void searchByLengthOfSentence() // allows the user to search Prisoner by Length of sentence
{
	Prisoner *temp=starNode;
	if (starNode == NULL)
	 {
	 	  cout << "There are no registered prisoners." << endl;
	 }
     char length[30];
     cout<<"Enter Prisoner length of sentence to search"<<endl;
     cin>>length;
     int counter=0;

     while(temp!=NULL)
     {
         if (strnicmp(temp->lengthOfSentence, length,4) == 0)
         {
            displaySearchedPrisoner(temp);
             counter++;
         }
         temp=temp->next;
     }
     if (counter == 0)
	 {
    	cout << "No prisoners found with that name." << endl;
  	 }
}

void searchByDateOfRelease() // allows the user to search Prisoner by their date of release
{
	 Prisoner *temp=starNode;
	 if (starNode == NULL)
	 {
	 	  cout << "There are no registered prisoners." << endl;
	 }
     char date[15];
     cout<<"Enter Prisoner date of release to search"<<endl;
     cin>>date;
     int counter=0;

     while(temp!=NULL)
     {
         if (strcmp(temp->dateOfRelease, date) == 0)
         {
            displaySearchedPrisoner(temp);
             counter++;
         }
         temp=temp->next;
     }
     if (counter == 0)
	 {
    	cout << "No prisoners found with that name." << endl;
  	 }
}

void searchByCommittedCrime() // allows the user to search Prisoner by their committed crime
{
	Prisoner *temp=starNode;
	if (starNode == NULL)
	 {
	 	  cout << "There are no registered prisoners." << endl;
	 }
     char crime[30];
     cout<<"Enter Prisoner committed crime to search"<<endl;
     cin>>crime;
     int counter=0;

     while(temp!=NULL)
     {
         if(stricmp(temp->committedCrime,crime)==0)
         {
            displaySearchedPrisoner(temp);
             counter++;
         }
         temp=temp->next;
     }
     if (counter == 0)
	 {
    	cout << "No prisoners found with that name." << endl;
  	 }
}

void searchByID() // allows the user to search Prisoner by their ID number
{
	 Prisoner *temp=starNode;
	 if (starNode == NULL)
	 {
	 	  cout << "There are no registered prisoners." << endl;
	 }
     char id_no[10];
     cout<<"Enter Prisoner ID number to search"<<endl;
     cin>>id_no;

     while(temp!=NULL)
     {
         if(temp->ID == id_no)
         if(strcmp(temp->ID,id_no)==0)
         {
            displaySearchedPrisoner(temp);
             break; //  no need to check another ID number because it must be unique number for each prisoners//
         }
         temp=temp->next;
     }
}

void forwardDisplay(){
    Prisoner *temp=starNode;
    if(temp==NULL)
    cout<<"No prisoner registered!"<<endl<<endl;
    while(temp!=NULL)

    {    cout<<endl<<endl<<endl<<"-------------------------------------------------------"<<endl<<endl<<endl;
	          cout << "Name: " << temp->name << endl;
		      cout << "ID: " << temp->ID << endl;
		      cout << "Gender: " << temp->gender << endl;
		      cout << "Age: " << temp->age << endl;
		      cout << "Committed Crime: " << temp->committedCrime << endl;
		      cout << "Date of Release: " << temp->dateOfRelease << endl;
		      cout << "Length of Sentence: " << temp->lengthOfSentence << endl;
    cout<<endl<<endl<<endl<<"-------------------------------------------------------"<<endl<<endl<<endl;
        temp=temp->next;
    }

}

void backwardDisplay(){
    Prisoner *temp=endNode;
    while(temp!=NULL)

    {           cout<<endl<<endl<<endl<<"-------------------------------------------------------"<<endl<<endl<<endl;
	          cout << "Name: " << temp->name << endl;
		      cout << "ID: " << temp->ID << endl;
		      cout << "Gender: " << temp->gender << endl;
		      cout << "Age: " << temp->age << endl;
		      cout << "Committed Crime: " << temp->committedCrime << endl;
		      cout << "Date of Release: " << temp->dateOfRelease << endl;
		      cout << "Length of Sentence: " << temp->lengthOfSentence << endl;
              cout<<endl<<endl<<endl<<"-------------------------------------------------------"<<endl<<endl<<endl;
        temp=temp->prev;
    }

}

void writeOnNotePad()
{
    if(starNode==NULL)
        cout<<"nouthing to write"<<endl;
    else{

    // Open a notepad file for writing
    ofstream file("data.txt");

    if (file.is_open()){


        // Write each prisoner's information to the file
        Prisoner* current = starNode;
        while (current != NULL) {
            file << current->name <<endl
                 << current->ID<<endl
				   << current->gender <<endl
				   << current->age
			<<endl
			<< current->committedCrime<<endl
			<<current->dateOfRelease<<endl
			<<current->lengthOfSentence << endl;
            current = current->next;
        }

        file.close(); // Close the file
        cout << "Successfully wrote to file." << endl;
    }
    else {
        cout << "Unable to open file." << endl;
    }
}}

int long countAllPrisoner(){
  Prisoner *temp=starNode;
   long int prisonerCounter=0;
      while(temp!=NULL)

    {      prisonerCounter++;
        temp=temp->next;
    }

return prisonerCounter;

}

struct Node {
    int data;
    Node* next;
};

int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void countByID() {
    	Prisoner *temp=starNode;
	if (starNode == NULL)
	 {
	 	  cout << "There are no registered prisoners." << endl;
	 }
	 else{
    string ID;
    cout<<"Enter the ID you want to count"<<endl;
    cin>>ID;
    int count = 0;
    Prisoner* current = starNode;

    while (current != NULL) {
        if (current->ID == ID) {
            count++;
        }
        current = current->next;
    }

    cout << "Number of occurrences of " << ID << ": " << count << endl;
}}

void countByName(){
    Prisoner *temp=starNode;
	if (starNode == NULL)
	 {
	 	  cout << "There are no registered prisoners." << endl;
	 }
	 else{
    string name;
    cout<<"Enter the name you want to count"<<endl;
    cin>>name;
    int count = 0;
    Prisoner* current = starNode;

    while (current != NULL) {
        if (current->name == name) {
            count++;
        }
        current = current->next;
    }

    cout << "Number of occurrences of " << name << ": " << count << endl;
}}
void countByGender() {
  //  Prisoner *temp=starNode;
	if (starNode == NULL)
	 {
	 	  cout << "There are no registered prisoners." << endl;
	 }
	 else{
    string gender;
    cout<<"Enter the gender you want to count"<<endl;
    cin>>gender;
    int count = 0;
    Prisoner* current = starNode;

    while (current != NULL) {
        if (current->gender == gender) {
            count++;
        }
        current = current->next;
    }

    cout << "Number of occurrences of " << gender << ": " << count << endl;
}}
void countByAge() {
    Prisoner *temp=starNode;
	if (starNode == NULL)
	 {
	 	  cout << "There are no registered prisoners." << endl;
	 }
	 else{
    int age;
    cout<<"Enter the age you want to count"<<endl;
    cin>>age;
    int count = 0;
    Prisoner* current = starNode;

    while (current != NULL) {
        if (current->age == age) {
            count++;
        }
        current = current->next;
    }

    cout << "Number of occurrences of " << age << ": " << count << endl;
}}
void countByCommittedCrime() {
    Prisoner *temp=starNode;
	if (starNode == NULL)
	 {
	 	  cout << "There are no registered prisoners." << endl;
	 }
	 else{
    string committedCrime;
    cout<<"Enter the committed crime you want to count"<<endl;
    cin>>committedCrime;
    int count = 0;
    Prisoner* current = starNode;

    while (current != NULL) {
        if (current->committedCrime == committedCrime) {
            count++;
        }
        current = current->next;
    }

    cout << "Number of occurrences of " << committedCrime << ": " << count << endl;
}}
void countByDateOfRelease() {
    Prisoner *temp=starNode;
	if (starNode == NULL)
	 {
	 	  cout << "There are no registered prisoners." << endl;
	 }
	 else{
    string dateOfRelease;
    cout<<"Enter the date of release you want to count"<<endl;
    cin>>dateOfRelease;
    int count = 0;
    Prisoner* current = starNode;

    while (current != NULL) {
        if (current->dateOfRelease == dateOfRelease) {
            count++;
        }
        current = current->next;
    }

    cout << "Number of occurrences of " << dateOfRelease << ": " << count << endl;
}}
void countByLengthOfSentence() {
    Prisoner *temp=starNode;
	if (starNode == NULL)
	 {
	 	  cout << "There are no registered prisoners." << endl;
	 }
	 else{
    string lengthOfSentence;
     cout<<"Enter the length of sentence you want to count"<<endl;
    cin>>lengthOfSentence;

    int count = 0;
    Prisoner* current = starNode;

    while (current != NULL) {
        if (current->lengthOfSentence == lengthOfSentence) {
            count++;
        }
        current = current->next;
    }

    cout << "Number of occurrences of " << lengthOfSentence << ": " << count << endl;
}}



void updateByName()
{
    if(starNode == NULL)
    {
        cout << "There are no registered prisoners." << endl;
        return;
    }

       char oldName[20] = "";

        cout << endl << "Enter the name you want to update: ";
        cin >> oldName;


        bool prisonerFound = false;
        Prisoner *current = starNode;

     while (current != NULL) {
        if (stricmp(current->name, oldName) == 0) { // if the name matches
             cout << "Enter new name: ";
             cin >>current->name; // update the name
             prisonerFound = true;
        }
        current = current->next;
     }

         if (prisonerFound) {
            cout <<"successfully updated"<< endl<<endl;
         }
        else {
        cout << "There are no prisoners with name " << oldName << " in the list." << endl;
        }
    }


void updateOneAge() {
    if (starNode == NULL) {
        cout << endl << "There are no prisoners registered." << endl;
        return;
    }

    int oldAge, newAge;
    bool foundAge = false;

    cout << endl << "Which age would you like to update? ";
    cin >> oldAge;

    Prisoner *current = starNode;

    while(current != NULL) {
        if (current->age == oldAge) {
                  cout << endl << "Enter the new age: ";
                  cin >>current->age;

                while(current->age<18)
                {
                      cout<<"Age must be 18 or above!"<<endl;
                      cout << endl << "Enter the new age: ";
                     cin >>current->age;
                }
            foundAge = true;
        }
        current=current->next;
    }

    if (foundAge)
    cout << "successfully updated!"<< endl;
    else{
    cout << "No prisoner was found with that age " << oldAge << "." << endl;
    }
}
void updateAgeRange() {
    if (starNode == NULL) {
        cout << endl << "There are no registered prisoners." << endl;
        return;
    }
    bool foundAge = false;
    int startAge, endAge;
    cout << "Enter the starting age: ";
    cin >> startAge;
    cout << "Enter the ending age: ";
    cin >> endAge;
     int newAge;

    Prisoner *current = starNode;
    while (current != NULL) {
        if (current->age >= startAge && current->age <= endAge) {
            foundAge = true;
                 cout << "Enter the new age for prisoner with age " << current->age << ": "<<endl;
                 cin >> newAge;

                while(newAge<18)
                {
                      cout<<"Age must be 18 or above!"<<endl;
                      cout << "Enter the new age for prisoner with age " << current->age << ": "<<endl;
                      cin >>newAge;
                }
               current->age = newAge;
        }
        current = current->next;
    }
    if(foundAge)
    cout << "Ages have been successfully updated." << endl;
    else
    cout << " No ages found with that range." << endl;

}

 void updateByGender(){

    if(starNode == NULL){
        cout << "There are no registered prisoners." << endl;
        return;
    }

    char oldGender[12] = "";
    cout << endl << "Enter the gender you want to update: ";
    cin >> oldGender;
    bool prisonerFound = false;
    Prisoner *current = starNode;

    while (current != NULL) {
        if (strcmp(current->gender, oldGender) == 0) {
            cout << "Enter new gender: ";
            cin>>current->gender;
            prisonerFound = true;
        }
        current = current->next;
    }

    if (prisonerFound)
        cout <<"Successfully updated!" << endl;
    else
        cout << "There are no prisoners with gender " << oldGender << " in the list." << endl;


 }

void updateByID(){
    if(starNode == NULL){
        cout << "There are no registered prisoners." << endl;
        return;
    }



    char oldID[12] = "";
    char newID[12] = "";

    cout << endl << "Enter the ID you want to update: ";
    cin >> oldID;

    Prisoner *current = starNode;

    bool prisonerFound = false;
    while (current != NULL) {
        if (strcmp(current->ID, oldID) == 0){

                 cout << "Enter the new ID for prisoner with ID " << current->ID << ": "<<endl;
                 cin>>newID;

               while(checkIdExists(newID))
                {
                      cout<<"The Id is already taken."<<endl;
                      cout << "Enter the new ID for prisoner with ID " << current->ID << ": "<<endl;
                      cin>>newID;
                }

                strcpy(current->ID,newID);
            prisonerFound = true;

        }
        current = current->next;
    }

    if (!prisonerFound) {
        cout << "There are no prisoners with ID " << oldID << " in the list." << endl;
    }
    else
    cout<< "Successfully updated!"<< endl;


}

void updateByLengthOfSentence()
{
    if(starNode == NULL){
        cout << "There are no registered prisoners." << endl;
        return;
    }

    char oldLengthOfSentence[10] = "";


    cout << endl << "Enter the lengthOfSentence you want to update: ";
    cin >> oldLengthOfSentence;


    bool prisonerFound = false;
    Prisoner *current = starNode;

    while (current != NULL) {
        if (strcmp(current->lengthOfSentence, oldLengthOfSentence) == 0) {
          cout << "Enter new lengthOfSentence: ";
          cin >> current->lengthOfSentence;
          prisonerFound = true;
        }
        current = current->next;
    }

    if (prisonerFound) {
        cout    << "Successfully updated!" <<endl;
    } else {
        cout << "There are no prisoners with lengthOfSentence " << oldLengthOfSentence << " in the list." << endl;
    }
}


void updateByDateOfRelease(){
{
    if(starNode == NULL){
        cout << "There are no registered prisoners." << endl;
        return;
    }

    char oldDateOfRelease[12] = "";


    cout << endl << "Enter the dateOfRelease you want to update: ";
    cin >> oldDateOfRelease;


    bool prisonerFound = false;
    Prisoner *current = starNode;

    while (current != NULL) {
        if (strcmp(current->dateOfRelease, oldDateOfRelease) == 0) {
                    cout << "Enter the date of release in DD-MM-YYYY format: ";
                  cin >>current->dateOfRelease;

            prisonerFound = true;
        }
        current = current->next;
    }

    if (prisonerFound) {
        cout << "Successfully updated!"<<endl;
    } else {
        cout << "There are no prisoners with dateOfRelease " << oldDateOfRelease << " in the list." << endl;
    }
}

}

void updateByCommittedCrime(){

{
    if(starNode == NULL){
        cout << "There are no registered prisoners." << endl;
        return;
    }

    char oldCommittedCrime[12] = "";


    cout << endl << "Enter the committedCrime you want to update: ";
    cin >> oldCommittedCrime;

    bool prisonerFound = false;
    Prisoner *current = starNode;

    while (current != NULL) {
        if (strcmp(current->committedCrime, oldCommittedCrime) == 0) {

            cout << "Enter new committedCrime: ";
            cin >> current->committedCrime;

            prisonerFound = true;
        }
        current = current->next;
    }

    if (prisonerFound) {
        cout<< "Successfully updated!" <<endl;
    } else {
        cout << "There are no prisoners with committedCrime " << oldCommittedCrime << " in the list." << endl;
    }
}

}
void swapPrisoner( Prisoner *i,Prisoner *j){
     // swapping name
         char temp[40];
       strcpy(temp,i->name);
       strcpy(i->name,j->name);
       strcpy(j->name,temp);

          // swapping age

          int ageSwapper;
        ageSwapper=i->age;
        i->age=j->age;
        j->age=ageSwapper;

       //swapping  id

       char idSwapper[12];
       strcpy(idSwapper,i->ID);
       strcpy(i->ID,j->ID);
       strcpy(j->ID,idSwapper);

       //swapping gender

       char genderSwapper[10];
       strcpy(genderSwapper,i->gender);
       strcpy(i->gender,j->gender);
       strcpy(j->gender,genderSwapper);

       // swapping committed crime

       char committedCrimeSwapper[30];
       strcpy(committedCrimeSwapper,i->committedCrime);
       strcpy(i->committedCrime,j->committedCrime);
       strcpy(j->committedCrime,committedCrimeSwapper);

       // swapping date of release
       char dateOfReleaseSwapper[12];
       strcpy(dateOfReleaseSwapper,i->dateOfRelease);
       strcpy(i-> dateOfRelease,j-> dateOfRelease);
       strcpy(j-> dateOfRelease,dateOfReleaseSwapper);

      // swapping length of sentence
     char lengthOfSentenceSwapper[15];
       strcpy(lengthOfSentenceSwapper,i->lengthOfSentence);
       strcpy(i->lengthOfSentence,j->  lengthOfSentence);
       strcpy(j->  lengthOfSentence,lengthOfSentenceSwapper);


}


 void sortByName(){
      if(countAllPrisoner()<2)
{
    cout<<"NO enough prisoner to be sorted"<<endl<<endl;
        return;

}

Prisoner *j;
Prisoner *i;
  for(i=starNode;i->next!=NULL;i=i->next)
    for(j=i->next;j!=NULL;j=j->next)
     if(stricmp(i->name,j->name)>0)
        swapPrisoner(i,j);


   cout<<"done!"<<endl<<endl<<endl;

}
void sortByAge(){
     if(countAllPrisoner()<2)


    {cout<<"NO enough prisoner to be sorted"<<endl<<endl;
        return;

    }

    Prisoner *j;
Prisoner *i;
  for(i=starNode;i->next!=NULL;i=i->next)
    for(j=i->next;j!=NULL;j=j->next)
     if(i->age > j->age)
         swapPrisoner(i,j);
           cout<<"done!"<<endl<<endl<<endl;




}
void sortByID(){
     if(countAllPrisoner()<2)
{
    cout<<"NO enough prisoner to be sorted"<<endl<<endl;
             return;
}

Prisoner *j;
Prisoner *i;
  for(i=starNode;i->next!=NULL;i=i->next)
    for(j=i->next;j!=NULL;j=j->next)
     if(yonasFunctionI(i->ID,j->ID)==1)
        swapPrisoner(i,j);
          cout<<"done!"<<endl<<endl<<endl;


}
void sortByGender(){
     if(countAllPrisoner()<2)
{
      cout<<"NO enough prisoner to be sorted"<<endl<<endl;
          return;
}

    Prisoner *j;
Prisoner *i;
  for(i=starNode;i->next!=NULL;i=i->next)
    for(j=i->next;j!=NULL;j=j->next)
     {if(stricmp(i->gender,j->gender)>0)
        swapPrisoner(i,j);

        }
       cout<<"done!"<<endl<<endl<<endl;


}
void sortByLengthOfSentence(){
     if(countAllPrisoner()<2)
{

        cout<<"NO enough prisoner to be sorted"<<endl<<endl;
             return;


}
    Prisoner *j;
Prisoner *i;
  for(i=starNode;i->next!=NULL;i=i->next)
    for(j=i->next;j!=NULL;j=j->next)
    {
        if(strnicmp(i->lengthOfSentence,"life",4)==0 )
         swapPrisoner(i,j);

      else if (yonasFunctionI(i->lengthOfSentence,j->lengthOfSentence)==1)
        swapPrisoner(i,j);

    }
   cout<<"done!"<<endl<<endl<<endl;



}
void sortByDateOfRelease(){

    if(countAllPrisoner()<2)
    {
          cout<<"NO enough prisoner to be sorted"<<endl<<endl;
        return;
    }




Prisoner *j;
Prisoner *i;
  for(i=starNode;i->next!=NULL;i=i->next)
    for(j=i->next;j!=NULL;j=j->next)
     if(yonasFunctionI(i->dateOfRelease,j->lengthOfSentence)==-1)
        swapPrisoner(i,j);

     cout<<"done!"<<endl<<endl<<endl;
}
void sortByCommittedCrime(){
      if(countAllPrisoner()<2)
{
    cout<<"NO enough prisoner to be sorted"<<endl<<endl;
        return;
}




Prisoner *j;
Prisoner *i;
  for(i=starNode;i->next!=NULL;i=i->next)
    for(j=i->next;j!=NULL;j=j->next)
     if(stricmp(i->committedCrime,j->committedCrime)>0)
        swapPrisoner(i,j);

         cout<<"done!"<<endl<<endl<<endl;
}


void TopName(int x)

{ sortByName();
cout<<"*****Top "<<x<<" by name*******"<<endl;
Prisoner *temp=starNode;
 for(int i=1;i<=x;i++)
 {

              cout<<"(-------------)(--------------(-------------)(-------------)--------------(-------------)"<<endl;
              cout<<"Name:"<<temp->name<<endl;
              cout<<"ID:"<<temp->ID<<endl;
              cout<<"Age:"<<temp->age<<endl;
              cout<<"Gender Age:"<<temp->gender<<endl;
              cout<<"length of sentence:"<<temp->lengthOfSentence<<endl;

              cout<<"Committed crime:"<<temp->committedCrime<<endl;
              cout<<"Date of release:"<<temp->dateOfRelease<<endl;
              cout<<"(-------------)(--------------(-------------)(-------------)--------------(-------------)"<<endl<<endl;
           temp=temp->next;
 }
}
void TopLengthOfSentenceName(int x){
sortByLengthOfSentence();
cout<<"*****Top "<<x<<" by length of sentence *******"<<endl;

Prisoner *temp=endNode;
 for(int i=1;i<=x;i++)
 {

              cout<<"(-------------)(--------------(-------------)(-------------)--------------(-------------)"<<endl;
                  cout<<"length of sentence:"<<temp->lengthOfSentence<<endl;
              cout<<"Name:"<<temp->name<<endl;
              cout<<"ID:"<<temp->ID<<endl;
              cout<<"Age:"<<temp->age<<endl;
              cout<<"Gender Age:"<<temp->gender<<endl;


              cout<<"Committed crime:"<<temp->committedCrime<<endl;
              cout<<"Date of release:"<<temp->dateOfRelease<<endl;
              cout<<"(-------------)(--------------(-------------)(-------------)--------------(-------------)"<<endl<<endl;
              temp=temp->prev;
 }

}
void TopAge(int x)

{ sortByLengthOfSentence();
    cout<<"*****Top "<<x<<" by age *******"<<endl;

Prisoner *temp=endNode;
 for(int i=1;i<=x;i++)
 {

              cout<<"(-------------)(--------------(-------------)(-------------)--------------(-------------)"<<endl;
                cout<<"Age:"<<temp->age<<endl;
                  cout<<"length of sentence:"<<temp->lengthOfSentence<<endl;
              cout<<"Name:"<<temp->name<<endl;
              cout<<"ID:"<<temp->ID<<endl;

              cout<<"Gender Age:"<<temp->gender<<endl;


              cout<<"Committed crime:"<<temp->committedCrime<<endl;
              cout<<"Date of release:"<<temp->dateOfRelease<<endl;
              cout<<"(-------------)(--------------(-------------)(-------------)--------------(-------------)"<<endl<<endl;
              temp=temp->prev;
 }

}
void TopID(int x)

{sortByLengthOfSentence();
    cout<<"*****Top "<<x<<" by Id *******"<<endl;

Prisoner *temp=endNode;
 for(int i=1;i<=x;i++)
 {

              cout<<"(-------------)(--------------(-------------)(-------------)--------------(-------------)"<<endl;
                cout<<"ID:"<<temp->ID<<endl;
                cout<<"Age:"<<temp->age<<endl;
                  cout<<"length of sentence:"<<temp->lengthOfSentence<<endl;
              cout<<"Name:"<<temp->name<<endl;

              cout<<"Gender Age:"<<temp->gender<<endl;


              cout<<"Committed crime:"<<temp->committedCrime<<endl;
              cout<<"Date of release:"<<temp->dateOfRelease<<endl;
              cout<<"(-------------)(--------------(-------------)(-------------)--------------(-------------)"<<endl<<endl;
              temp=temp->prev;
 }

}
int yonasFunctionI(char x[],char z[]){
    int j;

    if(strlen(x)!=strlen(z)){
        if(strlen(x)>strlen(z))
        return 1;
        return -1;

        }
    else{
        int y=pow(10,strlen(x)-1);
        long int result1=0;
        int i=strlen(x);
          for(int j=0;j<i;j++){
           result1=result1 +((int)x[j])*y;
             y=y/10;

            }
              int  k=pow(10,strlen(x)-1);
       int result2=0;
   for(int j=0;j<i;j++)
    {
    result2=result2 +((int)z[j])*k;
    k=k/10;

    }


if(result1>result2)
return 1;

if(result1<result2)
return -1;
 return 0;
}

}
int takeinput()
{
   int numberOfTops;
      cout<<"enter how many tops you want to display"<<endl;
      cin>>numberOfTops;

         if(cin){
              if(numberOfTops<=0)
              cout<<"Input can not be negative or zero"<<endl<<endl;
                   else
                    if(countAllPrisoner()<numberOfTops)
                      cout<<"Too Little Prisoner Number!"<<endl<<endl<<endl;
                     else
                                      return numberOfTops;
             }

                else
                cout<<"invalid input"<<endl<<endl;


                            return 0;




}


int main(){
    int delimeter;

do{
                cout<<"1--- Add prisoner "<<endl;
                cout<<"2--- Delete prisoner "<<endl;
                cout<<"3--- Do statistics  "<<endl;
                cout<<"4--- Search for a prisoner "<<endl;
                cout<<"5--- Display all records  "<<endl;
                cout<<"6--- Write on note pad "<<endl;
                cout<<"7--- Count prisoner "<<endl;
                cout<<"8--- Update prisoner "<<endl;
                cout<<"9--- Sort prisoner "<<endl;
                cout<<"10---Rank prisoner "<<endl;
                cout<<"0----Exit "<<endl<<endl<<endl;

                cin>>delimeter;
   if(cin){
               cout<<endl<<endl<<endl;

         switch(delimeter){

             case 1:
                    cout<<"1----Add from notepad at the beginning"<<endl;
                    cout<<"2----Add from the keyboard at the end"<<endl;
                    cout<<"3----Add from the keyboard at the middle"<<endl;
                    cout<<"4----Add from the keyboard at the beginning"<<endl;
                    cout<<"-1---Return to main menue"<<endl;
                    cin>> navigator;

                if(cin){
                    cout<<endl<<endl<<endl;
                        if(navigator==1)
                        addPrisonerFromNotePad();

                        else if(navigator==2)
                                addPrisonerAtTheEnd();

                        else if(navigator==3)
                            addPrisonerAtTheMiddle();

                        else if(navigator==4)
                            addPrisonerAtTheBeginning();

                        else if(navigator==-1)
                            break;
                        else
                        cout<<"wrong number choice"<<endl;

                }
                else
                        cout<<"invalid number"<<endl;


             break;

           case 2:          cout<<"1----Delete from the beginning"<<endl;
                         cout<<"2----Delete from the end"<<endl;
                         cout<<"3----Delete All"<<endl;
                         cout<<"4----Delete by name"<<endl;
                         cout<<"5----Delete by id"<<endl;
                         cout<<"6----Delete by date of release"<<endl;
                         cout<<"7----Delete by committed crime"<<endl;
                         cout<<"8----Delete by  length of sentence"<<endl;
                         cout<<"9----Delete by gender"<<endl;
                         cout<<"10---Delete by age"<<endl;
                         cout<<"11---Delete by maximum age"<<endl;
                         cout<<"12---Delete by record number"<<endl;
                         cout<<"-1---Return to main menue"<<endl<<endl;
                         cin>>navigator;
                if(cin) {
                          cout<<endl<<endl<<endl;

                            switch(navigator) {
                                                case 1:deleteAtTheBeginning();
                                                    break;
                                                case 2: deleteAtTheEnd();
                                                    break;
                                                case 3: deleteAll();
                                                    break;
                                                case 5: deleteByID();
                                                    break;
                                                case 4: deleteByName();
                                                    break;
                                                case 6: deleteByDateOfRelease();
                                                    break;
                                                case 7: deleteByCommittedCrime();
                                                    break;
                                                case 8: deleteByLengthOfSentence();
                                                    break;
                                                case 9: deleteByGender();
                                                    break;
                                                case 10: deleteByAge();
                                                    break;
                                                case 11: deleteByMaxAge();
                                                    break;
                                                case 12: deleteByNodeNumber();
                                                break;
                                                case -1:
                                                    break;
                                            default : cout<<"Wrong Number Choice,TRY AGAIN"<<endl<<endl<<endl;
                           }
                 }
                else

                 cout<<"invalid input";

             break;
             case 3:

                        cout<<"1--- Get average age"<<endl;
                        cout<<"2--- Get minimum age"<<endl;
                        cout<<"3--- Get maximum age"<<endl;
                        cout<<"4--- Get minimu length of sentence"<<endl;
                        cout<<"5--- Get maximum length of sentence"<<endl;
                        cout<<"-1---Return to main menue"<<endl<<endl<<endl;
                                cin>>navigator;
                    if(cin) {
                            switch(navigator) {

                                                case 1:
                                                    getAverageAge();
                                                    break;
                                                case 2:
                                                    getMinimumAge();
                                                    break;
                                                case 3:
                                                    getMaximumAge();
                                                    break;
                                                case 4:
                                                    getMinimumLengthOfSentence();
                                                    break;
                                                case 5:
                                                    getMaximuLengthOfSentence();
                                                    break;
                                                case -1:
                                                break;
                                                default :
                                                cout<<"Wrong Number Choice, TRY AGAIN!"<<endl<<endl<<endl;

                                            }
                    }
                    else
                        cout<<" invalid input"<<endl;



                    break;
            case 4:
                        cout<<"1--- Search a prisoner by name"<<endl;
                        cout<<"2--- Search a prisoner by age"<<endl;
                        cout<<"3--- Search a prisoner by gender"<<endl;
                        cout<<"4--- Search a prisoner by length of sentence"<<endl;
                        cout<<"5--- Search a prisoner by date of release"<<endl;
                        cout<<"6--- Search a prisoner by id"<<endl;
                        cout<<"7--- Search a prisoner by committed crime"<<endl;
                        cout<<"-1---Return to main menue"<<endl<<endl<<endl;
                        cin>>navigator;
                if(cin){
                        cout<<endl<<endl<<endl;
                         switch(navigator) {

                                        case 1:
                                            searchByName();
                                            break;
                                        case 2:
                                            searchByAge();
                                            break;
                                        case 3:
                                            searchByGender();
                                            break;
                                        case 4:
                                            searchByLengthOfSentence();
                                            break;
                                        case 5:
                                            searchByDateOfRelease();
                                            break;
                                        case 6:
                                            searchByID();
                                        case 7:
                                            searchByCommittedCrime();
                                            break;
                                        case -1:
                                        break;
                                        default :
                                        cout<<"Wrong Number Choice,TRY AGAIN"<<endl<<endl<<endl;

                                    }
                        }
                        else
                            cout<<"invalid input"<<endl;
                         break;
            case 5:        cout<<"1---- Forward display"<<endl;
                           cout<<"2---- Backward display"<<endl;
                cout<<endl<<endl<<endl;
                cin>>navigator;
                if(cin){cout<<endl<<endl<<endl;
                    if(navigator==1)
                        forwardDisplay();
                    else if(navigator==2)
                         backwardDisplay();
                  }
                    else
                    cout<<"invalid input"<<endl<<endl<<endl;

            break;
            case 6: writeOnNotePad();
            break;
            case 7:
                 cout<<"1---- Count all"<<endl;
                 cout<<"2---- Count by age"<<endl;
                 cout<<"3---- Count by gender"<<endl;
                 cout<<"4---- Count by length of sentence"<<endl;
                 cout<<"5---- Count by date of release"<<endl;
                 cout<<"6---- Count by id"<<endl;
                 cout<<"7---- Count by committed crime"<<endl;
                 cout<<"8---- Count by name"<<endl;
                 cout<<"-1----Return to menue"<<endl<<endl<<endl;
                 cin>>navigator;

                if(cin) {
                           switch(navigator){
                                        case 1:

                                            cout<<"There are "<<countAllPrisoner()<<" prisoners"<<endl<<endl;
                                            break;
                                        case 2:
                                            countByAge();
                                            break;
                                        case 3:
                                            countByGender();
                                            break;
                                        case 4:
                                            countByLengthOfSentence();
                                            break;
                                        case 5:
                                            countByDateOfRelease();
                                            break;
                                        case 6:
                                            countByID();
                                            break;
                                        case 7:
                                            countByCommittedCrime();
                                            break;
                                        case 8:
                                            countByName();
                                            break;
                                        case -1:
                                        break;
                                        default :
                                        cout<<"Wrong Number Choice,TRY AGAIN"<<endl<<endl<<endl;

                           }

                }


                else
                   cout<<"invalid input"<<endl;
            break;
            case 8:      cout<<"1---- Update one age"<<endl;
                     cout<<"2---- update age range"<<endl;
                    cout<<"3---- Update gender"<<endl;
                    cout<<"4---- Update length of sentence"<<endl;
                    cout<<"5---- Update date of release"<<endl;
                    cout<<"6---- Update id"<<endl;
                    cout<<"7---- Update committed crime"<<endl;
                    cout<<"8---- Update name"<<endl;
                    cout<<"-1----Return to menue"<<endl;
                    cin>>navigator;

                        if(cin){

                          cout<<endl<<endl<<endl;
                             switch(navigator) {
                                           case 1:
                                                updateOneAge();
                                                break;
                                           case 2:
                                                 updateAgeRange();
                                                 break;
                                            case 3:
                                                updateByGender();
                                                break;
                                            case 4:
                                                updateByLengthOfSentence();
                                                break;
                                            case 5:
                                                updateByDateOfRelease();
                                                break;
                                            case 6:
                                                updateByID();
                                                break;
                                            case 7:
                                                updateByCommittedCrime();
                                                break;
                                            case 8:
                                                updateByName();
                                                break;
                                            case -1:
                                                break;

                                            default :
                                            cout<<"Wrong Number Choice,TRY AGAIN"<<endl<<endl<<endl;

                           }

                        }
                        else
                        cout<<"invalid input";

            break;
            case 9: cout<<"1---- Sort by age"<<endl;
                    cout<<"2---- Sort by gender"<<endl;
                    cout<<"3---- Sort by length of sentence"<<endl;
                    cout<<"4---- Sort by date of release"<<endl;
                    cout<<"5---- Sort by id"<<endl;
                    cout<<"6---- Sort by committed crime"<<endl;
                    cout<<"7--- Sort by name"<<endl;
                    cout<<"-1----Return to menue"<<endl;
                    cin>>navigator;
                    if(cin){

                         cout<<endl<<endl<<endl;
                         switch(navigator){

                                        case 1:
                                            sortByAge();
                                            break;
                                        case 2:
                                            sortByGender();
                                            break;
                                        case 3:
                                                sortByLengthOfSentence();
                                            break;
                                        case 4:
                                            sortByDateOfRelease();
                                            break;
                                        case 5:
                                            sortByID();
                                            break;
                                        case 6:
                                            sortByCommittedCrime();
                                            break;
                                        case 7:
                                            sortByName();
                                            break;
                                        case -1:
                                            break;

                                        default :
                                        cout<<"Wrong Number Choice,TRY AGAIN"<<endl<<endl<<endl;

                        }
                    }

                    else
                       cout<<"invalid input"<<endl<<endl<<endl;


            break;
            case 10:

                    cout<<"1---Get tops by name"<<endl;
                    cout<<"2---Get tops by length of entence"<<endl;
                    cout<<"3---Get tops by Id"<<endl;
                    cout<<"4---Get tops by age"<<endl;
                    cout<<"-1--Return back to main menue"<<endl;
                    cout<<endl<<endl;
                    cin>>navigator;
               if(cin){
                                if(cin){
                                    if(navigator<0)
                                        cout<<"Wrong number choice"<<endl<<endl;
                                         else{
                                        int x=takeinput();


                    switch(navigator) {


                       case 1:  if(x)
                                TopName(x);

                                        break;

                       case 2: if(x)
                                        TopLengthOfSentenceName ( x);
                                        break;

                        case 3:
                                       if( x)

                                           TopID (x);
                                        break;

                        case 4:
                                        if(x)

                                        TopAge (x);

                                        break;
                        case -1:
                                        break;
                        default :
                                        cout<<"Wrong Number Choice,TRY AGAIN"<<endl;

                     }
                         }       }
                                else
                                              cout<<"Invalid input"<<endl;

            }

              else
                 cout<<"Invalid input"<<endl;

            break;

        }


    }
else
    cout<<"invalid input"<<endl<<endl;

}



while(delimeter!=0);

return 0;
}
