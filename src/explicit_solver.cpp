#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "explicit_solver.h"
#include "solver.h"

Explicit_solver::Explicit_solver(double t_0, double t_end, double dt, double y_0)
: Solver(t_0, t_end, dt, y_0)
{ std::cout << "===========This is a explicit method=========== "<<std::endl;
}

double  Explicit_solver::calculate_y_next(double y_current)
{
    double y_next = y_current + _dt * y_dot(y_current);
    return y_next;

}