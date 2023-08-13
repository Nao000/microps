#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

#include "util.h"
#include "net.h"

#define DUMMY_MTU UINT16_MAX /* maximum size of IP datagram */

/**
 * 関数の引数に const ってつけられるのか？
 * => 出来るらしい
 *
 * > 関数の引数を const として宣言すると、その関数が引数の値を変更しないことを約束するということを意味する。
 * https://www.jpcert.or.jp/sc-rules/c-dcl13-c.html
*/
static int
dummy_transmit(struct net_device *dev, uint16_t type, const uint8_t *data, size_t len, const void *dst)
{
}

static struct net_device_ops dummy_ops = {
    .transmit = dummy_transmit,
};

struct net_device *
dummy_init(void)
{
}