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

void recordNewDist(float *maj, float *min, float dist, float *ref){
	
	*ref = dist;
	*maj = dist + DEFAULT_TOLER;
	*min = dist - DEFAULT_TOLER;

	if(*maj > TOO_FAR_DIST)
  {
    *maj = TOO_FAR_DIST;
  }

  if(*min < TOO_CLOSE_DIST)
  {
    *min = TOO_CLOSE_DIST;
  }
	
}


int stateCase1(float dist, float ref){
  if (dist < ref) 
  {
    return IN_FOCUS;
  }

  else
  {
    return SEARCHING;
  }
}

int stateCase2(float dist, float min, float maj){
	if(dist > min && dist < maj)
  {
    return IN_FOCUS;
	}

  else
  {
		return SEARCHING;
	}

}

int stateCase2Extended(float dist, float min, float maj){

  int button_state = digitalRead(CALIBRATION_BUTTON);
  if(button_state == LOW){
    return CALIBRATING;
  }

	if((dist > TOO_FAR_DIST) || (dist < TOO_CLOSE_DIST)){
		return WARNING;
	}

	if(dist > min && dist < maj)
  {
    return IN_FOCUS;
	}
  
  else
  {
		return SEARCHING;
	}
}
