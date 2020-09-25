#include <iostream>
#include <cmath>
#include <string>
#include <vector>

std::vector<std::string> processText(std::string text, unsigned int maxLength)
{
	std::vector<std::string> keywords;
	std::string keyword = std::string(maxLength, ' ');

	for (int i = 0; i <= text.size(); ++i)
	{
		keyword[i % maxLength] = text[i];

		if ((i + 1) % maxLength == 0 || i == text.size())
		{
			keywords.push_back(keyword);
			keyword = std::string(maxLength, ' ');
		}
	}

	return keywords;
}

void borderedText(std::string text, unsigned int maxLength, unsigned int vertPad, unsigned int horaPad, std::string pattern)
{
	if (text.size() < maxLength)
	{
		maxLength = text.size();
	}
	std::vector<std::string> textLines = processText(text, maxLength);
	unsigned int rowsText = std::ceil(static_cast<float>(text.size()) / maxLength);
	unsigned int rows = 2 * vertPad + 2 + rowsText;
	unsigned int columns =  2 * horaPad + maxLength + 2;
	for (int row = 0; row != rows; row++)
	{
		if (row != 0)
		{
			std::cout << std::endl;
		}
		for (int column = 0; column != columns; ++column)
		{
			//std::cout << pattern[((row * columns) + column) % pattern.size()];
			if (row == 0 || row == rows - 1 || column == 0 || column == columns - 1)
			{
				std::cout << pattern[((row * columns) + column) % pattern.size()];
			}

			else if (row > vertPad&& row < rows - vertPad - 1 && column > horaPad && column < columns - horaPad - 1)
			{
				std::cout << textLines[row - vertPad - 1][column - horaPad - 1];
			}

			else
				std::cout << ' ';
		}
	}
}
