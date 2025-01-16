#pragma once
#include <memory>

using std::shared_ptr;

class game
{
public:
	game();

	shared_ptr<class input_handler> get_input_handler() const { return inputHandler; }
	

private:
	shared_ptr<class input_handler> inputHandler;
};

