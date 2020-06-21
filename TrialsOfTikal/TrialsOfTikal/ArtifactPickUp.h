#pragma once
#include "Component.h"
#include "Entity.h"
class ArtifactPickUp :
	public Component
{
public: ArtifactPickUp(Entity& newOwner);
	  void UpdateComponent();
	  void PickUp();
	  Entity* owner; //points at owner object //TODO: put this in component....component will need a constructor
};

