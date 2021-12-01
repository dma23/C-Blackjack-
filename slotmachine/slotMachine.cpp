#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <time.h>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>

#include "slotmachine.h"

using namespace std;

slot:: slot(int bet) : bet(bet){

    srand((unsigned int)time(NULL));

	vector<int> panel;

	vector<int> items = {1, 1, 1,1,1,2,2,2,3,4};

    int num;
    int slot;

    num = rand() % (10);

    if (items[num] == 2){
        slot1 = 1;
        slot2 = 1;
        slot3 = 1;
        result = 2*bet;

    }else if(items[num] == 3){
        slot1 = 2;
        slot2 = 2;
        slot3 = 2;
        result = 5*bet;

    }else if (items[num] == 4){
        slot1 = 3;
        slot2 = 3;
        slot3 = 3;
        result = 7*bet;
    }else{  
        bool trigger = true;
        while(trigger){
            for (int i = 0; i < 3; i++){
                slot = rand() % (3)+1;
                panel.push_back(slot);  

            }
            if ((panel[0] != panel[1]) && (panel[2] !=  panel[0])) {
                trigger = false;
            }
        } 
        slot1 = panel[0];
        slot2 = panel[1];
        slot3 = panel[2];
        result = -bet;
        overwritePlayerData("data.csv", id, "password", account_val + bet, "slotmachine");

    }

    

 

}

int slot :: getSlot1() const {

	return slot1;
}

int slot :: getSlot2() const {

	return slot2;

}int slot :: getSlot3() const {

	return slot3;
}

int slot :: getBet() const {

	return bet;

}

int slot :: getResult() const {

	return result;
}