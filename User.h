#pragma once

#include <filesystem>
#include <string>

constexpr auto userFile = "/home/alexey/zd/user.txt";

class User final 
{
public:
	User();
	~User();

	void setName(const std::string& name);
	void setLogin(const std::string& login);
	void setPassword(const std::string& password);

	const std::string& getName() const;
	const std::string& getLogin() const;
	const std::string& getPassword() const;

private:
	std::string name_;
	std::string login_;
	std::string password_;

	void readUser();
	void writeUser() const;

};

