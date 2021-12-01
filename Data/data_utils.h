#ifndef DATA_PART_DATA_UTILS_H
#define DATA_PART_DATA_UTILS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>
#include <string>
using namespace std;


vector<vector<string>> readFile (string fName);
const string currentDateTime();
vector<vector<string>> updateData(vector<vector<string>> data, string playerName, string playerPassword, int newBalance, string gameType);
void writeData(string fileName, vector<vector<string>> data);
void overwritePlayerData(string fName, string pName, string pPassword, int adjustedBalance, string gameType);
bool checkPlayerExists(string pName, string fName);
bool addPlayer(string fName, string pName, string pPassword);
bool securityCheck(string pName, string pPassword, string fName);
int balance(string pName, string password, string fName);
#endif //DATA_PART_DATA_UTILS_H

