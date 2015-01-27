# About
Author: Y^w^L(Ye Li)

Organization: University of Macau

Contact: umacyeli@gmail.com

#Briefing
This repository is initially created for my possible TA workload. It relates to our familiar commandline tool curl[1] as well as its library -- libcurl[2].

If luckily someone else is viewing this page(or is forced to view it, e.g. you have enrolled Prof. U's course), please be noticed that I am also learning cURL from the scratches.

If you are not familiar with curl, you are suggested to visit [1][2] for further information from the contributors. Reading document is both useful and full of fun. If you understand simplified Chinese, [3] is a good resource for you to quickly grasp the ideas of curl which can lead you to easily write a shell script of a web crawler. 

Let's hope we can have fun in it.

#Installation Guide
(Test on ubuntu 14.04 LTS)

```shell
apt-get intall curl
```

Finish the installation of command tool curl.

```shell
apt-get install libcurl-dev
```

Then you may encounter some problems. You may possibly be told that libcurl-dev is a virtual package provided by some other packages. Please choose one to install.

Here I pick libcurl4-openssl-dev.

```shell
apt-get install libcurl4-openssl-dev
```

#Compilation Guide
Whenever you compile your code, please tell the compiler to link the libary of curl.

Example compilation command: 

```shell
g++ simple.cpp -lcurl
```

#References
1. http://curl.haxx.se/
2. http://curl.haxx.se/libcurl/
3. http://baiqiuyi.com/linux/curl.html
