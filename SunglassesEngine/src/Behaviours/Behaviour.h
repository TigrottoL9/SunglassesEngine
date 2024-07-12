#pragma once
#include <vector>

#include "../IUpdetable.h"
#include "../Components/IComponent.h"


class Behaviour : public IUpdatable
{
public:
	// Inherited via IUpdatable
	virtual void Update() = 0;
private:


};

