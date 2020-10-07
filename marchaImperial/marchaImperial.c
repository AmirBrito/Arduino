/*
	-Documentacao
    -Trabalho Embarcados - Marcha Imperial Star Wars
    -@author: Amir Brito
*/

/*
	-Informações:
    -Notas Musicais - Freq. do Buzzer:
    	Dó: 262Hz;
        Ré: 294Hz;
        Mi: 330Hz;
        Fá: 349Hz;
        Sol: 392Hz;
        Lá: 440Hz;
        Si: 494Hz;
        Dó: 523Hz;
*/

#include <stdio.h>
#include <stdlib.h>

// sons utilizados no buzzer;

#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 466
#define b 494
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880

int buzzer = 10;
int intervalo = 1000;
int timeCurto = 400;
int timeCurto2 = 300;
int timeCurto3 = 200;
int timeCurto4 = 125;
int noTime = 0;
int ledLine = 2;
int button1 = 6;
int button2 = 7;
int button3 = 8;
int ledUm = 3;
int ledDois = 4;
int ledTres = 5;



void timeIntervalo(int time){ // intervalo de tempo
  	delay(time);
}

void semSom(){ // retirando som do buzzer
  	noTone(buzzer);
}

void tocarNota(int som, int nota, int timeInicio, int timeFinal, int ritmo){ // tocando a nota
  	int time = 0;
  	tone(som, nota);
  	digitalWrite(ledLine, HIGH);
  	time = timeInicio * ritmo;
  	timeIntervalo(time);
  	semSom();
  	digitalWrite(ledLine, LOW);
  	time = timeFinal * ritmo;
  	timeIntervalo(timeFinal);
}
	

void musicaParte1(int ritmo){
 
  	tocarNota(buzzer, a, timeCurto, timeCurto4, ritmo);
  	tocarNota(buzzer, a, timeCurto, timeCurto4, ritmo);
  	tocarNota(buzzer, a, timeCurto, timeCurto4, ritmo);
	tocarNota(buzzer, f, timeCurto, timeCurto4, ritmo);
  	tocarNota(buzzer, cH, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, a, timeCurto3, timeCurto4, ritmo);
  	tocarNota(buzzer, f, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, cH, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, a, timeCurto3, timeCurto, ritmo);
}

void musicaParte2(int ritmo){
  
  	tocarNota(buzzer, eH, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, eH, timeCurto, timeCurto4, ritmo);
  	tocarNota(buzzer, eH, timeCurto, timeCurto4, ritmo);
  	tocarNota(buzzer, fH, timeCurto, timeCurto4, ritmo);
  	tocarNota(buzzer, cH, timeCurto3, timeCurto4, ritmo);
  	tocarNota(buzzer, gS, timeCurto4, timeCurto4, ritmo);
  	tocarNota(buzzer, f, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, cH, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, a, timeCurto3, timeCurto, ritmo);
  
}

void musicaParte3(int ritmo){
 	
  	tocarNota(buzzer, aH, timeCurto, timeCurto4, ritmo);
  	tocarNota(buzzer, a, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, a, timeCurto3, timeCurto4, ritmo);
  	tocarNota(buzzer, aH, timeCurto, timeCurto4, ritmo);
  	tocarNota(buzzer, gSH, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, gH, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, fSH, timeCurto3, timeCurto4, ritmo);
  	tocarNota(buzzer, fH, timeCurto3, timeCurto4, ritmo);
  	tocarNota(buzzer, fSH, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, aS, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, dSH, timeCurto, timeCurto4, ritmo);
  	tocarNota(buzzer, dH, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, cSH, timeCurto2, timeCurto, ritmo);
  	
}

void musicaParte4(int ritmo){
  	
  	tocarNota(buzzer, cH, timeCurto, timeCurto4, ritmo);
  	tocarNota(buzzer, b, timeCurto3, timeCurto4, ritmo);
  	tocarNota(buzzer, cH, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, f, timeCurto3, timeCurto4, ritmo);
  	tocarNota(buzzer, gS, timeCurto, timeCurto4, ritmo);
  	tocarNota(buzzer, f, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, a, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, cH, timeCurto, timeCurto4, ritmo);
  	tocarNota(buzzer, a, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, cH, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, eH, timeCurto3, timeCurto, ritmo);  
  
}

void musicaParte5(int ritmo){
  	
  	tocarNota(buzzer, aH, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, a, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, a, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, aH, timeCurto, timeCurto4, ritmo);
  	tocarNota(buzzer, gSH, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, gH, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, fSH, timeCurto3, timeCurto4, ritmo);
  	tocarNota(buzzer, fH, timeCurto3, timeCurto4, ritmo);
  	tocarNota(buzzer, fSH, timeCurto3, timeCurto4, ritmo);
  	tocarNota(buzzer, aS, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, dSH, timeCurto, timeCurto4, ritmo);
  	tocarNota(buzzer, dH, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, cSH, timeCurto2, timeCurto, ritmo);
}

void musicaParte6(int ritmo){
  
 	tocarNota(buzzer, cH, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, b, timeCurto3, timeCurto4, ritmo);
  	tocarNota(buzzer, cH, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, f, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, gS, timeCurto, timeCurto4, ritmo);
  	tocarNota(buzzer, f, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, cH, timeCurto3, timeCurto4, ritmo);
  	tocarNota(buzzer, a, timeCurto, timeCurto4, ritmo);
  	tocarNota(buzzer, f, timeCurto2, timeCurto4, ritmo);
  	tocarNota(buzzer, c, timeCurto3, timeCurto4, ritmo);
  	tocarNota(buzzer, a, timeCurto2, intervalo, ritmo);
  	
}

void marchaImperial(int ritmo){
  	
  	musicaParte1(ritmo); 
  	musicaParte2(ritmo);
  	musicaParte3(ritmo);
  	musicaParte4(ritmo);
  	musicaParte5(ritmo);
  	musicaParte6(ritmo);
}

void setup() {
  
  	pinMode(buzzer,OUTPUT);
  	pinMode(ledLine, OUTPUT);
  	pinMode(button1, INPUT);
    pinMode(button2, INPUT);
    pinMode(button3, INPUT);
  	pinMode(ledUm, OUTPUT);
  	pinMode(ledDois, OUTPUT);
  	pinMode(ledTres, OUTPUT);
}



void loop(){
	int buttonStatus1 = 0;
  	int buttonStatus2 = 0;
  	int buttonStatus3 = 0;
  	int ritmo = 0;
	
  	buttonStatus1 = digitalRead(button1);
    buttonStatus2 = digitalRead(button2);
    buttonStatus3 = digitalRead(button3);
  
  	if(buttonStatus1 == HIGH){
    	ritmo = 1;
      	digitalWrite(ledUm, HIGH);
      	digitalWrite(ledDois, LOW);
      	digitalWrite(ledTres, LOW);
      	marchaImperial(ritmo);
    }else if(buttonStatus2 == HIGH){
      	ritmo = 2;
      	digitalWrite(ledUm, LOW);
      	digitalWrite(ledDois, HIGH);
      	digitalWrite(ledTres, LOW);
      	marchaImperial(ritmo);
    }else if(buttonStatus3 == HIGH){
      	ritmo = 3;
      	digitalWrite(ledUm, LOW);
      	digitalWrite(ledDois, LOW);
      	digitalWrite(ledTres, HIGH);
      	marchaImperial(ritmo);
    }else{
      	digitalWrite(ledUm, LOW);
      	digitalWrite(ledDois, LOW);
      	digitalWrite(ledTres, LOW);
    }	
}
