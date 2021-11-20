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
//   fprintf(stderr, "%s: ", (const char*)data);

  /* for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i],argv[i] ? argv[i] : "NULL");
   }
*/
ofstream file;
file.open("file.txt");
   for(i = 0; i<argc; i++){
      file << /*"%s = %s\n", azColName[i],*/argv[i] ? argv[i] : "NULL";
   }
   file.close();
  // printf("\n");
   return 0;
}

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   const char* data = "Callback function called";
   char *statement = "Snickers";

   /* Open database */
   rc = sqlite3_open("Food.db", &db);
   
   if( rc ) {
 //     fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
 //     fprintf(stderr, "Opened database successfully\n");
   }

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
   return 0;
}
