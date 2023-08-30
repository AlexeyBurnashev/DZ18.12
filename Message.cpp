#include "Message.h"

#include <filesystem>
#include <fstream>

Message::Message() 
{
	readMessage();
}

Message::~Message() 
{
	writeMessage();
}

void Message::setText(const std::string& text)
{
	text_ = text;
}


void Message::setSender(const std::string& sender)
{
	sender_ = sender;
}

void Message::setReceiver(const std::string& receiver)
{
	receiver_ = receiver;
}

const std::string& Message::getText() const
{
	return text_;
}

const std::string& Message::getSender() const
{
	return sender_;
}

const std::string& Message::getReceiver() const
{
	return receiver_;
}

void Message::readMessage() 
{
	std::fstream file(messageFile, std::ios::in);

	auto permissions = std::filesystem::perms::group_all | std::filesystem::perms::others_all;
	std::filesystem::permissions(messageFile, permissions, std::filesystem::perm_options::remove);

	const std::string delimiter = ":";
	if (file.is_open()) 
	{
		std::string line;
		std::string name;
		std::string value;

		while (std::getline(file, line)) 
		{
	   		size_t delimiterPosition = line.find(delimiter);
			if (delimiterPosition > 0) 
			{
				name = line.substr(0, delimiterPosition);
				value = line.substr(delimiterPosition + 1);

				if (name == "Text") 
				{
					text_ = value;
				}
				else if (name == "Sender") 
				{
					sender_ = value;
				}
				else if (name == "Receiver") 
				{
					receiver_ = value;
				}
			}
	   	}
	}
	file.close();
}

void Message::writeMessage() const 
{
	std::fstream file(messageFile, std::ios::out);
	file << "Text:" << text_ << "\n";
	file << "Sender:" << sender_ << "\n";
	file << "Receiver:" << receiver_ << "\n";
	file.close();
}
