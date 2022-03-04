#include "graphic.h"
#include "input.h"
#include "Game.h"
#include "InputComponent.h"
#include "StateComponent.h"
#include "AnimSpriteComponent.h"
#include "Player.h"
#include "PlayerStates.h"

Player::Player(Game* game)
	:Actor(game)
{
	//�摜�̍����Ɗg�嗦���珰�ɗ��ʒu���v�Z
	float texH = 128;
	float scale = 5;
	SetPosition(VECTOR2(width / 2, height - texH * scale / 2));
	SetScale(scale);

	//����
	mIn = new InputComponent(this);

	//�A�j���[�V�����摜�ǂݍ���
	mAnim = new AnimSpriteComponent(this, 50);
	char filename[128];
	for (int i = 0; i <= 9; i++)
	{
		sprintf_s(filename, "%s%02d.%s", "assets\\Character", i, "png");
		mAnim->AddImage(loadImage(filename));
	}
	//�A�j���[�V�������Ƃ�(�J�n�C���f�b�N�X�A�I���C���f�b�N�X�A���[�v���[�h)
	mAnim->SetRange(0, 0, 0);//Wait
	mAnim->SetRange(0, 5, 1);//Walk Loop
	mAnim->SetRange(6, 6, 0);//Jump
	mAnim->SetRange(7, 9, 0);//Punch

	//Actor��Ԑ؂�ւ��R���|�[�l���g
	mState = new StateComponent(this);
	mState->RegisterState(new PlayerWait(mState));
	mState->RegisterState(new PlayerWalk(mState));
	mState->RegisterState(new PlayerJump(mState));
	mState->RegisterState(new PlayerPunch(mState));
	mState->ChangeState("Wait");
}
