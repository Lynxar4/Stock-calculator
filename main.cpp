#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>

class Stock
{
public:
	Stock() = default;

	Stock(std::string_view name, double price, double peRatio, double dividend, double revenue, double debt)
		:m_name{ name }, m_price{ price }, m_peRatio{ peRatio }, m_dividend{ dividend }, m_revenue{ revenue }, m_debt{ debt }
	{}

	void printInfo() const;
	double getRatio() const { return m_peRatio; }

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
	std::cout << '\n';
}

bool compare(Stock& x, Stock& y)
{
	return x.getRatio() < y.getRatio();
}

void printStockList(const std::vector<Stock>& stocks)
{
	for (const auto& i : stocks)
	{
		i.printInfo();
	}
}

int main()
{
	std::vector<Stock> stocks{};
	Stock Microsoft{"Microsoft", 487.31, 27.15, 0.75, 331.84, 31.07};
	Stock Apple{"Apple", 310.34, 35.58, 0.35, 364.36, 84.34};
	Stock Google{"Google", 344.59, 17.31, 0.26, 229.7, 98.165};
	Stock Nvidia{"Nvidia", 208.48, 31.93, 0.48, 215.9, 11.41};
	Stock AMD{ "AMD", 456.74, 117.20, 0, 21.889, 4.28 };

	stocks.push_back(Microsoft);
	stocks.push_back(Apple);
	stocks.push_back(Google);
	stocks.push_back(Nvidia);
	stocks.push_back(AMD);

	printStockList(stocks);
	
	std::vector<Stock> sortedStocks{stocks};
	std::sort(sortedStocks.begin(), sortedStocks.end(), compare);

	std::cout << "Ranking stocks by P/E Ratio\n";
	printStockList(sortedStocks);
}