#pragma once
#include "SceneBase.h"

class SceneTitle : public SceneBase
{
public:
	// �f�t�H���g�R���X�g���N�^
	SceneTitle() {}

	// �f�X�g���N�^
	virtual ~SceneTitle() {}

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
};

