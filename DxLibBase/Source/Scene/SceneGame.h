#pragma once
#include "SceneBase.h"

class SceneGame : public SceneBase
{
public:
	// �f�t�H���g�R���X�g���N�^
	SceneGame() {}

	// �f�X�g���N�^
	virtual ~SceneGame() {}

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
};

