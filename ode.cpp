#include <iostream>
#include<fstream>
#include<cassert>
#include<cmath>
#include "ode.hpp"

ode::ode(int node_num, double x_min, double x_max)  // node_num exclude boundary nodes
{
	m_node_num = node_num;
	m_x_min = x_min;
	m_x_max = x_max;
	m_mesh_size = (x_max - x_min) / (m_node_num + 1);
	
	m_matrix = new Matrix(m_node_num, m_node_num);
	m_right_vector = new Vector(m_node_num);
	m_sol_vector = new Vector(m_node_num);
	m_LS = NULL;
	
}

ode::~ode()
{
	delete m_matrix;
	delete m_right_vector;
	delete m_sol_vector;
}

void ode::set_up_matrix()
{
	for (int i = 1; i <= m_node_num; i++)
	{
		if (i == 1)
		{
			(*m_matrix)(i, i) = -2 / m_mesh_size / m_mesh_size;
			(*m_matrix)(i, i+1) = 1 / m_mesh_size / m_mesh_size;
		}
		else if (i == m_node_num)
		{
			(*m_matrix)(i, i) = -2 / m_mesh_size / m_mesh_size;
			(*m_matrix)(i, i - 1) = 1 / m_mesh_size / m_mesh_size;
		}
		else
		{
			(*m_matrix)(i, i) = -2 / m_mesh_size / m_mesh_size;
			(*m_matrix)(i, i + 1) = 1 / m_mesh_size / m_mesh_size;
			(*m_matrix)(i, i - 1) = 1 / m_mesh_size / m_mesh_size;
		}
	}
}

void ode::set_up_right_vector()
{
	for (int i = 1; i <= m_node_num; i++)
	{
		(*m_right_vector)(i) = 1;
	}
}

Vector ode::solve()
{
	set_up_matrix();
	set_up_right_vector();
	m_LS = new LS(*m_right_vector, *m_matrix);
	return m_LS->solve();
}