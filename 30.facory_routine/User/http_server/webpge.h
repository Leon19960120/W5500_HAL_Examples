
/**
******************************************************************************
* @file   webpge.h
* @author  WIZnet Software Team
* @version V1.0
* @date    2015-xx-xx
* @brief web server content now
* @attention
******************************************************************************
**/
#ifndef __WEBPAGE_H
#define __WEBPAGE_H
#define INDEX_HTML "<!DOCTYPE html>"                                                                  \
                   "<html>"                                                                           \
                   "<head>"                                                                           \
                   "<meta http-equiv='Content-Type' content='text/html; charset=GB2312'/>"            \
                   "<title>WIZNET::�����</title>"                                           \
                   "<style>"                                                                          \
                   "::selection{background:red;color:#fff;}"                                          \
                   "::-moz-selection{background:red;color:#fff;}"                                     \
                   "::-webkit-selection{background:red;color:#fff;}"                                  \
                   "body,div,h1,h2,h3{margin: 0; padding: 0; border: 0;}"                             \
                   "body{background: #474747;text-align:center;}"                                     \
                   "#inset h1{"                                                                       \
                   "text-align: center;"                                                              \
                   "margin: 0px auto;"                                                                \
                   "font-family:'����','����';"                                       \
                   "font-size: 100px; text-transform: uppercase;"                                     \
                   "color: #222;"                                                                     \
                   "text-shadow: 0px 2px 3px #666;"                                                   \
                   "display:block;}"                                                                  \
                   "h1 a:link{text-decoration:none; background:red;color:#fff}"                       \
                   "h1 a:hover{color: #fff; text-shadow: 0px 5px 8px #2a2a2a; text-decoration:none;}" \
                   "h1 a:visited{color:#fff;}"                                                        \
                   "#inset{margin-top:150px;margin-right:auto;margin-left:auto;}"                     \
                   ".foot{margin-top:20px;font-size:10px;font-family:'arial';color:#222;}"            \
                   "</style>"                                                                         \
                   "</head>"                                                                          \
                   "<body>"                                                                           \
                   "<div id='inset'>"                                                                 \
                   "<h1><a href='dream.html' target='_blank'>dream</a></h1>"                          \
                   "<h1>still have to be had</h1>"                                                    \
                   "<h1><a href='config.html' target='_blank'>Just in case</a></h1>"                  \
                   "<h1>if it's implemented</h1>"                                                     \
                   "<h3 class='foot'>&copy;2016 WIZnet Shenzhen Team</h3>"                            \
                   "</div>"                                                                           \
                   "</body>"                                                                          \
                   "</html>"

