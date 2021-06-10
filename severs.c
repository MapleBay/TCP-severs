/*
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 * 
 * 
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *            佛祖保佑       永不宕机     永无BUG
 * 
 * @Author: Bei gen feng
 * @Date: 2021-06-10 11:22:51
 * @LastEditTime: 2021-06-10 11:22:51
 * @LastEditors: Bei gen feng
 * @Description: 
 * @FilePath: /TCP/severs.c
 * 
 */

#include "./include.c"

void mian()
{
  //1 创建TCP通信socket
  int tcp_socket_fd = socket(AF_INET, SOCK_STREAM, 0); //AF_INET:标识IPv4协议，IPv6是AF_INET6；SOCK_STREAM标识是TCP协议，UDP是SOCK_DGRAM;0表示默认

  //2 绑定IP地址
  struct sockaddr_in local_addr = {0};
  local_addr.sin_family = AF_INET;         //使用IPv4
  local_addr.sin_port = htons(port);       //port是端口号，网络传输使用大端字节序，使用htons()进行转换。端口是int类型，范围0~65535
  local_addr.sin_addr.s_addr = INADDR_ANY; //自动检测本地网卡设备并绑定IP

  bind(tcp_socket_fd, (struct sockaddr *)&local_addr, sizeof(local_addr)); //绑定socket的IP地址

  // 3 设置监听队列(最多可以连接多少个客户端)
  listen(tcp_socket_fd, 5);

  //4 等待，接受客户端的链接
  struct sockaddr_in client_addr = {0};                                      //用来存放客户端的地址信息
  int len = sizeof(client_addr);                                             //地址信息长度
  int new_socket = 0;                                                        //与客户端通信的socket
  new_socket = accept(tcp_socket_fd, (struct sockaddr *)&client_addr, &len); //阻塞，等待客户端的连接

  //5 关闭通信socket
  close(new_socket);
  close(tcp_socket_fd);
}