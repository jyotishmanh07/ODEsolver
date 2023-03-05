#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cassert>
#include "solver.h"


Solver::Solver(double t_0, double t_end, double dt, double y_0)
:_t_0(t_0), _t_end(t_end), _dt(dt), _y_0(y_0)
{
    _y_approx.push_back(y_0);
    _y_anal.push_back(y_analytic(t_0));
}

void Solver::solve(){
    int N = (_t_end-_t_0)/_dt;
    double y_current = _y_approx[0];
    double t = _t_0+_dt;
    double error_sum = 0;

    std::cout<<"Solving the ODE equation..."<<std::endl;

    for (int i=0; i<N; i++){
        _y_approx.push_back(calculate_y_next(y_current));
        y_current = _y_approx[i+1];
        _y_anal.push_back(y_analytic(t));
        t += _dt;
        error_sum += (_y_approx[i+1]-_y_anal[i+1])*(_y_approx[i+1]-_y_anal[i+1]);
    }
    std::cout<<"The error is: "<< sqrt(error_sum/N)<<std::endl;
}

void Solver::print_results(){
    
    assert(_y_approx.size() == _y_anal.size());

    std::cout<<"=====This is the result of the ODE equation.====="<<std::endl;
    std::cout<< "time"<<"\t"<< "y_approx_sol"<<"\t"<< "y_anal_sol"<<"\t"<<"Error"<<"\n";
    
    double t = _t_0;
    for (int i=0; i<_y_approx.size(); i++){
        double error = abs(_y_anal[i]-_y_approx[i]);
        std::cout<< std::left <<  std::setw(8) <<  t << std::left << std::setw(16) 
        << _y_approx[i]<< std::left << std::setw(16) << _y_anal[i]<< error <<"\n";
        t += _dt;
    }
}

// an ode equation
double Solver::y_dot(double y)
{
    return (-7*y);
}

// an analytic solution of the ode equation
double Solver::y_analytic(double t){
    return (exp(-7*t));
}




