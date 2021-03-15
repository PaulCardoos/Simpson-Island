#ifndef hw2_h
#define hw2_h

#include <iostream> 
#include <vector>
#include <cstdlib>
#include <string>
#include <utility>
#include <fstream>
#include <algorithm>
#include <iterator>


using namespace std;

struct Simp{
    string name;
    std::pair<int, int> Dims;
    bool visited = false;
};

//Description: This is a helper function for canStack.
//Pre-Condition: must have a valid vector of pair, a struct Creature contain dimensions, and int pos
//of the pair you want to remove from Krustys hand
//Post-condition: will return a new vector with the modified results
vector<pair<int,int>> Remove_and_Replace(int pos, Simp Creature, vector<pair<int, int>> pool);
//Description: This boolean function will determine whther you can stack a card in Kristy's hand or 
//whether to put it in his pocket
//Pre-Condition: need a valid vector of pairs representing Kristys hand, and a struct containing 
//dimensions to perform the analysis 
//Post-Condition: will return true or false. If true place card in Krustys hand, if false put in pocket
bool canStack(vector<pair<int, int>> pool, Simp Creature);
//Description: displays the dimension from a given struct
//Pre-Condition: A struct contain dimension must be passed as parameter
//Post-Condition: printed out pair ex.) (3,1)
void DisplayDimensions(Simp Creature);
//Description: Will loop through a vecture of structs contain bool variable and if all true return true
//otherwise return false
//Pre-Condition: a vector of structs containing a boolean variable
//Post-Condition: return true or false, whether all Creatures have been visited or not
bool hasVisitedAllCreatures(vector<Simp> Creatures);
//Description: checks whether Krusty can leave AThlantis or not
//Pre-Condition: Krusty's hand which is a vector must be passed along with a vector of creatures 
//Post-Condition: will return true or false 
bool canLeaveAtlantis(vector<Simp> hand, vector<Simp> Creatures);
//Description: will generate random string from a vector of string
//Pre-Condition: must pass vector of strings as a paramter
//Post-Condition: return a random string
string getRandomSaying(vector<string> Sayings);
//Description: gets a random struct from a vector of structs
//Pre-Condition: must pass a vector of structs as a parameter
//Post-Condition: returns a random struct from the given vector
Simp getRandomCreature(vector<Simp> Creatures);
//Description: Takes three variables and binds them together in a struct
//Pre-Condition: must pass a valid string, and two positive integers
//Post-Condition: return a struct represent a creature and his business card
Simp createSimpson(string name, int first, int second);
//Description: take two strings first and last name a concatenates them into a full name
//Pre-Condition: must have two strings representing the first name and last name of a Creature in Atlantis
//Post-Condition: will return a string represent full name of Creature
string createFullName(string firstname, string lastname);
//Description: will read a file, extract the names and dimesnions, and return a vector of structs that represent
//the creatures from Atlantis
//Pre-Condition:must have a file names Creatures.txt
//Post-Condition: will return a vector of Structs representing the creature
vector<Simp> getNames();
//Description: will read from a file, and pull eeach line, and store it into a string which will 
//be stored in a vector
//Pre-Condition: must have a file named Sayings.txt
//Post-Condition: will return a vector of string containing potential phrases of the creatures form 
//Atlantis
vector<string> getSayings();

#endif