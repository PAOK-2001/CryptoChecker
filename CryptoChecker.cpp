// In this file, the code for the actual tool will live
#include <bits/stdc++.h> 
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
const int MAX_ARGUMENTS = 3;
using namespace std;
curlpp::Cleanup cleanup;
string key = "https://api.binance.com/api/v3/ticker/price?symbol=BTCUSDT";

void getPrice()
{
    cout<<curlpp::options::Url(key);
}

void helpCommand()
{
    fprintf(stderr,
    "Welcome to Crypto Checker!!\n"
    "The command scheme is as follows\n"
    "---------------------------------\n"
    "-h    Print out help menu\n"
    "-C    Specify which crypto to check\n"   
    "  -C b  Check Bitcoin\n"
    "  -C e  Check Etherium\n"
    "  -C s  Check Solona\n"

    );

}

int main(int argc, char*argv[]){
    // Sanity check to determine if arguments passed are accepted
    if(argc > (MAX_ARGUMENTS+1))
    {
        cout<<"Too many parameters\n";
        return -1;
    }

    if(argc == 1)
    {
        getPrice();
        return 0;
    }
    //Parse flags
    switch (getopt(argc,argv,"hC:M:"))
    {
    case 'h':
        helpCommand();
        break;
    
    default:
        getPrice();
        break;
    }

}
