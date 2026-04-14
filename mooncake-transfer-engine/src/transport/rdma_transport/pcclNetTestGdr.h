//
// Created by liujialai on 2026/1/16.
//

#ifndef MOONCAKE_PCCLNETTESTGDR_H
#define MOONCAKE_PCCLNETTESTGDR_H
#include "pccl_socket.h"

typedef enum {
    TEST_PASS = 0,
    TEST_FAIL = 1,
    TEST_SKIP = 2
} test_result_t;
/* 测试选项 */
typedef struct {
    bool verbose;           /* 详细输出 */
    int test_num;           /* 运行特定测试编号 */
    bool run_all;           /* 运行所有测试 */
    int device_id;          /* 指定设备ID */
    int gpu_id;             /* 指定GPU ID */
    size_t buffer_size;     /* 缓冲区大小 */
    int iterations;         /* 迭代次数（用于性能测试） */
    bool server_mode;       /* 服务端模式 */
    char *remote_ip;        /* 对端IP地址（客户端模式需要） */
    int port;               /* 端口号（默认0，系统自动分配） */
} test_options_t;

/* 测试上下文 */
typedef struct {
    int dev;
    int gpu_id;
    pcclNetProperties_t props;
    bool gdr_supported;
} test_context_t;

test_result_t test_30_gdr_capability_query(test_options_t *opts);

#endif  // MOONCAKE_PCCLNETTESTGDR_H
