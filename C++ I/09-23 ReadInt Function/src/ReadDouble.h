/*
 * ReadDouble.h
 *
 *  Created on: Sep 28, 2015
 *      Author: mbd06b
 */

#ifndef READDOUBLE_H_
#define READDOUBLE_H_

int ReadInt ()

int ReadDouble(){




	cout <<"Please put in an operator (+,-,*,/,X,x,C,c)"<<endl;
			cin >> Op;
			switch (Op)
				{
				case '+':

					break;
				case '-':
					cout<<"plugin a number"<<endl;
					cin>>num2;
					result = num1 - num2;
					cout<<num1 <<" - "<< num2 <<" = "<<result<<endl;
					break;
				case '*':
				    cout<<"plugin a number"<<endl;
					cin>>num2;
					result = num1 * num2;
					cout<<num1 <<" * "<< num2 <<" = "<<result<<endl;
					break;
				case '/':
					  cout<<"The number Zero is not allowed"<<endl;
				      cout<<"plugin a number esxcept 0."<<endl;
					  cin>>num2;
					  result = num1 / num2;
					  cout<<num1 <<" / "<< num2 <<" = "<<result<<endl;

					   break;
				case 'x':
				case 'X':
					      exit (0);
						  break;
				case 'c':
				case 'C':
					         num1   = 0;
		                     num2   = 0;
		                     result = 0;
	                         swap   = 0;
							ValidOperator = true;
							break;
				default:
							ValidOperator = false;
							cout << "Invalid Operator" << endl;

}



#endif /* READDOUBLE_H_ */
