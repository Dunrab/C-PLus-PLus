//converters.h
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <cmath>

using namespace std;

#ifndef CONVERTER_H
#define CONVERTER_H

class converter
{
	public:
	
	//constructor
	converter();
	
	//function delcaration
	void decimalToBinary();
	void binarytoDecimal();
	void hexToBinary();
	void ipv6macadressCalc();
	void printCalcToFile();
	
	//test printing functions
	void dtobTestPrint();
	
	//all vectors used
	vector<int> dToB; //decimal to binary
	vector<int> bToD; //binary to decimal
	vector<int> hToB; //hex to binary
	
	vector<string> macadressvector; //for reading in mac adresses
	vector<string> macadresstodb; //for sending mac adresses into the database
	vector<string> pKey;
	vector<string> pKey2;
	vector<string> username;
	vector<string> calctodb; //create a copy of macadress todb vector this is created to fix an issue with segmentation faults.
	vector<string> pkey1todb;
	vector<string> pkey2todb;
	vector<string> un;
	
	private:
	
	protected:
	int inputedDec;
	int inputedBin;
	
	//for ipv6macadressCalc
	string macstring1;
	string macstring2;
	string macstring3;
	string macstring4;
	string macstring5;
	string macstring6;
	string macstring7;
	string macstring8;
	string macstring9;
	string macstring10;
	string macstring11;
	string macstring12;
	
	string subnetmask;
	
	string tempCombine1;
	string tempCombine2;
	
	string ff = "FF";
	string fe = "FE";
	
	string tempBin1;
	string tempBin2;
	
	string bin1;
	string bin2;
	string bin3;
	string bin4;
	string bin5;
	string bin6;
	string bin7;
	string bin8;
	
	string combbin1;
	string combbin2;
	string combinedBinary;
	
	string twosetbin1;
	string twosetbin2;
	
	string hex1;
	string hex2;
	string combineHex;
	
	string combineAll;
	string toTextFile;
	
	//rename these to proper names
	string startofAddress = "2001:DB8:";
	string startofAddress2 = "FE80::"; // :: = 0000
};
#endif
