#pragma once

/**
 * @file OutputImpl.hpp
 * @author Adrian Szczepanski
 * @date 2023-08-19
 */

#include <libretirement/core/Output.hpp>

namespace retirement::core
{
	class OutputImpl : public Output
	{
	public:
		OutputImpl();

		void print(const std::string&) override;
	};
}
