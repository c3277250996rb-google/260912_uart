/***********************V1.0 20220322 jane********************************/
1.设置SPI的时钟分频为8分频
2.设置SPI为空闲高，相位选择CPHA = 1，设置SPI NSSx受SSCR内容控制
3.设置P15为SCLK, P17为MISO, P16为MOSI, P36为NSS
4.设置SPI为slave模式
5.使能SPI中断

SPI中断中读取master发送过来的SPI数据后，再发送固定数据0x5A






