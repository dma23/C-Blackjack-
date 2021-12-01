#pragma once
#include <vector>
using namespace std;

// main class 
class blackjack { 

    public:
        // default constructor, no id and starts with set amount   
        blackjack();
        // constuctor with user id, should be the main constructor
        // account value should be imported from accounts database
        blackjack(string user, int account_value);
        // starts the game, returns total win/loss per session as int (betting options are whole numbers, no decimals)
        string play_game();
        // play the dealers turn
        string play_dealer();
        // adds a card to the player/dealers hand, returns an int value for card 
        void hit();
        // stops the current players turn
        void stand();
        // player controlled bet amount, 
        void bet(int val); 
        // resets player/dealers hand and restarts the game
        void shuffle(); 
        // double a player bet and hit once
        void double_down();
        // get player/dealer hands, returns char
        vector<string> get_player_hand();
        // get dealer hand, retrun char
        vector<string> get_dealer_hand();
        // get current bet size
        int get_cur_bet();
        // gets the current account balance
        int get_cur_balance();
        
        vector<string> prev_hand;
        vector<string> prev_dealer_hand;
        
    private:
        // player variables
        vector<string> hand;
        char turn;
        string id; 
        int account_val;
        int hand_value;
        int cur_bet;

        // dealer variables
        int dealer_val;
        char dealer_turn;
        vector<string> dealer_hand;

        
};

