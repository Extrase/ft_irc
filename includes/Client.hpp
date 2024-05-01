/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:20:29 by diavolo           #+#    #+#             */
/*   Updated: 2024/05/01 17:59:32 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "Server.hpp"

class	Server;

class Client
{
  private:
	int fd;
	std::string ipClient;
	std::string nameClient;
    std::string nicknameClient;

  public:
	Client();
	int getFd();
	std::string getIPAddress() const;
    std::string getName();
    std::string getNickname();
	Client(int serverSocket);
	~Client();
};

#endif
