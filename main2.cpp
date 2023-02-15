/* Miad Mobarak Alosaimi 2220001911
Bashayer Ali AlBrahim 2220005680
Fatimah MohammedJawad Alsayednasser 2220004256
Mzoon Alzahrani 2220005230 */

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "functions.h"
#include <fstream>

using namespace std;

//global variable
int g_var1=1;


//structure
struct user_information{
    string first_name;
    string scond_name;
    string id;
    int age;
};

//pre-defined functuions
//functions for the delivery fees
double WithDeliveryFeesCARD(double price, int fees){//paying with card
    double final;
    final=price-(price*20/100)+fees;
    return final;
}

void phone_number(string x){
    cout<<"\n Please enter your number to coordinate the delivery date: ";
        cout<<"\n **note: enter your number in the format 05**********"<<endl;
        cin>>x;
}
//overloaded function
void add (double a, double b){//if he choose one thing (gift card or wrapped)
    cout<<"the total would be: "<<(a+b)<<endl;
}
void add (double a, double b, double c){//if both choosen
    cout<<"the total would be: "<<(a+b+c)<<endl;
}

double water_intake(double *weight, double *exercise){
    return (*weight*0.67)+(*exercise*24);
}

//recursion
//points earned according to day entered (1 point for Sunday, 3 points for Monday...etc)
int rate(int day, int n){
if(day==1){
    return n;}
else{
    n=n+day;
    return rate(day-1, n);}}

//namespace
//calcuating total with 20% discount when using card with/out tax
namespace card_pricing_noVAT {
    void setPrice(double sum){//without tax
    cout << "The total is: "<< (sum-(sum*20/100)) <<endl;
}
}
namespace card_pricing_VAT {
    void setPrice(double T){//with tax
    float discount;
    cout << "The total with the tax is: "<<(T-(T*20/100))<< endl;
}
}

