/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:56:58 by lde-mais          #+#    #+#             */
/*   Updated: 2024/05/01 19:21:22 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"
Server::Server() {}

Server::Server(int port) : _port(port)
{
	_serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (_serverSocket == -1)
		throw std::invalid_argument("socket creation failed");
}

Server::~Server()
{
	close(_serverSocket);
}

void Server::run()
{
	memset(&_serverAddr, 0, sizeof(_serverAddr));
	_serverAddr.sin_family = AF_INET;
	_serverAddr.sin_port = htons(_port);
	_serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	_client_number = 0;

	if (bind(_serverSocket, (sockaddr*)&_serverAddr, sizeof(_serverAddr)) == -1)
		throw std::logic_error("bind error");
	if (listen(_serverSocket, 10) == -1)
		throw std::logic_error("listen error");

	std::cout << "waiting for connexion on the port " << _port << std::endl;

	pollfds.push_back((struct pollfd){.fd = _serverSocket, .events = POLLIN});

	while (true){
		int ret = poll(pollfds.data(), pollfds.size(), -1);
		if (ret == -1)
			throw std::logic_error("Poll failed");
		Client test(_serverSocket);
		map_client[test.getFd()] = test;
		pollfds.push_back((struct pollfd){.fd = test.getFd(), .events = POLLIN});
		size_t i = 0;
		if (ret > 0)
		{
			while (pollfds[i].revents){

				if (i == 0)
					Client test2(_serverSocket);
				std::cout << "Connexion accepted since " << test.getIPAddress() << std::endl;
				// if (pollfds[i].revents & POLLOUT)
				if (pollfds[i].revents & POLLIN){
				while (true){
					_bytesRead = recv(pollfds[i].fd, &_buff, 1024, MSG_DONTWAIT);
					if (_bytesRead <= 0){
						if (_bytesRead == 0)
						{
							std::cout << "Client disconnected" << std::endl;
							break;
						}
						else
							throw std::runtime_error("Error recv");
					}
					_buff[_bytesRead] = '\0';
					std::cout << "Message from the client: " << _buff << std::endl;
				}
				}
				++i;
				if (i >= pollfds.size())
					i = 0;
			}
		}
	}
}
