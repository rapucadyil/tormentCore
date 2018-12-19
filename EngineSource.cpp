#include "integraEngineCore.h"
#include <iostream>

using namespace std;

int main() {
	

	Entity* e = new Entity(0);
	e->addComponent(new Component(1, "test"));
	while(1) {
	cout << " Entity, with ID:  " << e->getEntityID() << endl;
	//cout << "With Components: " << e->getCompByName("test") << endl;
	}
	return 0;

}
