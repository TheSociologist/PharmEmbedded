#include "pillclasses.h"

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