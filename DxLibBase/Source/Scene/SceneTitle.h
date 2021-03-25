#pragma once
#include "SceneBase.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	virtual ~SceneTitle();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
};

