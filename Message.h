#pragma once

#include <filesystem>
#include <string>

constexpr auto messageFile = "/home/alexey/zd/message.txt";

class Message final 
{
public:
	Message();
	~Message();

	void setText(const std::string& text);
	void setSender(const std::string& sender);
	void setReceiver(const std::string& receiver);

	const std::string& getText() const;
	const std::string& getSender() const;
	const std::string& getReceiver() const;

private:
	std::string text_;
	std::string sender_;
	std::string receiver_;

	void readMessage();
	void writeMessage() const;
};
