/*************************************************************************
	> File Name: datatype.h
	> Author: 
	> Mail: 
	> Created Time: 2020年06月09日 星期二 21时49分00秒
 ************************************************************************/

#ifndef _DATATYPE_H
#define _DATATYPE_H
#define MAXMSG 1024
struct LogRequest{
    char name[20];
    int team;//0 RED 1 BLUE
    char msg[512];
};

struct LogResponse{
    int type;
    char msg[512];
};

struct Point{
    int x, y;
};

struct User{
    int team; //0  1
    int fd;
    char name[20];
    int flag; //三次没有响应
    int online;
    struct Point loc;//目前所在位置
};
struct Map {
    int width;
    int height;
    struct Point start;//区域大小
    int gate_width;//球门
    int gate_height;
};

struct Ctrl{
    int carry;//带球
    int kick;//踢球
};

struct TransMsg{//客户端只负责控制，服务端负责计算
    int dirx, diry;//方向
    struct Ctrl ctrl;
};


#define FT_TEST 0x01
#define FT_WALL 0x02
#define FT_MSG  0x04
#define FT_ACK  0x08
#define FT_FIN  0x10

struct FootBallMsg{
    int type;
    char name[20];
    int team;
    int size;
    char msg[MAXMSG];
};

#endif
