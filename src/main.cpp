#include <Arduino.h>

bool infochecked;
String DataStream;

unsigned char type;
unsigned char nowhour;
unsigned char nowminute;

struct Time{
  unsigned char hour;
  unsigned char minute;
};

class Pill{
  private: 
    unsigned char total;
    unsigned char dose;
    bool Week[7];

  protected:
    unsigned char delimiterOne = DataStream.indexOf("<");
    unsigned char delimiterTwo = DataStream.indexOf("<", delimiterOne + 1);
    
    void delimiterSwitcher(){
      delimiterOne = DataStream.indexOf("<", delimiterTwo + 1);
      delimiterTwo = DataStream.indexOf("<", delimiterOne + 1);
    };

    void baseParser(){
      total = DataStream.substring(delimiterOne+1, delimiterTwo).toInt();
      delimiterSwitcher();
      dose = DataStream.substring(delimiterOne+1, delimiterTwo).toInt();
      delimiterSwitcher();
      Week[0] = DataStream.substring(delimiterOne+1, delimiterTwo).toInt();
      delimiterSwitcher();
      Week[1] = DataStream.substring(delimiterOne+1, delimiterTwo).toInt();
      delimiterSwitcher();
      Week[2] = DataStream.substring(delimiterOne+1, delimiterTwo).toInt();
      delimiterSwitcher();
      Week[3] = DataStream.substring(delimiterOne+1, delimiterTwo).toInt();
      delimiterSwitcher();
      Week[4] = DataStream.substring(delimiterOne+1, delimiterTwo).toInt();
      delimiterSwitcher();
      Week[5] = DataStream.substring(delimiterOne+1, delimiterTwo).toInt();
      delimiterSwitcher();
      Week[6] = DataStream.substring(delimiterOne+1, delimiterTwo).toInt();
      delimiterSwitcher();
    }
};

class UniPill : Pill{
  private: 
    Time time1;

  public: 
    bool infoverified = false;

    void dispense(){
      Serial.println("Dispensing at " + time1.hour + time1.hour);
      while (true){
        if (time1.hour == nowhour && time1.minute == nowminute){
          Serial.println("Dispensing");
        };
      };
    };

    UniPill(String DataStream){
      
    }; 

    UniPill(){
      baseParser();
      time1.hour = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
      delimiterSwitcher();
      time1.minute = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
    }
};

class DiPill : Pill{
  private: 
    Time time1;
    Time time2;

  public: 
  bool infoverified = false;
    void dispense(){
      Serial.println("Dispensing at " + time1.hour + time1.hour);
      while (true){
        if (time1.hour == nowhour && time1.minute == nowminute){
          Serial.println("Dispensing");
        }
        else if (time2.hour == nowhour && time2.minute == nowminute){
          Serial.println("Dispensing");
        }
        else{
        };
      };
    };

    DiPill(){
      baseParser();
      time1.hour = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
      delimiterSwitcher();
      time1.minute = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
      delimiterSwitcher();
      time2.hour = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
      delimiterSwitcher();
      time2.minute = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
    };

};

class TriPill : Pill{
  private:
    Time time1;
    Time time2;
    Time time3; 
  public: 
    bool infoverified = false;
    void dispense(){
      Serial.println("Dispensing at " + time1.hour + time1.hour);
      while (true){
        if (time1.hour == nowhour && time1.minute == nowminute){
          Serial.println("Dispensing");
        }
        else if (time2.hour == nowhour && time2.minute == nowminute){
          Serial.println("Dispensing");
        }
        else if (time3.hour == nowhour && time2.minute == nowminute){
          Serial.println("Dispensing");
        }
        else{
        };
      };
    };

    TriPill(){
      baseParser();
      time1.hour = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
      delimiterSwitcher();
      time1.minute = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
      delimiterSwitcher();
      time2.hour = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
      delimiterSwitcher();
      time2.minute = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
      delimiterSwitcher();
      time3.hour = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
      delimiterSwitcher();
      time3.minute = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
    }
};

class QuadPill : Pill{
  private:
    Time time1;
    Time time2;
    Time time3;
    Time time4; 
  public: 
    bool infoverified = false;
    void dispense(){
      Serial.println("Dispensing at " + time1.hour + time1.hour);
      while (true){
        if (time1.hour == nowhour && time1.minute == nowminute){
          Serial.println("Dispensing");
        }
        else if (time2.hour == nowhour && time2.minute == nowminute){
          Serial.println("Dispensing");
        }
        else if (time3.hour == nowhour && time2.minute == nowminute){
          Serial.println("Dispensing");
        }
        else if (time4.hour == nowhour && time4.minute == nowminute){
          Serial.println("Dispensing");
        }
        else{
        };
      };
    };

    QuadPill(){
      baseParser();
      time1.hour = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
      delimiterSwitcher();
      time1.minute = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
      delimiterSwitcher();
      time2.hour = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
      delimiterSwitcher();
      time2.minute = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
      delimiterSwitcher();
      time3.hour = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
      delimiterSwitcher();
      time3.minute = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
      delimiterSwitcher();
      time4.hour = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
      delimiterSwitcher();
      time4.minute = DataStream.substring(delimiterOne + 1, delimiterTwo).toInt();
    }
};

void SerialReader(){
  Serial.begin(115200);
  while(DataStream == ""){
    DataStream = Serial.read();
    type = DataStream[0];
  };
};

void setup() {
  SerialReader();
  while (infochecked == false){
  if (type == 'u'){
    UniPill unipill;
      if (unipill.infoverified == false){
        Serial.write("INVALID");
        infochecked = false;
        break;
      }
    else{
      infochecked = true;
      break;
    }
    unipill.dispense();
  }

  else if (type == 'd'){
    DiPill dipill;
    if (dipill.infoverified == false){
      Serial.write("INVALID");
      infochecked = false;
      break;
    }
    else{
      infochecked = true;
      break;
    }
    dipill.dispense();
  }

  else if (type == 't'){ 
    TriPill tripill;
    if (tripill.infoverified == false){
      Serial.write("INVALID");
      infochecked = false;
      break;
    }
    else{
      infochecked = true;
      break;
    }
    tripill.dispense();
  }

  else if(type == 'q'){
    QuadPill quadpill;
    if (quadpill.infoverified == false){
      Serial.write("INVALID");
      infochecked = false;
      break;
    }
    else{
      infochecked = true;
      break;
    }
    quadpill.dispense();
  }
  };
}

void loop() {
  
}