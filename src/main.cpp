/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:46:50 by mderkaou          #+#    #+#             */
/*   Updated: 2024/04/18 19:16:45 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/struct.hpp"


int main(int ac, char *av[])
{
	if (ac == 1)
	{
		(void)av;
		addrinfo hints, *res;
		int sockfd;

		memset(&hints, 0, sizeof hints);
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;

		if (getaddrinfo("www.example.com", "3490", &hints, &res) != 0){
			std::cerr << "Error getaddrinfo" << std::endl;
			return 1;
		}

		sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if (sockfd == -1){
			std::cerr << "Erroc de socket" << std::endl;
			return 1;
		}
		close(sockfd);
		freeaddrinfo(res);
	}

}

// int main(){

// 	protoent *protocol = getprotobyname("TCP");
// 	ssize_t len;
// 	addrinfo addrinfo_;
// 	if (!getaddrinfo(addrinfo_.ai_canonname, addrinfo_.))
// 	std::string test = "Ce qui compte c'est pas d'avoir beaucoup de temps";
// 	char buff[512];
// 	int sockfd;
// 	if (protocol == NULL)
// 		return (1);
// 	sockfd = socket(PF_INET, SOCK_STREAM, protocol->p_proto);
// 	if (sockfd == -1)
// 		return (1);
// 	send(sockfd, test.c_str(), 50, MSG_DONTWAIT);
// 	len = recv(sockfd, buff, 50, MSG_DONTWAIT);
// 	if (len == 0 || len == -1)
// 		return 1;
// 	buff[len] = '\0';
// 	std::cout << buff << std::endl;
// 	close(sockfd);
// }

