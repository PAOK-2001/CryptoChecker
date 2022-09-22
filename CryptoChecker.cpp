// In this file, the code for the actual tool will live
#include <bits/stdc++.h> 
#include<iostream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <json/json.h>

constexpr int MAX_ARGUMENTS = 3;
using namespace std;

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
    return returnVec;
}
// Command functions
void help_command()
{
    cerr<<"Welcome to Crypto Checker!!\n"
    "-----------------------------\n"
    "The command scheme is as follows\n"
    "-h    Print out help menu\n"
    "-t    See 7 most popular cryptos in USD\n"
    "-s    Search for a crypto or cryptos separates with commas and no space\n";
}

void topCommand(){
    vector<pair<string, string>> defaultResult;
    get_price(defaultResult);
    cerr<<"CRYPTO CURRENY | PRICE \n"
        "-----------------------\n";
    for(auto& result: defaultResult){
        cerr<<result.first<<"    | "<<result.second<<endl;
    }
}

void search_command(string search){
    vector<pair<string, string>> defaultResult;
    get_price(defaultResult, search);
     cerr<<"CRYPTO CURRENY | PRICE \n"
        "-----------------------\n";
    for(auto& result: defaultResult){
        cerr<<result.first<<"    | "<<result.second<<endl;
    }
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