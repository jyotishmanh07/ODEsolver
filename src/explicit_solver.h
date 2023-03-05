#ifndef EMPLICIT_SOLVER_H
#define EMPLICIT_SOLVER_H
#include "solver.h"

class Explicit_solver : public Solver{
    public:
        Explicit_solver(double t_0, double t_end, double dt, double y_0);
 
        double calculate_y_next(double y_current) override;
};

#endif