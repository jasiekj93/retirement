#pragma once

/**
 * @file System.hpp
 * @author Adrian Szczepanski
 * @date 2023-08-19
 */

#include <libretirement/core/Date.hpp>

namespace retirement::core
{
	class System
	{
	public:
		virtual ~System() {}

		virtual Date getDate() const = 0;

		static System* getInstance();

	protected:
		static System* instance;
	};
}
