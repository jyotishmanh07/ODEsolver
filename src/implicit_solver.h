#ifndef IMPLICIT_SOLVER_H
#define IMPLICIT_SOLVER_H
#include "solver.h"

class Implicit_solver : public Solver{
    public:
        Implicit_solver(double t_0, double t_end, double dt, double y_0);
 
        double calculate_y_next(double y_current) override;

        double newton(double y_0);
        
        double G(double y_next, double y_current);

        double dG(double y_next);

        double y_tt(double y);

};

#endif