# About
Author: Y^w^L(Ye Li)

Organization: University of Macau

#Briefing
This repository is initially created for my possible TA workload. It relates to our familiar commandline tool curl[1] as well as its library -- libcurl[2].

If luckily someone else is viewing this page(or is forced to view it, e.g. you have enrolled Prof. U's course), please be noticed that I am also learning cURL from the scratches.

Let's hope we can have fun in it.

#Installation Guide
(Test on ubuntu 14.04 LTS)

'''sh
apt-get intall curl
'''

Finish the installation of command tool curl.

'''sh
apt-get install libcurl-dev
'''

Then you may encounter some problems. You may possibly be told that libcurl-dev is a virtual package provided by some other packages. Please choose one to install.

Here I pick libcurl4-openssl-dev.

'''sh
apt-get install libcurl4-openssl-dev
'''

#Compilation Guide
Whenever you compile your code, please tell the compiler to link the libary of curl.

Example compilation command: 

'''sh
g++ simple.cpp -lcurl
'''

#References
1. http://curl.haxx.se/
2. http://curl.haxx.se/libcurl/
