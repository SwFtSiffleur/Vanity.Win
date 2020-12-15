#ifndef _STRUCT_HPP
#define _STRUCT_HPP

#include <string>
#include <vector>


struct Vector2
{
	double x;
	double y;
};

namespace Weapon
{

	struct data
	{
		std::string type;

		std::vector<Vector2> angles;

		double repeat_delay;
	};
}

#endif 