#include <string>
enum EntityType {
	EMPTY = 0, FOX = 1, GOPHER = 2, PLANT = 3
};

std::string v[] = {"E", "F", "G", "P"};

class Entity {
	protected:
		int row;
		int column;
	public:
		Entity(int r, int c) : row(r), column(c) {}

		virtual ~Entity() {};

		virtual EntityType what() const = 0;

		std::string toString() const;
};


class Plant : public Entity {
	public :
		Plant(int r, int c) : Entity{r,c} {}

		EntityType what() const override {
			return EntityType::PLANT;
		}

		std::string toString() const {
			return v[what()];			
		}

		friend std::ostream& operator<<(std::ostream& os, Plant& p) {
			os << p.toString();
			return os;	
		}
};

class Empty : public Entity {
	public:
		Empty(int r, int c) : Entity{r, c} {}

		EntityType what() const override {
			return EntityType::EMPTY;
		}

		std::string toString() const {
			return v[what()];
		}

		friend std::ostream& operator<<(std::ostream& os, Empty& e) {
			os << e.toString();
			return os;
		}
};

class Animal : public Entity {
	protected: 
		int age;
	public:
		Animal(int r, int c, int a) : Entity {r, c} {
			age = a;
		}
		int getAge() const {
			return age;
		}

		void setAge(int newAge) {
			age = newAge;
		}
};

class Fox : public Animal {
	public: 
		Fox(int r, int c, int a) : Animal{r,c,a}{}
		EntityType what() const override {
			return EntityType::FOX;
		}

		friend std::ostream& operator<<(std::ostream& os, Fox& f) {
			os << f.toString();
			return os;
		}
};

class Gopher : public Animal {
	public:
		Gopher(int r, int c, int a) : Animal{r,c,a} {}

		EntityType what() const override {
			return EntityType::GOPHER;
		}

		friend std::ostream& operator<<(std::ostream& os, Gopher& g) {
			os << g.toString();
			return os;
		}
};
