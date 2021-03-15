#include "hw2.h"

vector<pair<int,int>> Remove_and_Replace(int pos, Simp Creature, vector<pair<int, int>> pool){
    pool[pos].first = Creature.Dims.first;
    pool[pos].second = Creature.Dims.second;
    return pool;
}

string getRandomSaying(vector<string> Sayings){
    int random = rand() % 12;
    return Sayings[random];
}

Simp getRandomCreature(vector<Simp> Creatures){
    int random = rand() % 12;
    //cout << random << endl;
    return Creatures[random];
}
bool canStack(vector<pair<int, int>> pool, Simp Creature){
    bool condition1 = false;
    bool condition2 = false;
    bool equal1 = false;
    bool equal2 = false;

    if(pool.size() == 0){
        return true;
    }

    for(int i = 0; i < pool.size(); i++){
        if(pool[i].first == Creature.Dims.first && pool[i].second == Creature.Dims.second){
            return false; //check for duplicates
        }
    }

    for(int i = pool.size()-1; i>=0; i--){
        if(Creature.Dims.first > pool[i].first){
            condition1 = true;
        }
        if(Creature.Dims.first == pool[i].first){
            equal1 = true;
        }
        if(Creature.Dims.second > pool[i].second){
            condition2 = true;
        }
        if(Creature.Dims.second == pool[i].second){
            equal2 = true;
        }
        
        if(condition1 && condition2 && !equal1 && !equal2){
            return true;
        }

        if(!condition1 && condition2 && equal1 && !equal2){
            return true;
        }

        if(condition1 && !condition2 && !equal1 && !equal2){
            return false; 
        }

        if(!condition1 && !condition2 && equal1 && !equal2){
            equal1 = false;
            equal2 = false;
            condition1 = false;
            condition2 = false;      
        }

        if(!condition1 && !condition2 && !equal1 && (!equal2 || equal2)){
            equal1 = false;
            equal2 = false;
        }

        if(!condition1 && condition2 &&!equal1 && !equal2){
            pool = Remove_and_Replace(i, Creature, pool);
            return false; 
        }
    }
    return true;      
}

void DisplayDimensions(Simp Creature){
    int first = Creature.Dims.first;
    int second = Creature.Dims.second;
    cout << "(" << first << ", " << second << ")" << endl;
}

bool canLeaveAtlantis(vector<Simp> hand, vector<Simp> Creatures){
    if(hasVisitedAllCreatures(Creatures) == true){
        return true;
    }
    if(hand.size() == 6){
        return true;
    }
    return false;
}

bool hasVisitedAllCreatures(vector<Simp> Creatures){
    if(Creatures.size() == 0){
        return false;
    }

    for(int i = 0; i < Creatures.size(); i++){
        if(Creatures[i].visited == false){
            return false;
        }
    }
    return true;
}

Simp createSimpson(string name, int first, int second){
    std::pair<int, int> dimensions;
    dimensions = make_pair(first, second);
    Simp Simpson;
    Simpson.name = name;
    Simpson.Dims = dimensions;
    Simpson.visited = false;
    return Simpson;
}

string createFullName(string firstname, string lastname){
    string full_name; 
    full_name = firstname + " " + lastname;
    return full_name;
}

vector<Simp> getNames(){
    int first;
    int second;
    string firstname;
    string lastname;
    char x; 
    Simp Simpson; //will use these value to pass to createSimpson to create a vector of structs
    string name;
    vector<Simp> Simpsons;
    ifstream fin("Creatures.txt");
    for(int i = 0; i < 14; i++){
        
        fin >> firstname;
        fin >> lastname;
        fin >> first;
        fin >> x;
        fin >>second;
        if(second > first){
            Simpson = createSimpson(createFullName(firstname, lastname), second, first);
        }
        else{
            Simpson = createSimpson(createFullName(firstname, lastname), first, second);
        }
        
        Simpsons.push_back(Simpson); 
    }
    fin.close();
    return Simpsons;
}

vector<string> getSayings(){
    string phrase;
    vector<string> sayings;
    ifstream fin("Sayings.txt");
    for(int i = 0; i < 12; i++){
        getline(fin, phrase, '\n');
        sayings.push_back(phrase);
    }   
    fin.close();
    return sayings;
}