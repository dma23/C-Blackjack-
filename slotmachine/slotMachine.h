#pragma once
#include <iostream>
#include "Data/data_utils.h"

using namespace std;

class slot{
public:
    slot(int bet);
 
	int getSlot1() const;
	int getSlot2() const;
    int getSlot3() const;
    int getResult() const;
    int getBet() const;

private:
	int slot1, slot2, slot3;
    int result,bet;

};