# W5500_HAL_Examples

#### 介绍
​	W5500是一款高性价比的以太网芯片，其全球独一无二的全硬件TCPIP协议栈专利技术，解决了嵌入式以太网的接入问题，简单易用，安全稳定，是物联网设备的首选解决方案。WIZnet提供完善的配套资料以及实时周到的技术支持服务，极大地缩短产品开发周期，全方位保障客户项目按时落地。

​	例程使用STM32F103VCT6+HAL库进行驱动，涵盖了大部分以太网协议在W5500上的使用。

#### 例程说明
1.Network_install：标准驱动例程

2.DHCP：通过DHCP方式从服务器获取网络配置信息

3.TCP Client：以TCP客户端的方式和服务器进行数据回环测试

4.TCP Server：作为TCP服务器，回环客户端发来的数据

5.UDP：以UDP方式回环接收到的数据

6.UDP_Multicast：以UDP组播方式进行通信

7.DNS：通过DNS解析wiznet.io的IP地址

8.HTTP Client：HTTP发起请求示例

9.HTTP_Server：作为HTTP服务器，处理客户端请求

10.SNTP：获取网络时间

11.SMTP：通过SMTP协议快速发送邮件

12.NetBIOS：通过NetBIOS协议，让其他用户可以以类似域名的格式发起ping请求

13.UPnP：通过UPnP协议快速控制设备

14.TFTP：以客户端身份连接TFTP服务器下载文件

15.SNMP：通过SNMP协议管理网络设备

16.PING：IPRAW模式ping设备

17.ARP：硬件ARP示例

18.FTP_Server：FTP服务器模式示例，其他设备可以通过访问服务器下载文件

19.FTP_Client：FTP客户端模式示例，可以访问FTP服务器下载文件

20.WOL：通过网络唤醒设备

21.Low_Power：软件控制PHY模式

22.MQTT&Aliyun：通过MQTT协议连接阿里云平台并实现数据交互

23.MQTT_OneNET：通过MQTT协议连接OneNET平台并实现数据交互

24.TCP_Client_Multi_socket：开启全部socket连接TCP服务器

25.TCP_Server_Multi_socket：作为TCP服务器，允许多个设备连接进行数据通信

26.Upper_computer_search_and_config：通过上位机修改配置

27.interrupt：中断回环数据示例

28.velocity_measurement：以太网测速示例

29.Modbus_TCP_Server：Modbus TCP示例

30.facory_routine：DHCP+HTTP Server+NetBIOS示例


#### 例程目录介绍

├─Core                                                                                                                  
│  ├─Inc                                                         头文件目录                                                       
│  └─Src                                                         源文件目录                                                       
├─Drivers                                                      设备驱动目录                                           
├─MDK-ARM                                                 Keil工程目录                                                              
│  ├─Project                                                  生成目录                                                          
└─User                                                          用户文件夹                                                       
    ├─ioLibrary_Driver                                  以太网驱动库                                                                           
    ├─user_main                                            用户主程序                                                             
    ├─wiz_interface                                        以太网接口                                                             
    └─wiz_platform                                        硬件平台适配以太网目录 

#### 移植说明

1.  将User目录全部添加至工程中，硬件初始化之后调用user_main文件中的user_run程序
2.  适配wiz_platform.c文件中的相关接口
3.  测试验证

#### 问题排查

1.  确认SPI读写是否正确，能否正常读取到芯片版本
2.  确认PHY状态是否正常
3.  查看设置网络地址以及回读网络地址是否一致
4.  在同一个网络环境中，ping芯片看能否ping通（无法ping通请关闭防火墙以及排查是否存在地址冲突情况（静态配置网络信息））
5.  应用协议不通建议先本地确认环境搭建正常，再跑例程测试


#### 技术支持

1.  邮箱：support_wiznet@126.com
2.  微信：support_wiznet

#### 相关资料

官网：wiznet.io

github:[WIZnet (github.com)](https://github.com/Wiznet/)

gitee:[WIZnet HK (wiznet-hk) - Gitee.com](https://gitee.com/wiznet-hk)

CSDN：https://blog.csdn.net/WIZnet2012

哔哩哔哩：[WIZnet_HK的个人空间-WIZnet_HK个人主页-哔哩哔哩视频 (bilibili.com)](https://space.bilibili.com/3493140098976365)