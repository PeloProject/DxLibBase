#pragma once
#include "SceneBase.h"

class SceneGame : public SceneBase
{
public:
	// デフォルトコンストラクタ
	SceneGame() {}

	// デストラクタ
	virtual ~SceneGame() {}

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
};

