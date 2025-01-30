#pragma once
#include <SFML/Graphics.hpp>

using std::shared_ptr;

class ui
{
public:
	ui(shared_ptr<class game> gInst);

private:

	shared_ptr<class game> gameInst;
};

