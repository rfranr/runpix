//
// Created by rfranr on 7/2/21.
//

#include "../r/infrastructure/log/logger.h"
#include <string>

using namespace r::infrastructure;


void testingComments (int x) {
	auto s = std::to_string(x);
	Log::error("test := " + s);
}