int main(){
    int start, section, choice, SC, anotherchoice, intro2, end2, n;
    float sum=0, bmi, h, w;
    string sum2[5], search;
    char choice22;
    double *wat_weight, *wat_exer, intake;
    wat_weight=new double;
    wat_exer=new double;
    
    string med[5]={"Dorofen","Panadol","Depovit","Erastapex","Colovatil"};
    float med2[5]={42,56,40,70,35};
    
    string personal[8]={"1.Toothbrush", "2.Toothpaste", "3.Floss", "4.Shampoo", "5.Shower gel", "6.Conditioner", "7.Lotion", "8.Sunscreen"};
    float personal2[8]={22,18,65,30,34,30,19,50};
    
    string cose[4]={"1.Face serum", "2.Under eye cream", "3.Toner", "4.Face cleanser"};
    float cose2[4]={61,101,55,130};
    
    string supp[4]={"1.Vitamin C", "2.Ferinject", "3.Protien powder", "4.Chromium"};
    float supp2[4]={25,120,315,55};
    
    string medical[5]={"1.Alcohol swaps", "2.Gauze", "3.Sanitizer", "4.Burn oiments", "5.Wound oiments"};
    float medical2[5]={26,15,12,24,32};
    
    string diet[4]={"1.Weight Gain Program", "2.Weight Loss Program", "3.Get Help", "4.Water intake calculator"};
    float diet2[4]={150,90,0,0};
   
    intro(intro2);//in header file
    int day;
    cout<<"\nEnter the day you entered the program (1 for Sunday, 2 for Monday..etc): ";
    cin>>day;
    cout<<"You earned "<<rate(day, g_var1)<<" points!"<<endl;
    cout<<"\n to begin, please press 1 : ";
    cin>>start;
    if (start!=1)
    {cout<<"\nthank you for visiting, see you later. "<<endl;
        }
        else{
    cout<<"\n********************************************************"<<endl;
    do{
        cout<<"which section would you like to buy from?";
        cout<<"\n1.Medicines\n2.Personal Care\n3.Cosematics\n4.Supplements\n5.Medical supplies\n6.Diet Schedule\n";
        cout<<"\n********************************************************"<<endl;
        cout<<"your choice is: ";
        cin>>section;
        cout<<endl;
        do {
            if (section==1)
            {
                int i, j, size=5;
                string temp;
                bool ordered=false;
                if (size > 2)
                {
                    for(i = 0; i < size-1 && ordered==false ; ++i) //sort array alphabetically
                        {
                            ordered=true;
                            for(j = 0; j < size-1;++j)
                            if(med[j].compare(med[j+1])>0)
                            {
                                ordered=false;
                                temp = med[j];
                                med[j] = med[j+1];
                                med[j+1] = temp;
                            }
                        }
                    int to_search;
                    cout<<"Do you want to check if specific item is available? (yes: press 1) (No: press 2): ";
                    cin>>to_search;
                    if(to_search==1){
                    int key=-1;
                    cout<<"Enter the item you want to find in this section: ";
                    cin>>search;
                    for(int i=0; i<size; i++){
                        if(med[i]==search){//search array to find item
                            key=i;
                            cout<<"Item found";
                            break;
                        }}
                    if(key<0){
                            cout<<"Item was not found!";}
                    cout<<"\nThe list of all items: ";
                    for (int i=0;i<size;i++)//printing array after sort and search
                        cout<<i+1<<". "<<med[i]<<endl;}
                    else{
                        for (int i=0;i<size;i++)//printing before search
                        cout<<i+1<<". "<<med[i]<<endl;
                } }
                cout<<endl<<"\nWhat item would you like to get from the MEDICINES section?"<<endl;
                cout<<"You choose to buy a: ";
                cin>>choice;
                if(choice==1)
                {sum+=med2[0];}
                else if(choice==2)
                {sum+=med2[1];}
                else if(choice==3)
                {sum+=med2[2];}
                else if(choice==4)
                {sum+=med2[3];}
                else if(choice==5)
                {sum+=med2[4];}
                else{
                    cout<<"invalid entry! ";
                }
            }
            else if (section==2)
            {
                for (int i=0; i<8; i++)
                {
                    cout<<personal[i]<<"\t"<<personal2[i]<<" S.R"<<endl;}
                    int list, rotate, newIndex;
                    string rotatedItems[8];
                    cout<<"is this section is listed by your priority? would you like it to be rearranged? (1. yes ,, 2. no) ";
                    cin>>list;
                    if (list==1){
                        cout<<"by how much would you like it to be rotated? ";
                        cin>>rotate;
                        for (int i=0;i<8;i++){//rotating items
                            newIndex=i+rotate;
                            if (newIndex>=8){
                            newIndex=newIndex%8;
                        }
                        rotatedItems[newIndex]=personal[i];
                    }
                      cout<<"\nItems after rotation : \n";
                    for (int i=0;i<8;i++){
                    cout<<rotatedItems[i]<<endl;}
                    }

                cout<<endl<<"What item would you like to get from the PERSONAL CARE section?"<<endl;
                cout<<"You choose to buy a: ";
                cin>>choice;
                if(choice==1)
                {sum+=personal2[0];}
                else if(choice==2)
                {sum+=personal2[1];}
                else if(choice==3)
                {sum+=personal2[2];}
                else if(choice==4)
                {sum+=personal2[3];}
                else if(choice==5)
                {sum+=personal2[4];}
                else if(choice==6)
                {sum+=personal2[5];}
                else if(choice==7)
                {sum+=personal2[6];}
                else if(choice==8)
                {sum+=personal2[7];}
                else{
                    cout<<"invalid entry! ";
                }
            }
                    else if (section==3){
                        for (int i=0; i<4; i++)
                        {
                        cout<<cose[i]<<"\t"<<cose2[i]<<" S.R"<<endl;}
                        cout<<endl<<"What item would you like to get from the COSEMATICS section?"<<endl;
                        cout<<"You choose to buy a: ";
                        cin>>choice;
                        //deleting chosen item
                        int Deletet, n=4, D;
                    cout<<"do you want to delete and choose again? (yes=1, no=2):  ";
                    cin>>D;
                    if (D==1)
                    {
                        cout<<"enter the number of the product that you want to delete: ";
                        cin>>Deletet;
                
                for (int i=Deletet; i<n ; i++){
                    cose[i-1]=cose[i];
                    cose2[i-1]=cose2[i];
                }
                n=n-1;
                cout<<endl<<endl;
                for (int i=0 ; i<n; i++)
                {
                    cout<<cose[i]<<"  "<<cose2[i]<<" S.R"<<endl;
                }
                        cout<<"your choice after deleting?  ";
                        cin>>choice;

                    }
                        if(choice==1)
                        {sum+=cose2[0];}
                        else if(choice==2)
                        {sum+=cose2[1];}
                        else if(choice==3)
                        {sum+=cose2[2];}
                        else if(choice==4)
                        {sum+=cose2[3];}
                        else{
                            cout<<"invalid entry! ";
                        }
                    }
            
                        else if (section==4)
                        {
                            for (int i=0; i<4; i++)
                            {
                                cout<<supp[i]<<"\t"<<supp2[i]<<" S.R"<<endl;}
                            cout<<endl<<"What item would you like to get from the SUPPLEMENTS section?"<<endl;
                            cout<<"You choose to buy a: ";
                            cin>>choice;
                            if(choice==1)
                            {sum+=supp2[0];}
                            else if(choice==2)
                            {sum+=supp2[1];}
                            else if(choice==3)
                            {sum+=supp2[2];}
                            else if(choice==4)
                            {sum+=supp2[3];}
                            else{
                                cout<<"invalid entry! ";
                            }
                        }
                            else if (section==5)
                            {
                                for (int i=0; i<5; i++)
                                {
                                    cout<<medical[i]<<"\t"<<medical2[i]<<" S.R"<<endl;}
                                cout<<endl<<"What item would you like to get from the MEDICAL SUPPLIES section?"<<endl;
                                cout<<"You choose to buy a: ";
                                cin>>choice;
                                if(choice==1)
                                {sum+=medical2[0];}
                                else if(choice==2)
                                {sum+=medical2[1];}
                                else if(choice==3)
                                {sum+=medical2[2];}
                                else if(choice==4)
                                {sum+=medical2[3];}
                                else if(choice==5)
                                {sum+=medical2[4];}
                                else{
                                    cout<<"invalid entry! ";
                                }
                            }
                            else if (section==6)
                            {for(int i=0; i<4; i++){
                                cout<<diet[i]<<"\t"<<diet2[i]<<" S.R"<<endl;}
                                cout<<endl<<"What item would you like to get from the DIET section?"<<endl;
                                cout<<"You choose to buy a: ";
                                cin>>choice;
                                if(choice==1){
                                    sum+=diet2[0];
                                }
                                else if(choice==2){
                                    sum+=diet2[1];
                                }
                                else if(choice==3){
                                cout<<"please provide us with your height (in centimeters) and weight (in kgs) respectively to select the best option for you: ";
                                cin>>h>>w;
                                bmi=(w/(pow(h, 2))); //pow is a pre-defined function, used to get the value of h to the power 2
                                if(bmi<18.5){
                                    cout<<"According to your BMI, the best diet for you is "<<diet[0]<<endl;
                                    cout<<"Whould you like to get this item? ";
                                    cout<<"Yes(press 1), No(press 2) : ";
                                    cin>>choice;
                                    if(choice==1){
                                        sum+=diet2[0];
                                    }}
                                
                                else if(bmi>27){
                                        cout<<"According to your BMI, the best diet for you is "<<diet[1]<<endl;
                                    cout<<"Whould you like to get this item? ";
                                    cout<<"\nYes(press 1), No(press 2) : ";
                                    cin>>choice;
                                    if(choice==1){
                                        sum+=diet2[1];
                                    }
                                }
                                else if(18.5<bmi<27){
                                    cout<<"According to your BMI, you are in your best shape"<<endl;
                                }
                            }
                            else if(choice==4){
                                
                                cout<<"\n Please provide us with your weight -in kg- and how many hours you exercise per day: ";
                                cout<<"\n\n Your weight is: ";
                                cin>>*wat_weight;
                                cout<<"\n The number of hours you exersice per day is: ";
                                cin>>*wat_exer;
                                
                                intake=water_intake(wat_weight, wat_exer);
                                
                                cout<<"The minimum water consumption for you is: "<<intake<<" oz."<<endl;
                                delete wat_weight;
                                delete wat_exer;

                            }
                            else{
                                cout<<"invalid entry! ";
                            }
                            }
                cout<<"Would you like to add something from the same section? ";
                cout<<"\n (Yes press 1, NO press 2) : ";
                cin>>SC;
                cout<<"************************************************\n";
        }while(SC==1);
        cout<<"Would you like to buy something from another section, OR going to shopping cart? ";
        cout<<"\n (press 1 to go to another section and 2 to go to the shopping cart): " ;
        cin>>anotherchoice;
    }while(anotherchoice==1);
    cout<<"\n********************************************************"<<endl;
}
    
      //asking if you want to gift wrapped/gift card
      int gift, card, g=10, gc=5;
    cout<< "would you like it to be gift wrapped? (10 S.R)"<<endl;
    cout<< "press 1 if yes, 2 if no. "<<endl;
    cin>>gift;
    if (gift != 1 && gift !=2){
        cout<<"invalid entry! ";
    }
    cout<< "would you like to add a gift card to it? (5 S.R)"<<endl;
    cout<< "press 1 if yes, 2 if no. "<<endl;
    cin>>card;
    if (card != 1 && card !=2){
        cout<<"invalid entry! ";
    }
    if (gift==1 && card==1){
        add(sum, g, gc);
        sum=sum+g+gc;
    }
        else if (gift==1 && card==2){
            add(sum, g);
            sum+=g;
        }
            else if (gift==2 && card==1){
                add(sum, gc);
                sum+=gc;
            }
    else
        cout<<"invalid entry! ";
        
        cout<<"\n********************************************************"<<endl;
        
     //if sum over 300, 10% discount is applied
     if (sum>300){
        sum=sum-(sum*0.10);
        cout<<"\n********************************************************"<<endl;
        cout<<"since your bill is more than 300 S.R, you will get a 10% off!";
    }
    
    float T=Tax(sum,15,100);//definition in header file

    char card_cash;
    cout<<"\nAre you paying with card or cash? "; //if paying with card, get 20% discount, if paying with cash round up the total
    cout<<"\nyou will get a 20% off when paying with card!"<<endl;
    cout<<"\nPress C for card OR S for cash "<<endl;
    cin>>card_cash;
    
    switch(card_cash){
        case 'c':
        case 'C':{
            cout<<"\n********************************************************"<<endl;
            card_pricing_noVAT :: setPrice(sum); //namespace
            cout<<"\n********************************************************"<<endl;
            card_pricing_VAT :: setPrice(T); //namespace
            break;
        }
        case 's':
        case 'S':{
             cout<<"\n********************************************************"<<endl;
    cout<<"The Total Is :  "<<sum<<" S.R"<<endl;
    cout<<"\n********************************************************"<<endl;
    cout<<"The Total With The Tax Is :  "<<ceil(T)<<endl; //pre-defined function to round up total with tax when paying with cash
            
            break;
        }
        default:
        cout<<"Invalid entry!";
    }

int delivery_fees=20;
int *q=&delivery_fees; //pointer
int free_delivery=50;
string phonenum;
char cont;
struct user_information p; //structure
string city, st, dist, buildingNo, change, updatedLoc;
int edit;

cout<<"\n********************************************************"<<endl;
cout<<"Please provide us with your building number: ";
cin>>buildingNo;
cout<<"Please provide us with your street: ";
cin>>st;
cout<<"Please provide us with your district: ";
cin>>dist;
string location[3];
location[0]=buildingNo; //adding new items to the location array
location[1]=st;
location[2]=dist;
int size=3;
cout<<endl<<"would you like to edit your location information? (1- yes, 2- no) ";
cin>>edit;
if (edit !=1 && edit !=2)
{
    cout<<"Invalid entry!";
}
if (edit==1){
cout<<endl<<"what would you like to edit? (please write the wrong name) ";
cin>>change;
for (int i=0;i< size;i++){ //updating existing items(updating location array)
    if (location[i]== change){
        cout<<endl<<"what would you like it to be? ";
        cin>>updatedLoc;
        location[i]= updatedLoc;
        break;  }
    else
        cout<<"Invalid entry!";
}}

cout<<endl<<"please provide us with your city: ";
cin>>city;
if (city=="khobar"||city=="alkhobar"||city=="Khobar"||city=="Alkhobar"){
    cout<<"the nearest branch to you is at Golden Belt, Khobar. ";
}
else if (city=="dammam"||city=="Dammam"||city=="Aldammam"||city=="aldammam"){
    cout<<"the nearest branch to you is at Alfaisaliyah, Dammam. ";
}
else if (city=="Dhahran"||city=="dhahran"||city=="Aldhahran"||city=="aldhahran"){
    cout<<"the nearest branch to you is at Alqusor, Dhahran. ";
}
else{
    cout<<"sorry, no branches at your city. ";
}

cout<<"\n********************************************************"<<endl;


cout<<"\n Would you like to pick up your order from the store or have it delivered to you?"<<endl<<endl;
cout<<"\n Press A for order pick up\t\t press B for order delivery. "<<endl<<"\n Delivery fees: 20 SR. \t Note: You will get free delivery if your bill exceeds 50 SR."<<endl<<endl;
cin>>choice22;
if(choice22=='A'||choice22=='a'){
    cout<<"\n********************************************************"<<endl;
cout<<"\nAre you sure you want to checkout?"<<endl;
cout<<"Press C to continue"<<endl;
cin>>cont;
if(cont=='c' || cont=='C'){
    //using structure for user information
    cout<<"Please enter your first name "<<endl;
    cin>>p.first_name;
    cout<<"Please enter your last name "<<endl;
    cin>>p.scond_name;
    cout<<"Please enter your national ID "<<endl;
    cin>>p.id;
    cout<<"Please enter your age "<<endl;
    cin>>p.age;
    if(p.age<18){
        cout<<"You must be older to place an order!";
    }
    else{
        cout<<"\n********************************************************"<<endl;
        cout<<"\t***\tOrder placed\t***\t";
        cout<<"\nYour order number is: "<<"<<"<<rand()<<">>"<<endl;
        cout<<"\nWill have your order prepared as soon as possible :)"; }
}
else
{
cout<<"\n): Sorry to see you leaving ):"; }
    con(end2);}
else if(choice22=='b'||choice22=='B'){
    if(T>free_delivery){
        cout<<"\n Congratulations, your order is eligible for free delivery."<<endl;
        phone_number(phonenum);
        cout<<"\n********************************************************"<<endl;
cout<<"\nAre you sure you want to checkout?"<<endl;
cout<<"Press C to continue"<<endl;
cin>>cont;
if(cont=='c' || cont=='C'){
    //using structure for user information
    cout<<"Please enter your first name "<<endl;
    cin>>p.first_name;
    cout<<"Please enter your last name "<<endl;
    cin>>p.scond_name;
    cout<<"Please enter your national ID "<<endl;
    cin>>p.id;
    cout<<"Please enter your age "<<endl;
    cin>>p.age;
    if(p.age<18){
        cout<<"You must be older to place an order!";
    }
    else{
        cout<<"\n********************************************************"<<endl;
        cout<<"\t***\tOrder placed\t***\t";
        cout<<"\nYour order number is: "<<"<<"<<rand()<<">>"<<endl;
        cout<<"\nWill have your order prepared as soon as possible :)"; }
}
else
{
cout<<"\n): Sorry to see you leaving ):"; }
        con(end2);
    }
    else{
        if(card_cash=='c'||card_cash=='C'){
        cout<<"\n Your total with the delivery fees: "<<WithDeliveryFeesCARD(T, delivery_fees); //function to give total with 20% discount
        }
        else{
        cout<<"\n Your total with the delivery fees: "<<(ceil(T)+*q); //function ceil to round up the total + pointer to give the value of delivery fees
        }
    cout<<"\n********************************************************"<<endl;
cout<<"\nAre you sure you want to checkout?"<<endl;
cout<<"Press C to continue"<<endl;
cin>>cont;
if(cont=='c' || cont=='C'){
    //using structure for user information
    cout<<"Please enter your first name "<<endl;
    cin>>p.first_name;
    cout<<"Please enter your last name "<<endl;
    cin>>p.scond_name;
    cout<<"Please enter your national ID "<<endl;
    cin>>p.id;
    cout<<"Please enter your age "<<endl;
    cin>>p.age;
    if(p.age<18){
        cout<<"You must be older to place an order!";
    }
    else{
        cout<<"\n********************************************************"<<endl;
        cout<<"\t***\tOrder placed\t***\t";
        cout<<"\nYour order number is: "<<"<<"<<rand()<<">>"<<endl; //pre-defined funcion to give random number as order number
        cout<<"\nWill have your order prepared as soon as possible :)"; }
}
else
{
cout<<"\n): Sorry to see you leaving ):"; };
    con(end2);
    }
}
else{
    cout<<"\n Invalid entry, Please try again.";
}


ofstream outFile, appFile;
outFile.open("user_information_out.txt",ios::out);
appFile.open("user_information_app.txt",ios::app);
if(outFile.is_open() && appFile.is_open()){
        outFile<<p.first_name<<" "<<p.scond_name<<" "<<p.id<<" "<<p.age<<endl;
        appFile<<p.first_name<<" "<<p.scond_name<<" "<<p.id<<" "<<p.age<<endl;
    
    outFile.close(); appFile.close();}
else{
    cout<<"Failed!"<<endl;
}

ifstream inFile;
string fi;
cout<<"\nThe programmers of this program: "<<endl;
inFile.open("programmers_name.txt",ios::in);
if(inFile.is_open()){
	for(int i=0; i<4; i++){
    getline(inFile,fi);
    cout<<fi<<endl; }
    inFile.close();
}
else{
    cout<<"\nFailed!"<<endl;
}
    return 0;
}
