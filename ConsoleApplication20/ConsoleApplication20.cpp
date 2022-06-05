#include <iostream>
class Civilization
{
public:
	virtual int GetPopulation() = 0;
};
class Country : Civilization
{
protected:
	std::string name;
	int population;
public:
	//constructors
	Country(std::string name, int population) : name(name), population(population) {}
	Country() :Country("No name", 0) {}
	Country(Country& country) : name(country.name), population(country.population) { std::cout << "Country copy constructor was used" << std::endl; }
	//destructor
	virtual ~Country() { std::cout << "Country destructed" << std::endl; }
	//additional methods
	virtual int GetPopulation()
	{
		return population;
	}
	std::string GetName()
	{
		return name;
	}
	
};
class Monarchy final: public Country
{
	std::string monarch;
public:
	//constructors
	Monarchy(std::string name, int population, std::string monarch) : Country(name, population), monarch(monarch) {}
	Monarchy() : Country(), monarch("Bob") {}
	Monarchy(Monarchy& monarchy) :Country(monarchy), monarch(monarchy.monarch) { std::cout << "Monarchy copy constructor was used" << std::endl; }
	using Country::Country;
	//destructor
	~Monarchy() { std::cout << "Monarchy destructed" << std::endl; }
	//additional methods
	void SetMonarch(std::string monarch)
	{
		std::cout << "Monarch " << this->monarch << " was banished!" << std::endl;
		this->monarch = monarch;
		std::cout << "Long live monarch " << this->monarch << "!" << std::endl;
	}
	int GetPopulation() override
	{
		return population + 1; //monarch is a human too, and we need to add him to the population.
	}
};
int main()
{
	Country* countries[3] =
	{
		new Country("Applestria",10100),
		new Monarchy("Orangestria", 17600, "Ronald the great"),
		new Country("Cherria", 22750)
	};
	for(int i = 0; i < 3; i++)
	{
		std::cout << "Country " << countries[i]->GetName() << " have population of " << countries[i]->GetPopulation() << " people" <<std::endl;
	}
}
