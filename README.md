## QtBtcExplorer

This is a small api wrapper to communicate with bitcoin blockchain explorer running [btc-rpc-explorer](https://github.com/janoside/btc-rpc-explorer).
This wrapper is written on c++ using Qt. Tested using Qt 5.15.8.

For additional information you can check:
- [btc-rpc-explorer github](https://github.com/janoside/btc-rpc-explorer)
- [Bitcoin explorer API documentation](https://bitcoinexplorer.org/api/docs)
- [Running example of server](https://bitcoinexplorer.org/)

Current version: 0.0.1

## Adding QtBtcExplorer to yout project

Download QtEtherscan from github
```bash
mkdir lib && cd lib
git clone https://github.com/ivan-odinets/QtBtcExplorer.git
```
Alternatively you can add QtBtcExplorer as a git submodule:
```bash
mkdir lib && cd lib
git submodule add https://github.com/ivan-odinets/QtBtcExplorer.git
```
In your project file (*project*.pro) add this include:
```qmake
include($$PWD/lib/QtBtcExplorer/QtBtcExplorer.pri)
```
Somewhere in your code add this include:
```cpp
#include "QtBtcExplorer.h"
```
And than you can use etherscan.io api methods in the following manner:
```cpp
QtBtcExplorer::API btcExplorer;                       // Create QtBtcExplorer::API object
explorer.setApiHost("https://bitcoinexplorer.org");   // Set API server hostname. By default https://bitcoinexplorer.org 
                                                      // will be used
QtBtcExplorer::Address addres = explorer.getAddress("1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa");    // Call API method
qDebug() << addres;     // Handle results
```

## Examples & Documentation

Examples can be found in the "examples" folder

Documentation can be generated in the docs folder using doxygen
```bash
doxygen Doxyfile
```

## Donations

Donations are optional, but highly appriciated. So if you like this software and you want to say thanks - feel free to send any amount of crypto to one of the addresses below:
- BTC - bc1qc8nj8swjxtu0fpfsxspv2k49np56u8h86mgy0e
- ETH - 0x903Fd8C2cE645cB6B6F38e7465728c49170d5530
- USDT (ETH Network) - 0x903Fd8C2cE645cB6B6F38e7465728c49170d5530
- XMR - 893ipCFWQXjhXAyMXaryu4RofqZQzpH1nBZDsN9nA6c5BwK79Ae48Ci4rtRoyTi5nAHrpTqbVMPDkXgnHswha2a5F2y62mG

## License
[GNU Lesser General Public License v3.0](https://choosealicense.com/licenses/lgpl-3.0/)
