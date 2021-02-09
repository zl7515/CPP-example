#ifndef odeHEADERDEF
#define odeHEADERDEF

#include <string>
#include "Vector.hpp"
#include "Matrix.hpp"
#include "LS.hpp"
#include "BC.hpp"
#include "Grid.hpp"

class ode  // solve du^2/dx^2 = 1
{
private:
    ode(const ode& ode1);

	int m_node_num;
	double m_x_min;
	double m_x_max;
	double m_mesh_size;
	Matrix* m_matrix; 
	Vector* m_right_vector;  // vector on the RHS
	Vector* m_sol_vector;  // vector of solution
	LS* m_LS;  // linear system to solve
	
    void set_up_matrix();
	void set_up_right_vector();

public:
	ode(int node_num, double x_min, double x_max);
	~ode();
	Vector solve();
};


#endif