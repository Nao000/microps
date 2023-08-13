#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#include "util.h"
#include "net.h"

#include "driver/dummy.h"

#include "test.h"

/**
 * `volatile sig_atomic_t` ってなに
 *
 * `volatule`
 * > 要するに、volatile キーワードの唯一の役割は、この変数はコンパイラが決定できない方法で変更される可能性があること、そのため、volatile としてとして示されたメモリ領域で最適化を実行すべきではないということをコンパイラに伝えることである。
 * https://www.jpcert.or.jp/sc-rules/c-con02-c.html
 *
 * > sig_atomic_tは、非同期割込みの存在下でも、1つの不可分な実体としてアクセス(代入や参照)できるオブジェクトの整数型です。シグナルを受けたときの割込検出フラグなどに使用されます。
 * http://www.c-lang.org/detail/signal_h.html
 *
 * 同時アクセスを安全に行うためっぽい
*/
static volatile sig_atomic_t terminate;

static void
on_signal(int s)
{
    (void)s;
    terminate = 1;
}

int
main(int argc, char *argv[])
{}