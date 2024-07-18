#pragma once
#include <vector>
#include <memory>

#include "../Core/IUpdetable.h"

class Behaviour : public IUpdatable
{
public:
	~Behaviour() = default;

	virtual void Update() {};

private:


};