#define DREAM_HTML "<!DOCTYPE html>"                                                                                                                                                                                                      \
                   "<html>"                                                                                                                                                                                                               \
                   "<head>"                                                                                                                                                                                                               \
                   "<title>W5500EVB::Routine download</title>"                                                                                                                                                                            \
                   "<style type='text/css'>"                                                                                                                                                                                              \
                   "div{float:left;margin:0 260px;}"                                                                                                                                                                                      \
                   "</style>"                                                                                                                                                                                                             \
                   "</head>"                                                                                                                                                                                                              \
                   "<body>"                                                                                                                                                                                                               \
                   "<div>"                                                                                                                                                                                                                \
                   "<table>"                                                                                                                                                                                                              \
                   "<table border='2'>"                                                                                                                                                                                                   \
                   "<caption>"                                                                                                                                                                                                            \
                   "<h1>WIZNET Routine download</h1>"                                                                                                                                                                                     \
                   "</caption>"                                                                                                                                                                                                           \
                   "<br></br>"                                                                                                                                                                                                            \
                   "<tr>"                                                                                                                                                                                                                 \
                   "<th>��������</th>"                                                                                                                                                                                    \
                   "<th>��&nbsp;&nbsp;��</th>"                                                                                                                                                                                    \
                   "<tr>"                                                                                                                                                                                                                 \
                   "<td><a href='http://www.w5500.com/download/code/w5500evb/1.Network Install/1.Network Install.zip' style='text-decoration:none'>&nbsp;&lt;1.Network Install&gt; </a></td>"                                             \
                   "<td>&nbsp;�����ʼ�����ã�����ͨ�������Ping W5500EVB���в���</td>"                                                                                             \
                   "</tr>"                                                                                                                                                                                                                \
                   "<tr>"                                                                                                                                                                                                                 \
                   "<td><a href='http://www.w5500.com/download/code/w5500evb/2.TCPS/2.TCPS.zip' style='text-decoration:none'>&nbsp;&lt;2.TCP Server&gt; </a></td>"                                                                        \
                   "<td>&nbsp;W5500EVB��ΪTCP��������ͬԶ���豸TCP�ͻ��˽���ͨ��</td>"                                                                                                          \
                   "</tr>"                                                                                                                                                                                                                \
                   "<tr>"                                                                                                                                                                                                                 \
                   "<td><a href='http://www.w5500.com/download/code/w5500evb/3.TCPC/3.TCPC.zip' style='text-decoration:none'>&nbsp;&lt;3.TCP Client&gt; </a></td>"                                                                        \
                   "<td>&nbsp;W5500EVB��ΪTCP�ͻ��ˣ�ͬԶ���豸TCP����������ͨ��</td>"                                                                                                          \
                   "</tr>"                                                                                                                                                                                                                \
                   "<tr>"                                                                                                                                                                                                                 \
                   "<td><a href='http://www.w5500.com/download/code/w5500evb/4.UDP/4.UDP.zip' style='text-decoration:none'>&nbsp;&lt;4.UDP&gt; </a></td>"                                                                                 \
                   "<td>&nbsp;W5500EVBͬԶ���豸֮��ͨ��UDPЭ����/������</td>"                                                                                                                          \
                   "</tr>"                                                                                                                                                                                                                \
                   "<tr>"                                                                                                                                                                                                                 \
                   "<td><a href='http://www.w5500.com/download/code/w5500evb/5.DHCP/5.DHCP.zip' style='text-decoration:none'>&nbsp;&lt;5.DHCP&gt; </a></td>"                                                                              \
                   "<td>&nbsp;W5500EVB��·����ͨ��DHCP��ʽ��ȡIP</td>"                                                                                                                                            \
                   "</tr>"                                                                                                                                                                                                                \
                   "<td><a href='http://www.w5500.com/download/code/w5500evb/6.DNS/6.DNS.zip' style='text-decoration:none'>&nbsp;&lt;6.DNS&gt; </a></td>"                                                                                 \
                   "<td>&nbsp;W5500EVBͨ��DNS������ϵͳ�����û��������������Ϊ��Ӧ��IP��ַ</td>"                                                                        \
                   "</tr>"                                                                                                                                                                                                                \
                   "<tr>"                                                                                                                                                                                                                 \
                   "<td><a href='http://www.w5500.com/download/code/w5500evb/7.HTTPS/7.HTTPS.zip' style='text-decoration:none'>&nbsp;&lt;7.HTTP Server&gt; </a></td>"                                                                     \
                   "<td>&nbsp;W5500EVB��ΪHTTP���������û�����ͨ����ҳ��W5500EVB��������</td>"                                                                                \
                   "</tr>"                                                                                                                                                                                                                \
                   "<tr>"                                                                                                                                                                                                                 \
                   "<td><a href='http://www.w5500.com/download/code/w5500evb/8.HTTPC/8.HTTPC.zip' style='text-decoration:none'>&nbsp;&lt;8.HTTP Client&gt; </a></td>"                                                                     \
                   "<td>&nbsp;W5500EVB��ΪHTTP�ͻ��ˣ���Yeelink��ƽ̨�ύ�ɼ���������</td>"                                                                                                     \
                   "</tr>"                                                                                                                                                                                                                \
                   "<tr>"                                                                                                                                                                                                                 \
                   "<td><a href='http://www.w5500.com/download/code/w5500evb/9.NTP/9.NTP.zip' style='text-decoration:none'>&nbsp;&lt;9.NTP&gt; </a></td>"                                                                                 \
                   "<td>&nbsp;W5500EVB�������ϻ�ȡ��׼ʱ��</td>"                                                                                                                                                  \
                   "</tr>"                                                                                                                                                                                                                \
                   "<tr>"                                                                                                                                                                                                                 \
                   "<td><a href='http://www.w5500.com/download/code/w5500evb/10.SMTP/10.SMTP.zip' style='text-decoration:none'>&nbsp;&lt;10.SMTP&gt; </a></td>"                                                                           \
                   "<td>&nbsp;W5500EVB���û�ָ�������䷢���ʼ�</td>"                                                                                                                                        \
                   "</tr>"                                                                                                                                                                                                                \
                   "<tr>"                                                                                                                                                                                                                 \
                   "<td><a href='http://www.w5500.com/download/code/w5500evb/11.Weibo/11.Weibo.zip' style='text-decoration:none'>&nbsp;&lt;11.Weibo&gt; </a></td>"                                                                        \
                   "<td>&nbsp;W5500EVBʵ�ַ�΢�����ܣ�Ŀǰ΢�����������ϣ������̽����ο���</td>"                                                                          \
                   "</tr>"                                                                                                                                                                                                                \
                   "<tr>"                                                                                                                                                                                                                 \
                   "<td><a href='http://www.w5500.com/download/code/w5500evb/12.NetBIOS/12.NetBIOS.zip' style='text-decoration:none'>&nbsp;&lt;12.NetBIOS&gt; </a></td>"                                                                  \
                   "<td>&nbsp;NetBIOSЭ����ʾ���û�������������롰W5500EVB�����ɵ�¼������ҳ����&nbsp;&nbsp;&nbsp;</td>"                                          \
                   "</tr>"                                                                                                                                                                                                                \
                   "<tr>"                                                                                                                                                                                                                 \
                   "<td><a href='http://www.w5500.com/download/code/w5500evb/13.UPnP/13.UPnP.zip' style='text-decoration:none'>&nbsp;&lt;13.UPnP&gt; </a></td>"                                                                           \
                   "<td>&nbsp;UPnPЭ����ʾ</td>"                                                                                                                                                                                  \
                   "</tr>"                                                                                                                                                                                                                \
                   "<tr>"                                                                                                                                                                                                                 \
                   "<td><a href='http://www.w5500.com/download/code/w5500evb/14.TFTPC/14.TFTPC.zip' style='text-decoration:none'>&nbsp;&lt;14.TFTP Client&gt; </a></td>"                                                                  \
                   "<td>&nbsp;TFTPЭ����ʾ��W5500EVBͬ�����֮������ļ�����</td>"                                                                                                              \
                   "</tr>"                                                                                                                                                                                                                \
                   "<tr>"                                                                                                                                                                                                                 \
                   "<td><a href='http://www.w5500.com/download/code/w5500evb/15.SNMP/15.SNMP.zip' style='text-decoration:none'>&nbsp;&lt;15.SNMP&gt; </a></td>"                                                                           \
                   "<td>&nbsp;SNMPЭ��V1�汾��ʾ</td>"                                                                                                                                                                          \
                   "</tr>"                                                                                                                                                                                                                \
                   "<tr>"                                                                                                                                                                                                                 \
                   "<td><a href='http://www.w5500.com/download/code/w5500evb/16.Ping/16.Ping.zip' style='text-decoration:none'>&nbsp;&lt;16.Ping&gt; </a></td>"                                                                           \
                   "<td>&nbsp;Ping������ʾ��W5500EVB Ping�����</td>"                                                                                                                                            \
                   "</tr>"                                                                                                                                                                                                                \
                   "<tr>"                                                                                                                                                                                                                 \
                   "<td><a href='http://www.w5500.com/download/code/w5500evb/W5500EVB N��1����/W5500EVB N��1����.zip' style='text-decoration:none'>&nbsp;&lt;17.W5500EVB N��1����&gt;&nbsp;</a></td>" \
                   "<td>&nbsp;��������������Ϊ1�������̣������û�����</td>"                                                                                               \
                   "</tr>"                                                                                                                                                                                                                \
                   "<tr>"                                                                                                                                                                                                                 \
                   "<td><a href='http://www.w5500.com/download/code/w5500evb/W5500EVB���̣�ȫ��/W5500EVB����(ȫ).zip' style='text-decoration:none'>&nbsp;&lt;18.W5500EVB����(ȫ)&gt; </a></td>"               \
                   "<td>&nbsp;������17�����̴������</td>"                                                                                                                                               \
                   "</tr>"                                                                                                                                                                                                                \
                   "</table>"                                                                                                                                                                                                             \
                   "<br></br>"                                                                                                                                                                                                            \
                   "<div align='center'>&copy; 2016 WIZnet Shenzhen Team"                                                                                                                                                                 \
                   "<br></br>"                                                                                                                                                                                                            \
                   "</div>"                                                                                                                                                                                                               \
                   "</body>"                                                                                                                                                                                                              \
                   "</html>"

