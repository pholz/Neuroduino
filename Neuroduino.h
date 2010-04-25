/*
 *  Neuroduino.h
 *  
 *  Arduino Neural Network Library
 *  Adapted and simplified from:
 *  http://www.neural-networks-at-your-fingertips.com/bpn.html
 *
 *  Implements a simple feedforward perceptron network
 * 
 *  Created by Ted Hayes on 4/15/10.
 *  Copyright 2010 Limina.Studio. All rights reserved.
 *
 */

#ifndef Neuroduino_h
#define Neuroduino_h

#include "WProgram.h"

// used for get_free_memory()
extern int __bss_end;
extern void *__brkval;

typedef double VAL;		// no idea why this has to go here

class Neuroduino
{
	public:
		// methods
		Neuroduino(double nodeArray[], int numLayers, double eta, double theta, boolean debug);
		void	train(double inputArray[], double trainArray[]);
		void	printNet();
		double*	getOutput();
		void	randomizeWeights();
		double*	simulate(double inputArray[]);
		
		// properties
		
		//int		_output[3];
		
	private:
		// types
		//typedef double VAL;	// this doesn't work here
		typedef struct {			   /* A LAYER OF A NET:			   */
			int			Units;	   /* - number of units in this layer	 */
			//VAL*		Output;	  /* - output of ith unit			*/
			double*		Output;		// 1 or -1
			//VAL*		Error;	   /* - error term of ith unit		  */
			VAL**		Weight;	  /* - connection weights to ith unit	*/
			//VAL**		WeightSave;    /* - saved weights for stopped training  */
			//VAL**		dWeight;	 /* - last weight deltas for momentum     */
		} LAYER;
		typedef struct {			   /* A NET:					  */
			LAYER**		Layer;	   /* - layers of this net			*/
			LAYER*		InputLayer;    /* - input layer				 */
			LAYER*		OutputLayer;   /* - output layer				*/
			//double	Alpha;	   /* - momentum factor			   */
			double	    Eta;	     /* - learning rate			     */
			//double	Gain;	    /* - gain of sigmoid function		*/
			//double	Error;	   /* - total net error			   */
			double		Theta;
		} NET;
	
		// class methods
		
		void	setInput(double inputs[]);
		void	adjustWeights(double trainArray[]);
		double		signThreshold(double sum);
		double	weightedSum(int layer, int node);
		void	simulateNetwork();
	
		// utility methods
		void trace(char *message);
		VAL doubleToVal(double dValue);
		double randomEqualDouble(double Low, double High);
		int get_free_memory();
		
		// properties
		boolean		_debug;
		int			_numLayers;
		NET			_net;
		double*		_output;
};

#endif