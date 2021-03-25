#pragma once
class SceneBase
{

public:
	SceneBase() {}
	virtual ~SceneBase() {}

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};

