//Question 11
#include <iostream>
using namespace std;

class Restaurant{ //parent class, passes 'menu' down
public:
  virtual string menu() = 0; //create virtual function that'll return string since a menu consists of food names
  virtual string name() = 0;
};

//first restaurant child class
class Italian_Restaurant: public Restaurant{
public:
  string name(){ //uses required virtual function from inheritance to return a string of restaurant name
    return "Il Triangolo";
  }
  string menu(){
    return "Menu:\n\tSpaghetti and Meatballs\n\tLarge Pizza\n\tGnocchi\n"; //uses required virtual function from inheritance to give menu list
  }
};

class Greek_Restaurant: public Restaurant{
public:
  string name(){
    return "Mythos";
  }
  string menu(){
    return "Menu:\n\tHummus Trio\n\tKabob Stick\n\tGyro Sandwich\n";
  }
};

class Chinese_Restaurant: public Restaurant{
public:
  string name(){
    return "Panda Express";
  }
  string menu(){
    return "Menu:\n\tOrange Chicken\n\tShrimp Fried Rice\n\tEgg Roll\n";
  }
};

//templated class that will take a reference to a specific restaurant object and return its name and menu to be called in main
template <typename T>
string Reader_Robot(Restaurant &r){
  return r.name() + " " + r.menu();
}

int main(){
  //initialize each object
  Chinese_Restaurant c;
  Italian_Restaurant i;
  Greek_Restaurant g;
  //calling reader robot to read menus from child classes
  cout << Reader_Robot<Restaurant>(c);
  cout << Reader_Robot<Restaurant>(i);
  cout << Reader_Robot<Restaurant>(g);
  
  return 0;
}