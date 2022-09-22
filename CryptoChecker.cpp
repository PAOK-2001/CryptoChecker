// In this file, the code for the actual tool will live
#include <bits/stdc++.h> 
#include<iostream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <json/json.h>
#include "SylizedCout.h"

constexpr int MAX_ARGUMENTS = 3;
using namespace std;

bool sortbysec(const pair<string,string> &a,
              const pair<string,string> &b){
    return (stof(a.second) > stof(b.second));
}

void sortOperation(vector<pair<string, string>> &cryptos){
    sort(cryptos.begin(), cryptos.end(), sortbysec);
}

curlpp::Cleanup cleanup;
Json::Value jsonData;
Json::Reader jsonReader;

vector<string> spliter(string rawQuery)
{
    vector<string> returnVec;
    stringstream rawString;
    rawString << rawQuery;
    while (rawString.good())
    {
        string coin;
        getline(rawString, coin, ',');
        returnVec.push_back(coin + "USDT");
    }
    return returnVec;
}

// API Queries
vector<pair<string, string>> get_price(vector<pair<string, string>>& returnVec, string search = " ")
{
    stringstream stringQuery;
    const string key = "https://api.binance.com/api/v3/ticker/price?symbol=";
    vector<string> defaultCryptos = {"BTCUSDT","ETHUSDT","BNBUSDT","BUSDUSDT","XRPUSDT","ADAUSDT","SOLUSDT"};
    if(search != " ")
    {
        defaultCryptos = spliter(search);
    }
    for(auto& crypto :defaultCryptos)
    {
        stringQuery<<curlpp::options::Url(key+crypto);
        jsonReader.parse(stringQuery, jsonData);
        returnVec.push_back(make_pair(crypto, jsonData["price"].asString()));
    }
    sortOperation(returnVec);
    return returnVec;
}
// Command functions
void help_command()
{
    cerr<<endl<<BOLD(GREEN("Welcome to Crypto Checker!!"))<<endl;
    cerr<<"-----------------------------\n"
    "The command scheme is as follows\n";
    cerr<<BOLD(BLUE("-h"))<<"    Print out help menu\n";
    cerr<<BOLD(BLUE("-t"))<<"    See 7 most popular cryptos in USD\n";
    cerr<<BOLD(BLUE("-s"))<<"    Search for a crypto or cryptos separates with commas and no space"<<endl<<endl;
}

void topCommand(){
    vector<pair<string, string>> defaultResult;
    get_price(defaultResult);
    cerr<<endl<<BOLD(BLUE("CRYPTO CURRENY"))<<BOLD(" | ")<<BOLD(BLUE("PRICE \n"));
    cerr<<BOLD("-----------------------\n");
    int i = 0;
    for(auto& result: defaultResult){
        if(i == 0)
        {
            cerr<<result.first<<BOLD("        | ")<<KGRN<<result.second<<RST<<endl;
        }else if(i==(defaultResult.size()-1)){
            cerr<<result.first<<BOLD("        | ")<<KRED<<result.second<<RST<<endl;
        }
        else{
            cerr<<result.first<<BOLD("        | ")<<result.second<<endl;
        }
        i++;
    }
    cerr<<endl;
}

void search_command(string search){
    vector<pair<string, string>> defaultResult;
    get_price(defaultResult, search);
    cerr<<endl<<BOLD(BLUE("CRYPTO CURRENY"))<<BOLD(" | ")<<BOLD(BLUE("PRICE \n"));
    cerr<<BOLD("-----------------------\n");
    for(auto& result: defaultResult){
        cerr<<result.first<<BOLD("        | ")<<result.second<<endl;
    }
    cerr<<endl;
}

int main(int argc, char*argv[]){
    string flagValue;
    //Parse flags
    switch (getopt(argc,argv,"hts:M:"))
    {
    case 'h':
        help_command();
        break;

    case 't':
        topCommand();
        break;

    case 's':
        flagValue = optarg;
        search_command(flagValue);
        break;
    
    default:
        help_command();
        break;
    }
}