#include "functions.h"
#include <iostream>
using namespace std;
//calculate tax
float Tax(float x, float o, float m){
    
    return (x+(x*(o/m)));
}
//print introduction
void intro(int intr){
	 cout<<"********************************************************"<<endl;
    cout<<"\n*************** welcome to our pharmacy ****************"<<endl;
    cout<<"\n********************************************************"<<endl;
}
//print conclusion
void con(int end){
    cout<<"\n********************************************************"<<endl;
    cout<<"\nThank you for visiting, see you later."<<endl;
    cout<<"\n********************************************************"<<endl;
}
