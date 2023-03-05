#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

class Solver{
    protected:
        std::vector<double> _y_approx;
        std::vector<double> _y_anal;
        const double _t_0, _t_end, _dt, _y_0;

    public:
        Solver(double t_0, double t_end, double dt, double y_0);

        // using different solver to calculate y for the next time step
        virtual double calculate_y_next(double y_current) = 0;

        // solving the equation and return y_approx and y_anal
        void solve();

        void print_results();

        // an ode equation
        double y_dot(double y);

        // an analytic solution of y
        double y_analytic(double t);

        virtual ~Solver() {};
};

#endif
