###OSI五层模型

* 应用层(HTTP，HTTPS，FTP，TELNET，SSH，SMTP，POP3等)
* 传输层(TCP/UDP等)
* 网络层(IP,ICMP等)
* 链路层(WI-FI，PPPoE,ARP等)
* 物理层(双绞线等)

###TCP

####主要介绍

* 传输控制协议（英语：Transmission Control Protocol，缩写为 TCP）是一种面向连接的、可靠的、基于字节流的传输层通信协议，由IETF的RFC 793定义。在简化的计算机网络OSI模型中，它完成第四层传输层所指定的功能

* TCP三次握手

	* 客户端向服务器发送SYN 
	* 服务器向客户端发送SYN/ACK 
	* 客户端想服务器发送ACK

* TCP四次挥手(可以由客户端或服务器首先发出)
 
	* 客户端向服务器发送FIN
	* 服务器向客户端发送ACK
	* 服务器向客户端发送FIN
	* 客户端向服务器发送ACK,并等待2MSL后关闭
	
* TCP连接状态图

![](http://i.imgur.com/aI6ATrk.jpg)

* 为什么要三次握手，不是两次或四次
	* 如果是两次的话会发生这种情况，已失效的连接请求报文段”的产生在这样一种情况下：client发出的第一个连接请求报文段并没有丢失，而是在某个网络结点长时间的滞留了，以致延误到连接释放以后的某个时间才到达server。本来这是一个早已失效的报文段。但server收到此失效的连接请求报文段后，就误认为是client再次发出的一个新的连接请求。于是就向client发出确认报文段，同意建立连接。假设不采用“三次握手”，那么只要server发出确认，新的连接就建立了。由于现在client并没有发出建立连接的请求，因此不会理睬server的确认，也不会向server发送数据。但server却以为新的运输连接已经建立，并一直等待client发来数据。(A想和异地恋的B结婚，就写了一封信，但这封信寄了两年才寄到，B收到了给A发送请求同意结婚，但A收到时已经移情别恋并把这封信丢弃，B一直等待孤独终老。。。)
	* 发三次已经保证了可靠传输，四次比较多余。
	
* 为什么挥手要四次，而不是三次或两次
	* 为当Server端收到Client端的SYN连接请求报文后，可以直接发送SYN+ACK报文。其中ACK报文是用来应答的，SYN报文是用来同步的。但是关闭连接时，当Server端收到FIN报文时，很可能并不会立即关闭SOCKET，所以只能先回复一个ACK报文，告诉Client端，"你发的FIN报文我收到了"。只有等到我Server端所有的报文都发送完了，我才能发送FIN报文，因此不能一起发送。故需要四步握手。


###UDP

####主要介绍

* 用户数据报协议（英语：User Datagram Protocol，缩写为UDP），又称用户数据报文协议，是一个简单的面向数据报的传输层协议，正式规范为RFC 768。
* 它只是IP协议暴露在传输层上的接口。它的传输方式也是"Best Effort"的，所以UDP协议也是不可靠的(unreliable)。那么，我们为什么不直接使用IP协议而要额外增加一个UDP协议呢？ 一个重要的原因是IP协议中并没有端口(port)的概念。

####常见协议

* 运行在TCP协议上的协议：
	* HTTP（Hypertext Transfer Protocol，超文本传输协议），主要用于普通浏览。
	* HTTPS（Hypertext Transfer Protocol over Secure Socket Layer, or HTTP over SSL，安全超文本传输协议）,HTTP协议的安全版本。
	* FTP（File Transfer Protocol，文件传输协议），由名知义，用于文件传输。
	* POP3（Post Office Protocol, version 3，邮局协议），收邮件用。
	* SMTP（Simple Mail Transfer Protocol，简单邮件传输协议），用来发送电子邮件。
	* TELNET（Teletype over the Network，网络电传），通过一个终端（terminal）登陆到网络。
	* SSH（Secure Shell，用于替代安全性差的TELNET），用于加密安全登陆用。
* 运行在UDP协议上的协议：
	* BOOTP（Boot Protocol，启动协议），应用于无盘设备。
	* NTP（Network Time Protocol，网络时间协议），用于网络同步。
	* DHCP（Dynamic Host Configuration Protocol，动态主机配置协议），动态配置IP地址。
* 其他：
	* DNS（Domain Name Service，域名服务），用于完成地址查找，邮件转发等工作（运行在TCP和UDP协议上）。
	* ECHO（Echo Protocol，回绕协议），用于查错及测量应答时间（运行在TCP和UDP协议上）。
	* SNMP（Simple Network Management Protocol，简单网络管理协议），用于网络信息的收集和网络管理。
	* ARP（Address Resolution Protocol，地址解析协议），用于动态解析以太网硬件的地址

##参考资料

* [协议森林](http://www.cnblogs.com/vamei/archive/2012/12/05/2802811.html)
* [编程起跑线 第 12 课 ](http://wdxtub.com/2016/01/23/programmer-startline-12/)
* [TCP为什么是三次握手，为什么不是两次或四次？](https://www.zhihu.com/question/24853633/answer/63668444)
* [TCP协议中的三次握手和四次挥手(图解)](http://blog.csdn.net/whuslei/article/details/6667471/)
