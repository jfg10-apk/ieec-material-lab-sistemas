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



/***
 * Começar a editar as funções a partir daqui.
 */

void recordNewDist(float maj, float min, float dist, float ref){
	/*
	ref = ???;
	maj = ???;
	min = ???;
	if(maj > ???) maj = ???;
  if(min < ???) min = ???;
	*/
}


// Objetivo: "Foca-se" quando objeto está perto e "varre" quando se encontra longe.
int stateCase1(float dist, float min, float maj, int last_state){
  if (/*last_state == */) 
  {
      if(dist < min){
        //Serial.println("Focusing on close object...");
        /*return ;*/
      }
      else return SEARCHING;
  }

  if(/*last_state == */)
  {
      if (dist > maj){
        //Serial.println("Object lost, searching...");
        /*return ;*/
      }
      else return IN_FOCUS;
  }
  return WARNING;
}

// Objetivo: "Foca-se" quando objeto está a uma determinada distância. C.C., faz o varrimento.
int stateCase2(float dist, float min, float maj){
	if(/*(dist > ???) && (dist < ???)*/){

	}else{
		return SEARCHING;
	}

}

// Objetivo: stateCase2() + Verifica medida fidedigna + Calibração
int stateCase2Extended(float dist, float ref, float min, float maj, int last_state){
	if(/*(dist > ???) || (dist < ???)*/){
		
		///return ???;
	}

	if(/*(dist > ???) || (dist < ???)*/){
		//Serial.println("Warning! Possible bad measurement...");
		// return ???;
	}

	if(/*(dist > ???) && (dist < ???)*/){
		//Serial.println("Object found! Focusing...");
		//return ???;
	}else{
		//return ???;
	}
}



int stateCase1Wrong(float dist){

  if (dist < DEFAULT_DIST) {
      //Serial.println("Focusing on close object...");
      return IN_FOCUS;
  
  }else{
      Serial.println("Object lost, searching...");
      return SEARCHING;
  
  }
}


int stateCase2Wrong(float dist){

  if (dist == DEFAULT_DIST) {
      //Serial.println("Focusing on close object...");
      return IN_FOCUS;
  
  }else{
      Serial.println("Object lost, searching...");
      return SEARCHING;
  
  }
}