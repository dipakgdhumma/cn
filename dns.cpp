#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
unordered_map<string,string> hostip;
unordered_map<string,string> iphost;

void maphostip(string ip,string host)
{
   hostip[host] = ip;
   iphost[ip] = host;
}

void lookhost(string ip)
{
    cout << ip <<"==" << iphost[ip] ;
}

void lookip(string host)
{
    cout << host <<"==" << hostip[host] ;
}

int main()
{
    int choice;
    string temphost,tempip;

    while (true) {
        std::cout << "\nChoose an option:\n";
        std::cout << "1. Add mapping (hostname and IP address)\n";
        std::cout << "2. Lookup IP from hostname\n";
        std::cout << "3. Lookup hostname from IP address\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

         if (choice == 1) {
            cout << "host ";
            cin>>temphost;
            cout <<endl << "ip " ;
            cin>>tempip;
            maphostip(tempip,temphost);
        } else if (choice == 2) {
           cout << "enter host ";
           cin >> temphost;
           lookip(temphost);
        } else if (choice == 3) {
            cout << "enter ip " ;
           cin >> tempip;
           lookhost(tempip);
        } else if (choice == 4) {
           
        } else {
            
        }
    
    }
}