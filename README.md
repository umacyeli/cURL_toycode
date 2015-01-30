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

```sh
apt-get install curl
```

Finish the installation of command tool curl.

```sh
apt-get install libcurl-dev
```

Then you may encounter some problems. You may possibly be told that libcurl-dev is a virtual package provided by some other packages. Please choose one to install.

Here I pick libcurl4-openssl-dev.

```sh
apt-get install libcurl4-openssl-dev
```

#Compilation Guide
Whenever you compile your code, please tell the compiler to link the libary of curl.

Example compilation command: 

```sh
g++ simple.cpp -lcurl
```

For othor examples, we may need to include additional libraries. Here two examples htmltitle.html[4] and htmltidy.html[5] are introduced. For these two example, htmltile.html utilizes libxml2 while htmltidy utilizes libtidy. In order to compile these two codes, these libraries should be installed. For libxml2, the following command can be used in ubuntu:

```sh
apt-get install libxml2
apt-get install libxml2-dev
```

From the beginning of source code in htmltitle.html, the authors kindly provide the command to compile this source code:

```sh
g++ -Wall -I/opt/curl/include -I/opt/libxml/include/libxml2 htmltitle.cpp -o htmltitle -L/opt/curl/lib -L/opt/libxml/lib -lcurl -lxml2
```

But the paths of libraries vary from machines, you can check the path on your own machine by:

```sh
dpkg --listfiles libxml2
dpkg --listfiles curl
```

Revising the compiling command accordingly, the following command works perfectly on my machine:

```sh
g++ -Wall -I/usr/include/curl -I/usr/include/libxml2 htmltitle.cpp -o htmltitle -L /usr/lib/x86_64-linux-gnu -lcurl -lxml2
```

After then we have a executable binary file htmltile in the same path which accepts one arguement of a url path

```sh
Usage: ./htmltitle <url>
```

Executing with a url as the argument, this program will parse the html associated to the url path and return the title:

```sh
./htmltitle www.umac.mo
Title: University of Macau | The only public comprehensive university in Macao
```

Followings are commands to compile the other example.


```sh
apt-get install tidy
apt-get install libtidy-dev
```

```sh
gcc -Wall -I/usr/include/curl -I/usr/include/tidy htmltidy.c -L/usr/lib/x86_64-linux-gnu -lcurl -ltidy -o tidycurl
```


#References
1. http://curl.haxx.se/
2. http://curl.haxx.se/libcurl/
3. http://baiqiuyi.com/linux/curl.html
4. http://curl.haxx.se/libcurl/c/htmltitle.html
5. http://curl.haxx.se/libcurl/c/htmltidy.html
