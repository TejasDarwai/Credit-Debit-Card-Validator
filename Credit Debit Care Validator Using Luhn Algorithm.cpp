#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int isnumber(string creditcardnumber){
    for(int i=0; i<creditcardnumber.size(); i++){
        if(creditcardnumber[i]<'0' || creditcardnumber[i]>'9'){
            return 0;
        }
    }
    return 1;
}

int main(){
    
    string creditcardnumber;
    cout<<"***********Credit/Debit card Validator***********"<<endl;
    cout<<endl;
    cout<<"**************Using Luhn Algorithm***************"<<endl;
    cout<<endl;
    cout<<"       To Exit from this Program Enter Exit       "<<endl;
    cout<<endl;
    
    while(true){
        cout<<"Enter Credit/Debit Card Number =>";
        cin>>creditcardnumber;
        if(creditcardnumber=="exit" || creditcardnumber=="Exit"){
            break;
        }
        else if(!isnumber(creditcardnumber)){
            cout<<"Wrong input, Re-enter Number"<<endl;
            continue;
        }
        int numbersize = creditcardnumber.size();
        int sumdoubledeven=0;
        
        for(int i=numbersize-2; i>=0; i=i-2){
            int temp = ((creditcardnumber[i] - 48)*2);
            if(temp>9){
                temp = (temp/10) + (temp%10);
            }
            sumdoubledeven = sumdoubledeven + temp;
        }
        
        for(int i=numbersize-1; i>=0; i=i-2){
            sumdoubledeven = sumdoubledeven + (creditcardnumber[i] - 48);
        }
        int cardname=0;
        for(int i=0; i<2; i++){
            cardname = cardname*10 + creditcardnumber[i] - 48;
        }
        if(sumdoubledeven%10==0){
            if(cardname == 34 || cardname ==37){
                cout<<"Valid "<<"American Express Card"<<endl;
                cout<<endl;
            }
            else if(cardname == 60 || cardname ==65 || cardname ==81 || cardname ==82){
                cout<<"Valid "<<"Rupay Card"<<endl;
                cout<<endl;
            }
            else if(cardname == 41 || cardname ==40){
                cout<<"Valid "<<"Visa Card"<<endl;
                cout<<endl;
            }
            else if(cardname == 55 || cardname ==51){
                cout<<"Valid "<<"MasterCard"<<endl;
                cout<<endl;
            }
            else if(cardname == 56){
                cout<<"Valid "<<"Australian BankCard"<<endl;
                cout<<endl;
            }
            else{
                cout<<"Valid Card"<<endl;
                cout<<endl;
            }
        }
        else{
            cout<<"Invalid Card"<<endl;
            cout<<endl;
        }
        
    }
    
    return 0;
}