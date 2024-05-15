#include "InteractiveMapDecorator.h"

InteractiveMapDecorator::InteractiveMapDecorator(InteractiveMap* baseMap) : map(baseMap) {
}

void InteractiveMapDecorator::display() {
	map->display();
}
