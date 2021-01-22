//////////////////////////////////////////////////////////////
// converter.cpp										    //
// This file is to initialized everything in the			//
// converter. header file.									//
// All of vectors and other functions are defined here      //
// and are all in main.										//
//////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include "converter.h"
#define MAX 10000

using namespace std;

//base constuctor:
converter::converter()
{
	
}

/////////////////////////////////////////
//		Vector for taking in data.	   //
/////////////////////////////////////////

void converter::decimalToBinary()
{
	cout<<"Enter a number to be converted to binary: ";
	cin >> inputedDec;
	dToB.push_back(inputedDec);
	int i = 0;
	while (inputedDec > 0)
	{
		dToB[i] = inputedDec % 2;
		inputedDec = inputedDec / 2;
		dToB.push_back(inputedDec);
		i++;
	}
	
	cout << "The binary converion is: ";
	//print function for decimal to binary;
    for (int j = i - 1; j >= 0; j--) 
        cout << dToB[j];

}

void converter::binarytoDecimal()
{
	cout<<"Enter a binary number to be converted to decimal: ";
	cin >> inputedBin;
	
	int decimalNumber = 0, i = 0, remainder;
    while (inputedBin!=0)
    {
        remainder = inputedBin % 10;
        inputedBin /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    
    bToD.push_back(decimalNumber);

		cout<<"Conversion: "<<endl;
    	for (vector<int>::const_iterator iter = bToD.begin();
        iter != bToD.end(); ++iter)
    	cout << *iter << endl;

}

void converter::dtobTestPrint()
{
	
}

void converter::hexToBinary()
{
	char binaryNumber[MAX],hexaDecimal[MAX];
    long int i=0;

    cout<<"Enter any hexadecimal number: ";
    cin>>hexaDecimal;

    cout<<"Equivalent binary value: ";
    cout<<endl;
    while(hexaDecimal[i])
    {
         switch(hexaDecimal[i])
         {
             case '0': cout<<"0000"; break;
             case '1': cout<<"0001"; break;
             case '2': cout<<"0010"; break;
             case '3': cout<<"0011"; break;
             case '4': cout<<"0100"; break;
             case '5': cout<<"0101"; break;
             case '6': cout<<"0110"; break;
             case '7': cout<<"0111"; break;
             case '8': cout<<"1000"; break;
             case '9': cout<<"1001"; break;
             case 'A': cout<<"1010"; break;
             case 'B': cout<<"1011"; break;
             case 'C': cout<<"1100"; break;
             case 'D': cout<<"1101"; break;
             case 'E': cout<<"1110"; break;
             case 'F': cout<<"1111"; break;
             case 'a': cout<<"1010"; break;
             case 'b': cout<<"1011"; break;
             case 'c': cout<<"1100"; break;
             case 'd': cout<<"1101"; break;
             case 'e': cout<<"1110"; break;
             case 'f': cout<<"1111"; break;
             default:  cout<<"nInvalid hexadecimal digit "<< hexaDecimal[i] <<endl;
         }
         i++;
    }
}

void converter::ipv6macadressCalc()
{
	cout<<"Begining new calculation!"<<endl;
	
	ifstream in4("pk.txt");
	string pkeyIN;
	
	while (getline(in4, pkeyIN)) 
	{
		//puts everything into the vector
		pKey.push_back(pkeyIN);
	}		
	in4.close();
	
	ifstream in3("pk.txt");
	string pkey2IN2;
	
	while (getline(in3, pkey2IN2)) 
	{
		//puts everything into the vector
		pKey2.push_back(pkey2IN2);
	}		
	in3.close();
	
	ifstream in2("username.txt");
	string nameIN;
	
	while (getline(in2, nameIN)) 
	{
		//puts everything into the vecotr
		username.push_back(nameIN);
	}
	//closes the file so it can be ovveridden with the new set
	//of macadresses to convert.			
	in2.close();
	
		for(int i = 0; i < username.size(); i++)
	{
		
		cout << username[i] << " ";
	}
	
	ifstream in("mac.txt");
	string macIN;
	
/*takes everything line by line and puts it into the file	
the file is mac.txt and has the following format:
1
a
b
d
and so on. The file is always 12 lines long.
This is so it is easier and quicker to read into the file
and to allow for the the file to be overridden quickly. */
while (getline(in, macIN)) 
	{
		//puts everything into the vecotr
		macadressvector.push_back(macIN);
	}
	//closes the file so it can be ovveridden with the new set
	//of macadresses to convert.			
	in.close();

//printing all the data and rebuilding it as it was in file	
	for(int i = 0; i < macadressvector.size(); i++)
	{
		
		cout << macadressvector[i] << " ";
	}
	
	/*
	coded out this was used for intial testing of the vectors 
	and the calculations. DO NOT UN-COOMMENT unless there is no mac.txt
	file in the directory. This is used for testing purposes only.
	
	macadressvector.push_back("0");
	macadressvector.push_back("0");
	macadressvector.push_back("1");
	macadressvector.push_back("5");
	macadressvector.push_back("2");
	macadressvector.push_back("b");
	macadressvector.push_back("e");
	macadressvector.push_back("4");
	macadressvector.push_back("9");
	macadressvector.push_back("b");
	macadressvector.push_back("6");
	macadressvector.push_back("0");	
	*/
	
	macstring1 = macadressvector[0];
	macstring2 = macadressvector[1];
	macstring3 = macadressvector[2];
	macstring4 = macadressvector[3];
	macstring5 = macadressvector[4];
	macstring6 = macadressvector[5];
	macstring7 = macadressvector[6];
	macstring8 = macadressvector[7];
	macstring9 = macadressvector[8];
	macstring10 = macadressvector[9];
	macstring11 = macadressvector[10];
	macstring12 = macadressvector[11];
	subnetmask = macadressvector[12];
	
	tempBin1 = macstring1;
	tempBin2 = macstring2;
	
	//combines the subnets by spliting them inhalf and making them in groups of 6
	tempCombine1 = macstring1 + macstring2 + macstring3 + macstring4 + macstring5 + macstring6;
	tempCombine2 = macstring7 + macstring8 + macstring9 + macstring10 + macstring11 + macstring12;
	
	cout << tempCombine1 <<endl;
	cout << tempCombine2 <<endl;
	
	tempCombine1 = tempCombine1 + ff;
	tempCombine2 = fe + tempCombine2;

	cout << tempCombine1 <<endl;
	cout << tempCombine2 <<endl;
	
	
	if(tempBin1 == "0")
	{
		bin1 = "0";
//		bin2 = "0";
//		bin3 = "0";
//		bin4 = "0";
	}
	if(tempBin1 == "1")
	{
		bin1 = "0";
		bin2 = "0";
		bin3 = "0";
		bin4 = "1";
	}
	if(tempBin1 == "2")
	{
		bin1 = "0";
		bin2 = "0";
		bin3 = "1";
		bin4 = "0";
	}
	if(tempBin1 == "3")
	{
		bin1 = "0";
		bin2 = "0";
		bin3 = "1";
		bin4 = "1";
	}
	if(tempBin1 == "4")
	{
		bin1 = "0";
		bin2 = "1";
		bin3 = "0";
		bin4 = "0";
	}
	if(tempBin1 == "5")
	{
		bin1 = "0";
		bin2 = "1";
		bin3 = "0";
		bin4 = "1";
	}
		if(tempBin1 == "6")
	{
		bin1 = "0";
		bin2 = "1";
		bin3 = "1";
		bin4 = "0";
	}
		if(tempBin1 == "7")
	{
		bin1 = "0";
		bin2 = "1";
		bin3 = "1";
		bin4 = "1";
	}
		if(tempBin1 == "8")
	{
		bin1 = "1";
		bin2 = "0";
		bin3 = "0";
		bin4 = "0";
	}	
	if(tempBin1 == "9")
	{
		bin1 = "1";
		bin2 = "0";
		bin3 = "0";
		bin4 = "1";
	}	
	if(tempBin1 == "a")
	{
		bin1 = "1";
		bin2 = "0";
		bin3 = "1";
		bin4 = "0";
	}	
	if(tempBin1 == "b")
	{
		bin1 = "1";
		bin2 = "0";
		bin3 = "1";
		bin4 = "1";
	}	
	if(tempBin1 == "c")
	{
		bin1 = "1";
		bin2 = "1";
		bin3 = "0";
		bin4 = "0";
	}
	if(tempBin1 == "d")
	{
		bin1 = "1";
		bin2 = "1";
		bin3 = "0";
		bin4 = "1";
	}
	if(tempBin1 == "e")
	{
		bin1 = "1";
		bin2 = "1";
		bin3 = "1";
		bin4 = "0";
	}
	if(tempBin1 == "f")
	{
		bin1 = "1";
		bin2 = "1";
		bin3 = "1";
		bin4 = "1";
	}
	if(tempBin1 == "A")
	{
		bin1 = "1";
		bin2 = "0";
		bin3 = "1";
		bin4 = "0";
	}	
	if(tempBin1 == "B")
	{
		bin1 = "1";
		bin2 = "0";
		bin3 = "1";
		bin4 = "1";
	}	
	if(tempBin1 == "C")
	{
		bin1 = "1";
		bin2 = "1";
		bin3 = "0";
		bin4 = "0";
	}
	if(tempBin1 == "D")
	{
		bin1 = "1";
		bin2 = "1";
		bin3 = "0";
		bin4 = "1";
	}
	if(tempBin1 == "E")
	{
		bin1 = "1";
		bin2 = "1";
		bin3 = "1";
		bin4 = "0";
	}
	if(tempBin1 == "F")
	{
		bin1 = "1";
		bin2 = "1";
		bin3 = "1";
		bin4 = "1";
	}
	
	if(tempBin2 == "0")
	{
		bin5 = "0";
		bin6 = "0";
		bin7 = "0";
		bin8 = "0";
	}
	if(tempBin2 == "1")
	{
		bin5 = "0";
		bin6 = "0";
		bin7 = "0";
		bin8 = "1";
	}
	if(tempBin2 == "2")
	{
		bin5 = "0";
		bin6 = "0";
		bin7 = "1";
		bin8 = "0";
	}
	if(tempBin2 == "3")
	{
		bin5 = "0";
		bin6 = "0";
		bin7 = "1";
		bin8 = "1";
	}
	if(tempBin2 == "4")
	{
		bin5 = "0";
		bin6 = "1";
		bin7 = "0";
		bin8 = "0";
	}
	if(tempBin2 == "5")
	{
		bin5 = "0";
		bin6 = "1";
		bin7 = "0";
		bin8 = "1";
	}
		if(tempBin2 == "6")
	{
		bin5 = "0";
		bin6 = "1";
		bin7 = "1";
		bin8 = "0";
	}
		if(tempBin2 == "7")
	{
		bin5 = "0";
		bin6 = "1";
		bin7 = "1";
		bin8 = "1";
	}
		if(tempBin2 == "8")
	{
		bin5 = "1";
		bin6 = "0";
		bin7 = "0";
		bin8 = "0";
	}	
	if(tempBin2 == "9")
	{
		bin5 = "1";
		bin6 = "0";
		bin7 = "0";
		bin8 = "1";
	}	
	if(tempBin2 == "a")
	{
		bin5 = "1";
		bin6 = "0";
		bin7 = "1";
		bin8 = "0";
	}	
	if(tempBin2 == "b")
	{
		bin5 = "1";
		bin6 = "0";
		bin7 = "1";
		bin8 = "1";
	}	
	if(tempBin2 == "c")
	{
		bin5 = "1";
		bin6 = "1";
		bin7 = "0";
		bin8 = "0";
	}
	if(tempBin2 == "d")
	{
		bin5 = "1";
		bin6 = "1";
		bin7 = "0";
		bin8 = "1";
	}
	if(tempBin2 == "e")
	{
		bin5 = "1";
		bin6 = "1";
		bin7 = "1";
		bin8 = "0";
	}
	if(tempBin2 == "f")
	{
		bin5 = "1";
		bin6 = "1";
		bin7 = "1";
		bin8 = "1";
	}
	if(tempBin2 == "A")
	{
		bin5 = "1";
		bin6 = "0";
		bin7 = "1";
		bin8 = "0";
	}	
	if(tempBin2 == "B")
	{
		bin5 = "1";
		bin6 = "0";
		bin7 = "1";
		bin8 = "1";
	}	
	if(tempBin2 == "C")
	{
		bin5 = "1";
		bin6 = "1";
		bin7 = "0";
		bin8 = "0";
	}
	if(tempBin2 == "D")
	{
		bin5 = "1";
		bin6 = "1";
		bin7 = "0";
		bin8 = "1";
	}
	if(tempBin2 == "E")
	{
		bin5 = "1";
		bin6 = "1";
		bin7 = "1";
		bin8 = "0";
	}
	if(tempBin2 == "F")
	{
		bin5 = "1";
		bin6 = "1";
		bin7 = "1";
		bin8 = "1";
	}
	
	combbin1 = bin1 + bin2 + bin3 + bin4;
	combbin2 = bin5 + bin6 + bin7 + bin8;
	
	cout << combbin1;
	cout << combbin2;
	
	if (bin7 == "0")
	{
		bin7 = "1";
	}
	else
	{
		bin7 = "0";
	}
	
	combbin1 = bin1 + bin2 + bin3 + bin4;
	combbin2 = bin5 + bin6 + bin7 + bin8;
	
	cout <<"Testing to see if the binary 7th slot is changed properly:"<<endl;
	cout<<""<<endl;
	cout << combbin1;
	cout<<""<<endl;
	cout<<"This: ";
	cout << combbin2;
	
	twosetbin1 = bin1 + bin2 + bin3 + bin4;
	twosetbin2 = bin5 + bin6 + bin7 + bin8; 
	
if(combbin1 == "0")
	{
		hex2 = "0";
	}
		if(combbin1 == "0001")
	{
		hex2 = "1";
	}
		if(combbin1 == "0010")
	{
		hex2 = "2";
	}
		if(combbin1 == "0011")
	{
		hex2 = "3";
	}
		if(combbin1 == "0100")
	{
		hex2 = "4";
	}
		if(combbin1 == "0101")
	{
		hex2 = "5";
	}
		if(combbin1 == "0110")
	{
		hex2 = "6";
	}
		if(combbin1 == "0111")
	{
		hex2 = "7";
	}
		if(combbin1 == "1000")
	{
		hex2 = "8";
	}
		if(combbin1 == "1001")
	{
		hex2 = "9";
	}
		if(combbin1 == "1010")
	{
		hex2 = "A";
	}
		if(combbin1 == "1011")
	{
		hex2 = "B";
	}
			if(combbin1 == "1100")
	{
		hex2 = "C";
	}
			if(combbin1 == "1101")
	{
		hex2 = "D";
	}
			if(combbin1 == "1110")
	{
		hex2 = "E";
	}
			if(combbin1 == "1111")
	{
		hex2 = "F";
	}
	
		if(combbin2 == "0000")
	{
		hex1 = "0";
	}
		if(combbin2 == "0001")
	{
		hex1 = "1";
	}
		if(combbin2 == "0010")
	{
		hex1 = "2";
	}
		if(twosetbin2 == "0011")
	{
		hex1 = "3";
	}
		if(twosetbin2 == "0100")
	{
		hex1 = "4";
	}
		if(twosetbin2 == "0101")
	{
		hex1 = "5";
	}
		if(twosetbin2 == "0110")
	{
		hex1 = "6";
	}
		if(twosetbin2 == "0111")
	{
		hex1 = "7";
	}
		if(twosetbin2 == "1000")
	{
		hex1 = "8";
	}
		if(twosetbin2 == "1001")
	{
		hex1 = "9";
	}
		if(twosetbin2 == "1010")
	{
		hex1 = "A";
	}
		if(twosetbin2 == "1011")
	{
		hex1 = "B";
	}
		if(twosetbin2 == "1100")
	{
		hex1 = "C";
	}
		if(twosetbin2 == "1101")
	{
		hex1 = "D";
	}
		if(twosetbin2 == "1110")
	{
		hex1 = "E";
	}
		if(twosetbin2 == "1111")
	{
		hex1 = "F";
	}
	
	//for this part of tempCombine1 remove macstring2+ to remove an extra 0
	//might have to be re-added with further testing.
	tempCombine1 = macstring3 + macstring4 + ":" + macstring5 + macstring6 + ff;
	tempCombine2 = ":" + fe + macstring7 + macstring8 + ":" + macstring9 + macstring10 + macstring11 + macstring12;
	
	cout<<""<<endl;
	cout<<"Combined Hex is:";
	combineHex = hex2 + hex1;
	cout<<combineHex;
	cout<<""<<endl;
	combineAll = combineHex + tempCombine1 + tempCombine2;
	
	cout <<combineAll<<endl;
	
	//clears the vector out for the next set of calculations
	macadressvector.clear();
	
	cout <<"Combine hex: " <<combineHex<<endl;
	
	/*
	prints in proper format for ipv6 address.
	The 0000:: will allow for the adresses to be counted up, once FFFF:: is hit
	the next set of  0000's will begin to be assaigned so it would look like
	FFFF:0001/12 at the end of the address 
	*/
	
	combineAll = startofAddress + combineHex + "::" + "1" + "/" + subnetmask;
	
	macadresstodb.push_back(combineAll); //pus the final result into storage vector
	cout<<"Testing db vector: "<<endl; 
	cout <<combineAll<<endl; //prints final result to make sure it is accurate
	toTextFile = combineAll;
	
	combineAll = "";
	
	calctodb.assign(macadresstodb.begin(),macadresstodb.end());
	calctodb = macadresstodb;
	
	pkey1todb.assign(pKey.begin(),pKey.end());
	pkey1todb = pKey;
	
	pkey2todb.assign(pKey2.begin(),pKey2.end());
	pkey2todb = pKey2;
	
	un.assign(username.begin(),username.end());
	un = username;

	//cout<<"Testing to see if the vector was copied or not:"<<endl;
	
	int iter5;
    	for (vector<string>::const_iterator iter5 = calctodb.begin();
        iter5 != calctodb.end(); ++iter5)
    	cout << *iter5 << endl;
	/*
	The following website was used as a guide on the steps to convert macadresses
	to the proper ipv6 mac address section values. The macaddress section of an
	ipv6 adress is the last 2 octets
	
	https://kwallaceccie.mykajabi.com/blog/how-to-calculate-an-eui-64-address */
	
}//end of function

/*no longer used but if called in main using conv.printCalcToFile();
it will print all the calcualted values to a file.
This was turned off since everything is going into the database.
Call in main if this needs to be enabled.
*/
void converter::printCalcToFile()
{
	cout <<"Testing printing to file: "<<endl;
	cout <<toTextFile<<endl;
	ofstream calcFile;
	calcFile.open("finished_calculations.txt");
	
	int iter;
	for (vector<string>::const_iterator iter = macadresstodb.begin();
    iter != macadresstodb.end(); ++iter)
    calcFile << *iter << endl;
    calcFile.close();    	
}
