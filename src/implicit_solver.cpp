#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "implicit_solver.h"
#include "solver.h"
#include <chrono>

Implicit_solver::Implicit_solver(double t_0, double t_end, double dt, double y_0)
: Solver(t_0, t_end, dt, y_0)
{ std::cout << "===========This is an implicit method==========="<<std::endl;
}

double  Implicit_solver::calculate_y_next(double y_current) {

    double y_next = newton(y_current);
    return y_next;
}

double Implicit_solver::newton(double y_0){
    //Initial Conditions
    auto y_current = y_0;
    auto y_iter = y_0;
    int iterate = 0;
    double error = 1;
    
    // Stopping Criteria
    int max_iterate = 100;
    double accuracy = pow(10, -12);

    while (iterate < max_iterate && error > accuracy){
        y_iter = y_iter - G(y_iter, y_current)/dG(y_iter);
        // Use 2-Norm to estimate the error at each step
        error = G(y_iter, y_current);
        iterate += 1 ;
    }
    return y_iter;

}

double Implicit_solver::G(double y_iter, double y_current){
    return y_iter - y_current - _dt*y_dot(y_iter);
}

double Implicit_solver::dG(double y_iter){
    return 1 - _dt*y_tt(y_iter);
}

double Implicit_solver::y_tt(double y)
{
    return (-7);
}