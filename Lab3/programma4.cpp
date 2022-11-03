#include <iostream>
#include "MyVector.hpp"
#include "programmi.h"

namespace Prog4 {

	void exec() {
		try {
			MyVector v(3);

			v[0] = 2.3;
			v[1] = 3.4;
			v[2] = 4.5;

			std::cout << "v[0]: " << v[0] << std::endl;

			std::cout << "safe get v[4]: " << v.safe_get(4) << std::endl;

			v.safe_set(2, 12.3);
			std::cout << "safe set v[2] <- 12.3: " << v[2] << std::endl;

		}
		catch (SizeException e) {
			e.print();
		}
	}
}