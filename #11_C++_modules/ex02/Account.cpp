/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateow <ateow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:57:46 by ateow             #+#    #+#             */
/*   Updated: 2024/02/04 18:54:27 by ateow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <chrono>
#include <ctime>

// need to create a constructor to initalised a list of accounts

Account::Account(int initial_deposit)
{
    makeDeposit(initial_deposit);
}

//

void Account::makeDeposit(int deposit)
{

}

bool Account::makeWithdrawal(int withdrawal)
{

}

int Account::checkAmount(void) const
{

}

void Account::displayStatus(void) const
{

}

//

void	Account::_displayTimestamp( void )
{
    auto currentTime = std::chrono::system_clock::now();

    // Convert it to time_t
    std::time_t timestamp = std::chrono::system_clock::to_time_t(currentTime);

    // Format the timestamp
    std::tm* timeInfo = std::localtime(&timestamp);

    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", timeInfo);

    std::cout << "Current Formatted Timestamp: " << buffer << std::endl;
}

//

int Account::getNbAccounts(void)
{

}

int Account::getTotalAmount(void)
{

}

int Account::getNbDeposits(void)
{

}

int Account::getNbWithdrawals(void)
{

}

void Account::displayAccountsInfos(void)
{

}