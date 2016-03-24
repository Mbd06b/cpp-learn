/*
 * Functions.h
 *
 *  Created on: Sep 28, 2015
 *      Author: mbd06b
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

int Add (int, int); // adds 2 numbers separated by comma
					// you may give the parameters (argumens) names but
long Add (long, long);

double Add (double, double); // compiler can tell funcitons apart if the names are diferent
							// the parameters are different types

int Func1 (int, int);
int	Func2 (int &);   //using the "&"means x now refers back to the original value

int Divide (int, int, int &);

#endif /* FUNCTIONS_H_ */
