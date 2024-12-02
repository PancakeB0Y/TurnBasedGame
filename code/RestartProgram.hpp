#pragma once

#include <iostream>

static class RestartProgram {
	public:
		void static Restart(int(*func)());
};
