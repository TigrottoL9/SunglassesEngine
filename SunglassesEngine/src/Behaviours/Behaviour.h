#pragma once
#include <vector>

#include "../IUpdetable.h"
#include "../Components/IComponent.h"


class Behaviour : public IUpdatable
{
public:
	~Behaviour() = default;

	virtual void Update() {};
private:


};

