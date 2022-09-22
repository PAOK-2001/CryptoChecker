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

// API Queries
vector<pair<string, string>> get_price(vector<pair<string, string>>& returnVec, string search = " ")
{
    stringstream stringQuery;
    const string key = "https://api.binance.com/api/v3/ticker/price?symbol=";
    vector<string> defaultCryptos = {"BTCUSDT","ETHUSDT","BNBUSDT","BUSDUSDT","XRPUSDT","ADAUSDT","SOLUSDT"};
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
    "-T    See 7 most popular cryptos in USD"
    "-C    Specify which crypto to check\n"   
    "  -C b  Check Bitcoin\n"
    "  -C e  Check Etherium\n"
    "  -C s  Check Solona\n";
}

void topCommand(){
    vector<pair<string, string>> defaultResult;
    cerr<<"CRYPTO CURRENY | PRICE \n"
        "-----------------------\n";
    get_price(defaultResult);
    for(auto& result: defaultResult){
        cerr<<result.first<<"    | "<<result.second<<endl;
    }
}

void searchCommand(){
    
}

int main(int argc, char*argv[]){
    string flagValue;
    //Parse flags
    switch (getopt(argc,argv,"hTC:M:"))
    {
    case 'h':
        help_command();
        break;
    case 'T':
        topCommand();
        break;
    case 'C':
        flagValue = optarg;
        if(flagValue == "b")
        {
            cout<<"Checks Bitcoint"<<endl;
        }
        if(flagValue == "e")
        {
            cout<<"Checks Etherium"<<endl;
        }
        if(flagValue == "s")
        {
            cout<<"Checks Solona"<<endl;
        }
        break;
    
    default:
        help_command();
        break;
    }
}
