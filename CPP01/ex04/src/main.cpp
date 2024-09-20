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
	std::string		filename = argv[1];
	std::string 	new_filename = filename  + ".replace";
	std::string 	str_to_replace = argv[2];
	std::string 	str_replace_with = argv[3];
	std::size_t 	str_pos;
	std::string		line = "start";
	std::ofstream	outputFile(new_filename);

	while (true)
	{
		std::getline(inFile, line);
		while (line.find(str_to_replace) != std::string::npos)
		{
			str_pos = line.find(str_to_replace);
			line.erase(str_pos, str_to_replace.size());
			line.insert(str_pos, str_replace_with);
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
