#include "PID.h"
#include<iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	prev_cte = 0;
	i_cte = 0;
}

void PID::UpdateError(double cte) {
	p_error = -Kp*cte;
	i_cte = i_cte + cte;
	i_error = -i_cte*Ki;
	d_error = -Kd*(cte-prev_cte);
	prev_cte = cte;
}

double PID::TotalError() {
	return p_error+i_error+d_error;
}

