
#include "Message.h"
#include "User.h"
#include <iostream>
#include <string>

int main()
{
	Message message;
	User user;

	std::cout << "Initial message\n";
	std::cout << "text: " << message.getText() << "\n";
	std::cout << "Sender: " << message.getSender() << "\n";
	std::cout << "Receiver: " << message.getReceiver() << "\n";

	std::cout << "Initial user\n";
	std::cout << "Name: " << user.getName() << "\n";
	std::cout << "Login: " << user.getLogin() << "\n";
	std::cout << "Password: " <<user.getPassword() << "\n";

	const std::string newText = "Good";
	message.setText(newText);
	const std::string newSender = "Alex";
	message.setSender(newSender);
	const std::string newReceiver = "Masha";
	message.setReceiver(newReceiver);

	std::cout << "Current message\n";
	std::cout << "Text: " << message.getText() << "\n";
	std::cout << "Sender: " << message.getSender() << "\n";
	std::cout << "Receiver: " << message.getReceiver() << "\n";

	const std::string newName = "Alex";
	user.setName(newName);
	const std::string newLogin = "incitant";
	user.setLogin(newLogin);
	const std::string newPassword = "1234";
	user.setPassword(newPassword);

	std::cout << "Current user\n";
	std::cout << "Name; " << user.getName() << "\n";
	std::cout << "Login: " << user.getLogin() << "\n";
	std::cout << "Password: " << user.getPassword() << "\n";
}
