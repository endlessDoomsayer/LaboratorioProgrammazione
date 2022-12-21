#include "Robot.h"

Elem Robot::getTrailFromDir()
{
	switch (dir.getValue()) {
	case Value::up:
		return Elem('\x18', false);
	case Value::down:
		return Elem('\x19', false);
	case Value::right:
		return Elem('\x1a', false);
	case Value::left:
		return Elem('\x1b', false);
	}
}
