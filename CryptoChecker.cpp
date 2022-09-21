// In this file, the code for the actual tool will live
#include <bits/stdc++.h> 
#include<iostream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
constexpr int MAX_ARGUMENTS = 3;
using namespace std;
curlpp::Cleanup cleanup;

vector<pair<string, string>> get_price(vector<pair<string, string>>& returnVec)
{
    const string key = "https://api.binance.com/api/v3/ticker/price?symbol=";
    vector<string> defaultCryptos = {"BTCUSDT","ETHUSDT","BNBUSDT","BUSDUSDT","XRPUSDT","ADAUSDT","SOLUSDT"};
    for(auto& crypto :defaultCryptos)
    {
        cout<<curlpp::options::Url(key+crypto)<<"\n";
    }
    return returnVec;
}

void help_command()
{
    cerr<<"Welcome to Crypto Checker!!\n"
    "The command scheme is as follows\n"
    "---------------------------------\n"
    "-h    Print out help menu\n"
    "-C    Specify which crypto to check\n"   
    "  -C b  Check Bitcoin\n"
    "  -C e  Check Etherium\n"
    "  -C s  Check Solona\n";
}

int main(int argc, char*argv[]){
    vector<pair<string, string>> defaultResult;
    // Sanity check to determine if arguments passed are accepted
    if(argc > (MAX_ARGUMENTS+1))
    {
        cout<<"Too many parameters\n";
        return -1;
    }
    if(argc == 1)
    {
        get_price(defaultResult);
        return 0;
    }
    //Parse flags
    switch (getopt(argc,argv,"hC:M:"))
    {
    case 'h':
        help_command();
        break;
    
    default:
        get_price(defaultResult);
        break;
    }
}
