#pragma once
class SceneBase
{

public:
	// �f�t�H���g�R���X�g���N�^
	SceneBase() {}

	// �f�X�g���N�^
	virtual ~SceneBase() {}

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};

