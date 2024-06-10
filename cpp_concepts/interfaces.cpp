#include <iostream>
#include <string>

class Printable {
	public:
		virtual std::string getClassName() = 0;
};

class Entity : public Printable {
	public:
		// virtual std::string getName() = 0; // pure virtual function
		virtual std::string getName() { return "entity"; }
		std::string getClassName() override { return "entity"; }
};

class Player : public Entity {
	private:
		std::string m_Name;
	public:
		Player(const std::string& name): m_Name(name) {}

		std::string getName() override { return m_Name; }
		std::string getClassName() override { return "player"; }

};

class A : public Entity {
// class A : public Printable {
	public:
		std::string getClassName() override { return "A"; }
};


void PrintName(Entity* entity) {
	std::cout << entity->getName() << std::endl;
}

void Print(Printable* obj) { // we need a type which provides this function
	std::cout << obj->getClassName() << std::endl;
}

int main() {
	Entity* e = new Entity();
	//PrintName(e);

	Player* p = new Player("dashadsh");
	// PrintName(p);

	Print(e);
	Print(p);
	//Entity* test = new A(); // was not inherited from Entity
	Print(new A());

	Entity* a2 = new A();
	Print(a2);

	


	return 0;
}