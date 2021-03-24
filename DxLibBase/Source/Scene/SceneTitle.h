#pragma once
#include "SceneBase.h"

class SceneTitle : public SceneBase
{
public:
	// デフォルトコンストラクタ
	SceneTitle() {}

	// デストラクタ
	virtual ~SceneTitle() {}

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
};

