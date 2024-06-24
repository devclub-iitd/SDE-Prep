# Dev Topic of the Day

## Understanding networking protocols and standards in OSI model - Part 1.

With reference to Day#17s topic "OSI Reference Model", Now we discuss the protocols and standards employed at different Layers of OSI Model.

- ### What is a Networking Protocol?
Networking protocols are standardized rules and conventions that dictate how devices communicate over a network. 
They define methods for data transmission, error detection, and message formatting, ensuring reliable and efficient exchange of information. 
Protocols operate at various layers of the OSI model, each handling specific aspects of the communication process. 
[Techopedia](https://www.techopedia.com/definition/24961/osi-protocols) has a nice article for an overview of OSI Protocols.   

You can also see the Major Classification of Protocols in this image...
![image](https://github.com/devclub-iitd/SDE-Prep/assets/119093736/bf26b627-baa7-47b8-aa63-84aa0929de1a)

- ### Key Protocols : 
Apart from the overview, we also discuss the key protocols of transport layer: 
1. TCP : TCP is widely used in internet communication to ensure reliable data transmission. It underpins major applications like web browsing (HTTP/HTTPS), email (SMTP, IMAP), and file transfers (FTP). By providing error checking, data integrity, and flow control, TCP guarantees that data is delivered accurately and in order.
[Techtarget](https://www.techtarget.com/searchnetworking/definition/TCP) has an excellent article about TCP Protocol (covering TCP vs UDP as well).
Also, some nice interview [TCP/IP](https://www.pynetlabs.com/tcp-ip-interview-questions-and-answers/) Questions.
3. UDP : UDP (User Datagram Protocol) is used for applications that require fast, efficient transmission, where occasional packet loss is acceptable. It's ideal for real-time services such as video streaming, online gaming, and VoIP (Voice over IP), as well as for DNS lookups and broadcast/multicast communications, due to its low-latency and connectionless nature.
Here is a nice read from [ComputerWeekly](https://www.computerweekly.com/de/definition/UDP-User-Datagram-Protocol)

We will be discussing in detail about other OSI protocols in the upcoming week... So, stay tuned...
