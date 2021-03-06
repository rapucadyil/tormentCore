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
	Component(){}
	~Component() {}
	
	inline string getName() {
		return m_Name;
	}

	inline uint getID() {
	
		return m_CompID;
	}

protected:
	string m_Name;
	uint m_CompID;


};

/*
 * A basic base 'object' that will can be used to represent a player, enemy, npc etc...
 * */
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
		toReturn = this->m_Components.at(name);
		return *toReturn;
	}
private:
	uint m_EntID;	// the id of this entity
	
	map<string, Component*> m_Components;	// a list of components attached to this entity


};

/*
 * A structure that represents 2 dimensional objects i.e. position etc...
 * */

struct Vector2 {

	float x, y;

	Vector2() {
		x = y = 0;
	}

	Vector2(float p_x, float p_y) {
		x = p_x;
		y = p_y;
	}


	
	static Vector2* Zero() {
		return new Vector2();
	}

	static Vector2* Right() {
		return new Vector2(1,0);
	}

	static Vector2* Left() {
		return new Vector2(-1,0);
	}

	static Vector2* Up() {
		return new Vector2(0, 1);
	}

	static Vector2* Down() {
		return new Vector2(0, -1);
	}
};
/*
 *  The transform component that will be attached to any entity that will be in this game context
 * */
class Transform : public Component {
	
public:
	Transform(int xpos, int ypos) {
		m_CompID = 0;
		m_Name = "Transform";
		m_Pos = new Vector2(xpos, ypos); 
	}

	inline Vector2* getPosition() {
		return m_Pos;
	}

private: 
	Vector2* m_Pos;


};

/*
 * A animated sprite representation 
 * */
class AnimatedSprite : public Component {
	

};

