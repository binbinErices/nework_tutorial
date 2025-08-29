# 网络编程

## 1.Linux网络编程API

1.1 open/close/bind/listen/accept/connect  
1.2 阻塞和非阻塞 同步与异步  
1.3 高级 socket 选项  
1.4 零拷贝技术(sendfile/mmap/splice)  
1.5 多线程与多进程模型：线程池、进程池结合网络IO  
1.6 信号与网络IO：signalfd/ppoll  

## 2.Windows网络编程

2.1 套接字接口  
2.2 WSAAsyncSelect/WSAEventSelect  
2.3 IOCP 深入（线程池调度、CompletionPort 内部机制）  
2.4 跨平台封装（如何用 #ifdef 或抽象层屏蔽差异  

## 3.网络编程模型

3.1 同步阻塞  
3.2 同步非阻塞（select/poll/epoll/iocp） 
3.3 异步io_uring  
3.4 reactor/proactor模式  
3.5 事件驱动架构（EDA）  
3.6 多线程与多进程模型  


## 4.主流网络库案例

4.1 boost.asio  
4.2 java netty(muduo)  
4.3 redis网络库  
4.4 libevent/libuv(跨平台事件库)  
4.5 nginx的事件驱动模型（master/worker + epoll + 连接池） 
4.6 quic协议栈（ngtcp2、quiche）新一代高性能传输协议  
4.7 RPC: C++ RPC框架工业实践  

## 5. 网络编程调试套件

5.1 wireshark使用  
5.2 tcpdump使用  
5.3 netstat/ss工具  
5.4 lsof工具  
5.5 mcjoin/nc工具  
5.6 iperf/iperf3  

## 6.从零到一实现一个高性能网络框架

6.1 目标：支持TCP协议、http协议、实现RPC通信 支持win/linux平台  
6.2 架构选型  
6.3 确定API接口，编码实现  
6.4 功能测试  
6.5 性能测试  