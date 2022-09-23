# Crypto Checker: CLI Tool
## Instalation
To use this tool, clone this repository and navigate to it on terminal. Run the installer script (you might need to change the file permissions using chmod), taking note to change the <em>dir</em> variable with the direction of your PATH folder. Running the instaler will compile the tool and add the binary to path, making the **CryptoChecker** command globally accesible.

```console
[paok@fedora ~]$ cd Documents/CryptoChecker/
[paok@fedora CryptoChecker]$ ./installer.sh 
[sudo] password for paok: 
[paok@fedora CryptoChecker]$ CryptoChecker 

Welcome to Crypto Checker!!
-----------------------------
The command scheme is as follows
-h| --help      Print out help menu
-t| --top       See 7 most popular cryptos in USD
-s| --search    Search for a one or multiple cryptos separated with commas and no space. Specify the  abreviation ie. BTC
-c| --customcurreny See the top cryptos in a specified currency, specified after flag. Specify abreviation ie. MXN

```

## Inspiration
We wanted to provide a quick and easy way to access cryptocurrency price information, locate the top of the most popular ones as well as be able to access individual information on each of them or a desired list.

## What it does
Our tool allows you to check the prices of cryptocurrencies directly from the terminal. Also, it allows users to add flags and customize the query result in a dynamic and easy way.

## How we built it
To implement this tool we used the C++ programming language, which allowed us to connect with an API and access the real prices of cryptocurrencies at the time.

## Challenges we ran into
Making API requests with C++ isn't as trivial as other languages so we spent some time thinking about the idea and investigating the use of certain libraries that allowed us to connect to the API and use the information collected.

## Accomplishments that we're proud of
Something we prioritized for this project was making an integrated and easy to use solution. Developing the bash script to install the command line tool was something that we really liked, because even thought it was a small feature, it adds to the usability to the tool.

Another thing that stands out is the clean implementation of the API request. Instead of making redundant functions to change the query parameters, we were able to make one reusable function.
## What we learned
We refreshed our experience with C++, we learned about several ideas to create projects with this language. Also, the connection with the API, its different functions and in general about the use of the terminal and its flags.

## What's next for CryptoChecker: CLI
Some of the next steps would be to show the price information in a more graphic way, add more flags of different functionalities. As well as, having the ability to show even more cryptocurrencies in the market and not just the most popular of the moment.


[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)