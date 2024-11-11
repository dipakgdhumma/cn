#include<iostream>
#include<string>
using namespace std;
//121.68.12.1
int main()
{
 string str,mask="",networkadd="";
 int count = 0;
 cin>>str;
 int firstOctet = stoi(str.substr(0,3));
 cout << firstOctet;
 
 
 if (firstOctet <= 127)
    {
        mask = "255.0.0.0";
        count = 1;
        
        cout << "Class A IP Address" << endl;
    }
    else if (firstOctet >= 128 && firstOctet <= 191)
    {
        mask = "255.255.0.0";
        count = 2;
        cout << "Class B IP Address" << endl;
    }
    else if (firstOctet >= 192 && firstOctet <= 223)
    {
        mask = "255.255.255.0";
        count = 3;
        cout << "Class C IP Address" << endl;
    }
    else if (firstOctet >= 224 && firstOctet <= 239)
    {
        cout << "Class D IP Address (Used for multicasting)" << endl;
    }
    else if (firstOctet >= 240 && firstOctet <= 254)
    {
        cout << "Class E IP Address (Experimental Use)" << endl;
    }

    cout << "SUBNET MASK: " << mask << endl;
    
    if(firstOctet < 223)
    {
      
      cout << "neworkaddre = " 
    }

 return 0;
}
