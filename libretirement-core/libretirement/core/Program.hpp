#pragma once

/**
 * @file Program.hpp
 * @author Adrian Szczepanski
 * @date 2023-08-19
 */

#include <libretirement/core/Date.hpp>

namespace retirement::core
{
	class Program
	{
	public:
		Program();

		void execute(Date& retirement);

	};
}
