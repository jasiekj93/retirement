#pragma once

/**
 * @file Presenter.hpp
 * @author Adrian Szczepanski
 * @date 2023-08-19
 */

#include <libretirement/core/Interval.hpp>

namespace retirement::core
{
	class Presenter
	{
	public:
		virtual ~Presenter() {}

		virtual void display(const Interval&) = 0;


		static Presenter* getInstance();

	protected:
		static Presenter* instance;
	};
}
