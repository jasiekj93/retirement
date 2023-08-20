#pragma once

/**
 * @file SystemImpl.hpp
 * @author Adrian Szczepanski
 * @date 2023-08-19
 */

#include <libretirement/core/System.hpp>

namespace retirement::core
{
	class SystemImpl : public System
	{
	public:
		SystemImpl();

		Date getDate() const override;
	};
}
