/*
 This is version 0.6.0 of the code									
 The code will do the following:			        		
 1. Initilized the database. 											 
 2. Read in data to perform caluclations.
 3. Create two tables, usernames and calcualted.       
 4. Insert data into sqlite3 databases                                                                                              
	
 Recent Updates:                                                          
 1. calculated data and read in data are put into the databse     	
 2. there are now two tables in the database, usernames and calculated
 3. automation complete
 4. cleaned up comments and fixed typos
 5. fixed segmentation fault error
 6. commeneted out old functions that were used for testing and labeled them as no longer in use

Last edited 18/12/19 05:24

*/

//All libraries and header files required for the project to work.
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <thread>
#include <chrono>
#include <unistd.h>
#include "sqlite3.h"
#include "time.h"
#include "converter.h"

using namespace std;
using std::vector;
using std::string;
using std::stringstream;

//Clear screen function has issues not used.
/*
void ClearScreen()
    {
    cout << string( 100, '\n' );
    }
*/  
//Below is the code for the main menu *USED FOR TESTING ONLY!!!!!* this code will be removed once we are sure 
//that the automation works as we intend.
/*
No longer used. This was only used for tesitng.

int mainMenu()
{
	//ClearScreen(); clear screen function works but the issue is you can not see returned data 
    int choice;
	cout <<"\t\tMain Menu\n"
         <<"\t\t=========\n"
         <<"\t\t1. Test decimal to binary conversion.\n" //only used for testing puroses, will be removed when the main function is finished.
         <<"\t\t2. Input data into the Vectors.\n"  //only used for testing puroses, will be removed when the main function is finished.
         <<"\t\t3. Prints data in the vectors (Temp).\n" //only used for testing puroses, will be removed when the main function is finished.
         <<"\t\t4. Test hex to binary conversion.\n" //only used for testing puroses, will be removed when the main function is finished.
		 <<"\t\t5. Search inputed data.\n"
		 <<"\t\t6. TEST INSTERING DATA INTO DATABASE.\n" //only used for testing puroses, will be removed when the main function is finished.
		 <<"\t\t7. Test Reading data from file to a vector.\n"
		 <<"\t\t8. Test binary to decimal conversion using vectors.\n" //only used for testing puroses, will be removed when the main function is finished.
		 <<"\t\t9. Inserts the calculated macaddress into the database.\n"
		 <<"\t\t10. Testing subnet math.\n"
		 <<"\t\t11. EXIT\n"
         <<"\tEnter your choice: ";
    cin >>choice;
    return choice;
}//end code for main menu.
*/

///////////////////////////////////////
// Initialize the callback function  //
// The program starts here!          //
///////////////////////////////////////

int callback(void *NotUsed, int argc, char **argv, char **azColName){

    // int argc: holds the number of results
    // (array) azColName: holds each column returned
    // (array) argv: holds each value

    for(int i = 0; i < argc; i++) {
        
        // Show column name, value, and newline
        cout << azColName[i] << ": " << argv[i] << endl;
    
    }

    // Insert a newline
    cout << endl;

    // Return successful
    return 0;
}

/////////////////////////////////////////////
//		    End call back function         //
/////////////////////////////////////////////


////////////////////////////////////////////
//			Start of Main                 //
////////////////////////////////////////////

