//******************************************************************************
// Body Mass Index Calculator for SAE measurements
// Liam Boyle
// 28 Jun 2011
// lboyle0004@kctcs.edu liampboyle@gmail.com
//******************************************************************************

// include and using statements
#include <cstdlib>		// standard lib just for general principle
#include <iostream>		// access cin, cout
#include <cmath>		// access manipulators for data formatting

using namespace std;

// Named global constant declarations ##use all caps
    // pass
	
// Function Declarations ##use pascal casing
	float GetWeightFunc();
	float GetHeightFunc();
	float BMI_CalcFunc(float H, float W);

int main()	// Main Program Body
{
	// Global Variable Declarations ## use pascal casing w/ Var on end of name
	float WeightVar; // weight in pounds
	float HeightVar; // height in inches
	float BmiVar; // result of BMI calculation

	// function calls to get input and calculate value
	WeightVar = GetWeightFunc();
	HeightVar = GetHeightFunc();
	BmiVar = BMI_CalcFunc(HeightVar, WeightVar);

	// print results and status messages
	cout << "Your body mass index is " << BmiVar << "." << endl;
	cout << "Interpretation and instructions.  " << endl;
	if (BmiVar < 20)
		cout << "Underweight:  Have a milk shake." << endl;
	else if (BmiVar <= 25)
		cout << "Normal:  Have a glass of milk." << endl;
	else if (BmiVar <= 30)
		cout << "Overweight:  Have a glass of water." << endl;
	else
		cout << "Obese:  See your primary car physician!" << endl;

    system("PAUSE");
    return 0;
}

// Functions and Subroutines
float GetWeightFunc() // get weight and test data
{
	// Local Variable Declarations ## use camel casing
	    float weight;

	cout << "Please enter your weight in pounds:  ";
	cin >> weight;
	cout << endl;
	if (!cin) // test stream state for bad entry
	{
		cout << "invalid data entry, please try again" << endl;
		cin.clear();
		cin.ignore(250, '/n');
		weight=GetWeightFunc();
	}
	if (weight <= 0)
	{
		cout << "weight cannot be negative, please try again" << endl;
		cin.clear();
		cin.ignore(250, '/n');
		weight=GetWeightFunc();
	}
	return weight;
}

float GetHeightFunc() // get height and test data
{
	// Local Variable Declarations ## use camel casing
	    float height;

	cout << "Please enter your height in inches:  ";
	cin >> height;
	cout << endl;
	if (!cin) // test stream state for bad entry
	{
		cout << "invalid data entry, please try again" << endl;
		cin.clear();
		cin.ignore(250, '/n');
		height=GetHeightFunc();
	}
	if (height <= 0)
	{
		cout << "height cannot be negative, please try again" << endl;
		cin.clear();
		cin.ignore(250, '/n');
		height=GetHeightFunc();
	}
	return height;
}

float BMI_CalcFunc(float H, float W) // calculate BMI from passed values
{
	// Named Constant Declaration
	const int bmiConstant = 703; // nonmetric BMI constant

	// Local Variable Declarations ## use camel casing
	float bmi;

	// calculation
	bmi = W * bmiConstant / pow(H,2);

	return bmi;
}
