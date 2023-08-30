#include "User.h"

#include <filesystem>
#include <fstream>

User::User() 
{
	readUser();
}

User::~User() 
{
	writeUser();
}

void User::setName(const std::string& name)
{
	name_ = name;
}

void User::setLogin(const std::string& login)
{
	login_ = login;
}

void User::setPassword(const std::string& password)
{
	password_ = password;
}

const std::string& User::getName() const
{
	return name_;
}

const std::string& User::getLogin() const
{
	return login_;
}

const std::string& User::getPassword() const
{
	return password_;
}

void User::readUser() 
{
	std::fstream file(userFile, std::ios::in);

	auto permissions =std::filesystem::perms::group_all | 
		std::filesystem::perms::others_all;
	std::filesystem::permissions(userFile, permissions, std::filesystem::perm_options::remove);

	const std::string delimiter = ":";
	if (file.is_open()) {
		std::string line;
		std::string name;
		std::string value;

		while (std::getline(file, line)) {
	   		size_t delimiterPosition = line.find(delimiter);
			if (delimiterPosition > 0) {
				name = line.substr(0, delimiterPosition);
				value = line.substr(delimiterPosition + 1);

				if (name == "Name") {
					name_ = value;
				}
				else if (name == "Login") {
					login_ = value;
				}
				else if (name == "Password") {
					password_ = value;
				}
			}
	   	}
	}
	file.close();
}

void User::writeUser() const 
{
	std::fstream file(userFile, std::ios::out);
	file << "Name:" << name_ << "\n";
	file << "Login:" << login_ << "\n";
	file << "Password:" << password_ << "\n";
	file.close();
}
