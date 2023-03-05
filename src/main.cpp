#include <iostream>
#include <chrono>
#include <thread>
#include "solver.h"
#include "implicit_solver.h"
#include "explicit_solver.h"


int main()
{
    // initial condition
    const double t_0 = 0;
    const double t_end = 5;
    const double dt = 0.25;
    const double y_0 = 1;

    int method = 0;
    std::cout<<"Please enter 1 for Explicit euler method."<<std::endl;
    std::cout<<"Please enter 2 for Implicit euler method."<<std::endl;
    std::cin>>method;
    
    std::unique_ptr<Solver> solver;

    if (method == 1){
        // for explicit euler method
        

        solver = std::make_unique<Explicit_solver>(t_0, t_end, dt, y_0);

        
    }
    else if (method == 2){
        // for explicit euler method
        solver = std::make_unique<Implicit_solver>(t_0, t_end, dt, y_0);
    }
    else{
        std::cout<<"Please enter 1 or 2 for choosing the method."<<std::endl;
    }
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;
    start = std::chrono::system_clock::now();
    
    solver -> solve();
    
    end = std::chrono::system_clock::now();
        auto time_duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Solving time: " << time_duration.count()/1000000.0<< " seconds" << std::endl;
    
    solver -> print_results();

    return 0;

} 