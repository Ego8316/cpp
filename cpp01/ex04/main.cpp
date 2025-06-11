/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:00:44 by ego               #+#    #+#             */
/*   Updated: 2025/06/11 21:34:06 by ego              ###   ########.fr       */
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
 * @brief Replaces all occurences of string `s1` with string `s2` in the input
 * file stream and write the result to the output file stream.
 * 
 * Reads the input file line by line, searches for all non-overlapping
 * occurences of `s1` within each line, and replaces them with `s2`. The
 * modified lines are then written to the output file stream. Ensures that it
 * preserves the original file's newline structure by only adding newline
 * characters if the original file contained them.
 * 
 * @param in Reference to the input file stream.
 * @param out Reference to the output file stream.
 * @param s1 The substring to search for and replace.
 * @param s2 The substring to insert in place of s1.
 * 
 * @return true if everything went fine, 0 otherwise.
 */
static bool	replace(std::ifstream &in, std::ofstream &out, std::string s1, std::string s2)
{
	std::string	line;
	size_t		pos;
	
	while (std::getline(in, line))
	{
		if (in.bad())
		{
			std::cerr << COLOR_R << "Error: reading from input stream failed."
					<< C_RESET << std::endl;
			return (false);
		}
		pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		out << line;
		if (in.peek() != EOF)
			out << std::endl;
		if (out.bad())
		{
			std::cerr << COLOR_R << "Error: writing to output stream failed."
					<< C_RESET << std::endl;
			return (false);
		}
	}
	return (true);
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

	if (!open_fstreams(filename, infile, outfile))
		return (1);
	bool	status = replace(infile, outfile, s1, s2);
	infile.close();
	outfile.close();
	if (status)
		std::cout << COLOR_G << "Successfully replaced!" << C_RESET << std::endl;
	return (status ? 0 : 1);
}
