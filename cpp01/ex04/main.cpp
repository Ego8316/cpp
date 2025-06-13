/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:00:44 by ego               #+#    #+#             */
/*   Updated: 2025/06/13 11:40:43 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macros.hpp"
#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief Validates command-line arguments for the program.
 * 
 * Checks if the argument count is exactly 4 and ensures that the second and
 * third arguments (`filename` and `s1`) are not empty strings. If any argument
 * is invalid, prints the appropriate error messages and usage instructions.
 * 
 * @note `s2` is allowed to be empty to support removal of occurences.
 * 
 * @param ac Argument count.
 * @param av Argument vector.
 * 
 * @return true if arguments are valid, false otherwise.
 */
static bool	handle_argument(int ac, char **av)
{
	const char	*labels[4] = {"./replace", "filename", "s1", "s2"};
	bool		status;

	status = true;
	if (ac != 4)
		status = false;
	for (int i = 1; i < 3 && ac == 4; ++i)
	{
		std::string	arg(av[i]);
		if (arg.empty())
		{
			std::cerr << COLOR_R << "Error: " << labels[i] << " is empty!"
					<< C_RESET << std::endl;
			status = false;
		}
	}
	if (!status)
		std::cerr << "Usage: "<< labels[0] << " " << labels[1] << "> <"
				<< labels[2] << "> <" << labels[3] << ">" << std::endl;
	return (status);
}

/**
 * @brief Opens the input and output file streams.
 * 
 * Attempts to open an input file stream from `filename` and an output file
 * stream with the name `filename.replace`. Prints error messages and cleans
 * up resources on failure.
 * 
 * @param filename Filename to open.
 * @param in Reference to an ifstream object to open for reading.
 * @param out Reference to an ofstream object to open for writing.
 * 
 * @return true if both streams are succesfully opened, false otherwise.
 */
static bool	open_fstreams(std::string filename, std::ifstream &in, std::ofstream &out)
{
	in.open(filename.c_str());
	if (!in.is_open())
	{
		std::cerr << COLOR_R << "Error: cannot open file " << filename
				<< C_RESET << std::endl;
		return (false);
	}
	out.open((filename + ".replace").c_str());
	if (!out.is_open())
	{
		std::cerr << COLOR_R << "Error: cannot create output file."
				<< C_RESET << std::endl;
		in.close();
		return (false);
	}
	return (true);
}

/**
 * @brief Reads the input file line by line and adds it to the given string.
 * Ensures that it preserves the original file's newline structure by only
 * adding newline characters if the original file actually contained them.
 * 
 * @param ifstream Input file stream.
 * @param content Reference to the string to append.
 * 
 * @param true if everything went fine, false otherwise.
 */
static bool	getcontent(std::ifstream &in, std::string &content)
{
	
	std::string	line;

	while (std::getline(in, line))
	{
		if (in.bad())
		{
			std::cerr << COLOR_R << "Error: reading from input stream failed."
					<< C_RESET << std::endl;
			return (false);
		}
		content += line;
		if (!in.eof())
			content += "\n";
	}
	return (true);
}

/**
 * @brief Replaces all occurences of string `s1` with string `s2` in given
 * string.
 * 
 * Searches for all non-overlapping occurences of `s1` within each line, and
 * replaces them with `s2`.
 * 
 * @param in Content to be searched.
 * @param s1 The substring to search for and replace.
 * @param s2 The substring to insert in place of s1.
 * 
 * @return true if everything went fine, 0 otherwise.
 */
static void	replace(std::string &content, std::string s1, std::string s2)
{
	size_t		pos;
	pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos)
	{
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length();
	}
	return ;
}

int	main(int ac, char **av)
{
	if (!handle_argument(ac, av))
		return (1);
	std::string		filename(av[1]);
	std::string		s1(av[2]);
	std::string		s2(av[3]);
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		content;

	if (!open_fstreams(filename, infile, outfile))
		return (1);
	content = "";
	if (!getcontent(infile, content))
	{
		infile.close();
		outfile.close();
		return (1);
	}
	replace(content, s1, s2);
	outfile << content;
	infile.close();
	outfile.close();
	std::cout << COLOR_G << "Successfully replaced!" << C_RESET << std::endl;
	return (0);
}
