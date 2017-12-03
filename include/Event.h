/*****************************************************************************
*
*  PROJECT:     CIV5: Scripthook
*  LICENSE:     See LICENSE in the top level directory
*  PURPOSE:     Generic event template
*
*****************************************************************************/
#pragma once

#include <vector>
#include <functional>
#include <utility>

template<typename... Args>
class Event
{
public:
	using HandlerFunction_t = std::function<void(Args...)>;

	Event() = default;

	Event& operator+=(const HandlerFunction_t& func)
	{
		_handlers.push_back(func);
		return *this;
	}

	void operator()(Args... args)
	{
		for (auto& func : _handlers)
		{
			func(std::forward<Args>(args)...);
		}
	}

private:
	std::vector<HandlerFunction_t> _handlers;
};
