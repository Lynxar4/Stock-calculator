#include <iostream>
#include <string>
#include <string_view>

class Stock
{
public:
	Stock() = default;

	Stock(std::string_view name, double price, double peRatio, double dividend, double revenue, double debt)
		:m_name{ name }, m_price{ price }, m_peRatio{ peRatio }, m_dividend{ dividend }, m_revenue{ revenue }, m_debt{ debt }
	{}

	void printInfo() const;

private:
	std::string m_name{};
	double m_price{};
	double m_peRatio{};
	double m_dividend{};
	double m_revenue{};
	double m_debt{};
};

void Stock::printInfo() const
{
	std::cout << "Name: " << m_name << '\n';
	std::cout << "Price: " << '$' << m_price << '\n';
	std::cout << "P/E Ratio: " << m_peRatio << '\n';
	std::cout << "Dividend: " << m_dividend << "%\n";
	std::cout << "Revenue: " << m_revenue << " billion\n";
	std::cout << "Debt: " << m_debt << " billion\n";
}

int main()
{
	Stock microsoft{"Microsoft", 487.31, 27.15, 0.75, 331.84, 40.3};
	microsoft.printInfo();
}