#define CONFIG_HTML "<!DOCTYPE html>"                                                                                                                   \
                    "<html>"                                                                                                                            \
                    "<head>"                                                                                                                            \
                    "<title>W5500EVB::��ҳ����</title>"                                                                                     \
                    "<meta http-equiv='Content-Type' content='text/html; charset=GB2312'/>"                                                             \
                    "<style type='text/css'>"                                                                                                           \
                    "body {text-align:left; background-color:#c0deed;font-family:Verdana;}"                                                             \
                    "#main {margin-right:auto;margin-left:auto;margin-top:30px;}"                                                                       \
                    "label{display:inline-block;width:150px;}"                                                                                          \
                    "#main h3{color:#66b3ff; text-decoration:underline;}"                                                                               \
                    "</style>"                                                                                                                          \
                    "<script>"                                                                                                                          \
                    "function $(id) { return document.getElementById(id); };"                                                                           \
                    "function settingsCallback(o) {"                                                                                                    \
                    "if ($('txtVer')) $('txtVer').value = o.ver;"                                                                                       \
                    "if ($('txtMac')) $('txtMac').value = o.mac;"                                                                                       \
                    "if ($('txtIp')) $('txtIp').value = o.ip;"                                                                                          \
                    "if ($('txtSub')) $('txtSub').value = o.sub;"                                                                                       \
                    "if ($('txtGw')) $('txtGw').value = o.gw;"                                                                                          \
                    "};"                                                                                                                                \
                    "</script>"                                                                                                                         \
                    "</head>"                                                                                                                           \
                    "<body>"                                                                                                                            \
                    "<div id='main'>"                                                                                                                   \
                    "<div style='background:snow; display:block;padding:10px 20px;'>"                                                                   \
                    "<h3>�����������</h3>"                                                                                        \
                    "<form id='frmSetting' method='POST' action='config.cgi'>"                                                                          \
                    "<p><label for='txtIp'>�̼��汾��:</label><input type='text' id='txtVer' name='ver' size='16' disabled='disabled' /></p>" \
                    "<p><label for='txtIp'>MAC��ַ:</label><input type='text' id='txtMac' name='mac' size='16' disabled='disabled' /></p>"          \
                    "<p><label for='txtIp'>IP��ַ:</label><input type='text' id='txtIp' name='ip' size='16' /></p>"                                 \
                    "<p><label for='txtSub'>��������:</label><input type='text' id='txtSub' name='sub' size='16' /></p>"                \
                    "<p><label for='txtGw'>Ĭ������:</label><input type='text' id='txtGw' name='gw' size='16' /></p>"                       \
                    "<p><input type='submit' value='���沢����' /></p>"                                                                   \
                    "</form>"                                                                                                                           \
                    "</div>"                                                                                                                            \
                    "</div>"                                                                                                                            \
                    "<div style='margin:5px 5px;'>"                                                                                                     \
                    "&copy; 2016 WIZnet Shenzhen Team"                                                                                                  \
                    "</div>"                                                                                                                            \
                    "<script type='text/javascript' src='w5500.js'></script>"                                                                           \
                    "</body>"                                                                                                                           \
                    "</html>"

#endif
