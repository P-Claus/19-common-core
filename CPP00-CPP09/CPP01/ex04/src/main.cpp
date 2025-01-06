#include "../includes/main.hpp"

void	exit_handler(std::string error_message)
{
	std::cout << error_message << std::endl;
	exit(1);
}

void	error_check(std::ifstream & inFile)
{
	if (inFile.fail())
		exit_handler("Error opening the file");
	if (inFile.peek() == EOF)
		exit_handler("The file you passed as argument is empty.");
}

void	find_and_replace_string(std::ifstream & inFile, char **argv)
{
	std::string	filename = argv[1];
	std::string 	newFilename = filename  + ".replace";
	std::string 	strToReplace = argv[2];
	std::string 	strReplaceWith = argv[3];
	std::size_t 	strPos;
	std::string	line = "start";
	std::ofstream	outputFile(newFilename.c_str());

	while (true)
	{
		std::getline(inFile, line);
		while (line.find(strToReplace) != std::string::npos)
		{
			strPos = line.find(strToReplace);
			line.erase(strPos, strToReplace.size());
			line.insert(strPos, strReplaceWith);
		}
		if (inFile.eof())
		{
			outputFile << line;
			break;
		}
		outputFile << line << std::endl;
	}
	outputFile.close();
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::ifstream 	inFile;

		inFile.open(argv[1]);
		error_check(inFile);
		find_and_replace_string(inFile, argv);
		inFile.close();
	}
	else 
	{
		exit_handler("Please enter 3 arguments\n"
				"filename, string1, string2\n");
	}
}
