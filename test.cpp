#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <cstring>
#include <string>
#include <fstream>
using namespace std;
static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
ofstream file;
file.open("file.txt");
   for(i = 0; i<argc; i++){
      file << argv[i] ? argv[i] : "NULL";
   }
   file.close();
   return 0;
}

int main(int argc, char* argv[]) {
   //Declarations
   bool run;
   string allergies;
   char *choice = new char[20];

   //Getting data from user
   cout << "What are your food allergies: ";
   cin >> allergies;
   cout << "What would you like to eat today? " << endl
        << "1. Snickers" << endl
        << "2. Doritos" << endl
        << "3. Lucky Charms" << endl
        << "4. Kitkat" << endl
        << "5. Takis" << endl
        << "6. Cheezit" << endl
        << "7. Cheetos" << endl
        << "8. Pringles" << endl
        << "9. Peanut Butter" << endl
        << "10. Oreos" << endl;

   cin >> choice;




   //Getting data from database
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   const char* data = "Callback function called";
   char *statement = choice; //Need to change to input
   /* Open database */
   rc = sqlite3_open("Food.db", &db);

   /* Create SQL statement */
   sql = "SELECT * from food where Name = '";
   char *tmp = new char[100];
   strcpy(tmp,sql);
   strcat(tmp,statement);
   strcat(tmp,"'");
   /* Execute SQL statement */
   rc = sqlite3_exec(db,tmp, callback, (void*)data, &zErrMsg);
   
   if( rc != SQLITE_OK ) {
//      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
//      fprintf(stdout, "Operation done successfully\n");
   }
   sqlite3_close(db);

   string allergen="";
   //Getting data from file
   string fromFile;
   ifstream file;
   file.open("file.txt");
   file >> fromFile;
   file.close();
   for (int i = fromFile.size() - 9; i < fromFile.size(); i++){
      if(isdigit(fromFile[i])){
          allergen.append(1,fromFile[i]);
      }
   }
   cout << allergen;


   
return 0;
}

