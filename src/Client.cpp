/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:30:05 by diavolo           #+#    #+#             */
/*   Updated: 2024/05/01 17:59:37 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Client.hpp"

Client::Client(){}

Client::Client(int serverSocket)
{
	sockaddr_in clientAddr;
	socklen_t clientAddrLen = sizeof(clientAddr);
	char buffer[INET_ADDRSTRLEN];
	fd = accept(serverSocket, (sockaddr *)&clientAddr, &clientAddrLen);
	if (fd == -1)
		throw std::logic_error("Accept connexion error");
	inet_ntop(AF_INET, &(clientAddr.sin_addr), buffer, INET_ADDRSTRLEN);
	ipClient = buffer;
};
Client::~Client()
{
	close(fd);
}

int Client::getFd()
{
	return (this->fd);
};
std::string Client::getIPAddress() const
{
	return (this->ipClient);
}

std::string Client::getName()
{
	return (nameClient);
}

std::string Client::getNickname()
{
	return (nicknameClient);
}
