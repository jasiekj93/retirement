#pragma once

/**
 * @file OutputMock.hpp
 * @author Adrian Szczepanski
 * @date 2023-08-19
 */

#include <libretirement/core/Output.hpp>

namespace retirement::core::mock
{
	class OutputMock : public Output
	{
	public:
		OutputMock();

		void print(const std::string&) override;

		std::string text;
	};
}
