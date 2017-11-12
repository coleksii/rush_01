//
// Created by Dmytrii Spyrydonov on 12/11/2017.
//

#include "IMonitorModule.hpp"

IMonitorModule::IMonitorModule()
{}

IMonitorModule::~IMonitorModule()
{}

IMonitorModule& IMonitorModule::operator=(IMonitorModule const &rhs)
{
    (void)rhs;
    return *this;
}

IMonitorModule::IMonitorModule(IMonitorModule const &src)
{
    *this = src;
}