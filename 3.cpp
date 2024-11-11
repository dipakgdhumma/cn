#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

// Function to split a string by a delimiter
vector<int> splitIP(const string &ip)
{
    vector<int> parts;
    stringstream ss(ip);
    string part;
    while (getline(ss, part, '.'))
    {
        parts.push_back(stoi(part));
    }
    return parts;
}

int main()
{
    string ip;
    cout << "Enter IP: ";
    cin >> ip;

    // Split the IP address into its octets
    vector<int> ipParts = splitIP(ip);

    // Get the first octet to determine the class
    int firstOctet = ipParts[0];
    string mask = "";

    if (firstOctet <= 127)
    {
        mask = "255.0.0.0";
        cout << "Class A IP Address" << endl;
    }
    else if (firstOctet >= 128 && firstOctet <= 191)
    {
        mask = "255.255.0.0";
        cout << "Class B IP Address" << endl;
    }
    else if (firstOctet >= 192 && firstOctet <= 223)
    {
        mask = "255.255.255.0";
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

    // Calculate Network and Broadcast Addresses for Classes A, B, and C
    if (firstOctet <= 223)
    {
        vector<int> maskParts = splitIP(mask);
        vector<int> networkAddr(4, 0);
        vector<int> broadcastAddr(4, 0);

        for (int i = 0; i < 4; ++i)
        {
            networkAddr[i] = ipParts[i] & maskParts[i];               // Network address calculation
            broadcastAddr[i] = networkAddr[i] | (255 - maskParts[i]); // Broadcast address calculation
        }

        // Print Network Address
        cout << "First IP of block (Network Address): ";
        for (int i = 0; i < 4; ++i)
        {
            cout << networkAddr[i];
            if (i < 3)
                cout << ".";
        }
        cout << endl;

        // Print Broadcast Address
        cout << "Last IP of block (Broadcast Address): ";
        for (int i = 0; i < 4; ++i)
        {
            cout << broadcastAddr[i];
            if (i < 3)
                cout << ".";
        }
        cout << endl;
    }

    return 0;
}
