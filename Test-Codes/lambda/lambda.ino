/*
This program made by https://controlduino.com/ runs on an arduino UNO, MEGA and others, 
Target:
The aim of this program is to measure the (%O2, AFR, rpm) data of a gas coming from the combustion obtained from the 
lambda module (Controlduino 01M21V00) and display it on the serial monitor of the arduino.also sends battery voltage, state, 
and diagnostics.

Hardware required to use this software:
• Arduino board
• Lambda module and wires.(Controlduino 01M21V00)
• Wideband lambda probe
• Power supply (V=12v, I>=3A)
On the website https://controlduino.com/ you can find all the information about the lambda modules and Shield and other modules. 
Library:
To use this software you need to have installed the "Lambda_rpm" library which can be downloaded at: 
https://controlduino.com/lambda-rpm-module-01m21v00/ or https://controlduino.com/download/library-lambda_rpm-h-for-arduino/
Purchase:
In the store https://controlduino.com/store/ you can purchase, lambda shields and lambda modules, sensors, and other modules. 
Downloads:
In the following link you can download all the arduino files, smartphone APPs, data sheets about the board, and probes... : 
https://controlduino.com/lambda-rpm-module-01m21v00/
Forum:
If you have any questions or want to share your projects you can do it in the forum: https://controlduino.com/forum/

Enjoy        
*/



#include "Arduino.h"
#include <Lambda_rpm.h>

#define Lambda_SPI_NSS 2////assign to pin 2 SPI select slave ////asigno al pin 2 SPI select slave 
Lambda_rpm lambda1(Lambda_SPI_NSS);////assign to pin 2 SPI select slave ////asigno al pin 2 SPI select slave 

void setup() {
Serial.begin(57600); ///Establish UART_USB communication with the arduino IDE//Establezco comunicacion UART_USB con la IDE de arduino    
lambda1.SPIbeginsettings (500000);//Sets up SPI communications with the lambda sensor module(long int bauds)  //Establece comunicaciones SPI con el modulo de sonda lambda a una velocidad de (long int bauds)
lambda1.begin();//Turn on the lambda module, it will take a while as it has to warm up.  //Enciende placa lambda, tardara un rato puesto que tiene que calentarse
lambda1.rpmBegin();//Enables the rpm measurement of the module.

}
void loop() {
  
  lambda1.transmission();  //Communicate with lambda_rpm module, exchange message on SPI, with information //Comunico con modulo lambda_rpm, intercambio un mensaje en SPI, con informacion
  
  // Read values
  String State_value=lambda1.stateTextRead();//State of the lambda probe
  float  O2Value=lambda1.O2Read();//%O2
  float  AFRValue=lambda1.afrGasolineRead ();//AFR
  int rpmValue=lambda1.rpmRead();//RPM
  
  // Print values
  
  /*State of the lambda probe, Estado de la sonda lambda*/
  Serial.print("\t");  
  Serial.print(" Estate: ");
  Serial.print(State_value);
  Serial.print("\t");

  /*%O2*/
  Serial.print(" %O2: ");
  if (lambda1.validO2Read()!=true){//verify that the O2 sensor measurement is valid.//Compruebo que la medición del sensor de O2 es válida.
    Serial.print(O2Value,2);///print %O2 in the arduino IDE via the USART_USB//imprimo %O2 en la IDE de arduino por medio del USART_USB
  }else{
    Serial.print("------");
  }

    /*AFR*/
    Serial.print(" AFR Petrol: ");
  if (lambda1.validO2Read()!=true){//verify that the O2 sensor measurement is valid.//Compruebo que la medición del sensor de O2 es válida.
    Serial.print(AFRValue,2);
  }else{
    Serial.print("------");
  }
  
  /*RPM*/
  Serial.print("\t");
  Serial.print(" rpm: ");
  Serial.print(rpmValue);  
  Serial.print("\t");
   
  Serial.print("\n\r");  
   
  delay (200);////Delay a time to limit the received data to the desired value.//Retraso un tiempo para limitar los datos recibidos, al valor desesado

}
