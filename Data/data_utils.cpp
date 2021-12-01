#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>
#include <string>
#include "data_utils.h"
using namespace std;

// read a csv file into a vector<vector<string>> data frame
vector<vector<string>> readFile (string fName){
    ifstream  data(fName);
    string line;
    vector<vector<string>>parsedCsv;

    while(getline(data,line)){
        stringstream lineStream(line);
        string cell;
        vector<string> parsedRow;
        while(getline(lineStream,cell,',')){
            parsedRow.push_back(cell);
        }
        parsedCsv.push_back(parsedRow);
    }
    return parsedCsv;
}

//get the current time function
const string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];

    tstruct = *localtime(&now)
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    return buf;
}

//function to update the data and datafile
vector<vector<string>> updateData(vector<vector<string>> data, string playerName, string playerPassword, int newBalance, string gameType){
    int offset = 2 ;
    if(gameType=="Blackjack"){ // this allows for correct data to be altered
        offset=0;
    } else if(gameType=="Slots"){
        offset=1;
    }

// // alter the data frame
    for (int i=0; i<data.at(0).size();i++){
        if (data.at(i).at(0) == playerName){
            int oldBalance = stoi(data.at(i).at(2));
            if(offset!=2){
                data.at(i).at(3+offset) = to_string((stoi(data.at(i).at(9+offset))+ newBalance)/(stoi(data.at(i).at(5+offset))+1));
                data.at(i).at(5+offset) = to_string(1 + stoi(data.at(i).at(5+offset)));
                data.at(i).at(7+offset) = currentDateTime();
                cout<<data.at(i).at(7+offset);
                data.at(i).at(9+offset) = to_string(newBalance + stoi(data.at(i).at(9+offset)));
            }
            data.at(i).at(2) = to_string(oldBalance + newBalance);
            return data;
        }
    }

    return data;
}

// write data function will write to the data file path specified in csv form
void writeData(string fileName, vector<vector<string>> data){
ofstream file(fileName);
    for(auto &i : data ){
        file << i.at(0) << "," << i.at(1) << "," << i.at(2) << "," << i.at(3) << "," << i.at(4) << "," <<i.at(5)<< ","  <<i.at(6) << "," << i.at(7) << "," << i.at(8) <<"," << i.at(9) << "," <<i.at(10) << endl;
    }
}

// function for adding a new player to the data base should be called from
// the login screen when players are trying to register a new account
void addPlayerToDatabase(string fileName, vector<vector<string>> data, string name, string password){
    ofstream file(fileName);
    for(auto &i : data ){
        file << i.at(0) << "," << i.at(1) << "," << i.at(2)<<","  << i.at(3) << "," << i.at(4) << "," <<i.at(5)<< "," <<i.at(6) << "," << i.at(7) << "," << i.at(8)<< ","  << i.at(9) << "," <<i.at(10) << endl;
    }
    file << name << "," << password << "," << to_string(1000) << "," << "0" << "," << "0" << "," << "0"<< "," << "0"<< "," << "0" << "," << "0" <<"," << "0" << "," << "0" << endl;
}

void overwritePlayerData(string fName, string pName, string pPassword, int adjustedBalance, string gameType){
    vector<vector<string>> dataArray = readFile(fName);
    dataArray = updateData(dataArray, pName, pPassword, adjustedBalance, gameType);
    writeData(fName, dataArray);
}

bool checkPlayerExists(string pName, string fName){
    vector<vector<string>> dataArray = readFile(fName);
    for (int i=0; i<dataArray.size();i++){
        if (dataArray.at(i).at(0) == pName){
            return true;
        }
    }
    return false;
}

bool addPlayer(string fName, string pName, string pPassword){
    if(not checkPlayerExists(pName, fName)){
        vector<vector<string>> dataArray = readFile(fName);
        addPlayerToDatabase(fName, dataArray, pName, pPassword);
        return true;
    }
    return false;
}
bool securityCheck(string pName, string password, string fName){
    vector<vector<string>> dataArray = readFile(fName);
    for (int i=0; i<dataArray.size();i++){
        if (dataArray.at(i).at(0) == pName and dataArray.at(i).at(0)==password){
            return true;
        }
    }
    return false;
}

// balance function returns the amount of money in a player's account
//stoi converts string to int
int balance(string pName, string password, string fName){
    vector<vector<string>> dataArray = readFile(fName);
    for (int i=0; i<dataArray.size();i++){
        if (dataArray.at(i).at(0) == pName){
            return stoi(dataArray.at(i).at(2));
        }
    }
    return -1;
}

