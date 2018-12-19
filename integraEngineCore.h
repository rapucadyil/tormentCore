#include <iostream>
#include <map>
#include <string>
using namespace std;


#define uint unsigned int

class Engine {

public:

	Engine() {}
	~Engine() {}
	
	virtual bool onInit(const char* title, int xpos, int ypos, int w, int h) {}

};


class Component {

public:
	Component(uint id, string name){}
	~Component() {}
	
	inline string getName() {
		return m_Name;
	}

	inline uint getID() {
	
		return m_CompID;
	}

private:
	string m_Name;
	uint m_CompID;


};


class Entity {

public:
	Entity(uint id) {
		this->m_EntID = id;
		m_Components = map<string, Component*>();
	}
	
	inline void addComponent(Component* comp) {
		if (m_Components.size() != 0)
			m_Components[comp->getName()] = comp;
		else
			cout << "Error occured placing component in map\n map not initialized" << endl;
	
	}

	inline uint getEntityID() { return this->m_EntID; }

	inline Component& getCompByName(string name) {
	
		Component* toReturn = nullptr;
		toReturn = this->m_Component.at(name);
		return *toReturn;
	}
private:
	uint m_EntID;	// the id of this entity
	
	map<string, Component*> m_Components;	// a list of components attached to this entity


};









