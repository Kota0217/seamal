//Copyright 2021 RobomechFactory MicroMechanism
//
//@brief
//      author: k.ishizeki
//      Project: seamal
//      TargetCPU; STM32F303K8T6
//      mbed library revision number: 172:65be27845400
//      File revision: 2021/08/05-1
//

#include "mbed.h"

Serial pc(USBTX, USBRX);

Ticker sensorTicker;

DigitalOut led(LED1);


void isr(){
    led = !led;    
}

int main(){
    
    pc.baud(115200);
    sensorTicker.attach(&isr, 0.1);
    
    while(1){
        pc.printf("test\n");
        wait(1.0);
    }
    
}
