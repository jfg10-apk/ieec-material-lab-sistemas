#ifndef MY_FUNCT_HPP
#define MY_FUNCT_HPP

/**
 * @brief Prints logs in a convention.
 * 
 * @param input String of an useful info in runtime
 * @param dist Distance measured
 * @param ref Reference distance  
 * @param tol Tolerance
 */
void printLogs(char *input, float dist, float ref, float tol);

/**
 * @brief Prints errors in a convention.
 * 
 * @param input String of an useful error info in runtime  
 * @param dist Distance measured
 * @param ref Reference distance  
 * @param tol Tolerance
 */
void printError(char *input, float dist, float ref, float tol);

/**
 * @brief Records a new reference distance taking in account the tolerance provided. (Example of a modification)
 * 
 * @param maj Upper bound
 * @param min Lower bound
 * @param dist New reference distance
 * @param ref Reference distance
 */
void recordNewDist(float *maj, float *min, float dist, float *ref);

/**
 * @brief Returns the state of the circuit in Case 1. No Schmitt trigger.
 * 
 * @param dist Distance between the sensor and the obstacle
 * @param ref Reference distance
 * @return int 
 */
int stateCase1(float dist, float ref);

/**
 * @brief Returns the state of the circuit in Case 2. Uses an interval to detect an object distancing a determined value from the sensor
 * 
 * @param dist Current distance
 * @param min Lower bound
 * @param maj Upper bound
 * @return int 
 */
int stateCase2(float dist, float min, float maj);

/**
 * @brief stateCase2() + Verifies measurement + Cablibration
 * 
 * @param dist Current distance
 * @param min Lower bound
 * @param maj Upper bound
 * @return int 
 */
int stateCase2Extended(float dist, float min, float maj);

#endif