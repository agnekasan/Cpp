#include <iostream>
#include <memory>

class pImpl
{
	std::string name;
	int age;
public:
	pImpl(const std::string& name_, int age_) : name(name_), age(age_) {} 

	~pImpl() {}

	pImpl(const pImpl&) = delete;

	// setter
	void setAge(int age_) { age = age_; }

	//getter
	inline const std::string& getName() const { return name; }
	inline int getAge() const { return age; }
	
};

class Player
{
private:
	std::unique_ptr<pImpl> pimpl;
	
public:
	Player(const std::string& name_, int age_) 
		: pimpl{std::make_unique<pImpl>(name_, age_)}
	{ }

	// dtor
	~Player() { }

	Player& operator=(const Player&) = delete;

	// setter
	void setAge(int age_) { pimpl->setAge(age_); }

	// getter
	inline const std::string& getName() const { return pimpl->getName(); }
	inline int getAge() const { return pimpl->getAge(); }

	friend std::ostream& operator<<(std::ostream&, const Player&);

};

std::ostream& operator<<(std::ostream& out, const Player& rhs)
{
	return out << rhs.getName() << " " << rhs.getAge() << std::endl;
}


int main(int argc, char const *argv[])
{
	Player p1("Jack", 32);
	std::cout << p1;
	return 0;
}