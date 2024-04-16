/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:46:50 by mderkaou          #+#    #+#             */
/*   Updated: 2024/04/16 15:35:38 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <poll.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <stdlib.h>


int main(){

	protoent *protocol = getprotobyname("TCP");
	ssize_t len;
	if (!getaddrinfo())
	std::string test = "Ce qui compte c'est pas d'avoir beaucoup de temps";
	char buff[512];
	int sockfd;
	if (protocol == NULL)
		return (1);
	sockfd = socket(PF_INET, SOCK_STREAM, protocol->p_proto);
	if (sockfd == -1)
		return (1);
	send(sockfd, test.c_str(), 50, MSG_DONTWAIT);
	len = recv(sockfd, buff, 50, MSG_DONTWAIT);
	if (len == 0 || len == -1)
		return 1;
	buff[len] = '\0';
	std::cout << buff << std::endl;
	close(sockfd);
}

