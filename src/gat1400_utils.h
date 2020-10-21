/**
 * @File     gat1400-utils.h
 * @brief
 * @DateTime 2018/8/1 12:06:15
 * @Author   Nanuns
 */
#ifndef __GAT1400_UTILS_H_
#define __GAT1400_UTILS_H_

#include <stdint.h>
#include <stdio.h>
#include <string>

using namespace std;

#if defined(WIN32)

//#define WIN32_LEAN_AND_MEAN
#include <time.h>
#include <sys/timeb.h>
#include <windows.h>

static int gettimeofday(struct timeval *tp, void *tz)
{
    struct _timeb timebuffer;

    _ftime(&timebuffer);
    tp->tv_sec = (long)timebuffer.time;
    tp->tv_usec = timebuffer.millitm * 1000;
    return 0;
}
#else
#include <sys/time.h>
#endif

// https://blog.csdn.net/qiuchangyong/article/details/68945482
// http://blog.csdn.net/linyt/article/details/52728910 聊聊Linux2038年问题
// http ://wuzhiwei.net/one_overflow_issue/ 取毫秒的溢出问题
inline static int64_t gettime_ms() {
    struct timeval now;
    gettimeofday(&now, 0);
    return (((int64_t)now.tv_sec) * 1000 + now.tv_usec / 1000);
}

static const char* num2String(int port) {
    static char buff[8] = { 0 };
    sprintf(buff, "%d", port);
    return buff;
}

/**
 * @Method   checkAddress
 * @Brief
 * @DateTime 2018-08-04T14:15:16+0800
 * @Modify   2018-08-04T14:15:16+0800
 * @Author   Nanuns
 * @param    ip [description]
 * @param    port [description]
 * @return   [description]
 */
static int checkAddress(const char* ip, int port) {
    if (!ip || strlen(ip) < 5) {
        printf("IP address invalid.\n");
        return -1;
    }
    if (port < 1024 || port > 65536) {
        printf("port invalid.\n");
        return -2;
    }
    return 0;
}

/**
 * @Method   addressPrefix
 * @Brief
 * @DateTime 2018-08-04T14:15:16+0800
 * @Modify   2018-08-04T14:15:16+0800
 * @Author   Nanuns
 * @param    ip [description]
 * @param    port [description]
 * @return   [description]
 */
static string addressPrefix(const char* ip, int port) {
    if (checkAddress(ip, port) != 0) {
        return "";
    }
    string suri("http://");
    suri.append(ip);
    suri.append(":");
    suri.append(num2String(port));
    return suri;
}


#endif
