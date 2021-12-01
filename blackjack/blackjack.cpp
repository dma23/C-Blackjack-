#pragma once
#include <iostream>
#include <ostream>
#include "blackjack.h"
#include <string>

/*
- add dealer variables (dealer_hands, value, etc) ✓
- get function for player/dealer cards (return string[]) ✓
- look at bet function comments ✓
- get cur_bet function (return int) ✓
- get player_balance function (return int) ✓
- add double_function (void)  ✓
    - double cur_bet
    - hit once then force a stand
- update hit function to return card face not value 
- create hand_vlue function (retrun int) 
*/

blackjack::blackjack() { 
    id = "test";
    turn = 'w';
    account_val = 100;
    hand;
    hand_value = 0;
    
    cur_bet = 0;

    dealer_hand;
    dealer_val = 0;
    dealer_turn = 'w';
}

blackjack::blackjack(string player_id, int val) { 
    id = player_id;
    account_val = val;
    hand;
    turn = 'w';    
    hand_value = 0;

    cur_bet = 0;

    dealer_hand;
    dealer_val = 0;
    dealer_turn = 'w';
    
}

string blackjack::play_game() { 
    // initial setup
    if(turn == 'w') {
        shuffle();
        return "Shuffling";
    }
    // your hand is over 21, you lose
    if(hand_value > 21) { 
        // you lose
        cout << "You lost \n";
        shuffle();
        return "You Lost, player hand over 21";
    }
    // if player turn is 'd' waiting, play dealer turn 
    if(turn == 'd' && dealer_turn == 'p') { 
        return play_dealer();
    }
    // if both player turn and dealer turn is 'd' (done) reset
    if(turn == 'd' && dealer_turn == 'd') { 
        shuffle();
        return "Reseting game";
    }
    return "error";
} // end play_game()

string blackjack::play_dealer() { 
/* 
automate the dealers turn, hit until:
    - dealer_val >= 21
    - dealer_val >= 17
    - dealer_val >= hand_value
*/  
    cout << "dealers turn" << endl;
    while(dealer_turn == 'p') { 
        // dealer hand is better than player hand, player loses and bet resets
        if(dealer_val >= hand_value && dealer_val <= 21) { 
            // player loses 
            cout << "You lost \n";
            dealer_turn = 'd';
            return "You lost, dealer hand is better";
        }
        // dealer hand is worse than player hand but still under 17, hit
        else if(dealer_val < hand_value && dealer_val < 17) { 
            cout << "Dealer hit \n";
            hit();
            return "continue";
        }
        else if(dealer_val > 21){ 
            cout << "dealer busted \n";
            account_val += cur_bet;
            dealer_turn = 'd';
            return "You won, dealer busted";
        }
        else { 
            cout << "You win" << endl;
            account_val += cur_bet;
            shuffle();
            return "You win!";
        }
    } // end while

} // end dealer_turn

void blackjack::hit() { 
    cout << "Hit" << endl;
    char cards[] = "23456789TJQKA";
    char face[] = "cdhs";
    char pick = cards[rand() % 13];
    char pick_face = face[rand() % 4];
    string s;
    int value; 
    //printf("%d\n", pick);
    if(pick == 'T' || pick == 'J' || pick == 'Q' || pick == 'K') {
        value = 10;
    }
    else if(pick == 'A') { 
        if(hand_value + 11 > 21) { 
            value = 1;
        }
        else { 
            value = 11;
        }
    }
    else { 
        // converts char number into int value
        int x = pick-'0';
        //printf("%d\n", x);
        value = x;
    }
    // ex 10h = 10 of hearts
    s.push_back(pick);
    s.push_back(pick_face);
    // determine who to give card to
    cout << s << endl;
    if(turn == 'p') { 
        cout << "to player" << endl;
        hand.push_back(s);
        hand_value += value;
        cout << hand_value << endl;
    }
    else{ 
        dealer_hand.push_back(s);
        cout << "to dealer"<< endl;
        dealer_val += value;
        cout << dealer_val << endl;
    }

} // end hit() 

void blackjack::stand() { 
    cout << "Standing" << endl;
    if(turn=='p') { 
        turn = 'd';
        dealer_turn = 'p';
    }
} // end stand()

void blackjack::bet(int b) { 
   // make check for cur_bet above 0 ✓
   // check balance and update if valid ✓

    if(cur_bet >= 0 && account_val >= b) { 
        cur_bet += b; 
        account_val -= b;
    }
    else { 
        cout << "Error \n";
        // add exception class
    }
   
}

void blackjack::shuffle() { 
    // reset player hands
    cout << "shuffling" << endl;
    prev_dealer_hand = dealer_hand;
    prev_hand = hand;
    hand.clear();
    cur_bet = 0;
    hand_value = 0;
    turn = 'p';
    hit();
    hit();

    turn = 'w';
    // reset dealer hands
    dealer_hand.clear();
    dealer_val = 0;
    dealer_turn = 'w';
    
    hit();
    hit();
    
    turn = 'p';
    //overwritePlayerData("data.csv", id, "password", account_val, "blackjack");
}

void blackjack::double_down() { 
    cur_bet += cur_bet;
    hit();
    stand();
}

vector<string> blackjack::get_player_hand() {
    return hand;
}

vector<string> blackjack::get_dealer_hand() {
    return dealer_hand;
}

int blackjack::get_cur_bet() { 
    return cur_bet;
}

int blackjack::get_cur_balance() { 
    return account_val;
}

int main() { 

    // 1 is to hit , 2 is to stand, dont click any other key or youll have to restart since cin will be error
    blackjack cs;
    cs.play_game();
    cout << "game starting" << endl;
    int a;
    cin >> a;
    while(a != 3) { 
        if(a == 1) { 
            cs.hit();
            cs.play_game();
            cin >> a;
            
        }
        else if(a == 2) { 
            cs.stand();
            cs.play_game();
            cin >> a;
            
        }

    }
}