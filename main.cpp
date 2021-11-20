#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <cstring>
#include <string>

using namespace std;

//global variable main 8 allergies
bool Milk = false;
bool Eggs = false;
bool Fish = false;
bool Shellfish = false;
bool Treenuts = false;
bool Peanuts = false;
bool Wheat = false;
bool Soybean = false;
bool Sesame = false;



void userSetup(){
  string userName;
  cout << "Hi, welcome to Allergens!\nWhat's your name?\n";
  cin >> userName;
  cout << "Nice to meet you "+userName+"!\n";
  cout << "Which of the following food allergies do you have?\n";
  cout << "Milk\nEggs\nFish\nShellfish\nTreenuts\nPeanuts\nWheat\nSoybean\nSesame\n";
  cout << "Input directly as displayed\n";
  string allergies;
  getline(cin, allergies);
  
  getline(cin, allergies);
  
  const char *allergens[9] = { "Milk", "Eggs","Fish", "Shellfish","Treenuts", "Peanuts", "Wheat", "Soybean", "Sesame"};
                             
  for (int i = 0; i<9;i++)
  {
    if (allergies.find(allergens[i]) != string::npos){
      if(i==0){Milk=true;}
      else if(i==1){Eggs=true;}
      else if(i==2){Fish=true;}
      else if(i==3){Shellfish=true;}
      else if(i==4){Treenuts=true;}
      else if(i==5){Peanuts=true;}
      else if(i==6){Wheat=true;}
      else if(i==7){Soybean=true;}
      else if(i==8){Sesame=true;}
    }
  }

  /*cout << Milk<< Eggs << Fish<< Shellfish<< Treenuts<< Peanuts<< Wheat<< Soybean<< Sesame<<"\n";*/

  return;
}

/*void itemSearch(){
  const char *foods[10] = { "Snickers", "Doritos","Lucky Charms", "KitKat","Takis", "Cheezit", "Cheetos", "Pringles", "Peanut Butter", "Oreos"};
  cout << "What item would you like to check?\n";
  string food;
  getline(cin, food);
  for (int i = 0; i < 10; i++){
    if (food.find(foods[i]) != string::npos)
    if(Peanuts)cout<<"nooooo";
  }
}*/

/*void interest()
{
  string Interest;
  cout << "Are you interested in a particular restaurant or product?" << endl;
  cin >> Interest;
  if(Interest == "Restaurant" || Interest == "restaurant")
  {

  }
  if(Interest == "Product" || Interest == "product")
  {

  }
}*/

void checkComp(std::string allergen){
  if(Milk){
      if(allergen[0]=='1'){
      cout << "May contain traces of Milk\n\n";}
      if(allergen[0]=='2')
      {cout << "Contains Milk\n\n";}
    }
 if(Eggs){
  if(allergen[1]=='1')
      {cout << "May contain traces of Eggs\n\n";}
      if(allergen[1]=='2')
      {cout << "Contains Eggs\n\n";}
  }
 if(Fish){
  if(allergen[2]=='1')
      {cout << "May contain traces of Fish\n\n";}
      if(allergen[2]=='2')
      {cout << "Contains Fish\n\n";}
  }
  
 if(Shellfish){
  if(allergen[3]=='1')
      {cout << "May contain traces of Shellfish\n\n";}
      if(allergen[3]=='2')
      {cout << "Contains Shellfish\n\n";}
      }
 if(Treenuts){
  if(allergen[4]=='1')
      {cout << "May contain traces of Treenuts\n\n";}
      if(allergen[4]=='2')
      {cout << "Contains Treenuts\n\n";}
      }
 if(Peanuts){
  if(allergen[5]=='1')
      {cout << "May contain traces of Peanuts\n\n";}
      if(allergen[5]=='2')
      {cout << "Contains\n\n";}
      }
 if(Wheat){
  if(allergen[6]=='1')
      {cout << "May contain traces of Wheat \n\n";}
      if(allergen[6]=='2')
      {cout << "Contains Wheat \n\n";}
      }
 if(Soybean){
  if(allergen[7]=='1')
      {cout << "May contain traces of Soybean\n\n";}
      if(allergen[7]=='2')
      {cout << "Contains Soybean\n\n";}
      }
 if(Sesame){
  if(allergen[8]=='1')
      {cout << "May contain traces of Sesame\n\n";}
      if(allergen[8]=='2')
      {cout << "Contains Sesame\n\n";}
  }
}

int main()
{
  userSetup();
  checkComp("101010112");
  
  return 0;
}
