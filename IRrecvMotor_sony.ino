
#include <IRremote.h>
//外部のライブラリ(ここではIRremote)をスケッチに取り入れたいときに使う。

#define ENABLE 7
#define DIRA 5
#define DIRB 6

int RECV_PIN = 11;//IRからの信号受信を11ピンに設定

IRrecv irrecv(RECV_PIN);// 赤外線受信用オブジェクトの設定(irrecvというインスタンスを作成)

decode_results results;// 赤外線受信結果を格納するdecode_resultsというインスタンスを作成


int val=0;
int cnt=0;


void setup()
{
  Serial.begin(9600);//シリアル通信のデータ転送レートをbpsで指定、1秒間に通信するビット数
  irrecv.enableIRIn(); //受信を開始する  
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);

}

void loop() {


if (irrecv.decode(&results)) {//受信した結果のデコード
Serial.println(results.value, HEX);//受信した結果をバリューメソッドで出し、シリアルを出力する


//条件分岐1
if(results.value == 0xCD0){//16進数は0xを頭につける
cnt = cnt + 1;
  }

//条件分岐2
  if(results.value == 0xAF0){
cnt = 0;
  }
  
//条件分岐3
  if(results.value == 0x2D0){
cnt = cnt - 1;
  }

  

irrecv.resume(); // Receive the next value
delay(100);
}

if(cnt==1){
    digitalWrite(ENABLE,HIGH); //enable on
  analogWrite(DIRA,100); //on
  digitalWrite(DIRB,LOW);
  delay(100);
}




if(cnt==2){
  
    digitalWrite(ENABLE,HIGH); //enable on
  analogWrite(DIRA,120); //on
  digitalWrite(DIRB,LOW);
  delay(100);
}



if(cnt==3){
  
    digitalWrite(ENABLE,HIGH); //enable on
  analogWrite(DIRA,150); //on
  digitalWrite(DIRB,LOW);
  delay(100);
}
 



if(cnt==4){
  
    digitalWrite(ENABLE,HIGH); //enable on
  analogWrite(DIRA,200); //on
  digitalWrite(DIRB,LOW);
  delay(100);
}



if(cnt>=5){
  cnt=5;
    digitalWrite(ENABLE,HIGH); //enable on
  analogWrite(DIRA,250); //on
  digitalWrite(DIRB,LOW);
  delay(100);
}


if((cnt==-1)||(cnt==-2)){
    digitalWrite(ENABLE,HIGH); //enable on
  analogWrite(DIRB,100); //on
  digitalWrite(DIRA,LOW);
  delay(100);
}

if((cnt==-3)||(cnt==-4)){
    digitalWrite(ENABLE,HIGH); //enable on
  analogWrite(DIRB,140); //on
  digitalWrite(DIRA,LOW);
  delay(100);
}
 
if(cnt<=-5){
  cnt=-5;
    digitalWrite(ENABLE,HIGH); //enable on
  analogWrite(DIRB,180); //on
  digitalWrite(DIRA,LOW);
  delay(100);
}







    digitalWrite(ENABLE,LOW); //enable off
  digitalWrite(DIRA,LOW); //off
  digitalWrite(DIRB,LOW);
  delay(10);

}
 