int main(int argc, char** argv) 
{	
	string letter;
	int id;
	
	//for converter vectors and functions
	converter conv;
	
////////////////////////////////////////////////////////
//				Initializes Database                 //
//		*ONLY ALTER NAME OF THE DATABSE!*           //
/////////////////////////////////////////////////////
	
	//dont know what these do yet...
	sqlite3 *db; // Pointer to SQLite connection
	
    // Save any error messages
    char *zErrMsg = 0;
    // Save the result of opening the file
    int rc;    
	/* creates the sql function that we will call for the tables.
	//each new sql function will start here.
	once this is initalized then you can make a new table.
	*/
    string sql;
    string sql2;
    
    // Save the result of opening the file
    //Name of the database file is below. Only thing to alter here is the name of the .db file.
    rc = sqlite3_open("example.db", &db);
    
    //Will display an error if it can not connect to database and will close attempted connection.
	if( rc )
	{
        // Show an error message
        cout << "DB Error: " << sqlite3_errmsg(db) << endl;
        // Close the connection
        sqlite3_close(db);
        // Return an error
        return(1);
    }
      
	//Each table will be created here:
	//a few example tables are here just to pratice
	// Save SQL to create a table
    /*
	sql = "CREATE TABLE PEOPLE ("  \
      "ID INT PRIMARY KEY     NOT NULL,"
      "FNAME VARCHAR(25)      NOT NULL,"
      "LNAME VARCHAR(30)      NOT NULL,"
      "EMAIL VARCHAR(30)      NOT NULL,"
      "V4_O1                  NOT NULL,"
      "V4_O2                  NOT NULL,"
      "V4_O3                  NOT NULL,"
      "V4_O4                  NOT NULL,"
      "SUBNETMASK INT         NOT NULL,"
      "SUBNET1 INT            NOT NULL,"
      "SUBNET2 INT            NOT NULL,"
      "SUBNET3 INT            NOT NULL,"
      "SUBNET4 INT            NOT NULL);";
      */
      
    //sql table for putting usernames into the database
	sql = "CREATE TABLE USERNAMES ("  \
      "ID INT PRIMARY KEY 		      NOT NULL,"
      "USERNAME TEXT            NOT NULL);";
	
	//sql table for putting the macdresses into the database  
	sql2 = "CREATE TABLE MACADDRESS ("  \
      "ID INT PRIMARY KEY 		      NOT NULL,"
      "CALCMACADDRESS TEXT            NOT NULL);";

////////////////////////////////////////////////////
//		End of database initlization!!!          //
//////////////////////////////////////////////////
				
////////////////////////////////////////////
//		    Start of automation code:	  //
////////////////////////////////////////////			
		string temppk1, temppk2, tempname, tempcalc;
		int j = 0;
	
			while(1)
			{			
				rc = sqlite3_open("example.db", &db);
				cout<<"Opening database!"<<endl;
				sleep(15); //sets a delay in seconds!
					conv.ipv6macadressCalc();
    			//	conv.printCalcToFile(); <--- remove the comment and this extra text if you want this feature enabled.
			 			
						/* This takes the values from the temp vectors and puts them into strings by defualt
							this will allow for us to fix the segmentation fault error.*/ 
						temppk1	= conv.pkey1todb[j];
			 			temppk2	= conv.pkey2todb[j];
			 			tempname = conv.un[j];
						tempcalc = conv.calctodb[j];
						
						/*clears the temp vecors, this was done in order to fix the segmentation fault error 
						for when the vectors have nothing in them when the for loop keeps stepping up. */
						conv.pkey1todb.clear();
						conv.pkey2todb.clear();
						conv.un.clear();
						conv.calctodb.clear();
					 
    				for (int i=0; i < 1; i++)
        			{
        				// Run the SQL (convert the string to a C-String with c_str() )
    					rc = sqlite3_exec(db, sql2.c_str(), callback, 0, &zErrMsg);
					
						std::string	sql2 = "INSERT INTO MACADDRESS ('ID', 'CALCMACADDRESS') VALUES (" + temppk1 + ", '" + tempcalc + "')";	
						
						// Run the SQL (convert the string to a C-String with c_str() )
    					rc = sqlite3_exec(db, sql2.c_str(), callback, 0, &zErrMsg);
    					
    				// Save SQL insert data
					sql2 = "SELECT * FROM 'MACADDRESS' ;";
					
					// Run the SQL (convert the string to a C-String with c_str() )
    				rc = sqlite3_exec(db, sql2.c_str(), callback, 0, &zErrMsg);
					}
    				
    				for (int i=0; i < 1; i++)
        			{
        				// Run the SQL (convert the string to a C-String with c_str() )
    					rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
					
						std::string	sql = "INSERT INTO USERNAMES ('ID', 'USERNAME') VALUES (" + temppk2 + ", '" + tempname + "')";	
						
						// Run the SQL (convert the string to a C-String with c_str() )
    					rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    					
    				// Save SQL insert data
					sql = "SELECT * FROM 'USERNAME' ;";
					
					// Run the SQL (convert the string to a C-String with c_str() )
    				rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
					}
    
    				// Close the SQL connection and save all data put into the database.
    				sqlite3_close(db);
			}
//////////////////////////////////////////
//		    End of automation code:	  ///
////////////////////////////////////////
}

////////////////////////////////////////////
//			  End of Main!                //
////////////////////////////////////////////
