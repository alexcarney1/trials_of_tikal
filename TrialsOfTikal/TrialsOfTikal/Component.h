#pragma once
#include <string>
class Component
{
public: 
	std::string name;
	virtual void UpdateComponent()=0; //abstract when =0. Pure virtual function. 
};

