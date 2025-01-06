#include "../includes/BitcoinExchange.hpp"

std::map<std::string, float> dateAndValueMap;

void	exit_handler(std::string error_message)
{
	std::cout << error_message << std::endl;
	exit(1);
}

void	error_check(std::ifstream& inFile)
{
	if (inFile.fail())
		exit_handler("Error opening the file");
	if (inFile.peek() == EOF)
		exit_handler("The file you passed as argument is empty.");
}

bool	isInteger(std::string& string)
{
	std::stringstream 	ss;
	int 				integer;

	ss << string;
	ss >> integer;

	if (ss.fail() || !ss.eof())
		return (false);
	else
		return (true);
}

int		handle_int(std::string& string)
{
	std::stringstream	ss;
	int					integer;

	ss << string;
	ss >> integer;

	return (integer);
}

float		handle_float(std::string& string)
{
	std::stringstream	ss;
	float				floatNb;

	ss << string;
	ss >> floatNb;

	return (floatNb);
}

bool	isFloat(std::string& string)
{
    std::stringstream 	ss;
    float 				f;

	ss << string;
	ss >> f;
	
	if (ss.fail() || !ss.eof())
		return (false);
	else
		return (true);

	return (false);
}

std::string findClosestDateBefore(const std::string& targetDate)
{
	std::map<std::string, float>::iterator it = dateAndValueMap.lower_bound(targetDate);
    
    if (it == dateAndValueMap.begin())
        return "No earlier date available";
    if (it == dateAndValueMap.end() || it->first != targetDate)
        --it;
    return (it->first);
}

void	parseLine(std::string& data)
{
	DateAndValue	dateAndValueObj;
	std::size_t		delimPos;
	float			convertedNb = 0.0;
	int				convertedYear = 0;
	int				convertedMonth = 0;
	int				convertedDay = 0;

	delimPos = data.find("|");
	if (delimPos != 11 || data[12] != ' ')
	{
		std::cout << "Error: please provide a date and value in the correct format" << std::endl;
		return ;
	}

	std::string		date = data.substr(0, delimPos -1);
	std::string		nb = data.substr(delimPos + 2, data.length());
	std::string		year = date.substr(0, 4);
	if (isInteger(year) == true)
	{
		convertedYear = handle_int(year);
		if (convertedYear < 2009 || convertedYear > 2022)
		{
			std::cout << "Error: year has to be between 2009 and 2022" << std::endl;
			return ;
		}
	}

	std::string		month = date.substr(5, 2);
	if (isInteger(month) == true)
	{
		convertedMonth = handle_int(month);
		if (convertedMonth < 01 || convertedMonth > 12)
		{
			std::cout << "Error: month has to be between 1 and 12" << std::endl;
			return ;
		}
	}

	std::string		day = date.substr(8, 2);
	if (isInteger(day) == true)
	{
		convertedDay = handle_int(day);
		if (convertedDay < 01 || convertedDay > 31)
		{
			std::cout << "Error: day has to be between 1 and 31" << std::endl;
			return ;
		}
	}

	dateAndValueObj.setDate(date); 

	if (isInteger(nb) == true)
		convertedNb = handle_int(nb);
	else if (isFloat(nb) == true)
		convertedNb = handle_float(nb);
	else
	{
		std::cout << "Error: the value is not valid" << std::endl;
		return ;
	}

	if (convertedNb < 0 || convertedNb > 1000)
	{
		std::cout << "Error: the value needs to be between 0 and 1000" << std::endl;
		return ;
	}

	dateAndValueObj.setValue(convertedNb);

	if (dateAndValueObj.getDate() != "" && dateAndValueObj.getValue())
		dateAndValueObj.printOutput();
}

void	parseData(std::ifstream& inFile)
{
	std::string		data;

	std::getline(inFile, data);
	while (!inFile.eof())
	{
		std::getline(inFile, data);
		if (!data.empty())
			parseLine(data);
	}
}

void	read_from_db()
{
	std::ifstream	fin;	
	std::string		line;
	std::string		token;
	std::string		date;
	float			value;
	size_t			pos = 0;

	fin.open("data.csv");

	if (fin.fail())
		exit_handler("Error: failed to open the file");

	std::getline(fin, line);
	while (!fin.eof())
	{
		std::getline(fin, line);
		if ((pos = line.find(',')) != std::string::npos)
		{
			token = line.substr(0, pos);
			date = token;
			token = line.substr(11, 11);
			value = handle_float(token);
		}
		dateAndValueMap[date] = value;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		exit_handler("Please provide an input.txt file in the correct format");

	std::ifstream					inFile;

	read_from_db();
	inFile.open(argv[1]);
	error_check(inFile);
	parseData(inFile);
}
