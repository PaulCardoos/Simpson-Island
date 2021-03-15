#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include "hw2.h"
#include <algorithm>
using namespace std;

int main (){
    srand(37);

    vector<pair<int, int>> hand; //array of pairs
    vector<Simp> Creatures_in_hand; //this will be the names of Creatures in hand
    vector<Simp> Names; 
    vector<Simp> pocket; 

    vector<Simp> Simpson = getNames();
    vector<string> Sayings = getSayings();
    bool flag = true; 
    bool stack = false;
    bool leave = false;
    string random_saying;
    while(flag){
        int random = rand() % 14;
        //cout << Simpson[random].name << " ";
        //printf("(%d %d)\n", Simpson[random].Dims.first, Simpson[random].Dims.second);
        //cout << Simpson[random].visited <<endl;
        Simpson[random].visited = true;
        cout<< Simpson[random].name << ' ';
        printf("(%d %d): ", Simpson[random].Dims.first, Simpson[random].Dims.second);
        random_saying = getRandomSaying(Sayings);
        cout << random_saying << endl; 
        stack = canStack(hand, Simpson[random]);
        if(stack == true){
            hand.push_back(Simpson[random].Dims);
            Creatures_in_hand.push_back(Simpson[random]);
            sort(hand.begin(), hand.end());
            stack = false;
        }
        else{
            sort(hand.begin(), hand.end());
            pocket.push_back(Simpson[random]);
        }
        leave = canLeaveAtlantis(Creatures_in_hand, Simpson);
        if(leave == true){
            flag = false;
        }
    }
    if(hand.size() == 6){
        cout << "\n\nKRUSTY: I have stacked 6 business I'm so glad" << endl;
        cout <<"I do not have to visit another one of these wierdos!" << endl;
        cout <<"Here are the Creatures and there cards that I have stacked!\n" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        cout << "**Stackable Creature Business Card's that Krusty Visited***"<< endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<< endl;
        for(int i = 0; i < Creatures_in_hand.size(); i++){
            cout<< Creatures_in_hand[i].name << " ";
            printf("(%d %d)\n", Creatures_in_hand[i].Dims.first, Creatures_in_hand[i].Dims.second);
        }

        cout << "\n***********************************************************"<<endl;
        cout << "****Proof of Stackation for the Atlantis Visitor Bureau****" << endl;
        cout << "***********************************************************" << endl;
        
        for(int i = 0; i < hand.size(); i++){
            printf("(%d %d)\n", hand[i].first, hand[i].second);
        }

        cout << "-----------------CONGRATULATIONS KRUSTY--------------------" << endl;
        cout << "-- Krusty, you have hereby earned your right to leave------" << endl;
        cout << "-- Atlantis by satisfying condition 1 of the Atlantis------" << endl;
        cout << "-- Visitors Bureau by stacking 6 business cards! You-------" << endl;
        cout << "---are hereby free to leave! Thank you for visiting--------" << endl;

    }else{
        cout << "\n\nKRUSTY: I have visited everyone and I have still not been able" << endl;
        cout <<" to stack my business card properly. At least I visited all the" << endl;
        cout <<" creatures and gave an honest effort!" << endl;

        cout << "\n***********************************************************"<<endl;
        cout << "****Proof of Visitation for the Atlantis Visitor Bureau****" << endl;
        cout << "***********************************************************" << endl;

        for(int i = 0; i < Simpson.size(); i++){
            cout << Simpson[i].name << endl;
        }

        cout << "\n-----------------CONGRATULATIONS KRUSTY--------------------" << endl;
        cout << "-- Krusty, you have hereby earned your right to leave------" << endl;
        cout << "-- Atlantis by satisfying condition 2 of the Atlantis------" << endl;
        cout << "-- Visitors Bureau by visiting all of inhabitants. We------" << endl;
        cout << "-- thank you for your support------------------------------" << endl;
    }
}

