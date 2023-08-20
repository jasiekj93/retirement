#pragma once

/**
 * @file Output.hpp
 * @author Adrian Szczepanski
 * @date 2023-08-19
 */

#include <string>

namespace retirement::core
{
	class Output
	{
	public:
		virtual ~Output() {}

		virtual void print(const std::string&) = 0;

		static Output* getInstance();

	protected:
		static Output* instance;
	};
}
