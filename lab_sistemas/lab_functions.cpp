#include <Arduino.h>

#include "lab_functions.hpp"
#include "general_headers.hpp"

void printLogs(char *input, float dist, float ref, float tol){
  Serial.print("==== ");
  Serial.print(dist);
  Serial.print("\t | Ref: ");
  Serial.print(ref);
  Serial.print("\t | Tol: ");
  Serial.print(tol);
  Serial.print("\t ==== ");
  Serial.println(input);
}

void printError(char *input, float dist, float ref, float tol){
  Serial.print("==== ");
  Serial.print("ERROR: ");
  Serial.print(dist);
  Serial.print("\t | Ref: ");
  Serial.print(ref);
  Serial.print("\t | Tol: ");
  Serial.print(tol);
  Serial.print("\t ==== ");
  Serial.println(input);
}

void recordNewDist(float maj, float min, float dist){

}

int stateCase1(float dist, float min, float maj){

}

int stateCase2(float dist, float ref, float min, float maj, int last_state){

}

int stateCase2Extended(float dist, float ref, float min, float maj, int last_state){

}



int stateCase1Wrong(float dist){

  if (dist < DEFAULT_DIST) {
      //Serial.println("Focusing on close object...");
      return IN_PROXIMITY;
  
  }else{
      Serial.println("Object lost, searching...");
      return SEARCHING;
  
  }
}


int stateCase2Wrong(float dist){

  if (dist == DEFAULT_DIST) {
      //Serial.println("Focusing on close object...");
      return IN_PROXIMITY;
  
  }else{
      Serial.println("Object lost, searching...");
      return SEARCHING;
  
  }
}