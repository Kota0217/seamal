/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <cstdio>


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

//UART通信の定義
BufferedSerial serial_port(USBTX, USBRX);

//タイマー割り込みのための定義
//EventQueueを作成する
EventQueue queue;

//シーケンス番号を定義
int i = 0;

//ボード上LEDの定義
DigitalOut led(LED1);

//BufferdSerialで作成したオブジェクトにprintfが出力されるための設定
FileHandle *mbed::mbed_override_console(int fd)
{
    return &serial_port;
}

void isr(){
    //printf("%d\n", i);
    led = !led;
    i++;
}

int main()
{
    //シリアル通信のボーレートを115200に設定
    serial_port.set_baud(9600);

    //タイマー割り込みの開始
    queue.call_every(1000ms, isr);
    //イベントループを回し続ける
    

    while(true){
        //led = !led;
        printf("test\n");
        //ThisThread::sleep_for(BLINKING_RATE);
        wait_us(1000000);
    }
    
    queue.dispatch();
}
